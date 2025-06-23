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

#include "custom.h"



void setup_scr_Homepage(lv_ui *ui)
{
    //Write codes Homepage
    ui->Homepage = lv_obj_create(NULL);
    lv_obj_set_size(ui->Homepage, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->Homepage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Homepage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Homepage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Homepage, &_hp_bg21_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Homepage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Homepage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Homepage_imgbtn_1
    ui->Homepage_imgbtn_1 = lv_imgbtn_create(ui->Homepage);
    lv_obj_add_flag(ui->Homepage_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->Homepage_imgbtn_1_label = lv_label_create(ui->Homepage_imgbtn_1);
    lv_label_set_text(ui->Homepage_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->Homepage_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Homepage_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Homepage_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Homepage_imgbtn_1, 293, 50);
    lv_obj_set_size(ui->Homepage_imgbtn_1, 192, 184);

    //Write style for Homepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Homepage_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Homepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Homepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Homepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Homepage_imgbtn_2
    ui->Homepage_imgbtn_2 = lv_imgbtn_create(ui->Homepage);
    lv_obj_add_flag(ui->Homepage_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->Homepage_imgbtn_2_label = lv_label_create(ui->Homepage_imgbtn_2);
    lv_label_set_text(ui->Homepage_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->Homepage_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Homepage_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Homepage_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Homepage_imgbtn_2, 783, 60);
    lv_obj_set_size(ui->Homepage_imgbtn_2, 192, 184);

    //Write style for Homepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Homepage_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Homepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Homepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Homepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Homepage_imgbtn_3
    ui->Homepage_imgbtn_3 = lv_imgbtn_create(ui->Homepage);
    lv_obj_add_flag(ui->Homepage_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->Homepage_imgbtn_3_label = lv_label_create(ui->Homepage_imgbtn_3);
    lv_label_set_text(ui->Homepage_imgbtn_3_label, "");
    lv_label_set_long_mode(ui->Homepage_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Homepage_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Homepage_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Homepage_imgbtn_3, 300, 442);
    lv_obj_set_size(ui->Homepage_imgbtn_3, 192, 184);

    //Write style for Homepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Homepage_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Homepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Homepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Homepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Homepage_imgbtn_4
    ui->Homepage_imgbtn_4 = lv_imgbtn_create(ui->Homepage);
    lv_obj_add_flag(ui->Homepage_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->Homepage_imgbtn_4_label = lv_label_create(ui->Homepage_imgbtn_4);
    lv_label_set_text(ui->Homepage_imgbtn_4_label, "");
    lv_label_set_long_mode(ui->Homepage_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Homepage_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Homepage_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Homepage_imgbtn_4, 778, 442);
    lv_obj_set_size(ui->Homepage_imgbtn_4, 192, 184);

    //Write style for Homepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Homepage_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Homepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Homepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Homepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Homepage_imgbtn_5
    ui->Homepage_imgbtn_5 = lv_imgbtn_create(ui->Homepage);
    lv_obj_add_flag(ui->Homepage_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    ui->Homepage_imgbtn_5_label = lv_label_create(ui->Homepage_imgbtn_5);
    lv_label_set_text(ui->Homepage_imgbtn_5_label, "");
    lv_label_set_long_mode(ui->Homepage_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Homepage_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Homepage_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Homepage_imgbtn_5, 533, 220);
    lv_obj_set_size(ui->Homepage_imgbtn_5, 192, 184);

    //Write style for Homepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Homepage_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Homepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Homepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Homepage_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Homepage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Homepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Homepage_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Homepage_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Homepage_digital_clock_1
//    static bool Homepage_digital_clock_1_timer_enabled = false;
//    ui->Homepage_digital_clock_1 = lv_dclock_create(ui->Homepage, "11:25:50 AM");
//    if (!Homepage_digital_clock_1_timer_enabled) {
//        lv_timer_create(Homepage_digital_clock_1_timer, 1000, NULL);
//        Homepage_digital_clock_1_timer_enabled = true;
//    }
//    lv_obj_set_pos(ui->Homepage_digital_clock_1, 70, 10);
//    lv_obj_set_size(ui->Homepage_digital_clock_1, 160, 40);
//
//    //Write style for Homepage_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
//    lv_obj_set_style_radius(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_color(ui->Homepage_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_font(ui->Homepage_digital_clock_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_opa(ui->Homepage_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_letter_space(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_align(ui->Homepage_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_bg_opa(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_pad_top(ui->Homepage_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_pad_right(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_pad_bottom(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_pad_left(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_shadow_width(ui->Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Homepage_label_1
    ui->Homepage_label_1 = lv_label_create(ui->Homepage);
    lv_label_set_text(ui->Homepage_label_1, "ble");
    lv_label_set_long_mode(ui->Homepage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Homepage_label_1, 21, 5);
    lv_obj_set_size(ui->Homepage_label_1, 43, 32);

    //Write style for Homepage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Homepage_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Homepage_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Homepage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Homepage_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Homepage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Homepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Homepage.


    ui->home_page_imgbtn_6 = lv_imgbtn_create(ui->Homepage);
        lv_obj_add_flag(ui->home_page_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
        ui->home_page_imgbtn_6_label = lv_label_create(ui->home_page_imgbtn_6);
        lv_label_set_text(ui->home_page_imgbtn_6_label, "");
        lv_label_set_long_mode(ui->home_page_imgbtn_6_label, LV_LABEL_LONG_WRAP);
        lv_obj_align(ui->home_page_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(ui->home_page_imgbtn_6, 0, LV_STATE_DEFAULT);
        lv_obj_set_pos(ui->home_page_imgbtn_6, 0, 0);
        lv_obj_set_size(ui->home_page_imgbtn_6, 173, 179);

        //Write style for home_page_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
        lv_obj_set_style_text_color(ui->home_page_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui->home_page_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui->home_page_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_clip_corner(ui->home_page_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        //Write style for home_page_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
        lv_obj_set_style_img_recolor_opa(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_img_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_color(ui->home_page_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_font(ui->home_page_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_shadow_width(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

        //Write style for home_page_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
        lv_obj_set_style_img_recolor_opa(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_img_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_color(ui->home_page_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_font(ui->home_page_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_shadow_width(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

        //Write style for home_page_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
        lv_obj_set_style_img_recolor_opa(ui->home_page_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
        lv_obj_set_style_img_opa(ui->home_page_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);



    //Update current screen layout.
    lv_obj_update_layout(ui->Homepage);

    //Init events for screen.
    events_init_Homepage(ui);
}
