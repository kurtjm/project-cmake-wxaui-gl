#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

class wxAuiManager;

namespace Project
{

class Main_window : public wxFrame
{
public:

    Main_window(wxWindow*       window_parent,
                wxWindowID      window_id,
                const wxString& window_title,
                const wxPoint&  window_position,
                const wxSize&   window_size,
                long            window_style);

    virtual ~Main_window();

private:

    void init_aui();

    void init_status_bars();

    void init_menus();

    void on_command_file_exit(wxCommandEvent& wx_event);

    std::unique_ptr< wxAuiManager > m_aui_manager;

    DECLARE_EVENT_TABLE()
};

};

#endif
