
#include <memory>
#include <assert.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "Render_window.h"

namespace Project
{

BEGIN_EVENT_TABLE(Render_window, wxGLCanvas)
    EVT_PAINT(Render_window::on_paint)
    EVT_SIZE(Render_window::on_size)
    EVT_ERASE_BACKGROUND(Render_window::on_erase_background)
END_EVENT_TABLE()

Render_window::Render_window(wxWindow* window_parent, const wxGLAttributes& gl_attribs)
:   wxGLCanvas(window_parent, gl_attribs),
    m_context(nullptr),
    m_graphics_initialized(false)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    wxGLContextAttrs attrs;

#ifdef __APPLE__
    attrs.CoreProfile().OGLVersion(3, 0).Robust().ResetIsolation().EndList();
#else
    attrs.PlatformDefaults().EndList();
#endif

    m_context = std::unique_ptr< wxGLContext >(new wxGLContext(this, NULL, &attrs));
}

void Render_window::on_paint(wxPaintEvent& wx_event)
{
    if (!IsShown()) {
        return;
    }

    wxGLCanvas::SetCurrent(*(m_context.get()));

    if (!m_graphics_initialized) {
        if (!init_graphics()) {
            throw std::runtime_error("Unable to initialize graphics.");
        }
    }

    wxPaintDC dc(this);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();

    SwapBuffers();
}

void Render_window::on_size(wxSizeEvent& wx_event)
{
    Refresh();
}

void Render_window::on_erase_background(wxEraseEvent& wx_event)
{
}

bool Render_window::init_graphics()
{
    assert(!m_graphics_initialized);

    const GLubyte* version = glGetString(GL_VERSION);
    if (!version) {
        std::cout << "Unable to acquire OpenGL version." << std::endl;
        return false;
    }

    std::cout << "OpenGL Version: " <<  version << std::endl;

    glClearColor(0.5f, 0.25f, 0.25f, 1.0f);
    glClearDepth(1.0f);
    
    return (m_graphics_initialized = true); 
}

};
