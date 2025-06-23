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



void setup_scr_iotpage(lv_ui *ui)
{
    //Write codes iotpage
    ui->iotpage = lv_obj_create(NULL);
    lv_obj_set_size(ui->iotpage, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->iotpage, LV_SCROLLBAR_MODE_OFF);

    //Write style for iotpage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->iotpage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->iotpage, lv_color_hex(0x0a0a0a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->iotpage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->iotpage, &_iot_page_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->iotpage, 141, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->iotpage, lv_color_hex(0x001430), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->iotpage, 84, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_imgbtn_1
    ui->iotpage_imgbtn_1 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_ylight_alpha_254x211, NULL);
    ui->iotpage_imgbtn_1_label = lv_label_create(ui->iotpage_imgbtn_1);
    lv_label_set_text(ui->iotpage_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_1, 78, 333);
    lv_obj_set_size(ui->iotpage_imgbtn_1, 254, 211);

    //Write style for iotpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_imgbtn_2
    ui->iotpage_imgbtn_2 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_blightt_alpha_254x211, NULL);
    ui->iotpage_imgbtn_2_label = lv_label_create(ui->iotpage_imgbtn_2);
    lv_label_set_text(ui->iotpage_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_2, 532, 340);
    lv_obj_set_size(ui->iotpage_imgbtn_2, 254, 211);

    //Write style for iotpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_imgbtn_3
    ui->iotpage_imgbtn_3 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_glightt_alpha_254x211, NULL);
    ui->iotpage_imgbtn_3_label = lv_label_create(ui->iotpage_imgbtn_3);
    lv_label_set_text(ui->iotpage_imgbtn_3_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_3, 999, 340);
    lv_obj_set_size(ui->iotpage_imgbtn_3, 254, 211);

    //Write style for iotpage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_label_1
    ui->iotpage_label_1 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_1, "Yellow BULB");
    lv_label_set_long_mode(ui->iotpage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_1, 115, 551);
    lv_obj_set_size(ui->iotpage_label_1, 216, 51);

    //Write style for iotpage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_1, &lv_font_Alatsi_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_2
    ui->iotpage_label_2 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_2, "Blue BULB");
    lv_label_set_long_mode(ui->iotpage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_2, 575, 544);
    lv_obj_set_size(ui->iotpage_label_2, 178, 51);

    //Write style for iotpage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_2, &lv_font_Alatsi_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_3
    ui->iotpage_label_3 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_3, "Green BULB");
    lv_label_set_long_mode(ui->iotpage_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_3, 1036, 544);
    lv_obj_set_size(ui->iotpage_label_3, 216, 51);

    //Write style for iotpage_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_3, &lv_font_Alatsi_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_4
    ui->iotpage_label_4 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_4, "Iot ");
    lv_label_set_long_mode(ui->iotpage_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_4, 583, 13);
    lv_obj_set_size(ui->iotpage_label_4, 178, 51);

    //Write style for iotpage_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_4, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_imgbtn_4
    ui->iotpage_imgbtn_4 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_224x99, NULL);
    ui->iotpage_imgbtn_4_label = lv_label_create(ui->iotpage_imgbtn_4);
    lv_label_set_text(ui->iotpage_imgbtn_4_label, "Back");
    lv_label_set_long_mode(ui->iotpage_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_4, 1045, 612);
    lv_obj_set_size(ui->iotpage_imgbtn_4, 224, 99);

    //Write style for iotpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_4, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_4, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_4, lv_color_hex(0xf9f9f9), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_4, lv_color_hex(0xeae6ea), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_4, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_imgbtn_5
    ui->iotpage_imgbtn_5 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_thermometer_alpha_100x65, NULL);
    ui->iotpage_imgbtn_5_label = lv_label_create(ui->iotpage_imgbtn_5);
    lv_label_set_text(ui->iotpage_imgbtn_5_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_5, 154, 133);
    lv_obj_set_size(ui->iotpage_imgbtn_5, 100, 65);

    //Write style for iotpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_label_8
    ui->iotpage_label_8 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_8, "Humidity");
    lv_label_set_long_mode(ui->iotpage_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_8, 103, 266);
    lv_obj_set_size(ui->iotpage_label_8, 178, 51);

    //Write style for iotpage_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_8, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_7
    ui->iotpage_label_7 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_7, "C");
    lv_label_set_long_mode(ui->iotpage_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_7, 1112, 123);
    lv_obj_set_size(ui->iotpage_label_7, 68, 51);

    //Write style for iotpage_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_7, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_6
    ui->iotpage_label_6 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_6, "--");
    lv_label_set_long_mode(ui->iotpage_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_6, 147, 212);
    lv_obj_set_size(ui->iotpage_label_6, 116, 51);

    //Write style for iotpage_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_6, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_5
    ui->iotpage_label_5 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_5, "Room \nTemperature");
    lv_label_set_long_mode(ui->iotpage_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_5, 999, 263);
    lv_obj_set_size(ui->iotpage_label_5, 218, 74);

    //Write style for iotpage_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_5, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_imgbtn_6
    ui->iotpage_imgbtn_6 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_thermometer_alpha_81x65, NULL);
    ui->iotpage_imgbtn_6_label = lv_label_create(ui->iotpage_imgbtn_6);
    lv_label_set_text(ui->iotpage_imgbtn_6_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_6, 1056, 130);
    lv_obj_set_size(ui->iotpage_imgbtn_6, 81, 65);

    //Write style for iotpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_label_10
    ui->iotpage_label_10 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_10, "Air Quality");
    lv_label_set_long_mode(ui->iotpage_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_10, 569, 266);
    lv_obj_set_size(ui->iotpage_label_10, 196, 51);

    //Write style for iotpage_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_10, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_11
    ui->iotpage_label_11 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_11, "--");
    lv_label_set_long_mode(ui->iotpage_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_11, 1053, 215);
    lv_obj_set_size(ui->iotpage_label_11, 116, 51);

    //Write style for iotpage_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_11, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_label_12
    ui->iotpage_label_12 = lv_label_create(ui->iotpage);
    lv_label_set_text(ui->iotpage_label_12, "--");
    lv_label_set_long_mode(ui->iotpage_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->iotpage_label_12, 604, 212);
    lv_obj_set_size(ui->iotpage_label_12, 116, 51);

    //Write style for iotpage_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->iotpage_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_label_12, &lv_font_Acme_Regular_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->iotpage_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes iotpage_imgbtn_7
    ui->iotpage_imgbtn_7 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_airquality_alpha_116x88, NULL);
    ui->iotpage_imgbtn_7_label = lv_label_create(ui->iotpage_imgbtn_7);
    lv_label_set_text(ui->iotpage_imgbtn_7_label, "");
    lv_label_set_long_mode(ui->iotpage_imgbtn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_7, 607, 119);
    lv_obj_set_size(ui->iotpage_imgbtn_7, 116, 88);

    //Write style for iotpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_7, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_7, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_7, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes iotpage_imgbtn_8
    ui->iotpage_imgbtn_8 = lv_imgbtn_create(ui->iotpage);
    lv_obj_add_flag(ui->iotpage_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->iotpage_imgbtn_8, LV_IMGBTN_STATE_RELEASED, NULL, &_btn1_alpha_224x99, NULL);
    ui->iotpage_imgbtn_8_label = lv_label_create(ui->iotpage_imgbtn_8);
    lv_label_set_text(ui->iotpage_imgbtn_8_label, "Refresh");
    lv_label_set_long_mode(ui->iotpage_imgbtn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->iotpage_imgbtn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->iotpage_imgbtn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->iotpage_imgbtn_8, 18, 612);
    lv_obj_set_size(ui->iotpage_imgbtn_8, 224, 99);

    //Write style for iotpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_8, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_8, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->iotpage_imgbtn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->iotpage_imgbtn_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for iotpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_8, lv_color_hex(0xf9f9f9), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_8, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for iotpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->iotpage_imgbtn_8, lv_color_hex(0xeae6ea), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->iotpage_imgbtn_8, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for iotpage_imgbtn_8, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->iotpage_imgbtn_8, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->iotpage_imgbtn_8, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of iotpage.


    //Update current screen layout.
    lv_obj_update_layout(ui->iotpage);

    //Init events for screen.
    events_init_iotpage(ui);
}
