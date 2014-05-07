/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"

//Device specific boundaries for touch recognition
/*	
	WARNING
	these might not be the same as resX, resY (from below)
	these have to be found by setting them to zero and then in debug mode
	check the values returned by on screen touch output by click on the 
	touch panel extremeties
*/
//int maxX = 0;		
//int maxY = 0;		

/*
	the values of following two variables are dependent on specifc device resolution
	and can be obtained using the outputs of the gr_fb functions
*/

#define resX gr_fb_width()		//Value obtained from function 'gr_fb_width()'
#define resY gr_fb_height()		//Value obtained from function 'gr_fb_height()'	


char* MENU_HEADERS[] = { NULL };

char* MENU_ITEMS[] = { "Power Menu",
                       "Install zip",
                       "Wipe Menu",
                       "Backup/Restore",
                       "Mounts/Storage",
                       "Advanced Menu",
                       "Carliv",
                       "Reboot Phone",
                       NULL };

void device_ui_init(UIParameters* ui_parameters) {
}

int device_recovery_start() {
    return 0;
}

int device_wipe_data() {
    return 0;
}

int device_wipe_cache() {
    return 0;
}

int device_wipe_dalvik_cache() {
    return 0;
}

int device_wipe_all() {
    return 0;
}

int device_perform_action(int which) {
    return which;
}

extern int device_reboot_now(volatile char* key_pressed, int key_code);

// call a clean reboot
void reboot_main_system(int cmd, int flags, char *arg);

int minimum_storage=512;

//For those devices which has skewed X axis and Y axis detection limit (Not similar to XY resolution of device), So need normalization
int MT_X(int fd, int x)
{	
	int abs_store[6] = {0};

  	ioctl(fd, EVIOCGABS(ABS_MT_POSITION_X), abs_store);
   	int maxX = abs_store[2];

	int out;
	out = maxX ? (x*resX/maxX) : x;
	return out;
}

int MT_Y(int fd, int y)
{	
	int abs_store[6] = {0};
   	
   	ioctl(fd, EVIOCGABS(ABS_MT_POSITION_Y), abs_store);
   	int maxY = abs_store[2];

	int out;
	out = maxY ? (y*resY/maxY) : y;
	return out;
}
