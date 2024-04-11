/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STARTUPVIEWBASE_HPP
#define STARTUPVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/startup_screen/StartupPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class StartupViewBase : public touchgfx::View<StartupPresenter>
{
public:
    StartupViewBase();
    virtual ~StartupViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image Background;
    touchgfx::Image Logo;
    touchgfx::Button Touch_to_Continue_Button;
    touchgfx::TextArea Touch_to_Continue;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<StartupViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STARTUPVIEWBASE_HPP