#ifndef __RENDER_WINDOW_H__
#define __RENDER_WINDOW_H__

class wxGLContext;

namespace Project
{

class Render_window : public wxGLCanvas
{
public:

    Render_window(wxWindow* window_parent, const wxGLAttributes& gl_attribs);

private:

    void on_paint(wxPaintEvent& wx_event);

    void on_size(wxSizeEvent& wx_event);

    void on_erase_background(wxEraseEvent& wx_event);
    
    bool init_graphics();

    std::unique_ptr< wxGLContext > m_context;

    bool m_graphics_initialized;

    DECLARE_EVENT_TABLE()
};

};

#endif
