/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef COUNTINGVIEWBASE_HPP
#define COUNTINGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/counting_screen/CountingPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>

class CountingViewBase : public touchgfx::View<CountingPresenter>
{
public:
    CountingViewBase();
    virtual ~CountingViewBase();
    virtual void setupScreen();
    virtual void transitionBegins();
    virtual void handleTickEvent();

    /*
     * Virtual Action Handlers
     */
    virtual void stop_count_btn_vf()
    {
        // Override and implement this function in Counting
    }
    virtual void update_max_cnt_vf()
    {
        // Override and implement this function in Counting
    }
    virtual void update_current_count()
    {
        // Override and implement this function in Counting
    }
    virtual void continue_btn_vf()
    {
        // Override and implement this function in Counting
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image Background;
    touchgfx::TextAreaWithTwoWildcards Current_Count;
    touchgfx::Button Stop_Counting_Button;
    touchgfx::TextArea Stop_Counting;
    touchgfx::Image Logo;
    touchgfx::BoxProgress Progress_Box;
    touchgfx::Button continue_button;
    touchgfx::TextArea textArea1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t CURRENT_COUNTBUFFER1_SIZE = 4;
    touchgfx::Unicode::UnicodeChar Current_CountBuffer1[CURRENT_COUNTBUFFER1_SIZE];
    static const uint16_t CURRENT_COUNTBUFFER2_SIZE = 4;
    touchgfx::Unicode::UnicodeChar Current_CountBuffer2[CURRENT_COUNTBUFFER2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<CountingViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // COUNTINGVIEWBASE_HPP
