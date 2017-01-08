#ifndef __APPLICATION_H__
#define __APPLICATION_H__

namespace Project
{

class Application : public wxApp
{
public:

    virtual bool OnInit();

    virtual int  OnExit();

    virtual bool OnExceptionInMainLoop();
};

};

DECLARE_APP(Project::Application)

#endif
