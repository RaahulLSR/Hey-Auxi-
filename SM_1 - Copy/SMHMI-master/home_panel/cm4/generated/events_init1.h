/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT1_H_
#define EVENTS_INIT1_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gui_guider1.h>

void events_init1(lv_ui *ui);

void events_init_Homepage(lv_ui *ui);
void events_init_Gamepage(lv_ui *ui);
void events_init_kids_page(lv_ui *ui);
void events_init_rhymepages(lv_ui *ui);
void events_init_Healthpage(lv_ui *ui);
void events_init_iotpage(lv_ui *ui);
void events_init_roverpage(lv_ui *ui);
void events_init_blackscreen(lv_ui *ui);
void events_init_lockscreen(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
