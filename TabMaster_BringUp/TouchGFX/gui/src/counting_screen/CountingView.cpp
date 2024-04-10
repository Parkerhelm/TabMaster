#include <gui/counting_screen/CountingView.hpp>
#include <stdlib.h>

extern "C"{
#include "btn_callbacks.h"
}

CountingView::CountingView()
{

}

void CountingView::setupScreen()
{
    CountingViewBase::setupScreen();
}

void CountingView::tearDownScreen()
{
    CountingViewBase::tearDownScreen();
}

void CountingView::update_max_cnt_vf(){
    Unicode::snprintf(Current_CountBuffer2, CURRENT_COUNTBUFFER2_SIZE, "%d", to_count);
    Current_Count.resizeToCurrentText();
    Background.invalidateContent();
    Current_Count.invalidate();
}

void CountingView::stop_count_btn_vf(){
	to_count = 0;
	reset_btn_callback();
}

















