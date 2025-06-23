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
#include <stdio.h>
#include "lvgl.h"

#include "custom.h"
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif
#include "widgets_init.h"
static char buf[10];
static int type=0;
static int prev_type=0;
static bool player1=true;
static bool player2=false;
static int password_counter = 0;
static int correct_password = 0;

int state_YB = 0;
int state_GB = 0;
int state_BB = 0;

void updatepass() {
	password_counter++;
  if (password_counter < 0 || password_counter > 4) {
	  password_counter = 0;
  }

  static char result[6]; // Static to avoid memory leaks
  for (int i = 0; i < password_counter; i++) {
    result[i] = '*';
  }
  for (int i = password_counter; i < 4; i++) {
    result[i] = '-';
  }
  result[4] = '\n';
  lv_label_set_text(guider_ui.lockscreen_label_1,result);

}
static void Homepage_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	gui_load_screen1(1);
		PlayPrompt(PROMPT_BEEP, 1);
		//vTaskDelay(1000);
		homeexitScreen_Callback();
        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.Homepage_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_NONE, 0, 50, false, true);
        kidsenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Homepage_imgbtn_1_event_handler_gest ()
{
		gui_load_screen1(1);
		PlayPrompt(PROMPT_BEEP, 1);
		//vTaskDelay(1000);
		homeexitScreen_Callback();
        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.Homepage_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_NONE, 0, 50, false, true);
        kidsenterScreen_Callback();

}

static void Homepage_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	homeexitScreen_Callback();
    		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.roverpage, guider_ui.roverpage_del, &guider_ui.Homepage_del, setup_scr_roverpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        roverenterScreen_Callback();
        break;
    }
    default:
        break;
    }
}

void Homepage_imgbtn_2_event_handler_gest ()
{
		homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.roverpage, guider_ui.roverpage_del, &guider_ui.Homepage_del, setup_scr_roverpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        roverenterScreen_Callback();
}

static void Homepage_imgbtn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.iotpage, guider_ui.iotpage_del, &guider_ui.Homepage_del, setup_scr_iotpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        IOTenterScreen_Callback();

        break;
    }
    default:
        break;
    }
}

void Homepage_imgbtn_3_event_handler_gest ()
{

    		homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.iotpage, guider_ui.iotpage_del, &guider_ui.Homepage_del, setup_scr_iotpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        IOTenterScreen_Callback();


}



static void Homepage_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.Healthpage, guider_ui.Healthpage_del, &guider_ui.Homepage_del, setup_scr_Healthpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        healthenterScreen_Callback();
        break;
    }
    default:
        break;
    }
}

void Homepage_imgbtn_4_event_handler_gest ()

    {	homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.Healthpage, guider_ui.Healthpage_del, &guider_ui.Homepage_del, setup_scr_Healthpage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        healthenterScreen_Callback();

    }
static void Homepage_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.blackscreen, guider_ui.blackscreen_del, &guider_ui.Homepage_del, setup_scr_blackscreen, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        lockenterScreen_Callback();
        break;
    }
    default:
        break;
    }
}

void Homepage_imgbtn_5_event_handler_gest ()
    {	homeexitScreen_Callback();
		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.blackscreen, guider_ui.blackscreen_del, &guider_ui.Homepage_del, setup_scr_blackscreen, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        lockenterScreen_Callback();

}
int timesync = 0;

static void home_page_imgbtn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	toggle_facereg_cutom();
    	if(timesync == 0){
    		char* temp_str = get_temp_custom(9);
		int Homepage_digital_clock_1_sec_value = atoi(temp_str);
		temp_str = get_temp_custom(8);
    		int Homepage_digital_clock_1_min_value = atoi(temp_str);
    		temp_str = get_temp_custom(7);
    		int Homepage_digital_clock_1_hour_value = atoi(temp_str);
    		char* Homepage_digital_clock_1_meridiem = get_temp_custom(10);
    			static bool Homepage_digital_clock_1_timer_enabled = false;
    			char formatted_time[16]; // Buffer for formatted time string
    			    snprintf(formatted_time, sizeof(formatted_time), "%02d:%02d:%02d %s",
    			             Homepage_digital_clock_1_hour_value,
    			             Homepage_digital_clock_1_min_value,
    			             Homepage_digital_clock_1_sec_value,
    			             Homepage_digital_clock_1_meridiem);
    		    guider_ui.Homepage_digital_clock_1 = lv_dclock_create(guider_ui.Homepage, formatted_time);
    		    if (!Homepage_digital_clock_1_timer_enabled) {
    		        lv_timer_create(Homepage_digital_clock_1_timer, 1000, NULL);
    		        Homepage_digital_clock_1_timer_enabled = true;
    		    }
    		    lv_obj_set_pos(guider_ui.Homepage_digital_clock_1, 70, 10);
    		    lv_obj_set_size(guider_ui.Homepage_digital_clock_1, 160, 40);

    		    //Write style for Homepage_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    		    lv_obj_set_style_radius(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_text_color(guider_ui.Homepage_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_text_font(guider_ui.Homepage_digital_clock_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_text_opa(guider_ui.Homepage_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_text_letter_space(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_text_align(guider_ui.Homepage_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_bg_opa(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_pad_top(guider_ui.Homepage_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_pad_right(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_pad_bottom(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_pad_left(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_set_style_shadow_width(guider_ui.Homepage_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    		    lv_obj_update_layout(guider_ui.Homepage);
    		    timesync =1;
    	}

    	break;
    }
    default:
        break;
    }
}

