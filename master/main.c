#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "MCAL/DIO/int.h"
#include "HAL/LCD/int.h"
#include "HAL/KeyBad/int.h"
#include "HAL/Sensor/int.h"
#include "HAL/Motor/int.h"
#include "HAL/StepperMotor/int.h"
#include <avr/interrupt.h>
#include"LIB/BIT_Math.h"
#include "MCAL/Interrupt/int.h"
#include "MCAL/ADC/int.h"
#include "MCAL/Timer/int.h"
#include "MCAL/SPI/int.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "min.h"


u8  password[PASS_SIZE];


int main(void){
	LCD_Init();
	KeypadInit();
	init_SPI_Master();

	while(1){
		u8 user_type = showSettingsScreen();
		showMainScreen(user_type);

	}
}

u8 check_EEPROM_Flag(void) {
	u8 flag_val = EEPROM_read(EEPROM_FLAG_ADDRESS); //EEPROM_ReadByteFromAddress(EEPROM_FLAG_ADDRESS);

	return flag_val == EEPROM_EMPTY_ADDRESS;
}

void getAdminPass(void) {
	EEPROM_ReadBlockFromAddress(EEPROM_ADMIN_ADDRESS, password, PASS_SIZE);
//	return password;
}

void getGuestPass(void) {
	EEPROM_ReadBlockFromAddress(EEPROM_GUEST_ADDRESS, password, PASS_SIZE);
//	return password;
}

void setAdminPass(u8 pass[]) {
	EEPROM_WriteBlockToAddress(EEPROM_ADMIN_ADDRESS, pass, PASS_SIZE);
}

void setGuestPass(u8 pass[]) {
	EEPROM_WriteBlockToAddress(EEPROM_GUEST_ADDRESS, pass, PASS_SIZE);
}


void goBackCMD(void){
	SPI_Start_Trans();
	SPI_Transceive(CMD_BACK);
	SPI_Stop_Trans();
}

void setAdminGuestScreen(void) {
	LCD_Clear();
	u8 adminPass[PASS_SIZE], guestPass[PASS_SIZE];
//	adminPass = (u8) calloc(PASS_SIZE, sizeof(u8));
//	guestPass = (u8) calloc(PASS_SIZE, sizeof(u8));
	LCD_WriteString("Enter Admin Password : ");
	LCD_GoTO(2, 0);
	u8 i;
	for (i = 0; i < PASS_SIZE; i++) {
		while (1) {
			u8 password_digit = KeypadGetKey();
			if (password_digit) {
				LCD_WriteChar(password_digit);
				adminPass[i] = password_digit;
				break;
			}
		}
	}
	_delay_ms(500);
	LCD_Clear();
	/* do the same as above for guest */

	LCD_WriteString("Enter Guest Password : ");
	LCD_GoTO(2, 0);
	for (i = 0; i < PASS_SIZE; i++) {
		while (1) {
			u8 password_digit = KeypadGetKey();
			if (password_digit) {
				LCD_WriteChar(password_digit);
				guestPass[i] = password_digit;
				break;
			}
		}
	}

	/* save the passwords in EEPROM and make the flag address with 0 */

	EEPROM_write(EEPROM_FLAG_ADDRESS, EEPROM_FLAG_NOT_EMPTY);
	setAdminPass(adminPass);
	setGuestPass(guestPass);

	_delay_ms(500);
	LCD_Clear();
	LCD_WriteString("Registration is");
	LCD_GoTO(2, 0);
	LCD_WriteString("Successful !");
	_delay_ms(1000);
	LCD_Clear();
	
}

