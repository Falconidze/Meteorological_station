#ifndef MODES_H
#define MODES_H

#include "../Status/status.h"
#include "../Ui/ui.h"

#define Mode_Settings 0x80
#define Mode_Help 0x40
#define Mode_Current_Data 0x20
#define Mode_Saved_Data 0x10
#define Mode_Reset 0x08
#define Mode_Choice 0x04


void mode_settings_run();
void mode_choice_run();
void mode_help_run();
void mode_init();
void mode_set(uint8_t data);
uint8_t mode_get();

#endif /* MODES_H */