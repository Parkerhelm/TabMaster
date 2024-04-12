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

    Progress_Box.setRange(0, to_count); //set the range of the progress box to to_count
    Progress_Box.setValue(0);
}

void CountingView::stop_count_btn_vf(){
	to_count = 0;
	reset_btn_callback();
}

void CountingView::update_current_count(){

		Progress_Box.setValue(prog_count);
	    Unicode::snprintf(Current_CountBuffer1, CURRENT_COUNTBUFFER1_SIZE, "%d", prog_count);
	    Current_Count.resizeToCurrentText();
	    Background.invalidateContent();
	    Current_Count.invalidate();
}

void CountingView::continue_btn_vf(){
	//needs to continue count after it is stopped at 50
	if( prog_count < to_count ){
		continue_btn_callback();
	}

}
















