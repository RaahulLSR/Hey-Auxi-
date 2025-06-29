/*
 * Copyright 2021 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef INDEXCOMMANDS_H_
#define INDEXCOMMANDS_H_

#include "IndexCommand_funcs.h"

#define ENABLE_HOME_PANEL 1

/* Number of Voice Commands Models */
#define CMD_MODELS_COUNT (4)

enum _hp_home_menu_action
{
    kHpHomeMenuActionThermostat,
    kHpHomeMenuActionSecurity,
    kHpHomeMenuActionAudioPlayer,k3,
	k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,kHpHomeMenuActionInvalid
};

enum _hp_thermostat_action
{
    kHpThermostatActionMainMenu,
    kHpThermostatActionGoBack,
    kHpThermostatActionSetCoolMode,
    kHpThermostatActionSetAutoMode,
    kHpThermostatActionSetHeatMode,
    kHpThermostatActionThermostatOn,
    kHpThermostatActionThermostatOff,
    kHpThermostatActionSlow,
    kHpThermostatActionMedium,
    kHpThermostatActionFast,
    kHpThermostatActionAuto,
    kHpThermostatActionFanOn,
    kHpThermostatActionFanOff,
    kHpThermostatActionEighteen,
    kHpThermostatActionNineteen,
    kHpThermostatActionTwenty,
    kHpThermostatActioTwentyOne,
    kHpThermostatActionTemperatureUp,
    kHpThermostatActionTemperatureDown,
    kHpThermostatActionConfirm,
    kHpThermostatActionCancel,
    kHpThermostatActionInvalid
};

enum _hp_security_action
{
    kHpSecurityActionMainMenu,
    kHpSecurityActionGoBack,
    kHpSecurityActionActivate,
    kHpSecurityActionDisable,
    kHpSecurityActionOpenFrontDoor,
    kHpSecurityActionCloseFrontDoor,
    kHpSecurityActionOpenBackDoor,
    kHpSecurityActionCloseBackDoor,
    kHpSecurityActionOpenGarageDoor,
    kHpSecurityActionCloseGarageDoor,
    kHpSecurityActionInvalid
};

enum _hp_audio_player_action
{
    kHpAudioPlayerActionMainMenu,
    kHpAudioPlayerActionGoBack,
    kHpAudioPlayerActionNextSong,
    kHpAudioPlayerActionPreviousSong,
    kHpAudioPlayerActionPlay,
    kHpAudioPlayerActionPause,
    kHpAudioPlayerActionVolumeUp,
    kHpAudioPlayerActionVolumeDown,
    kHpAudioPlayerActionMute,
    kHpAudioPlayerActionMaxVolume,
    kHpAudioPlayerActionInvalid
};

#endif /* INDEXCOMMANDS_H_ */
