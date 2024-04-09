#ifndef STARTUP_SCREENVIEW_HPP
#define STARTUP_SCREENVIEW_HPP

#include <gui_generated/startup_screen_screen/Startup_ScreenViewBase.hpp>
#include <gui/startup_screen_screen/Startup_ScreenPresenter.hpp>

class Startup_ScreenView : public Startup_ScreenViewBase
{
public:
    Startup_ScreenView();
    virtual ~Startup_ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STARTUP_SCREENVIEW_HPP
