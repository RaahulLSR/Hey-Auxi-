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



void setup_scr_kids_page(lv_ui *ui)
{
    //Write codes kids_page
    ui->kids_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->kids_page, 1280, 720);
    lv_obj_set_scrollbar_mode(ui->kids_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for kids_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->kids_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->kids_page, &_bg1_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->kids_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->kids_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes kids_page_imgbtn_1
    ui->kids_page_imgbtn_1 = lv_imgbtn_create(ui->kids_page);
    lv_obj_add_flag(ui->kids_page_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->kids_page_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_469x278, NULL);
    ui->kids_page_imgbtn_1_label = lv_label_create(ui->kids_page_imgbtn_1);
    lv_label_set_text(ui->kids_page_imgbtn_1_label, "Play game");
    lv_label_set_long_mode(ui->kids_page_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->kids_page_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->kids_page_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->kids_page_imgbtn_1, 175, 162);
    lv_obj_set_size(ui->kids_page_imgbtn_1, 469, 278);

    //Write style for kids_page_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->kids_page_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->kids_page_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for kids_page_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_1, lv_color_hex(0x161616), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for kids_page_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_1, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for kids_page_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    ui->kids_page_imgbtn_4 = lv_imgbtn_create(ui->kids_page);
        lv_obj_add_flag(ui->kids_page_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
        lv_imgbtn_set_src(ui->kids_page_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_469x278, NULL);
        ui->kids_page_imgbtn_4_label = lv_label_create(ui->kids_page_imgbtn_4);
        lv_label_set_text(ui->kids_page_imgbtn_4_label, "CALL MUMMY");
        lv_label_set_long_mode(ui->kids_page_imgbtn_4_label, LV_LABEL_LONG_WRAP);
        lv_obj_align(ui->kids_page_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(ui->kids_page_imgbtn_4, 0, LV_STATE_DEFAULT);
        lv_obj_set_pos(ui->kids_page_imgbtn_4, 175, 450);
        lv_obj_set_size(ui->kids_page_imgbtn_4, 469, 278);
        //Write style for kids_page_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
        lv_obj_set_style_text_color(ui->kids_page_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui->kids_page_imgbtn_4, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui->kids_page_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_clip_corner(ui->kids_page_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        //Write style for kids_page_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
        lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_img_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_color(ui->kids_page_imgbtn_4, lv_color_hex(0x161616), LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_font(ui->kids_page_imgbtn_4, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_text_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
        lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

        //Write style for kids_page_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
        lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_img_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_color(ui->kids_page_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_font(ui->kids_page_imgbtn_4, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_text_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
        lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

        //Write style for kids_page_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
        lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
        lv_obj_set_style_img_opa(ui->kids_page_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes kids_page_imgbtn_2
    ui->kids_page_imgbtn_2 = lv_imgbtn_create(ui->kids_page);
    lv_obj_add_flag(ui->kids_page_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->kids_page_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_469x278, NULL);
    ui->kids_page_imgbtn_2_label = lv_label_create(ui->kids_page_imgbtn_2);
    lv_label_set_text(ui->kids_page_imgbtn_2_label, "Back");
    lv_label_set_long_mode(ui->kids_page_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->kids_page_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->kids_page_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->kids_page_imgbtn_2, 796, 450);
    lv_obj_set_size(ui->kids_page_imgbtn_2, 469, 278);

    //Write style for kids_page_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->kids_page_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->kids_page_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for kids_page_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_2, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for kids_page_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_2, lv_color_hex(0x100f10), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_2, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for kids_page_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes kids_page_imgbtn_3
    ui->kids_page_imgbtn_3 = lv_imgbtn_create(ui->kids_page);
    lv_obj_add_flag(ui->kids_page_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->kids_page_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_469x278, NULL);
    ui->kids_page_imgbtn_3_label = lv_label_create(ui->kids_page_imgbtn_3);
    lv_label_set_text(ui->kids_page_imgbtn_3_label, "Play Rhyme");
    lv_label_set_long_mode(ui->kids_page_imgbtn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->kids_page_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->kids_page_imgbtn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->kids_page_imgbtn_3, 738, 162);
    lv_obj_set_size(ui->kids_page_imgbtn_3, 469, 278);

    //Write style for kids_page_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_3, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->kids_page_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->kids_page_imgbtn_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for kids_page_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_3, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_3, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for kids_page_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->kids_page_imgbtn_3, lv_color_hex(0x282828), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->kids_page_imgbtn_3, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for kids_page_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->kids_page_imgbtn_3, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->kids_page_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes kids_page_label_1
    ui->kids_page_label_1 = lv_label_create(ui->kids_page);
    lv_label_set_text(ui->kids_page_label_1, "Kids mode");
    lv_label_set_long_mode(ui->kids_page_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->kids_page_label_1, 299, 67);
    lv_obj_set_size(ui->kids_page_label_1, 737, 60);

    //Write style for kids_page_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->kids_page_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->kids_page_label_1, &lv_font_Acme_Regular_64, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->kids_page_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->kids_page_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->kids_page_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->kids_page_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of kids_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->kids_page);

    //Init events for screen.
    events_init_kids_page(ui);
}
