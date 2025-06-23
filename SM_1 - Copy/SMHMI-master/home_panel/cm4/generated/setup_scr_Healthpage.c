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



void setup_scr_Healthpage(lv_ui *ui)
{
    //Write codes Healthpage
    ui->Healthpage = lv_obj_create(NULL);
    lv_obj_set_size(ui->Healthpage, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->Healthpage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Healthpage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Healthpage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Healthpage, lv_color_hex(0x0a0a0a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Healthpage, &_iot_page_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Healthpage, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->Healthpage, lv_color_hex(0x001430), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Healthpage, 98, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_imgbtn_1
    ui->Healthpage_imgbtn_1 = lv_imgbtn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Healthpage_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_img_heart_alpha_100x65, NULL);
    ui->Healthpage_imgbtn_1_label = lv_label_create(ui->Healthpage_imgbtn_1);
    lv_label_set_text(ui->Healthpage_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->Healthpage_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Healthpage_imgbtn_1, 139, 115);
    lv_obj_set_size(ui->Healthpage_imgbtn_1, 100, 65);

    //Write style for Healthpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Healthpage_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Healthpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Healthpage_imgbtn_2
    ui->Healthpage_imgbtn_2 = lv_imgbtn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Healthpage_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_img_ekg_alpha_100x65, NULL);
    ui->Healthpage_imgbtn_2_label = lv_label_create(ui->Healthpage_imgbtn_2);
    lv_label_set_text(ui->Healthpage_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->Healthpage_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Healthpage_imgbtn_2, 1049, 121);
    lv_obj_set_size(ui->Healthpage_imgbtn_2, 100, 65);

    //Write style for Healthpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Healthpage_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Healthpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Healthpage_img_1
    ui->Healthpage_img_1 = lv_img_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Healthpage_img_1, &_icn_water_alpha_100x100);
    lv_img_set_pivot(ui->Healthpage_img_1, 50,50);
    lv_img_set_angle(ui->Healthpage_img_1, 0);
    lv_obj_set_pos(ui->Healthpage_img_1, 601, 87);
    lv_obj_set_size(ui->Healthpage_img_1, 100, 100);

    //Write style for Healthpage_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_img_1, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Healthpage_img_1, lv_color_hex(0x38a1cc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Healthpage_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Healthpage_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_1
    ui->Healthpage_label_1 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_1, "Heart Rate");
    lv_label_set_long_mode(ui->Healthpage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_1, 107, 260);
    lv_obj_set_size(ui->Healthpage_label_1, 188, 51);

    //Write style for Healthpage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_1, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_2
    ui->Healthpage_label_2 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_2, "--");
    lv_label_set_long_mode(ui->Healthpage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_2, 134, 209);
    lv_obj_set_size(ui->Healthpage_label_2, 116, 51);

    //Write style for Healthpage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_2, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_5
    ui->Healthpage_label_5 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_5, "--");
    lv_label_set_long_mode(ui->Healthpage_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_5, 584, 203);
    lv_obj_set_size(ui->Healthpage_label_5, 128, 51);

    //Write style for Healthpage_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_5, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_6
    ui->Healthpage_label_6 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_6, "--");
    lv_label_set_long_mode(ui->Healthpage_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_6, 1045, 214);
    lv_obj_set_size(ui->Healthpage_label_6, 104, 51);

    //Write style for Healthpage_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_6, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_7
    ui->Healthpage_label_7 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_7, "SpO2");
    lv_label_set_long_mode(ui->Healthpage_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_7, 1014, 249);
    lv_obj_set_size(ui->Healthpage_label_7, 178, 51);

    //Write style for Healthpage_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_7, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_label_8
    ui->Healthpage_label_8 = lv_label_create(ui->Healthpage);
    lv_label_set_text(ui->Healthpage_label_8, "OEI");
    lv_label_set_long_mode(ui->Healthpage_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Healthpage_label_8, 544, 270);
    lv_obj_set_size(ui->Healthpage_label_8, 220, 51);

    //Write style for Healthpage_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_label_8, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Healthpage_imgbtn_4
    ui->Healthpage_imgbtn_4 = lv_imgbtn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Healthpage_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_224x99, NULL);
    ui->Healthpage_imgbtn_4_label = lv_label_create(ui->Healthpage_imgbtn_4);
    lv_label_set_text(ui->Healthpage_imgbtn_4_label, "Back");
    lv_label_set_long_mode(ui->Healthpage_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Healthpage_imgbtn_4, 704, 619);
    lv_obj_set_size(ui->Healthpage_imgbtn_4, 224, 99);

    //Write style for Healthpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_4, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_4, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Healthpage_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_4, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Healthpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Healthpage_tabview_1
    ui->Healthpage_tabview_1 = lv_tabview_create(ui->Healthpage, LV_DIR_TOP, 50);
    lv_obj_set_pos(ui->Healthpage_tabview_1, 166, 332);
    lv_obj_set_size(ui->Healthpage_tabview_1, 968, 265);
    lv_obj_set_scrollbar_mode(ui->Healthpage_tabview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for Healthpage_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Healthpage_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_tabview_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_tabview_1, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Healthpage_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Healthpage_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Healthpage_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Healthpage_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Healthpage_tabview_1, lv_color_hex(0x737373), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Healthpage_tabview_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_tabview_1, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Healthpage_tabview_1_extra_btnm_main_default
    static lv_style_t style_Healthpage_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_Healthpage_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_Healthpage_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_Healthpage_tabview_1_extra_btnm_main_default, lv_color_hex(0x9ce8ff));
    lv_style_set_bg_grad_dir(&style_Healthpage_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_Healthpage_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_Healthpage_tabview_1_extra_btnm_main_default, 8);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->Healthpage_tabview_1), &style_Healthpage_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Healthpage_tabview_1_extra_btnm_items_default
    static lv_style_t style_Healthpage_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_Healthpage_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_Healthpage_tabview_1_extra_btnm_items_default, lv_color_hex(0x291f1f));
    lv_style_set_text_font(&style_Healthpage_tabview_1_extra_btnm_items_default, &lv_font_Acme_Regular_16);
    lv_style_set_text_opa(&style_Healthpage_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->Healthpage_tabview_1), &style_Healthpage_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_Healthpage_tabview_1_extra_btnm_items_checked
    static lv_style_t style_Healthpage_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_Healthpage_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_Healthpage_tabview_1_extra_btnm_items_checked, lv_color_hex(0x007185));
    lv_style_set_text_font(&style_Healthpage_tabview_1_extra_btnm_items_checked, &lv_font_Alatsi_Regular_18);
    lv_style_set_text_opa(&style_Healthpage_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_Healthpage_tabview_1_extra_btnm_items_checked, 4);
    lv_style_set_border_opa(&style_Healthpage_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_color(&style_Healthpage_tabview_1_extra_btnm_items_checked, lv_color_hex(0x007185));
    lv_style_set_border_side(&style_Healthpage_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_RIGHT);
    lv_style_set_radius(&style_Healthpage_tabview_1_extra_btnm_items_checked, 4);
    lv_style_set_bg_opa(&style_Healthpage_tabview_1_extra_btnm_items_checked, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->Healthpage_tabview_1), &style_Healthpage_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes morning
    ui->Healthpage_tabview_1_tab_1 = lv_tabview_add_tab(ui->Healthpage_tabview_1,"morning");
    lv_obj_t * Healthpage_tabview_1_tab_1_label = lv_label_create(ui->Healthpage_tabview_1_tab_1);
    lv_label_set_text(Healthpage_tabview_1_tab_1_label, "ACODEP                 2                    Before food\n\nHimox                     1                     Before food");

    //Write codes noon
    ui->Healthpage_tabview_1_tab_2 = lv_tabview_add_tab(ui->Healthpage_tabview_1,"noon");
    lv_obj_t * Healthpage_tabview_1_tab_2_label = lv_label_create(ui->Healthpage_tabview_1_tab_2);
    lv_label_set_text(Healthpage_tabview_1_tab_2_label, "Diared -MP2                    1        Before food\n\nVoglibose                         2         After food");

    //Write codes night
    ui->Healthpage_tabview_1_tab_3 = lv_tabview_add_tab(ui->Healthpage_tabview_1,"night ");
    lv_obj_t * Healthpage_tabview_1_tab_3_label = lv_label_create(ui->Healthpage_tabview_1_tab_3);
    lv_label_set_text(Healthpage_tabview_1_tab_3_label, "Amlodipine             1               After food   \n\nGluconorm              2                After food");

    //Write codes Healthpage_btn_1
    ui->Healthpage_btn_1 = lv_btn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->Healthpage_btn_1_label = lv_label_create(ui->Healthpage_btn_1);
    lv_label_set_text(ui->Healthpage_btn_1_label, "");
    lv_label_set_long_mode(ui->Healthpage_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Healthpage_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Healthpage_btn_1, 882, 396);
    lv_obj_set_size(ui->Healthpage_btn_1, 50, 50);

    //Write style for Healthpage_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_1, lv_color_hex(0x21961b), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->Healthpage_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_btn_1, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_1, lv_color_hex(0x21961b), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->Healthpage_btn_1, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_btn_1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes Healthpage_btn_2
    ui->Healthpage_btn_2 = lv_btn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_btn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->Healthpage_btn_2_label = lv_label_create(ui->Healthpage_btn_2);
    lv_label_set_text(ui->Healthpage_btn_2_label, "");
    lv_label_set_long_mode(ui->Healthpage_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Healthpage_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Healthpage_btn_2, 882, 472);
    lv_obj_set_size(ui->Healthpage_btn_2, 50, 50);

    //Write style for Healthpage_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_2, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Healthpage_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_2, lv_color_hex(0x21961b), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->Healthpage_btn_2, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_btn_2, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_btn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Healthpage_btn_2, lv_color_hex(0x21961b), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Healthpage_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->Healthpage_btn_2, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_btn_2, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes Healthpage_imgbtn_5
    ui->Healthpage_imgbtn_5 = lv_imgbtn_create(ui->Healthpage);
    lv_obj_add_flag(ui->Healthpage_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Healthpage_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_224x99, NULL);
    ui->Healthpage_imgbtn_5_label = lv_label_create(ui->Healthpage_imgbtn_5);
    lv_label_set_text(ui->Healthpage_imgbtn_5_label, "Refresh");
    lv_label_set_long_mode(ui->Healthpage_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Healthpage_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Healthpage_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Healthpage_imgbtn_5, 463, 619);
    lv_obj_set_size(ui->Healthpage_imgbtn_5, 224, 99);

    //Write style for Healthpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_5, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_5, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Healthpage_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Healthpage_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Healthpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_5, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Healthpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Healthpage_imgbtn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Healthpage_imgbtn_5, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Healthpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Healthpage_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Healthpage_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of Healthpage.


    //Update current screen layout.
    lv_obj_update_layout(ui->Healthpage);

    //Init events for screen.
    events_init_Healthpage(ui);
}
