#include <stdbool.h>
#include "action.h"
#include "i2cmaster.h"
#include "expander.h"
#include "debug.h"

static uint8_t expander_status = 0;
static uint8_t left_expander_input = 0;
static uint8_t right_expander_input = 0;
#if (MATRIX_COLS <= 8)
static uint8_t    expander_input;
#elif (MATRIX_COLS <= 16)
static  uint16_t   expander_input;
#elif (MATRIX_COLS <= 32)
static  uint32_t   expander_input;
#else
#error "MATRIX_COLS: invalid value"
#endif

void expander_config(uint8_t expander_addr);
uint8_t expander_write(uint8_t expander_addr, uint8_t reg, uint8_t data);
uint8_t expander_read(uint8_t expander_addr, uint8_t reg, uint8_t *data);

void expander_init(uint8_t expander_addr)
{
  	//i2c_init();
  	expander_scan(expander_addr);
}

void expander_scan(uint8_t expander_addr)
{
  	dprintf("expander status: %d ... ", expander_status);
  	uint8_t ret = i2c_start(expander_addr | I2C_WRITE);
  	if (ret == 0) {
    	i2c_stop();
		expander_config(expander_addr);
    	if (expander_status == 0) {
      		dprintf("attached\n");
      		expander_status = 1;

      		//clear_keyboard();
    	}
  	}
  	else {
    	if (expander_status == 1) {
      		dprintf("detached\n");
      		expander_status = 0;
      		//clear_keyboard();
    	}
  	}
  	dprintf("%d\n", expander_status);
}

void expander_read_cols(void)
{
  	expander_read(LEFT_EXPANDER_ADDR, EXPANDER_REG_GPIOA, &left_expander_input);
	expander_read(RIGHT_EXPANDER_ADDR, EXPANDER_REG_GPIOA, &right_expander_input);
}

uint8_t expander_get_col(uint8_t col)
{
  	if (col > 4) {
    	col++;
  	}

	expander_input = expander_input | (left_expander_input << 1);
	expander_input = expander_input | (right_expander_input & 0x01);
	return expander_input & (1<<col) ? 1 : 0;
  	//return left_expander_input & (1<<col) ? 1 : 0;
}

matrix_row_t expander_read_row(void)
{
  	expander_read_cols();

  	/* make cols */
  	matrix_row_t cols = 0;
  	for (uint8_t col = 0; col < MATRIX_COLS; col++) {
    if (expander_get_col(col)) {
      	cols |= (1UL << (MATRIX_COLS - 1 - col));
    	}
  	}

  	return cols;
}

void expander_unselect_rows(uint8_t expander_addr)
{
  	expander_write(expander_addr, EXPANDER_REG_IODIRB, 0xFF);
}

void expander_select_row(uint8_t expander_addr, uint8_t row)
{
  	expander_write(expander_addr, EXPANDER_REG_IODIRB, ~(1<<(row+1)));
}

void expander_config(uint8_t expander_addr)
{
  	expander_write(expander_addr, EXPANDER_REG_IPOLA, 0xFF);
  	expander_write(expander_addr, EXPANDER_REG_GPPUA, 0xFF);
  	expander_write(expander_addr, EXPANDER_REG_IODIRB, 0xFF);
}

uint8_t expander_write(uint8_t expander_addr, uint8_t reg, uint8_t data)
{
	/*
  	if (expander_status == 0) {
    	return 0;
  	}
	*/
  	uint8_t ret;
	  ret = i2c_start(expander_addr | I2C_WRITE);
  	if (ret) goto stop;
  	ret = i2c_write(reg);
  	if (ret) goto stop;
  	ret = i2c_write(data);
 	stop:
  		i2c_stop();
  	return ret;
}

uint8_t expander_read(uint8_t expander_addr, uint8_t reg, uint8_t *data)
{
	expander_input = 0;
	right_expander_input = 0;
  	if (expander_status == 0) {
    	return 0;
  	}
  	uint8_t ret;
  	ret = i2c_start(expander_addr | I2C_WRITE);
  	if (ret) goto stop;
  	ret = i2c_write(reg);
  	if (ret) goto stop;
  	ret = i2c_rep_start(expander_addr | I2C_READ);
  	if (ret) goto stop;
  	*data = i2c_readNak();
 	stop:
  		i2c_stop();
  	return ret;
}
