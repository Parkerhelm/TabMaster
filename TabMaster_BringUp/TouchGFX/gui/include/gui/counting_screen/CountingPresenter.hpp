#ifndef COUNTINGPRESENTER_HPP
#define COUNTINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CountingView;

class CountingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CountingPresenter(CountingView& v);

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

    virtual ~CountingPresenter() {}

private:
    CountingPresenter();

    CountingView& view;
};

#endif // COUNTINGPRESENTER_HPP
