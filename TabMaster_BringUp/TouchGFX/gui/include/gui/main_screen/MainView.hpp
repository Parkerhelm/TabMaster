#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void p50_btn_vf();
    virtual void p10_btn_vf();
    virtual void p1_btn_vf();
    virtual void reset_btn_vf();


protected:
};

#endif // MAINVIEW_HPP