void events_init_Homepage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Homepage_imgbtn_1, Homepage_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Homepage_imgbtn_2, Homepage_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Homepage_imgbtn_3, Homepage_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Homepage_imgbtn_4, Homepage_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Homepage_imgbtn_5, Homepage_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_imgbtn_6, home_page_imgbtn_6_event_handler, LV_EVENT_ALL, ui);

}

static void Gamepage_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Rock");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Gamepage_imgbtn_1_event_handler_gest ()

    {
        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Rock");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);

}

static void Gamepage_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Paper");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Gamepage_imgbtn_2_event_handler_gest ()
{

        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Paper");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);

}

static void Gamepage_imgbtn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Scissors");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Gamepage_imgbtn_3_event_handler_gest ()
{

        if (prev_type==0) {
            lv_label_set_text(guider_ui.Gamepage_winner_2," ");
        }
        sprintf(buf,"Scissors");
        type=1;
        lv_label_set_text(guider_ui.Gamepage_choice_2,buf);
        PlayPrompt(PROMPT_BEEP, 1);

}

static void Gamepage_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        int random_number = rand() % 3 + 1;
        if(type==random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"Draw");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type==3 && random_number==1) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"AUXi Wins");
            PlayPrompt(PROMPT_BEEP, 1);

        }
        else if(type==1 && random_number==3) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"You Win");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type>random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"You Win");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type<random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"AUXi Wins");
            PlayPrompt(PROMPT_BEEP, 1);
        }

        //PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Gamepage_imgbtn_4_event_handler_gest ()
{

        int random_number = rand() % 3 + 1;
        if(type==random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"Draw");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type==3 && random_number==1) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"AUXi Wins");
            PlayPrompt(PROMPT_BEEP, 1);

        }
        else if(type==1 && random_number==3) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"You Win");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type>random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"You Win");
            PlayPrompt(PROMPT_BEEP, 1);
        }
        else if(type<random_number) {
            lv_label_set_text(guider_ui.Gamepage_winner_2,"AUXi Wins");
            PlayPrompt(PROMPT_BEEP, 1);
        }

        //PlayPrompt(PROMPT_BEEP, 1);

}

static void Gamepage_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.Gamepage_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        gamesexitScreen_Callback();
        //PlayPrompt(PROMPT_BEEP, 1);
        PlayPrompt(win, 1);
        break;
    }
    default:
        break;
    }
}



void Gamepage_imgbtn_5_event_handler_gest ()
{

        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.Gamepage_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        gamesexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}

void events_init_Gamepage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Gamepage_imgbtn_1, Gamepage_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Gamepage_imgbtn_2, Gamepage_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Gamepage_imgbtn_3, Gamepage_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Gamepage_imgbtn_4, Gamepage_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Gamepage_imgbtn_5, Gamepage_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
}

static void kids_page_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Gamepage, guider_ui.Gamepage_del, &guider_ui.kids_page_del, setup_scr_Gamepage, LV_SCR_LOAD_ANIM_FADE_ON, 0, 50, false, true);
        gamesenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void kids_page_imgbtn_1_event_handler_gest ()
{

        ui_load_scr_animation(&guider_ui, &guider_ui.Gamepage, guider_ui.Gamepage_del, &guider_ui.kids_page_del, setup_scr_Gamepage, LV_SCR_LOAD_ANIM_FADE_ON, 0, 50, false, true);
        gamesenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}

static void kids_page_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	gui_load_screen1(2);
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.kids_page_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        kidsexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void kids_page_imgbtn_2_event_handler_gest ()
{

    	gui_load_screen1(2);
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.kids_page_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        kidsexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}

