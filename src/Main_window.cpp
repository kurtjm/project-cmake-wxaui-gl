
#include <memory>
#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/glcanvas.h>

#include "Render_window.h"
#include "Main_window.h"

namespace Project
{

BEGIN_EVENT_TABLE(Main_window, wxFrame)
    EVT_MENU(wxID_EXIT, Main_window::on_command_file_exit)
END_EVENT_TABLE()

Main_window::Main_window(wxWindow*       window_parent,
                         wxWindowID      window_id,
                         const wxString& window_title,
                         const wxPoint&  window_position,
                         const wxSize&   window_size,
                         long            window_style) 
:   wxFrame(window_parent, window_id, window_title, window_position, window_size, window_style),
    m_aui_manager(std::unique_ptr< wxAuiManager >(new wxAuiManager()))
{
    init_aui();
    init_status_bars();
    init_menus();
}

Main_window::~Main_window()
{
    m_aui_manager->UnInit();
}

void Main_window::init_aui()
{
    m_aui_manager->SetManagedWindow(this);

    wxGLAttributes gl_attribs;
    gl_attribs.PlatformDefaults().MinRGBA(8, 8, 8, 8).DoubleBuffer().Depth(16).EndList();

    auto render_pane = new Render_window(this, gl_attribs);
    m_aui_manager->AddPane(render_pane, wxAuiPaneInfo().Name("PaneID").Center());

    // Other panes can be added here...

    m_aui_manager->Update();
}

void Main_window::init_status_bars()
{
    auto status_bar = CreateStatusBar();
    status_bar->SetStatusText(wxString("Ready."), 0);
}

void Main_window::init_menus()
{
    auto menu_file = new wxMenu();
    menu_file->Append(wxID_EXIT, "E&xit");

    auto menu_bar = new wxMenuBar();
    menu_bar->Append(menu_file, "&File");
    SetMenuBar(menu_bar);
}

void Main_window::on_command_file_exit(wxCommandEvent& wx_event)
{
    Close();
}

};
