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

    virtual void update_max_cnt_vf();
    virtual void stop_count_btn_vf();
    virtual void update_current_count();
    virtual void continue_btn_vf();

protected:
};

#endif // COUNTINGVIEW_HPP