static void kids_page_imgbtn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.rhymepages, guider_ui.rhymepages_del, &guider_ui.kids_page_del, setup_scr_rhymepages, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        rhymesenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void kids_page_imgbtn_3_event_handler_gest ()
{
        ui_load_scr_animation(&guider_ui, &guider_ui.rhymepages, guider_ui.rhymepages_del, &guider_ui.kids_page_del, setup_scr_rhymepages, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        rhymesenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}

static void kids_page_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        PlayPrompt(PROMPT_BEEP, 1);
        print_commands_fwk(11);
        break;
    }
    default:
        break;
    }
}

void events_init_kids_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->kids_page_imgbtn_1, kids_page_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->kids_page_imgbtn_2, kids_page_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->kids_page_imgbtn_3, kids_page_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->kids_page_imgbtn_4, kids_page_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
}

static void rhymepages_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.rhymepages_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        rhymesexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}


static int curr_song = 0;
static int play_pause = 0;

void rhymepages_imgbtn_5_event_handler_gest ()
{

        ui_load_scr_animation(&guider_ui, &guider_ui.kids_page, guider_ui.kids_page_del, &guider_ui.rhymepages_del, setup_scr_kids_page, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        rhymesexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
}

static void rhymepages_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(play_pause == 0){
        		if(curr_song == 0){
			PlayPrompt(twinkle11, 1);
			}
        		else{
        			PlayPrompt(twinkle22, 1);
        		}
        		play_pause = 1;
        break;
    }
        if(play_pause == 1){
                PlayPrompt(PROMPT_BEEP, 1);
                play_pause = 0;
                break;
            }
    }
    default:
        break;
    }
}
static void rhymepages_imgbtn_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	    switch (code) {
	    case LV_EVENT_CLICKED:
	    {
	        if(play_pause == 0){
	        	if(curr_song == 0){
	        				PlayPrompt(twinkle11, 1);
	        				}
	        	        		else{
	        	        			PlayPrompt(twinkle22, 1);
	        	        		}
	        play_pause = 1;
	        break;
	    }
	        if(play_pause == 1){
	                PlayPrompt(PROMPT_BEEP, 1);
	                play_pause = 0;
	                break;
	            }
	    }
	    default:
	        break;
    }
}
static void rhymepages_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    							if(curr_song == 0){
    								curr_song = 1;
    		        				}
    		        	        		else{
    		        	        			curr_song = 0;
    		        	        		}
		break;

    }
    default:
        break;
    }
}
void events_init_rhymepages (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->rhymepages_imgbtn_5, rhymepages_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->rhymepages_imgbtn_1, rhymepages_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->rhymepages_imgbtn_3, rhymepages_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->rhymepages_imgbtn_2, rhymepages_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
}

static void Healthpage_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.Healthpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        healthexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void Healthpage_imgbtn_4_event_handler_gest ()
{

        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.Healthpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        healthexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}
static void Healthpage_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	PlayPrompt(PROMPT_BEEP, 1);
		char* stra2  = get_temp_custom(6);
		lv_label_set_text(guider_ui.Healthpage_label_2,stra2 );

		stra2  = get_temp_custom(5);
		lv_label_set_text(guider_ui.Healthpage_label_5,stra2 );

		stra2  = get_temp_custom(3);
		lv_label_set_text(guider_ui.Healthpage_label_6,stra2 );

        break;
    }
    default:
        break;
    }
}

void Healthpage_imgbtn_5_event_handler_gest ()

    {	PlayPrompt(PROMPT_BEEP, 1);
		char* stra2  = get_temp_custom(6);
		lv_label_set_text(guider_ui.Healthpage_label_2,stra2 );

		stra2  = get_temp_custom(5);
		lv_label_set_text(guider_ui.Healthpage_label_5,stra2 );

		stra2  = get_temp_custom(3);
		lv_label_set_text(guider_ui.Healthpage_label_6,stra2 );

}

void events_init_Healthpage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Healthpage_imgbtn_4, Healthpage_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Healthpage_imgbtn_5, Healthpage_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
}

static void iotpage_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.iotpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        iotexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}



void iotpage_imgbtn_4_event_handler_gest ()
{

        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.iotpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        iotexitScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}


static void iotpage_imgbtn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	    switch (code) {
	    case LV_EVENT_CLICKED:
	    {
	    	PlayPrompt(PROMPT_BEEP, 1);
	    	if (state_YB){
	    print_commands(3);
	    state_YB = 0;
	    	}
	    	else {
	    		print_commands(6);
	    		state_YB = 1;
	    	}

	        break;
	    }
	    default:
	        break;
	    }
}

