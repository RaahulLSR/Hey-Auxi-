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



void setup_scr_Gamepage(lv_ui *ui)
{
    //Write codes Gamepage
    ui->Gamepage = lv_obj_create(NULL);
    lv_obj_set_size(ui->Gamepage, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->Gamepage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Gamepage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Gamepage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Gamepage, &_bg1_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Gamepage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Gamepage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Gamepage_label_1
    ui->Gamepage_label_1 = lv_label_create(ui->Gamepage);
    lv_label_set_text(ui->Gamepage_label_1, "Rock Paper Scissor");
    lv_label_set_long_mode(ui->Gamepage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Gamepage_label_1, 453, 22);
    lv_obj_set_size(ui->Gamepage_label_1, 381, 38);

    //Write style for Gamepage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Gamepage_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_label_1, &lv_font_Acme_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Gamepage_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Gamepage_imgbtn_1
    ui->Gamepage_imgbtn_1 = lv_imgbtn_create(ui->Gamepage);
    lv_obj_add_flag(ui->Gamepage_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Gamepage_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_299x177, NULL);
    ui->Gamepage_imgbtn_1_label = lv_label_create(ui->Gamepage_imgbtn_1);
    lv_label_set_text(ui->Gamepage_imgbtn_1_label, "Rock");
    lv_label_set_long_mode(ui->Gamepage_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Gamepage_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Gamepage_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Gamepage_imgbtn_1, 169, 99);
    lv_obj_set_size(ui->Gamepage_imgbtn_1, 299, 177);

    //Write style for Gamepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_1, &lv_font_montserratMedium_33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Gamepage_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Gamepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_1, lv_color_hex(0x110f11), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Gamepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_1, lv_color_hex(0x141414), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Gamepage_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Gamepage_imgbtn_2
    ui->Gamepage_imgbtn_2 = lv_imgbtn_create(ui->Gamepage);
    lv_obj_add_flag(ui->Gamepage_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Gamepage_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_299x177, NULL);
    ui->Gamepage_imgbtn_2_label = lv_label_create(ui->Gamepage_imgbtn_2);
    lv_label_set_text(ui->Gamepage_imgbtn_2_label, "Paper");
    lv_label_set_long_mode(ui->Gamepage_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Gamepage_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Gamepage_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Gamepage_imgbtn_2, 173, 257);
    lv_obj_set_size(ui->Gamepage_imgbtn_2, 299, 177);

    //Write style for Gamepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_2, &lv_font_montserratMedium_33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Gamepage_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Gamepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_2, lv_color_hex(0x0b0a0b), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_2, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Gamepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_2, lv_color_hex(0x151515), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_2, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Gamepage_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Gamepage_imgbtn_3
    ui->Gamepage_imgbtn_3 = lv_imgbtn_create(ui->Gamepage);
    lv_obj_add_flag(ui->Gamepage_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Gamepage_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_299x177, NULL);
    ui->Gamepage_imgbtn_3_label = lv_label_create(ui->Gamepage_imgbtn_3);
    lv_label_set_text(ui->Gamepage_imgbtn_3_label, "Scissor");
    lv_label_set_long_mode(ui->Gamepage_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Gamepage_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Gamepage_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Gamepage_imgbtn_3, 169, 435);
    lv_obj_set_size(ui->Gamepage_imgbtn_3, 299, 177);

    //Write style for Gamepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_3, &lv_font_montserratMedium_33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Gamepage_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Gamepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_3, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Gamepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_3, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_3, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Gamepage_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Gamepage_imgbtn_4
    ui->Gamepage_imgbtn_4 = lv_imgbtn_create(ui->Gamepage);
    lv_obj_add_flag(ui->Gamepage_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Gamepage_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_299x177, NULL);
    ui->Gamepage_imgbtn_4_label = lv_label_create(ui->Gamepage_imgbtn_4);
    lv_label_set_text(ui->Gamepage_imgbtn_4_label, "Confirm");
    lv_label_set_long_mode(ui->Gamepage_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Gamepage_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Gamepage_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Gamepage_imgbtn_4, 503, 538);
    lv_obj_set_size(ui->Gamepage_imgbtn_4, 299, 177);

    //Write style for Gamepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_4, &lv_font_montserratMedium_33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Gamepage_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Gamepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_4, lv_color_hex(0x060606), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Gamepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Gamepage_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Gamepage_imgbtn_5
    ui->Gamepage_imgbtn_5 = lv_imgbtn_create(ui->Gamepage);
    lv_obj_add_flag(ui->Gamepage_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Gamepage_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_299x177, NULL);
    ui->Gamepage_imgbtn_5_label = lv_label_create(ui->Gamepage_imgbtn_5);
    lv_label_set_text(ui->Gamepage_imgbtn_5_label, "Back");
    lv_label_set_long_mode(ui->Gamepage_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Gamepage_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Gamepage_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Gamepage_imgbtn_5, 977, 542);
    lv_obj_set_size(ui->Gamepage_imgbtn_5, 299, 177);

    //Write style for Gamepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_5, &lv_font_montserratMedium_33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Gamepage_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Gamepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_5, lv_color_hex(0x070707), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Gamepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Gamepage_imgbtn_5, lv_color_hex(0x1a181a), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Gamepage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Gamepage_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Gamepage_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Gamepage_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Gamepage_label_2
    ui->Gamepage_label_2 = lv_label_create(ui->Gamepage);
    lv_label_set_text(ui->Gamepage_label_2, "You choose:");
    lv_label_set_long_mode(ui->Gamepage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Gamepage_label_2, 524, 201);
    lv_obj_set_size(ui->Gamepage_label_2, 308, 68);

    //Write style for Gamepage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Gamepage_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_label_2, &lv_font_Acme_Regular_44, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Gamepage_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Gamepage_choice_2
    ui->Gamepage_choice_2 = lv_label_create(ui->Gamepage);
    lv_label_set_text(ui->Gamepage_choice_2, "");
    lv_label_set_long_mode(ui->Gamepage_choice_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Gamepage_choice_2, 875, 196);
    lv_obj_set_size(ui->Gamepage_choice_2, 233, 68);

    //Write style for Gamepage_choice_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Gamepage_choice_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_choice_2, &lv_font_Acme_Regular_44, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_choice_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Gamepage_choice_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_choice_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_choice_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Gamepage_label_3
    ui->Gamepage_label_3 = lv_label_create(ui->Gamepage);
    lv_label_set_text(ui->Gamepage_label_3, "Result:");
    lv_label_set_long_mode(ui->Gamepage_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Gamepage_label_3, 532, 320);
    lv_obj_set_size(ui->Gamepage_label_3, 308, 68);

    //Write style for Gamepage_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Gamepage_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_label_3, &lv_font_Acme_Regular_44, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Gamepage_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Gamepage_winner_2
    ui->Gamepage_winner_2 = lv_label_create(ui->Gamepage);
    lv_label_set_text(ui->Gamepage_winner_2, "");
    lv_label_set_long_mode(ui->Gamepage_winner_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Gamepage_winner_2, 834, 313);
    lv_obj_set_size(ui->Gamepage_winner_2, 308, 92);

    //Write style for Gamepage_winner_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Gamepage_winner_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Gamepage_winner_2, &lv_font_Acme_Regular_44, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Gamepage_winner_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Gamepage_winner_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Gamepage_winner_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Gamepage_winner_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Gamepage.


    //Update current screen layout.
    lv_obj_update_layout(ui->Gamepage);

    //Init events for screen.
    events_init_Gamepage(ui);
}
