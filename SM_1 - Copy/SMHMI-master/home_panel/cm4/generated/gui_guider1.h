/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Homepage;
	bool Homepage_del;
	lv_obj_t *Homepage_imgbtn_1;
	lv_obj_t *Homepage_imgbtn_1_label;
	lv_obj_t *Homepage_imgbtn_2;
	lv_obj_t *Homepage_imgbtn_2_label;
	lv_obj_t *Homepage_imgbtn_3;
	lv_obj_t *Homepage_imgbtn_3_label;
	lv_obj_t *Homepage_imgbtn_4;
	lv_obj_t *Homepage_imgbtn_4_label;
	lv_obj_t *Homepage_imgbtn_5;
	lv_obj_t *Homepage_imgbtn_5_label;
	lv_obj_t *home_page_imgbtn_6;
	lv_obj_t *home_page_imgbtn_6_label;
	lv_obj_t *Homepage_digital_clock_1;
	lv_obj_t *Homepage_label_1;
	lv_obj_t *Gamepage;
	bool Gamepage_del;
	lv_obj_t *Gamepage_label_1;
	lv_obj_t *Gamepage_imgbtn_1;
	lv_obj_t *Gamepage_imgbtn_1_label;
	lv_obj_t *Gamepage_imgbtn_2;
	lv_obj_t *Gamepage_imgbtn_2_label;
	lv_obj_t *Gamepage_imgbtn_3;
	lv_obj_t *Gamepage_imgbtn_3_label;
	lv_obj_t *Gamepage_imgbtn_4;
	lv_obj_t *Gamepage_imgbtn_4_label;
	lv_obj_t *Gamepage_imgbtn_5;
	lv_obj_t *Gamepage_imgbtn_5_label;
	lv_obj_t *Gamepage_label_2;
	lv_obj_t *Gamepage_choice_2;
	lv_obj_t *Gamepage_label_3;
	lv_obj_t *Gamepage_winner_2;
	lv_obj_t *kids_page;
	bool kids_page_del;
	lv_obj_t *kids_page_imgbtn_1;
	lv_obj_t *kids_page_imgbtn_1_label;
	lv_obj_t *kids_page_imgbtn_2;
	lv_obj_t *kids_page_imgbtn_2_label;
	lv_obj_t *kids_page_imgbtn_3;
	lv_obj_t *kids_page_imgbtn_3_label;
	lv_obj_t *kids_page_imgbtn_4;
	lv_obj_t *kids_page_imgbtn_4_label;
	lv_obj_t *kids_page_label_1;
	lv_obj_t *rhymepages;
	bool rhymepages_del;
	lv_obj_t *rhymepages_imgbtn_1;
	lv_obj_t *rhymepages_imgbtn_1_label;
	lv_obj_t *rhymepages_imgbtn_2;
	lv_obj_t *rhymepages_imgbtn_2_label;
	lv_obj_t *rhymepages_imgbtn_3;
	lv_obj_t *rhymepages_imgbtn_3_label;
	lv_obj_t *rhymepages_imgbtn_4;
	lv_obj_t *rhymepages_imgbtn_4_label;
	lv_obj_t *rhymepages_imgbtn_5;
	lv_obj_t *rhymepages_imgbtn_5_label;
	lv_obj_t *Healthpage;
	bool Healthpage_del;
	lv_obj_t *Healthpage_imgbtn_1;
	lv_obj_t *Healthpage_imgbtn_1_label;
	lv_obj_t *Healthpage_imgbtn_2;
	lv_obj_t *Healthpage_imgbtn_2_label;
	lv_obj_t *Healthpage_img_1;
	lv_obj_t *Healthpage_label_1;
	lv_obj_t *Healthpage_label_2;
	lv_obj_t *Healthpage_label_5;
	lv_obj_t *Healthpage_label_6;
	lv_obj_t *Healthpage_label_7;
	lv_obj_t *Healthpage_label_8;
	lv_obj_t *Healthpage_imgbtn_4;
	lv_obj_t *Healthpage_imgbtn_4_label;
	lv_obj_t *Healthpage_tabview_1;
	lv_obj_t *Healthpage_tabview_1_tab_1;
	lv_obj_t *Healthpage_tabview_1_tab_2;
	lv_obj_t *Healthpage_tabview_1_tab_3;
	lv_obj_t *Healthpage_btn_1;
	lv_obj_t *Healthpage_btn_1_label;
	lv_obj_t *Healthpage_btn_2;
	lv_obj_t *Healthpage_btn_2_label;
	lv_obj_t *Healthpage_imgbtn_5;
	lv_obj_t *Healthpage_imgbtn_5_label;
	lv_obj_t *iotpage;
	bool iotpage_del;
	lv_obj_t *iotpage_imgbtn_1;
	lv_obj_t *iotpage_imgbtn_1_label;
	lv_obj_t *iotpage_imgbtn_2;
	lv_obj_t *iotpage_imgbtn_2_label;
	lv_obj_t *iotpage_imgbtn_3;
	lv_obj_t *iotpage_imgbtn_3_label;
	lv_obj_t *iotpage_label_1;
	lv_obj_t *iotpage_label_2;
	lv_obj_t *iotpage_label_3;
	lv_obj_t *iotpage_label_4;
	lv_obj_t *iotpage_imgbtn_4;
	lv_obj_t *iotpage_imgbtn_4_label;
	lv_obj_t *iotpage_imgbtn_5;
	lv_obj_t *iotpage_imgbtn_5_label;
	lv_obj_t *iotpage_label_8;
	lv_obj_t *iotpage_label_7;
	lv_obj_t *iotpage_label_6;
	lv_obj_t *iotpage_label_5;
	lv_obj_t *iotpage_imgbtn_6;
	lv_obj_t *iotpage_imgbtn_6_label;
	lv_obj_t *iotpage_label_10;
	lv_obj_t *iotpage_label_11;
	lv_obj_t *iotpage_label_12;
	lv_obj_t *iotpage_imgbtn_7;
	lv_obj_t *iotpage_imgbtn_7_label;
	lv_obj_t *iotpage_imgbtn_8;
	lv_obj_t *iotpage_imgbtn_8_label;
	lv_obj_t *roverpage;
	bool roverpage_del;
	lv_obj_t *roverpage_imgbtn_5;
	lv_obj_t *roverpage_imgbtn_5_label;
	lv_obj_t *roverpage_img_1;
	lv_obj_t *roverpage_img_2;
	lv_obj_t *roverpage_img_3;
	lv_obj_t *roverpage_img_4;
	lv_obj_t *roverpage_img_5;
	lv_obj_t *roverpage_imgbtn_6;
	lv_obj_t *roverpage_imgbtn_6_label;
	lv_obj_t *roverpage_imgbtn_7;
	lv_obj_t *roverpage_imgbtn_7_label;
	lv_obj_t *roverpage_imgbtn_8;
	lv_obj_t *roverpage_imgbtn_8_label;
	lv_obj_t *roverpage_imgbtn_9;
	lv_obj_t *roverpage_imgbtn_9_label;
	lv_obj_t *roverpage_imgbtn_10;
	lv_obj_t *roverpage_imgbtn_10_label;
	lv_obj_t *roverpage_label_1;
	lv_obj_t *blackscreen;
	bool blackscreen_del;
	lv_obj_t *blackscreen_imgbtn_1;
	lv_obj_t *blackscreen_imgbtn_1_label;
	lv_obj_t *lockscreen;
	bool lockscreen_del;
	lv_obj_t *lockscreen_img_1;
	lv_obj_t *lockscreen_imgbtn_1;
	lv_obj_t *lockscreen_imgbtn_1_label;
	lv_obj_t *lockscreen_imgbtn_2;
	lv_obj_t *lockscreen_imgbtn_2_label;
	lv_obj_t *lockscreen_imgbtn_3;
	lv_obj_t *lockscreen_imgbtn_3_label;
	lv_obj_t *lockscreen_imgbtn_4;
	lv_obj_t *lockscreen_imgbtn_4_label;
	lv_obj_t *lockscreen_imgbtn_5;
	lv_obj_t *lockscreen_imgbtn_5_label;
	lv_obj_t *lockscreen_imgbtn_6;
	lv_obj_t *lockscreen_imgbtn_6_label;
	lv_obj_t *lockscreen_imgbtn_7;
	lv_obj_t *lockscreen_imgbtn_7_label;
	lv_obj_t *lockscreen_imgbtn_8;
	lv_obj_t *lockscreen_imgbtn_8_label;
	lv_obj_t *lockscreen_imgbtn_9;
	lv_obj_t *lockscreen_imgbtn_9_label;
	lv_obj_t *lockscreen_imgbtn_10;
	lv_obj_t *lockscreen_imgbtn_10_label;
	lv_obj_t *lockscreen_label_1;
	lv_obj_t *lockscreen_imgbtn_11;
	lv_obj_t *lockscreen_imgbtn_11_label;
	lv_obj_t *lockscreen_imgbtn_12;
	lv_obj_t *lockscreen_imgbtn_12_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui1(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_Homepage(lv_ui *ui);
void setup_scr_Gamepage(lv_ui *ui);
void setup_scr_kids_page(lv_ui *ui);
void setup_scr_rhymepages(lv_ui *ui);
void setup_scr_Healthpage(lv_ui *ui);
void setup_scr_iotpage(lv_ui *ui);
void setup_scr_roverpage(lv_ui *ui);
void setup_scr_blackscreen(lv_ui *ui);
void setup_scr_lockscreen(lv_ui *ui);

LV_IMG_DECLARE(_hp_bg21_1280x720);

LV_IMG_DECLARE(_bg1_1280x720);
LV_IMG_DECLARE(_btn4_alpha_299x177);
LV_IMG_DECLARE(_btn4_alpha_299x177);
LV_IMG_DECLARE(_btn4_alpha_299x177);
LV_IMG_DECLARE(_btn4_alpha_299x177);
LV_IMG_DECLARE(_btn4_alpha_299x177);

LV_IMG_DECLARE(_bg1_1280x720);
LV_IMG_DECLARE(_btn4_alpha_469x278);
LV_IMG_DECLARE(_btn4_alpha_469x278);
LV_IMG_DECLARE(_btn4_alpha_469x278);

LV_IMG_DECLARE(_kidspage_1280x720);
LV_IMG_DECLARE(_btn4_alpha_296x174);

LV_IMG_DECLARE(_iot_page_1280x720);
LV_IMG_DECLARE(_img_heart_alpha_100x65);
LV_IMG_DECLARE(_img_ekg_alpha_100x65);
LV_IMG_DECLARE(_icn_water_alpha_100x100);
LV_IMG_DECLARE(_btn1_alpha_224x99);
LV_IMG_DECLARE(_btn1_alpha_224x99);

LV_IMG_DECLARE(_iot_page_1280x720);
LV_IMG_DECLARE(_ylight_alpha_254x211);
LV_IMG_DECLARE(_blightt_alpha_254x211);
LV_IMG_DECLARE(_glightt_alpha_254x211);
LV_IMG_DECLARE(_btn1_alpha_224x99);
LV_IMG_DECLARE(_thermometer_alpha_100x65);
LV_IMG_DECLARE(_thermometer_alpha_81x65);
LV_IMG_DECLARE(_airquality_alpha_116x88);
LV_IMG_DECLARE(_btn1_alpha_224x99);

LV_IMG_DECLARE(_iot_page_1280x720);
LV_IMG_DECLARE(_btn1_alpha_224x99);
LV_IMG_DECLARE(_arrow2_alpha_100x100);
LV_IMG_DECLARE(_arrow2_alpha_100x100);
LV_IMG_DECLARE(_arrow2_alpha_100x100);
LV_IMG_DECLARE(_arrow2_alpha_100x100);
LV_IMG_DECLARE(_stop4_alpha_102x104);

LV_IMG_DECLARE(_iot_page_1280x720);
LV_IMG_DECLARE(_lockscreen_alpha_466x474);
LV_IMG_DECLARE(_btn1_alpha_194x91);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_26)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_Acme_Regular_35)
LV_FONT_DECLARE(lv_font_montserratMedium_33)
LV_FONT_DECLARE(lv_font_montserratMedium_27)
LV_FONT_DECLARE(lv_font_Acme_Regular_44)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_28)
LV_FONT_DECLARE(lv_font_Acme_Regular_64)
LV_FONT_DECLARE(lv_font_Acme_Regular_37)
LV_FONT_DECLARE(lv_font_Acme_Regular_30)
LV_FONT_DECLARE(lv_font_Acme_Regular_16)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_18)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_37)
LV_FONT_DECLARE(lv_font_montserratMedium_64)


#ifdef __cplusplus
}
#endif
#endif
