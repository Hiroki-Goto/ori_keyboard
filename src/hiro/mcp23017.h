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

#ifndef MCP_23017_H
#define MCP_23017_H

void initExpander(uint8_t dev_addr);
uint8_t mcp23017Write(uint8_t dev_addr, uint8_t i2c_addr, uint8_t regAddr, uint8_t val);
uint8_t mcp23017Read(uint8_t dev_addr, uint8_t i2c_addr, uint8_t reg_addr);
uint8_t mcp23017ModePortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);
uint8_t mcp23017ModePortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);
uint8_t mcp23017PullupPortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);
uint8_t mcp23017PullupPortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);
uint8_t mcp23017ReadPortA(uint8_t dev_addr, uint8_t i2c_addr);
uint8_t mcp23017ReadPortB(uint8_t dev_addr, uint8_t i2c_addr);
uint8_t mcp23017WritePortA(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);
uint8_t mcp23017WritePortB(uint8_t dev_addr, uint8_t i2c_addr, uint8_t mode);



//	MCP_23017 device address
#define MCP23017_LEFT_ADDRESS 0x20
#define MCP23017_RIGHT_ADDRESS 0x21

//	port A (right side) address
#define MCP23017_BANK0_IODIRA 0x00
#define MCP23017_BANK0_IPOLA 0x02
#define MCP23017_BANK0_GPINTENA 0x04
#define MCP23017_BANK0_DEFVALA 0x06
#define MCP23017_BANK0_INTCONA 0x08
#define MCP23017_BANK0_IOCONA 0x0a
#define MCP23017_BANK0_GPPUA 0x0c
#define MCP23017_BANK0_INTFA 0x0e
#define MCP23017_BANK0_INTCAPA 0x10
#define MCP23017_BANK0_GPIOA 0x12
#define MCP23017_BANK0_OLATA 0x14

//	port B (left side) address
#define MCP23017_BANK0_IODIRB 0x01
#define MCP23017_BANK0_IPOLB 0x03
#define MCP23017_BANK0_GPINTENB 0x05
#define MCP23017_BANK0_DEFVALB 0x07
#define MCP23017_BANK0_INTCONB 0x09
#define MCP23017_BANK0_IOCONB 0x0b
#define MCP23017_BANK0_GPPUB 0x0d
#define MCP23017_BANK0_INTFB 0x0f
#define MCP23017_BANK0_INTCAPB 0x11
#define MCP23017_BANK0_GPIOB 0x13
#define MCP23017_BANK0_OLATB 0x15



#define LEFT_GPA0 0x00
#define LEFT_GPA1 0x01
#define LEFT_GPA2 0x02
#define LEFT_GPA3 0x03
#define LEFT_GPA4 0x04
#define LEFT_GPA5 0x05
#define LEFT_GPA6 0x06
#define LEFT_GPA7 0x07
#define LEFT_GPB0 0x08
#define LEFT_GPB1 0x09
#define LEFT_GPB2 0x0a
#define LEFT_GPB3 0x0b
#define LEFT_GPB4 0x0c
#define LEFT_GPB5 0x0d
#define LEFT_GPB6 0x0e
#define LEFT_GPB7 0x0f

#define RIGHT_GPA0 0x10
#define RIGHT_GPA1 0x11
#define RIGHT_GPA2 0x12
#define RIGHT_GPA3 0x13
#define RIGHT_GPA4 0x14
#define RIGHT_GPA5 0x15
#define RIGHT_GPA6 0x16
#define RIGHT_GPA7 0x17
#define RIGHT_GPB0 0x18
#define RIGHT_GPB1 0x19
#define RIGHT_GPB2 0x1a
#define RIGHT_GPB3 0x1b
#define RIGHT_GPB4 0x1c
#define RIGHT_GPB5 0x1d
#define RIGHT_GPB6 0x1e
#define RIGHT_GPB7 0x1f


#endif