static void iotpage_imgbtn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	    switch (code) {
	    case LV_EVENT_CLICKED:
	    {
	    	PlayPrompt(PROMPT_BEEP, 1);
	    	if (state_GB){
	    	    print_commands(4);
	    	    state_GB =0 ;
	    	    	}
	    	    	else {
	    	    		print_commands(7);
	    	    	state_GB =1;
	    	    	}
	        break;
	    }
	    default:
	        break;
	    }
}

static void iotpage_imgbtn_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	    switch (code) {
	    case LV_EVENT_CLICKED:
	    {
	    	PlayPrompt(PROMPT_BEEP, 1);
	    	if (state_BB){
	    	    	    print_commands(5);
	    	    	    state_BB =0;
	    	    	    	}
	    	    	    	else {
	    	    	    		print_commands(8);
	    	    	    		state_BB =1;
	    	    	    	}
	        break;
	    }
	    default:
	        break;
	    }
}

static void iotpage_imgbtn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        PlayPrompt(PROMPT_BEEP, 1);
        char* stra1  = get_temp_custom(1);
		lv_label_set_text(guider_ui.iotpage_label_11,stra1 );

		stra1  = get_temp_custom(2);
		lv_label_set_text(guider_ui.iotpage_label_6,stra1 );

		stra1  = get_temp_custom(4);
		lv_label_set_text(guider_ui.iotpage_label_12,stra1 );
        break;
    }
    default:
        break;
    }
}

void iotpage_imgbtn_8_event_handler_gest ()
{
        PlayPrompt(PROMPT_BEEP, 1);
        char* stra1  = get_temp_custom(1);
		lv_label_set_text(guider_ui.iotpage_label_11,stra1 );

		stra1  = get_temp_custom(2);
		lv_label_set_text(guider_ui.iotpage_label_6,stra1 );

		stra1  = get_temp_custom(4);
		lv_label_set_text(guider_ui.iotpage_label_12,stra1 );

}


void events_init_iotpage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->iotpage_imgbtn_4, iotpage_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->iotpage_imgbtn_1, iotpage_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->iotpage_imgbtn_2, iotpage_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->iotpage_imgbtn_3, iotpage_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->iotpage_imgbtn_8, iotpage_imgbtn_8_event_handler, LV_EVENT_ALL, ui);
}

static void roverpage_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	roverexitScreen_Callback();
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 1U);
		GPIO_PinWrite(GPIO10,(9U) , 1U);
		GPIO_PinWrite(GPIO10,(12U) , 1U);
		GPIO_PinWrite(GPIO10,(11U) , 1U);
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.roverpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        homeenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

void roverpage_imgbtn_5_event_handler_gest ()
{

    	roverexitScreen_Callback();
    		PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.roverpage_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        homeenterScreen_Callback();
        PlayPrompt(PROMPT_BEEP, 1);

}

static void roverpage_imgbtn_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 0U);
    					GPIO_PinWrite(GPIO10,(9U) , 1U);
    					GPIO_PinWrite(GPIO10,(12U) , 1U);
    					GPIO_PinWrite(GPIO10,(11U) , 0U);

    					vTaskDelay(900);
    					GPIO_PinWrite(GPIO10,(10U) , 1U);
    					GPIO_PinWrite(GPIO10,(9U) , 1U);
    					GPIO_PinWrite(GPIO10,(12U) , 1U);
    					GPIO_PinWrite(GPIO10,(11U) , 1U);
    					PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}
static void roverpage_imgbtn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 1U);
    						GPIO_PinWrite(GPIO10,(9U) , 0U);
    						GPIO_PinWrite(GPIO10,(12U) , 0U);
    						GPIO_PinWrite(GPIO10,(11U) , 1U);
    						vTaskDelay(900);
    						GPIO_PinWrite(GPIO10,(10U) , 1U);
    						GPIO_PinWrite(GPIO10,(9U) , 1U);
    						GPIO_PinWrite(GPIO10,(12U) , 1U);
    						GPIO_PinWrite(GPIO10,(11U) , 1U);
    						PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}
static void roverpage_imgbtn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 0U);
		GPIO_PinWrite(GPIO10,(9U) , 1U);
		GPIO_PinWrite(GPIO10,(12U) , 0U);
		GPIO_PinWrite(GPIO10,(11U) , 1U);
		vTaskDelay(3000);
						GPIO_PinWrite(GPIO10,(10U) , 1U);
						GPIO_PinWrite(GPIO10,(9U) , 1U);
						GPIO_PinWrite(GPIO10,(12U) , 1U);
						GPIO_PinWrite(GPIO10,(11U) , 1U);
						PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}