u8 checkUserPassScreen(void) {
	LCD_Clear();
	u8 trial_number = MAX_TRIAL_NUMBER;

	u8 user_type = NOT_VALID_USER;

	LCD_WriteString("Select User Type:");
	LCD_GoTO(2, 0);

	LCD_WriteString("1:Admin 2:Guest");

	while (1) {
		user_type = KeypadGetKey();
		user_type -= '0';
		if (user_type == ADMIN || user_type == GUEST)
			break;
	}

	while (trial_number--) {

		LCD_Clear();


		LCD_WriteString("Enter Password:");
		LCD_GoTO(2, 0);

		switch (user_type) {
		case ADMIN:
			getAdminPass();
			break;
		case GUEST:
			getGuestPass();
			break;
		}

		u8 i;

		u8 is_correct_password = CORRECT_PASSWORD;
		for (i = 0; i < PASS_SIZE; i++) {
			u8 password_digit;

			while (1) {
				password_digit = KeypadGetKey();
				if (password_digit)
					break;
			}
			LCD_WriteChar(password[i]);
			if (password_digit != password[i]) {
				is_correct_password = WRONG_PASSWORD;
			}
		}

		if (!is_correct_password) {

			LCD_Clear();
			LCD_WriteString("incorrect !");
			LCD_GoTO(2, 0);
			LCD_WriteString("left tries : ");
			LCD_WriteChar(trial_number + '0');

			_delay_ms(1000);

			continue;
		}
		LCD_Clear();
		LCD_WriteString("Correct Password !");
		_delay_ms(500);
		LCD_Clear();
		return user_type;

	}

	return NOT_VALID_USER;

}

u8 showSettingsScreen(void) {
	LCD_Clear();
	if(check_EEPROM_Flag()){
		setAdminGuestScreen();
	}
	return checkUserPassScreen();

}

void changeLedStatusScreen(u8 room){
	LCD_Clear();
	LCD_WriteString("LED ROOM ");
	LCD_WriteChar(room + '1');
	LCD_GoTO(2, 0);
	LCD_WriteString("1:OFF 2:ON");
	u8 user_choice;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '1';

		if(user_choice == ROOM_LED_ON){
			// send CMD_LED_ON
			SPI_Start_Trans();
			SPI_Transceive(ROOM_LED);
			SPI_Stop_Trans();
			SPI_Start_Trans();
			SPI_Transceive(CMD_LED_ON);
			SPI_Stop_Trans();

			LCD_Clear();

			LCD_WriteString("LED is ON");

			_delay_ms(500);
			break;
		}

		if(user_choice == ROOM_LED_OFF){
			// send CMD_LED_OFF
			SPI_Start_Trans();
			SPI_Transceive(ROOM_LED);
			SPI_Stop_Trans();
			SPI_Start_Trans();
			SPI_Transceive(CMD_LED_OFF);
			SPI_Stop_Trans();

			LCD_Clear();

			LCD_WriteString("LED is OFF");

			_delay_ms(500);

			break;
		}

	}


}

void changeDoorStatusScreen(u8 room){
	LCD_Clear();
		LCD_WriteString("DOOR ROOM ");
		LCD_WriteChar(room + '1');
		LCD_GoTO(2, 0);
		LCD_WriteString("1:CLOSE 2:OPEN");
		u8 user_choice;

		while(1){
			user_choice = KeypadGetKey();
			user_choice -= '1';

			if(user_choice == ROOM_DOOR_OPEN){
				// send CMD_OPEN_DOOR
				SPI_Start_Trans();
				SPI_Transceive(ROOM_DOOR);
				SPI_Stop_Trans();
				SPI_Start_Trans();
				SPI_Transceive(CMD_OPEN_DOOR);
				SPI_Stop_Trans();

				LCD_Clear();

				LCD_WriteString("DOOR is OPEN");

				_delay_ms(500);
				break;
			}

			if(user_choice == ROOM_DOOR_CLOSED){
				// send CMD_CLOSE_DOOR
				SPI_Start_Trans();
				SPI_Transceive(ROOM_DOOR);
				SPI_Stop_Trans();
				SPI_Start_Trans();
				SPI_Transceive(CMD_CLOSE_DOOR);
				SPI_Stop_Trans();

				LCD_Clear();

				LCD_WriteString("DOOR is CLOSED");

				_delay_ms(500);

				break;
			}

		}
}

void showRoomAdminSettingScreen(u8 room){
	LCD_Clear();
	LCD_WriteString("1:Back 2:LED");
	LCD_GoTO(2 , 0);
	LCD_WriteString("3:DOOR");

	u8 user_choice;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '0';

		if(user_choice == BACK){
			goBackCMD();
			return;
		}

		if(user_choice == LED){
			changeLedStatusScreen(room);
			break;
		}

		if(user_choice == DOOR){
			changeDoorStatusScreen(room);
			break;
		}
	}
}

