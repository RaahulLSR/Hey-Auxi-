/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include <events_init1.h>
#include <gui_guider1.h>
#include "lvgl.h"
#include <stdio.h>
#include "widgets_init.h"
#include "custom.h"



void setup_scr_roverpage(lv_ui *ui)
{
    //Write codes roverpage
    ui->roverpage = lv_obj_create(NULL);
    lv_obj_set_size(ui->roverpage, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->roverpage, LV_SCROLLBAR_MODE_OFF);

    //Write style for roverpage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->roverpage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->roverpage, lv_color_hex(0x0a0a0a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->roverpage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->roverpage, &_iot_page_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->roverpage, 110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->roverpage, lv_color_hex(0x001430), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->roverpage, 94, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_imgbtn_5
    ui->roverpage_imgbtn_5 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->roverpage_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_224x99, NULL);
    ui->roverpage_imgbtn_5_label = lv_label_create(ui->roverpage_imgbtn_5);
    lv_label_set_text(ui->roverpage_imgbtn_5_label, "Back");
    lv_label_set_long_mode(ui->roverpage_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_5, 1045, 612);
    lv_obj_set_size(ui->roverpage_imgbtn_5, 224, 99);

    //Write style for roverpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_5, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_5, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_5, lv_color_hex(0xfefefe), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_img_1
    ui->roverpage_img_1 = lv_img_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->roverpage_img_1, &_arrow2_alpha_100x100);
    lv_img_set_pivot(ui->roverpage_img_1, 50,50);
    lv_img_set_angle(ui->roverpage_img_1, -900);
    lv_obj_set_pos(ui->roverpage_img_1, 612, 159);
    lv_obj_set_size(ui->roverpage_img_1, 100, 100);

    //Write style for roverpage_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->roverpage_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_img_2
    ui->roverpage_img_2 = lv_img_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->roverpage_img_2, &_arrow2_alpha_100x100);
    lv_img_set_pivot(ui->roverpage_img_2, 50,50);
    lv_img_set_angle(ui->roverpage_img_2, 900);
    lv_obj_set_pos(ui->roverpage_img_2, 612, 442);
    lv_obj_set_size(ui->roverpage_img_2, 100, 100);

    //Write style for roverpage_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->roverpage_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_img_3
    ui->roverpage_img_3 = lv_img_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->roverpage_img_3, &_arrow2_alpha_100x100);
    lv_img_set_pivot(ui->roverpage_img_3, 50,50);
    lv_img_set_angle(ui->roverpage_img_3, 0);
    lv_obj_set_pos(ui->roverpage_img_3, 773, 292);
    lv_obj_set_size(ui->roverpage_img_3, 100, 100);

    //Write style for roverpage_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->roverpage_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_img_4
    ui->roverpage_img_4 = lv_img_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->roverpage_img_4, &_arrow2_alpha_100x100);
    lv_img_set_pivot(ui->roverpage_img_4, 50,50);
    lv_img_set_angle(ui->roverpage_img_4, 1800);
    lv_obj_set_pos(ui->roverpage_img_4, 429, 292);
    lv_obj_set_size(ui->roverpage_img_4, 100, 100);

    //Write style for roverpage_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->roverpage_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_img_5
    ui->roverpage_img_5 = lv_img_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->roverpage_img_5, &_stop4_alpha_102x104);
    lv_img_set_pivot(ui->roverpage_img_5, 50,50);
    lv_img_set_angle(ui->roverpage_img_5, 0);
    lv_obj_set_pos(ui->roverpage_img_5, 612, 292);
    lv_obj_set_size(ui->roverpage_img_5, 102, 104);

    //Write style for roverpage_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_img_5, 85, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->roverpage_img_5, lv_color_hex(0x006aff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->roverpage_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes roverpage_imgbtn_6
    ui->roverpage_imgbtn_6 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
    ui->roverpage_imgbtn_6_label = lv_label_create(ui->roverpage_imgbtn_6);
    lv_label_set_text(ui->roverpage_imgbtn_6_label, "");
    lv_label_set_long_mode(ui->roverpage_imgbtn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_6, 612, 164);
    lv_obj_set_size(ui->roverpage_imgbtn_6, 100, 89);

    //Write style for roverpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_imgbtn_7
    ui->roverpage_imgbtn_7 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
    ui->roverpage_imgbtn_7_label = lv_label_create(ui->roverpage_imgbtn_7);
    lv_label_set_text(ui->roverpage_imgbtn_7_label, "");
    lv_label_set_long_mode(ui->roverpage_imgbtn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_7, 773, 297);
    lv_obj_set_size(ui->roverpage_imgbtn_7, 100, 89);

    //Write style for roverpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_7, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_7, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_imgbtn_8
    ui->roverpage_imgbtn_8 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);
    ui->roverpage_imgbtn_8_label = lv_label_create(ui->roverpage_imgbtn_8);
    lv_label_set_text(ui->roverpage_imgbtn_8_label, "");
    lv_label_set_long_mode(ui->roverpage_imgbtn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_8, 429, 297);
    lv_obj_set_size(ui->roverpage_imgbtn_8, 100, 89);

    //Write style for roverpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_8, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_8, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_imgbtn_9
    ui->roverpage_imgbtn_9 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);
    ui->roverpage_imgbtn_9_label = lv_label_create(ui->roverpage_imgbtn_9);
    lv_label_set_text(ui->roverpage_imgbtn_9_label, "");
    lv_label_set_long_mode(ui->roverpage_imgbtn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_9, 612, 450);
    lv_obj_set_size(ui->roverpage_imgbtn_9, 100, 89);

    //Write style for roverpage_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_9, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_9, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_9, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_imgbtn_10
    ui->roverpage_imgbtn_10 = lv_imgbtn_create(ui->roverpage);
    lv_obj_add_flag(ui->roverpage_imgbtn_10, LV_OBJ_FLAG_CHECKABLE);
    ui->roverpage_imgbtn_10_label = lv_label_create(ui->roverpage_imgbtn_10);
    lv_label_set_text(ui->roverpage_imgbtn_10_label, "");
    lv_label_set_long_mode(ui->roverpage_imgbtn_10_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->roverpage_imgbtn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->roverpage_imgbtn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->roverpage_imgbtn_10, 612, 301);
    lv_obj_set_size(ui->roverpage_imgbtn_10, 100, 89);

    //Write style for roverpage_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_imgbtn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->roverpage_imgbtn_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for roverpage_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_10, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for roverpage_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->roverpage_imgbtn_10, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->roverpage_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for roverpage_imgbtn_10, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->roverpage_imgbtn_10, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->roverpage_imgbtn_10, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes roverpage_label_1
    ui->roverpage_label_1 = lv_label_create(ui->roverpage);
    lv_label_set_text(ui->roverpage_label_1, "Rover Control");
    lv_label_set_long_mode(ui->roverpage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->roverpage_label_1, 583, 13);
    lv_obj_set_size(ui->roverpage_label_1, 159, 92);

    //Write style for roverpage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->roverpage_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->roverpage_label_1, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->roverpage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->roverpage_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->roverpage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->roverpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of roverpage.


    //Update current screen layout.
    lv_obj_update_layout(ui->roverpage);

    //Init events for screen.
    events_init_roverpage(ui);
}
