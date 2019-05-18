/* Copyright 2019 Hiroki-Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "i2cmaster.h"
#include "mcp23017.h"

void initExpander(uint8_t dev_addr){

}

uint8_t mcp23017Write(uint8_t dev_addr, uint8_t i2c_addr, uint8_t regAddr, uint8_t data){

	uint8_t err = i2c_start(((dev_addr | i2c_addr)<<1) | I2C_WRITE);
  	if (err) {
		goto i2c_error;
	}

	err = i2c_write(regAddr);
  	if (err){
		goto i2c_error;
	}

	err = i2c_write(data);
  	if (err){
		goto i2c_error;
	}

  	i2c_stop();
  	return 0;

	i2c_error:
  		i2c_stop();
  		return err;
}

uint8_t mcp23017Read(uint8_t dev_addr, uint8_t i2c_addr, uint8_t reg_addr){
	uint8_t data = 0;
	uint8_t err = i2c_start(((dev_addr | i2c_addr)<<1) | I2C_WRITE);
  	if (err) {
		goto i2c_error;
	}

	err = i2c_write(reg_addr);
  	if (err){
		goto i2c_error;
	}

	err = i2c_rep_start(((dev_addr | i2c_addr) << 1) | I2C_READ);
  	if (err){
		goto i2c_error;
	}
	data = i2c_readNak();
  	i2c_stop();
  	return data;

	i2c_error:
  		i2c_stop();
  		return data;
}

uint8_t mcp23017ModePortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_IODIRA, mode);
}

uint8_t mcp23017ModePortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_IODIRB, mode);
}

uint8_t mcp23017PullupPortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_GPPUA, mode);
}
uint8_t mcp23017PullupPortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_GPPUB, mode);
}

uint8_t mcp23017ReadPortA(uint8_t dev_addr, uint8_t i2c_addr){
	return mcp23017Read(dev_addr, i2c_addr, MCP23017_BANK0_GPIOA);
}

uint8_t mcp23017ReadPortB(uint8_t dev_addr, uint8_t i2c_addr){
	return mcp23017Read(dev_addr, i2c_addr, MCP23017_BANK0_GPIOB);
}

uint8_t mcp23017WritePortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	 return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_GPIOA, mode);
}

uint8_t mcp23017WritePortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode){
	 return mcp23017Write(dev_addr, i2c_addr, MCP23017_BANK0_GPIOB, mode);
}
