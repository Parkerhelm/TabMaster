#ifndef COUNTING_SCREENPRESENTER_HPP
#define COUNTING_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Counting_ScreenView;

class Counting_ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Counting_ScreenPresenter(Counting_ScreenView& v);

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

    virtual ~Counting_ScreenPresenter() {}

private:
    Counting_ScreenPresenter();

    Counting_ScreenView& view;
};

#endif // COUNTING_SCREENPRESENTER_HPP
