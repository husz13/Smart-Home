/*
 * min.h
 *
 *  Created on: 12 Sept 2023
 *      Author: compu market
 */

#ifndef MIN_H_
#define MIN_H_
#define ADMIN 0
#define GUEST 1
#define BLOCK 3
#define EEPROM_FLAG_ADDRESS 0x00
#define EEPROM_ADMIN_ADDRESS 0x01
#define EEPROM_GUEST_ADDRESS 0x05
u8 check_EEPROM_Flag(void); //Checks EEPROM Flag
u32 getAdminPass(void); //Returns Admin Password From EEPROM
u32 getGuestPass(void); //Returns Guest Password From EEPROM
void setAdminPass(u8 *pass); //Store Admin Password In EEPROM
void setGuestPass(u8 *pass); //Store Guest Password In EEPROM
u8 setAdminGuestScreen(void); // Get admin and guest pass From User And Set Them
u8 checkUserPassScreen(void); //Get User Type from user & checks password 0-->admin/1-->guest /3-->Block Mode
u8 showSettingsScreen(void);
/*
 * check EEPROM flag
 * if first time call setAdminGuestScreen to  Register pass
 * then call checkUserPassScreen
 * if not call checkUserPassScreen
 *
 */
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
