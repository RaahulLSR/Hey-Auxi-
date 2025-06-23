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



void setup_scr_lockscreen(lv_ui *ui)
{
    //Write codes lockscreen
    ui->lockscreen = lv_obj_create(NULL);
    lv_obj_set_size(ui->lockscreen, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->lockscreen, LV_SCROLLBAR_MODE_OFF);

    //Write style for lockscreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->lockscreen, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->lockscreen, lv_color_hex(0x070707), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->lockscreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->lockscreen, &_iot_page_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->lockscreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->lockscreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->lockscreen, 108, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes lockscreen_img_1
    ui->lockscreen_img_1 = lv_img_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->lockscreen_img_1, &_lockscreen_alpha_466x474);
    lv_img_set_pivot(ui->lockscreen_img_1, 50,50);
    lv_img_set_angle(ui->lockscreen_img_1, 0);
    lv_obj_set_pos(ui->lockscreen_img_1, 401, 152);
    lv_obj_set_size(ui->lockscreen_img_1, 466, 474);

    //Write style for lockscreen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_img_1, 157, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->lockscreen_img_1, lv_color_hex(0xfdfdfd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->lockscreen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes lockscreen_imgbtn_1
    ui->lockscreen_imgbtn_1 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_1_label = lv_label_create(ui->lockscreen_imgbtn_1);
    lv_label_set_text(ui->lockscreen_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_1, 590, 290);
    lv_obj_set_size(ui->lockscreen_imgbtn_1, 100, 91);

    //Write style for lockscreen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_2
    ui->lockscreen_imgbtn_2 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_2_label = lv_label_create(ui->lockscreen_imgbtn_2);
    lv_label_set_text(ui->lockscreen_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_2, 458, 171);
    lv_obj_set_size(ui->lockscreen_imgbtn_2, 100, 91);

    //Write style for lockscreen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_3
    ui->lockscreen_imgbtn_3 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_3_label = lv_label_create(ui->lockscreen_imgbtn_3);
    lv_label_set_text(ui->lockscreen_imgbtn_3_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_3, 458, 290);
    lv_obj_set_size(ui->lockscreen_imgbtn_3, 100, 91);

    //Write style for lockscreen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_4
    ui->lockscreen_imgbtn_4 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_4_label = lv_label_create(ui->lockscreen_imgbtn_4);
    lv_label_set_text(ui->lockscreen_imgbtn_4_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_4, 590, 171);
    lv_obj_set_size(ui->lockscreen_imgbtn_4, 100, 91);

    //Write style for lockscreen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_5
    ui->lockscreen_imgbtn_5 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_5_label = lv_label_create(ui->lockscreen_imgbtn_5);
    lv_label_set_text(ui->lockscreen_imgbtn_5_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_5, 723, 171);
    lv_obj_set_size(ui->lockscreen_imgbtn_5, 100, 91);

    //Write style for lockscreen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_6
    ui->lockscreen_imgbtn_6 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_6_label = lv_label_create(ui->lockscreen_imgbtn_6);
    lv_label_set_text(ui->lockscreen_imgbtn_6_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_6, 723, 287);
    lv_obj_set_size(ui->lockscreen_imgbtn_6, 100, 91);

    //Write style for lockscreen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_7
    ui->lockscreen_imgbtn_7 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_7_label = lv_label_create(ui->lockscreen_imgbtn_7);
    lv_label_set_text(ui->lockscreen_imgbtn_7_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_7, 458, 405);
    lv_obj_set_size(ui->lockscreen_imgbtn_7, 100, 91);

    //Write style for lockscreen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_7, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_7, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_7, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_8
    ui->lockscreen_imgbtn_8 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_8_label = lv_label_create(ui->lockscreen_imgbtn_8);
    lv_label_set_text(ui->lockscreen_imgbtn_8_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_8, 590, 402);
    lv_obj_set_size(ui->lockscreen_imgbtn_8, 100, 91);

    //Write style for lockscreen_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_8, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_8, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_8, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_8, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_9
    ui->lockscreen_imgbtn_9 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_9_label = lv_label_create(ui->lockscreen_imgbtn_9);
    lv_label_set_text(ui->lockscreen_imgbtn_9_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_9, 723, 399);
    lv_obj_set_size(ui->lockscreen_imgbtn_9, 100, 91);

    //Write style for lockscreen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_9, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_9, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_9, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_10
    ui->lockscreen_imgbtn_10 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_10, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_10_label = lv_label_create(ui->lockscreen_imgbtn_10);
    lv_label_set_text(ui->lockscreen_imgbtn_10_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_10_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_10, 590, 515);
    lv_obj_set_size(ui->lockscreen_imgbtn_10, 100, 91);

    //Write style for lockscreen_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_10, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_10, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_10, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_10, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_10, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_10, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_10, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_label_1
    ui->lockscreen_label_1 = lv_label_create(ui->lockscreen);
    lv_label_set_text(ui->lockscreen_label_1, "----\n");
    lv_label_set_long_mode(ui->lockscreen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->lockscreen_label_1, 565, 110);
    lv_obj_set_size(ui->lockscreen_label_1, 146, 42);

    //Write style for lockscreen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->lockscreen_label_1, lv_color_hex(0xfbfbfb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_label_1, &lv_font_montserratMedium_64, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->lockscreen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes lockscreen_imgbtn_11
    ui->lockscreen_imgbtn_11 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_11, LV_OBJ_FLAG_CHECKABLE);
    ui->lockscreen_imgbtn_11_label = lv_label_create(ui->lockscreen_imgbtn_11);
    lv_label_set_text(ui->lockscreen_imgbtn_11_label, "");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_11_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_11_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_11, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_11, 895, 269);
    lv_obj_set_size(ui->lockscreen_imgbtn_11, 100, 125);

    //Write style for lockscreen_imgbtn_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_11, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_11, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_11, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_11, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_11, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_11, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_11, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_11, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_11, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_11, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_11, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_11, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes lockscreen_imgbtn_12
    ui->lockscreen_imgbtn_12 = lv_imgbtn_create(ui->lockscreen);
    lv_obj_add_flag(ui->lockscreen_imgbtn_12, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->lockscreen_imgbtn_12, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_194x91, NULL);
    ui->lockscreen_imgbtn_12_label = lv_label_create(ui->lockscreen_imgbtn_12);
    lv_label_set_text(ui->lockscreen_imgbtn_12_label, "Confirm");
    lv_label_set_long_mode(ui->lockscreen_imgbtn_12_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->lockscreen_imgbtn_12_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->lockscreen_imgbtn_12, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->lockscreen_imgbtn_12, 892, 560);
    lv_obj_set_size(ui->lockscreen_imgbtn_12, 194, 91);

    //Write style for lockscreen_imgbtn_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_12, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lockscreen_imgbtn_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->lockscreen_imgbtn_12, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for lockscreen_imgbtn_12, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_12, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for lockscreen_imgbtn_12, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->lockscreen_imgbtn_12, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->lockscreen_imgbtn_12, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for lockscreen_imgbtn_12, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->lockscreen_imgbtn_12, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->lockscreen_imgbtn_12, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of lockscreen.


    //Update current screen layout.
    lv_obj_update_layout(ui->lockscreen);

    //Init events for screen.
    events_init_lockscreen(ui);
}
