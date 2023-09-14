/*
 * min.h
 *
 *  Created on: 12 Sept 2023
 *      Author: compu market
 */

#ifndef MIN_H_
#define MIN_H_

#define NOT_VALID_USER 0
#define ADMIN 1
#define GUEST 2
#define BLOCK 3
#define EEPROM_FLAG_ADDRESS 0x100
#define EEPROM_ADMIN_ADDRESS 0x101
#define EEPROM_GUEST_ADDRESS 0x105
#define EEPROM_EMPTY_ADDRESS 0xFF
#define EEPROM_FLAG_NOT_EMPTY 0
#define PASS_SIZE 4
#define MAX_TRIAL_NUMBER 3
#define CORRECT_PASSWORD 1
#define WRONG_PASSWORD 0
#define CHANGE 2
#define BACK 1
#define LED 2
#define DOOR 3

/*     Slave defines         */

#define ROOM1 0
#define ROOM2 1
#define ROOM3 2
#define AC 3
#define ROOM_DOOR 0
#define ROOM_LED 1
#define ROOM_LED_OFF 0
#define ROOM_LED_ON 1
#define ROOM_DOOR_CLOSED 0
#define ROOM_DOOR_OPEN 1
#define AC_OFF 0
#define AC_ON 1
#define CMD_CLOSE_DOOR 0
#define CMD_OPEN_DOOR 1
#define CMD_LED_OFF 0
#define CMD_LED_ON 1
#define CMD_AC_OFF 0
#define CMD_AC_ON 1


/*        end slave defines                 */


u8 check_EEPROM_Flag(void); //Checks EEPROM Flag
void getAdminPass(void); //Returns Admin Password From EEPROM
void getGuestPass(void); //Returns Guest Password From EEPROM
void setAdminPass(u8 *pass); //Store Admin Password In EEPROM
void setGuestPass(u8 *pass); //Store Guest Password In EEPROM
void setAdminGuestScreen(void); // Get admin and guest pass From User And Set Them
u8 checkUserPassScreen(void); //Get User Type from user & checks password 0-->admin/1-->guest /3-->Block Mode
u8 showSettingsScreen(void);
/*
 * check EEPROM flag
 * if first time call setAdminGuestScreen to  Register pass
 * then call checkUserPassScreen
 * if not call checkUserPassScreen
 *
 */
void showRoomScreen(u8 room , u8 user_type);
void showRoomAdminSettingScreen(u8 room);
void showRoomGuestSettingScreen(u8 room);
void showAcSettingScreen(void);
void showAcScreen(void);
void showAdminScreen(void);
void showGuestScreen(void);
void showMainScreen(u8 userType);
/*Shows Main Screen Based On User Type -->
 * ADMIN
 * ROOM 1 , 2, 3 ,AC
 * inside Room
 * Open/Close Door
 * on/off Led
 * GUEST
 * ROOM 1 , 2, 3
 * inside Room
 * on/off Led
 *
 * */







#endif /* MIN_H_ */