void showRoomGuestSettingScreen(u8 room){
	LCD_Clear();
	LCD_WriteString("1:Back 2:LED");

	u8 user_choice;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '0';

		if(user_choice == BACK){
			goBackCMD();
			return;
		}
		if(user_choice == LED){
			changeLedStatusScreen(room);
			break;
		}

	}
}

void showRoomScreen(u8 room , u8 user_type){
	LCD_Clear();
	// send room number
	// receive room status
	SPI_Start_Trans();
	SPI_Transceive(room);
	SPI_Stop_Trans();
	_delay_ms(50);

	SPI_Start_Trans();
	u8 status = SPI_Transceive(0);
	u8 room_door_status = GetBit(status , PIN_7);
	u8 room_led_status = GetBit(status , PIN_0);
	SPI_Stop_Trans();


	LCD_WriteString("LED: ");

	if(room_led_status == ROOM_LED_ON){
		LCD_WriteString("ON ");
	}else{
		LCD_WriteString("OFF ");
	}

	LCD_WriteString("DOOR: ");

	if(room_door_status == ROOM_DOOR_OPEN){
		LCD_WriteString("OPEN");
	}else{
		LCD_WriteString("CLOSED");
	}

	LCD_GoTO(2 , 0);

	LCD_WriteString("1:Back 2:Change");

	u8 user_choice;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '0';

		if(user_choice == BACK){
			goBackCMD();
			return;
		}

		if(user_choice == CHANGE){

			if(user_type == ADMIN){
				showRoomAdminSettingScreen(room);
			}else{
				showRoomGuestSettingScreen(room);
			}

			break;
		}
	}




}

void showAcSettingScreen(void){
	LCD_Clear();
	LCD_WriteString("1:OFF 2:ON");

	u8 user_choice;
	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '1';

		if(user_choice == AC_OFF){
			SPI_Start_Trans();
			SPI_Transceive(CMD_AC_OFF);
			SPI_Stop_Trans();

			LCD_Clear();
			LCD_WriteString("AC is OFF");
			_delay_ms(500);
			break;
		}else if(user_choice == AC_ON){
			SPI_Start_Trans();
			SPI_Transceive(CMD_AC_ON);
			SPI_Stop_Trans();
			_delay_ms(50);
			LCD_Clear();
			LCD_WriteString("AC is ON");
			_delay_ms(500);
			break;
		}
	}
}

void showAcScreen(void){
	LCD_Clear();

	// send AC
	// receive AC status

	SPI_Start_Trans();
	SPI_Transceive(AC);
	SPI_Stop_Trans();
	_delay_ms(50);

	SPI_Start_Trans();
	u8 status = SPI_Transceive(0);
	SPI_Stop_Trans();

	LCD_WriteString("AC ");

	if(status == AC_ON){
		LCD_WriteString("ON");
	}else{
		LCD_WriteString("OFF");
	}

	LCD_GoTO(2,  0);

	LCD_WriteString("1:Back 2:Change");

	u8 user_choice;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '0';
		if(user_choice == BACK)
			return;

		if(user_choice == CHANGE){
			showAcSettingScreen();
			break;
		}
	}

}

void showAdminScreen(void){
	LCD_Clear();
	LCD_WriteString("1:ROOM1 2:ROOM2");
	LCD_GoTO(2 , 0);
	LCD_WriteString("3:ROOM3 4:AC");

	u8 user_choice ;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '1';
		if(user_choice == ROOM1 || user_choice == ROOM2 || user_choice == ROOM3){
			showRoomScreen(user_choice , ADMIN);
			break;
		}

		if(user_choice == AC){
			showAcScreen();
			break;
		}
	}
}


void showGuestScreen(void){
	LCD_Clear();
	LCD_WriteString("1:ROOM1 2:ROOM2");
	LCD_GoTO(2 , 0);
	LCD_WriteString("3:ROOM3");

	u8 user_choice ;

	while(1){
		user_choice = KeypadGetKey();
		user_choice -= '1';
		if(user_choice == ROOM1 || user_choice == ROOM2 || user_choice == ROOM3){
			showRoomScreen(user_choice , GUEST);
			break;
		}


	}
}


void showMainScreen(u8 userType){
	while(1){
		switch(userType){
		case ADMIN:
			showAdminScreen();
			break;
		case GUEST:
			showGuestScreen();
			break;
		}
	}
}