static void roverpage_imgbtn_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 1U);
    	                                	GPIO_PinWrite(GPIO10,(9U) , 0U);
    	                                	GPIO_PinWrite(GPIO10,(12U) , 1U);
    	                                	GPIO_PinWrite(GPIO10,(11U) , 0U);
    	                                	vTaskDelay(3000);
    	                                							GPIO_PinWrite(GPIO10,(10U) , 1U);
    	                                							GPIO_PinWrite(GPIO10,(9U) , 1U);
    	                                							GPIO_PinWrite(GPIO10,(12U) , 1U);
    	                                							GPIO_PinWrite(GPIO10,(11U) , 1U);
    	                                							PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void roverpage_imgbtn_10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    		PlayPrompt(PROMPT_BEEP, 1);
    		GPIO_PinWrite(GPIO10,(10U) , 1U);
    		    					GPIO_PinWrite(GPIO10,(9U) , 1U);
    		    					GPIO_PinWrite(GPIO10,(12U) , 1U);
    		    					GPIO_PinWrite(GPIO10,(11U) , 1U);
    		    					PlayPrompt(PROMPT_BEEP, 1);

        break;
    }
    default:
        break;
    }
}

void events_init_roverpage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->roverpage_imgbtn_5, roverpage_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->roverpage_imgbtn_6, roverpage_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->roverpage_imgbtn_7, roverpage_imgbtn_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->roverpage_imgbtn_8, roverpage_imgbtn_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->roverpage_imgbtn_9, roverpage_imgbtn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->roverpage_imgbtn_10, roverpage_imgbtn_10_event_handler, LV_EVENT_ALL, ui);
}

static void blackscreen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void blackscreen_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	PlayPrompt(PROMPT_BEEP, 1);
        ui_load_scr_animation(&guider_ui, &guider_ui.lockscreen, guider_ui.lockscreen_del, &guider_ui.blackscreen_del, setup_scr_lockscreen, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        break;
    }
    default:
        break;
    }
}

void blackscreen_imgbtn_1_event_handler_gest ()
{
	PlayPrompt(PROMPT_BEEP, 1);
    ui_load_scr_animation(&guider_ui, &guider_ui.lockscreen, guider_ui.lockscreen_del, &guider_ui.blackscreen_del, setup_scr_lockscreen, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);

}



void events_init_blackscreen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->blackscreen, blackscreen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->blackscreen_imgbtn_1, blackscreen_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
}

static void lockscreen_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    if(password_counter == 2){
        			correct_password++;
        		}
    PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
        break;
    }
    PlayPrompt(PROMPT_BEEP, 1);
    default:
        break;
    }
}

static void lockscreen_imgbtn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
        break;
    }
    PlayPrompt(PROMPT_BEEP, 1);
    default:
        break;
    }
}

static void lockscreen_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
        break;
    }
    PlayPrompt(PROMPT_BEEP, 1);
    default:
        break;
    }
}

static void lockscreen_imgbtn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    		if(password_counter == 1){
    			correct_password++;
    		}
    		PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}
static void lockscreen_imgbtn_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    if(password_counter == 3){
        			correct_password++;
        		}
    PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    		if(password_counter == 4){
        			correct_password++;
        		}
    		PlayPrompt(PROMPT_BEEP, 1);
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.lockscreen_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        PlayPrompt(PROMPT_BEEP, 1);
        lockexitScreen_Callback();
        break;
    }
    default:
        break;
    }
}

static void lockscreen_imgbtn_12_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {	updatepass();
    		PlayPrompt(PROMPT_BEEP, 1);
    		if(correct_password == 4){

        	        ui_load_scr_animation(&guider_ui, &guider_ui.Homepage, guider_ui.Homepage_del, &guider_ui.lockscreen_del, setup_scr_Homepage, LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 50, false, true);
        	        lockexitScreen_Callback();
        	        PlayPrompt(intro_song, 1);
        	        correct_password = 0;
        	            		break;
    		}
    		correct_password = 0;
    		print_commands_fwk(10);
    		break;
    }
    default:
        break;
    }
}

void events_init_lockscreen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_1, lockscreen_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_2, lockscreen_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_3, lockscreen_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_4, lockscreen_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_5, lockscreen_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lockscreen_imgbtn_6, lockscreen_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_7, lockscreen_imgbtn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_8, lockscreen_imgbtn_8_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_9, lockscreen_imgbtn_9_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_10, lockscreen_imgbtn_10_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_11, lockscreen_imgbtn_11_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->lockscreen_imgbtn_12, lockscreen_imgbtn_12_event_handler, LV_EVENT_ALL, ui);
}



void events_init1(lv_ui *ui)
{

}
