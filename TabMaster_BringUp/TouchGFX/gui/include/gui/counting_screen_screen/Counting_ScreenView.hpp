#ifndef COUNTING_SCREENVIEW_HPP
#define COUNTING_SCREENVIEW_HPP

#include <gui_generated/counting_screen_screen/Counting_ScreenViewBase.hpp>
#include <gui/counting_screen_screen/Counting_ScreenPresenter.hpp>

class Counting_ScreenView : public Counting_ScreenViewBase
{
public:
    Counting_ScreenView();
    virtual ~Counting_ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // COUNTING_SCREENVIEW_HPP
