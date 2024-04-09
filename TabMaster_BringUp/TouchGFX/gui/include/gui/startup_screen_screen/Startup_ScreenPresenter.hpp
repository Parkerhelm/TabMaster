#ifndef STARTUP_SCREENPRESENTER_HPP
#define STARTUP_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Startup_ScreenView;

class Startup_ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Startup_ScreenPresenter(Startup_ScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Startup_ScreenPresenter() {}

private:
    Startup_ScreenPresenter();

    Startup_ScreenView& view;
};

#endif // STARTUP_SCREENPRESENTER_HPP
