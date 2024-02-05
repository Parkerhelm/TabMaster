/*
 * W25Q32JV.h
 *
 *  Created on: Feb 5, 2024
 *      Author: parke
 */

#ifndef SRC_W25Q32JV_H_
#define SRC_W25Q32JV_H_

void write_enable(QSPI_HandleTypeDef *hqspi);
void page_program(QSPI_HandleTypeDef *hqspi, uint8_t *buffer, uint32_t start_addr, uint32_t data_len);
void fast_read(QSPI_HandleTypeDef *hqspi, uint8_t *buffer, uint32_t start_addr, uint32_t data_len);
void device_ID(QSPI_HandleTypeDef *hqspi, uint8_t *buffer);

#endif /* SRC_W25Q32JV_H_ */
