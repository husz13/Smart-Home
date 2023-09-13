/*
 * int.h
 *
 *  Created on: 9 Sept 2023
 *      Author: compu market
 */

#ifndef MCAL_SPI_INT_H_
#define MCAL_SPI_INT_H_

void init_SPI_Master();
void init_SPI_Slave();
void SPI_Start_Trans();
void SPI_Stop_Trans();
u8 SPI_Transceive(u8 data);


#endif /* MCAL_SPI_INT_H_ */
