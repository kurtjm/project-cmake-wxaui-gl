
#include <memory>
#include <wx/wx.h>
#include <wx/app.h>

#include "Main_window.h"
#include "Application.h"

namespace Project
{

bool Application::OnInit()
{
    wxString title("Basic Render Window");

    // Window memory is managed by wxWidgets

    auto frame = new Main_window(0, wxID_ANY, title, wxDefaultPosition, 
                                 wxSize(640, 480), wxDEFAULT_FRAME_STYLE);
    SetTopWindow(frame);

    frame->Show();
    return true;
}

int Application::OnExit()
{
    return wxApp::OnExit();
}

bool Application::OnExceptionInMainLoop()
{
    wxString error;
    try {
        throw;
    } 
    catch (const std::exception& e) {
        error = e.what();
    }
    catch ( ... ) {
        error = "Unknown error.";
    }

    wxMessageBox(error, wxString("Error"), wxICON_ERROR|wxOK);
    return false;
}

};

IMPLEMENT_APP(Project::Application)
