EESchema Schematic File Version 4
LIBS:hiro-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Joystick:JT8P-3.2T-B10K-1-16Y TS?
U 1 1 5D2AA87C
P 4000 4250
AR Path="/5D2AA87C" Ref="TS?"  Part="1" 
AR Path="/5D2AA7B4/5D2AA87C" Ref="TS1"  Part="1" 
F 0 "TS1" H 4000 4637 60  0000 C CNN
F 1 "JT8P-3.2T-B10K-1-16Y" H 4000 4531 60  0000 C CNN
F 2 "keyboard:JT8P-3.2T-B10K-1-16Y" H 4150 4100 60  0001 C CNN
F 3 "" H 4150 4100 60  0000 C CNN
	1    4000 4250
	1    0    0    -1  
$EndComp
$Comp
L ATTINY85-20PU:ATTINY85-20PU IC?
U 1 1 5D2AA889
P 3400 2750
AR Path="/5D2AA889" Ref="IC?"  Part="1" 
AR Path="/5D2AA7B4/5D2AA889" Ref="IC2"  Part="1" 
F 0 "IC2" H 5750 3015 50  0000 C CNN
F 1 "ATTINY85-20PU" H 5750 2924 50  0000 C CNN
F 2 "keyboard:DIP781W56P254L950H533Q8N" H 7950 2850 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/1331672P" H 7950 2750 50  0001 L CNN
F 4 "MICROCHIP - ATTINY85-20PU - MICROCONTROLLER MCU, 8 BIT, ATTINY, 20MHZ, DIP-8" H 7950 2650 50  0001 L CNN "Description"
F 5 "5.334" H 7950 2550 50  0001 L CNN "Height"
F 6 "1331672P" H 7950 2450 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/1331672P" H 7950 2350 50  0001 L CNN "RS Price/Stock"
F 8 "Microchip" H 7950 2250 50  0001 L CNN "Manufacturer_Name"
F 9 "ATTINY85-20PU" H 7950 2150 50  0001 L CNN "Manufacturer_Part_Number"
	1    3400 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5D2AA890
P 6550 3700
AR Path="/5D2AA890" Ref="J?"  Part="1" 
AR Path="/5D2AA7B4/5D2AA890" Ref="J3"  Part="1" 
F 0 "J3" H 6630 3692 50  0000 L CNN
F 1 "Conn_01x04" H 6630 3601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6550 3700 50  0001 C CNN
F 3 "~" H 6550 3700 50  0001 C CNN
	1    6550 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5D2AA897
P 6550 4300
AR Path="/5D2AA897" Ref="J?"  Part="1" 
AR Path="/5D2AA7B4/5D2AA897" Ref="J4"  Part="1" 
F 0 "J4" H 6630 4342 50  0000 L CNN
F 1 "Conn_01x05" H 6630 4251 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6550 4300 50  0001 C CNN
F 3 "~" H 6550 4300 50  0001 C CNN
	1    6550 4300
	1    0    0    -1  
$EndComp
Text GLabel 7850 3900 2    50   Input ~ 0
TINY_SCL
Text GLabel 7850 3650 2    50   Input ~ 0
TINY_SDA
Text GLabel 7850 3750 2    50   Input ~ 0
TINY_MOSI
Text GLabel 7850 4000 2    50   Input ~ 0
TINY_SCK
Wire Wire Line
	7850 3650 7750 3650
Wire Wire Line
	7750 3650 7750 3700
Wire Wire Line
	7750 3700 7650 3700
Wire Wire Line
	7850 3750 7750 3750
Wire Wire Line
	7750 3750 7750 3700
Connection ~ 7750 3700
Wire Wire Line
	7850 3900 7750 3900
Wire Wire Line
	7750 3900 7750 3950
Wire Wire Line
	7750 3950 7650 3950
Wire Wire Line
	7850 4000 7750 4000
Wire Wire Line
	7750 4000 7750 3950
Connection ~ 7750 3950
Text HLabel 8100 2750 2    50   Input ~ 0
VCC
Text HLabel 3700 4150 0    50   Input ~ 0
VCC
Text HLabel 6350 3600 0    50   Input ~ 0
VCC
Text HLabel 6350 4100 0    50   Input ~ 0
VCC
Text HLabel 3400 3050 0    50   Input ~ 0
GND
Text HLabel 3700 4350 0    50   Input ~ 0
GND
Text HLabel 8100 2950 2    50   Input ~ 0
MISO
Text HLabel 8100 3050 2    50   Input ~ 0
TINY_5
Text HLabel 8100 2850 2    50   Input ~ 0
TINY_7
Text HLabel 7650 3700 0    50   Input ~ 0
TINY_5
Text HLabel 7650 3950 0    50   Input ~ 0
TINY_7
Text HLabel 6350 3900 0    50   Input ~ 0
GND
Text HLabel 6350 4500 0    50   Input ~ 0
GND
Text HLabel 4300 4150 2    50   Input ~ 0
x
Text HLabel 4300 4350 2    50   Input ~ 0
y
Text HLabel 3400 2950 0    50   Input ~ 0
y
Text HLabel 3400 2850 0    50   Input ~ 0
x
Text HLabel 6350 3700 0    50   Input ~ 0
TINY_5
Text HLabel 6350 4300 0    50   Input ~ 0
TINY_7
Text HLabel 6350 3800 0    50   Input ~ 0
TINY_7
Text HLabel 6350 4200 0    50   Input ~ 0
TINY_5
Text HLabel 6350 4400 0    50   Input ~ 0
MISO
Text HLabel 3400 2750 0    50   Input ~ 0
rst
$EndSCHEMATC
