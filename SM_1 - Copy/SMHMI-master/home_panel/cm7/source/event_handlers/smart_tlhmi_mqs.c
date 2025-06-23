/*
 * Copyright 2020-2022 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "board_define.h"
#ifdef ENABLE_OUTPUT_DEV_MqsStreamerAudio
#include "stdint.h"
#include "hal_voice_algo_asr_local.h"
#include "hal_event_descriptor_common.h"
#include "hal_output_dev.h"
#include "fwk_log.h"
#include "sounds.h"
#include "smart_tlhmi_mqs.h"

#define LANGUAGE_COUNT 2

enum
{
    Flying_On_The_Wings_Of_Love,
    Feel_Alright_Main,
    Digital_Technology_Full,
    SONG_INVALID
};

static audio_prompt_info_t s_Prompts[LANGUAGE_COUNT][PROMPT_INVALID];
static track_element s_Songs[SONG_INVALID];

void LoadAudioPrompts(void *base)
{
    s_Songs[Flying_On_The_Wings_Of_Love].track  = (base + 0);
    s_Songs[Flying_On_The_Wings_Of_Love].length = 365893;
    s_Songs[Feel_Alright_Main].track            = (base + 365952);
    s_Songs[Feel_Alright_Main].length           = 365893;
    s_Songs[Digital_Technology_Full].track      = (base + 731904);
    s_Songs[Digital_Technology_Full].length     = 365852;

    s_Prompts[1][PROMPT_BEEP].data = (base + 0);
    s_Prompts[1][PROMPT_BEEP].len = 981;
    s_Prompts[1][buzz].data = (base + 1024);
    s_Prompts[1][buzz].len = 65760;
    s_Prompts[1][demo1].data = (base + 66816);
    s_Prompts[1][demo1].len = 127485;
    s_Prompts[1][demo10].data = (base + 194304);
    s_Prompts[1][demo10].len = 202365;
    s_Prompts[1][demo11].data = (base + 396672);
    s_Prompts[1][demo11].len = 67005;
    s_Prompts[1][demo12].data = (base + 463680);
    s_Prompts[1][demo12].len = 67005;
    s_Prompts[1][demo13].data = (base + 530688);
    s_Prompts[1][demo13].len = 157725;
    s_Prompts[1][demo14].data = (base + 688448);
    s_Prompts[1][demo14].len = 106605;
    s_Prompts[1][demo15].data = (base + 795072);
    s_Prompts[1][demo15].len = 77085;
    s_Prompts[1][demo16].data = (base + 872192);
    s_Prompts[1][demo16].len = 164925;
    s_Prompts[1][demo17].data = (base + 1037120);
    s_Prompts[1][demo17].len = 115965;
    s_Prompts[1][demo2].data = (base + 1153088);
    s_Prompts[1][demo2].len = 208125;
    s_Prompts[1][demo3].data = (base + 1361216);
    s_Prompts[1][demo3].len = 178605;
    s_Prompts[1][demo4].data = (base + 1539840);
    s_Prompts[1][demo4].len = 146205;
    s_Prompts[1][demo5].data = (base + 1686080);
    s_Prompts[1][demo5].len = 172125;
    s_Prompts[1][demo6].data = (base + 1858240);
    s_Prompts[1][demo6].len = 89325;
    s_Prompts[1][demo7].data = (base + 1947584);
    s_Prompts[1][demo7].len = 132525;
    s_Prompts[1][demo8].data = (base + 2080128);
    s_Prompts[1][demo8].len = 154845;
    s_Prompts[1][demo9].data = (base + 2235008);
    s_Prompts[1][demo9].len = 162765;
    s_Prompts[1][draw].data = (base + 2397824);
    s_Prompts[1][draw].len = 35040;
    s_Prompts[1][good_morning].data = (base + 2432896);
    s_Prompts[1][good_morning].len = 89325;
    s_Prompts[1][good_night].data = (base + 2522240);
    s_Prompts[1][good_night].len = 65565;
    s_Prompts[1][how_are_you].data = (base + 2587840);
    s_Prompts[1][how_are_you].len = 57645;
    s_Prompts[1][intro_song].data = (base + 2645504);
    s_Prompts[1][intro_song].len = 161332;
    s_Prompts[1][introduce_yourself].data = (base + 2806848);
    s_Prompts[1][introduce_yourself].len = 190125;
    s_Prompts[1][lose].data = (base + 2996992);
    s_Prompts[1][lose].len = 137090;
    s_Prompts[1][nice_to_meet_you_too].data = (base + 3134144);
    s_Prompts[1][nice_to_meet_you_too].len = 41085;
    s_Prompts[1][robot_greet].data = (base + 3175232);
    s_Prompts[1][robot_greet].len = 88605;
    s_Prompts[1][tell_me_a_joke].data = (base + 3263872);
    s_Prompts[1][tell_me_a_joke].len = 63405;
    s_Prompts[1][turning_off_lights].data = (base + 3327296);
    s_Prompts[1][turning_off_lights].len = 25965;
    s_Prompts[1][win].data = (base + 3353280);
    s_Prompts[1][win].len = 161332;
    s_Prompts[1][turning_on_lights].data = (base + 3514624);
    s_Prompts[1][turning_on_lights].len = 25965;
    s_Prompts[1][twinkle11].data = (base + 3540608);
    s_Prompts[1][twinkle11].len = 80669;
    s_Prompts[1][twinkle22].data = (base + 3621312);
    s_Prompts[1][twinkle22].len = 130688;


    // Prompts Total: 0x12b080, 1224832
    s_Prompts[0][Have_Your_Favorite_Setttings_Confirm_Cancel].data = (base + 1097792);
    s_Prompts[0][Have_Your_Favorite_Setttings_Confirm_Cancel].len  = 12213;
    s_Prompts[0][Delete_Selected_User_Confirm_Cancel].data         = (base + 1110016);
    s_Prompts[0][Delete_Selected_User_Confirm_Cancel].len          = 11025;
    s_Prompts[0][Start_Registration].data                          = (base + 1121088);
    s_Prompts[0][Start_Registration].len                           = 3681;
    s_Prompts[0][Identified_New_User_Verify_Pin].data              = (base + 1124800);
    s_Prompts[0][Identified_New_User_Verify_Pin].len               = 11025;
    s_Prompts[0][Invalid_Pin].data                                 = (base + 1135872);
    s_Prompts[0][Invalid_Pin].len                                  = 3465;
    s_Prompts[0][Registration_Successful].data                     = (base + 1139392);
    s_Prompts[0][Registration_Successful].len                      = 4005;
    s_Prompts[0][Verify_Pin_To_Delete_User].data                   = (base + 1143424);
    s_Prompts[0][Verify_Pin_To_Delete_User].len                    = 9405;
    s_Prompts[0][User_Deleted].data                                = (base + 1152832);
    s_Prompts[0][User_Deleted].len                                 = 4113;
    s_Prompts[0][Registered_User].data                             = (base + 1156992);
    s_Prompts[0][Registered_User].len                              = 4329;
    s_Prompts[0][Come_Closer].data                                 = (base + 1161344);
    s_Prompts[0][Come_Closer].len                                  = 4005;
    s_Prompts[0][Stand_Still].data                                 = (base + 1165376);
    s_Prompts[0][Stand_Still].len                                  = 3789;
    s_Prompts[0][Face_The_Camera].data                             = (base + 1169216);
    s_Prompts[0][Face_The_Camera].len                              = 4005;
    s_Prompts[0][Reposition_Face].data                             = (base + 1173248);
    s_Prompts[0][Reposition_Face].len                              = 4977;
    s_Prompts[1][Have_Your_Favorite_Setttings_Confirm_Cancel].data = (base + 1178240);
    s_Prompts[1][Have_Your_Favorite_Setttings_Confirm_Cancel].len  = 12213;
    s_Prompts[1][Delete_Selected_User_Confirm_Cancel].data         = (base + 1190464);
    s_Prompts[1][Delete_Selected_User_Confirm_Cancel].len          = 9405;
    s_Prompts[1][Start_Registration].data                          = (base + 1199872);
    s_Prompts[1][Start_Registration].len                           = 4761;
    s_Prompts[1][Identified_New_User_Verify_Pin].data              = (base + 1204672);
    s_Prompts[1][Identified_New_User_Verify_Pin].len               = 11889;
    s_Prompts[1][Invalid_Pin].data                                 = (base + 1216576);
    s_Prompts[1][Invalid_Pin].len                                  = 3465;
    s_Prompts[1][Registration_Successful].data                     = (base + 1220096);
    s_Prompts[1][Registration_Successful].len                      = 5409;
    s_Prompts[1][Verify_Pin_To_Delete_User].data                   = (base + 1225536);
    s_Prompts[1][Verify_Pin_To_Delete_User].len                    = 7893;
    s_Prompts[1][User_Deleted].data                                = (base + 1233472);
    s_Prompts[1][User_Deleted].len                                 = 3357;
    s_Prompts[1][Registered_User].data                             = (base + 1236864);
    s_Prompts[1][Registered_User].len                              = 3789;
    s_Prompts[1][Come_Closer].data                                 = (base + 1240704);
    s_Prompts[1][Come_Closer].len                                  = 3141;
    s_Prompts[1][Stand_Still].data                                 = (base + 1243904);
    s_Prompts[1][Stand_Still].len                                  = 3141;
    s_Prompts[1][Face_The_Camera].data                             = (base + 1247104);
    s_Prompts[1][Face_The_Camera].len                              = 3573;
    s_Prompts[1][Reposition_Face].data                             = (base + 1250688);
    s_Prompts[1][Reposition_Face].len                              = 3141;
    s_Prompts[0][Beep_Tone].data                                   = (base + 1254848);
    s_Prompts[0][Beep_Tone].len                                    = 981;
    s_Prompts[1][Beep_Tone].data                                   = (base + 1254848);
    s_Prompts[1][Beep_Tone].len                                    = 981;

}

int APP_OutputDev_MqsAudio_GetSongs(track_element **songs, uint32_t *number)
{
	*songs  = s_Songs;
	*number = SONG_INVALID;
	return 0;
}

int APP_OutputDev_MqsAudio_InputNotifyDecode(
    const output_dev_t *dev, void *inputData, void **audio, uint32_t *len, asr_language_t language)
{
    event_base_t *pEventBase           = (event_base_t *)inputData;

    const audio_prompt_info_t *pPrompt = NULL;

    if (pEventBase->eventId == kEventID_PlayPrompt)
    {
        int promptId = (int)((event_common_t *)pEventBase)->data;
        LOGD("[MQS] Prompt id %d", promptId);
        if (promptId >= PROMPT_BEEP && promptId < PROMPT_INVALID)
        {
            switch (language)
            {
                case ASR_CHINESE:
                    pPrompt = s_Prompts[0];
                    break;
                case ASR_ENGLISH:
                    pPrompt = s_Prompts[1];
                    break;
                default:
                    pPrompt = s_Prompts[1];
                    break;
            }
            *audio = pPrompt[promptId].data;
            *len   = pPrompt[promptId].len;
        }
    }
    return 0;
}
#endif /* ENABLE_OUTPUT_DEV_MqsAudio */
