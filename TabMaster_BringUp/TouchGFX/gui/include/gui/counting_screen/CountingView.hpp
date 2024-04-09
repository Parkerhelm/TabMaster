#ifndef COUNTINGVIEW_HPP
#define COUNTINGVIEW_HPP

#include <gui_generated/counting_screen/CountingViewBase.hpp>
#include <gui/counting_screen/CountingPresenter.hpp>

class CountingView : public CountingViewBase
{
public:
    CountingView();
    virtual ~CountingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // COUNTINGVIEW_HPP
