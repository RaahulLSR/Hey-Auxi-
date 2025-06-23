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



void setup_scr_rhymepages(lv_ui *ui)
{
    //Write codes rhymepages
    ui->rhymepages = lv_obj_create(NULL);
    lv_obj_set_size(ui->rhymepages, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->rhymepages, LV_SCROLLBAR_MODE_OFF);

    //Write style for rhymepages, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rhymepages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->rhymepages, &_kidspage_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->rhymepages, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->rhymepages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rhymepages_imgbtn_1
    ui->rhymepages_imgbtn_1 = lv_imgbtn_create(ui->rhymepages);
    lv_obj_add_flag(ui->rhymepages_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->rhymepages_imgbtn_1_label = lv_label_create(ui->rhymepages_imgbtn_1);
    lv_label_set_text(ui->rhymepages_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->rhymepages_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rhymepages_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rhymepages_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->rhymepages_imgbtn_1, 321, 554);
    lv_obj_set_size(ui->rhymepages_imgbtn_1, 100, 96);

    //Write style for rhymepages_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rhymepages_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->rhymepages_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rhymepages_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rhymepages_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rhymepages_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes rhymepages_imgbtn_2
    ui->rhymepages_imgbtn_2 = lv_imgbtn_create(ui->rhymepages);
    lv_obj_add_flag(ui->rhymepages_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->rhymepages_imgbtn_2_label = lv_label_create(ui->rhymepages_imgbtn_2);
    lv_label_set_text(ui->rhymepages_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->rhymepages_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rhymepages_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rhymepages_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->rhymepages_imgbtn_2, 432, 557);
    lv_obj_set_size(ui->rhymepages_imgbtn_2, 100, 96);

    //Write style for rhymepages_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rhymepages_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->rhymepages_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rhymepages_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rhymepages_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rhymepages_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes rhymepages_imgbtn_3
    ui->rhymepages_imgbtn_3 = lv_imgbtn_create(ui->rhymepages);
    lv_obj_add_flag(ui->rhymepages_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->rhymepages_imgbtn_3_label = lv_label_create(ui->rhymepages_imgbtn_3);
    lv_label_set_text(ui->rhymepages_imgbtn_3_label, "");
    lv_label_set_long_mode(ui->rhymepages_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rhymepages_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rhymepages_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->rhymepages_imgbtn_3, 502, 440);
    lv_obj_set_size(ui->rhymepages_imgbtn_3, 138, 65);

    //Write style for rhymepages_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rhymepages_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->rhymepages_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rhymepages_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rhymepages_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rhymepages_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes rhymepages_imgbtn_4
    ui->rhymepages_imgbtn_4 = lv_imgbtn_create(ui->rhymepages);
    lv_obj_add_flag(ui->rhymepages_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->rhymepages_imgbtn_4_label = lv_label_create(ui->rhymepages_imgbtn_4);
    lv_label_set_text(ui->rhymepages_imgbtn_4_label, "");
    lv_label_set_long_mode(ui->rhymepages_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rhymepages_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rhymepages_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->rhymepages_imgbtn_4, 655, 440);
    lv_obj_set_size(ui->rhymepages_imgbtn_4, 138, 65);

    //Write style for rhymepages_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rhymepages_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->rhymepages_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rhymepages_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rhymepages_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rhymepages_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes rhymepages_imgbtn_5
    ui->rhymepages_imgbtn_5 = lv_imgbtn_create(ui->rhymepages);
    lv_obj_add_flag(ui->rhymepages_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    //lv_imgbtn_set_src(ui->rhymepages_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_296x174, NULL);
    ui->rhymepages_imgbtn_5_label = lv_label_create(ui->rhymepages_imgbtn_5);
    lv_label_set_text(ui->rhymepages_imgbtn_5_label, "");
    lv_label_set_long_mode(ui->rhymepages_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rhymepages_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rhymepages_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->rhymepages_imgbtn_5,0,0);
    lv_obj_set_size(ui->rhymepages_imgbtn_5, 296, 174);

    //Write style for rhymepages_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_5, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rhymepages_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->rhymepages_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rhymepages_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_5, lv_color_hex(0x010101), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_5, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rhymepages_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rhymepages_imgbtn_5, lv_color_hex(0x201d20), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rhymepages_imgbtn_5, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rhymepages_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->rhymepages_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->rhymepages_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of rhymepages.


    //Update current screen layout.
    lv_obj_update_layout(ui->rhymepages);

    //Init events for screen.
    events_init_rhymepages(ui);
}
