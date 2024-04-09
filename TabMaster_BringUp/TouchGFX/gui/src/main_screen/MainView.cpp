#include <gui/main_screen/MainView.hpp>
#include <stdlib.h>
#include <gui/counting_screen/CountingView.hpp>

extern "C"{
#include "btn_callbacks.h"
}


MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::p50_btn_vf(){
	p50_btn_callback();
    Unicode::snprintf(CountBuffer, COUNT_SIZE, "%d", to_count);
    Count.resizeToCurrentText();
    Background.invalidateContent();
    Count.invalidate();
}

void MainView::p10_btn_vf(){
	p10_btn_callback();
    Unicode::snprintf(CountBuffer, COUNT_SIZE, "%d", to_count);
    Count.resizeToCurrentText();
    Background.invalidateContent();
    Count.invalidate();
}

void MainView::p1_btn_vf(){
	p1_btn_callback();
    Unicode::snprintf(CountBuffer, COUNT_SIZE, "%d", to_count);
    Count.resizeToCurrentText();
    Background.invalidateContent();
    Count.invalidate();
}

void MainView::reset_btn_vf(){
	reset_btn_callback();
    Unicode::snprintf(CountBuffer, COUNT_SIZE, "%d", to_count);
    Count.resizeToCurrentText();
    Background.invalidateContent();
    Count.invalidate();
}

void MainView::start_btn_vf(){
	start_btn_callback();
}


























