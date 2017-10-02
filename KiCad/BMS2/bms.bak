EESchema Schematic File Version 2
LIBS:bms-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:EMB1428Q
LIBS:EMB1499Q
LIBS:Omat
LIBS:bms-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 5850 3900 2350 2150
U 5886E791
F0 "Power conversion" 59
F1 "Power_conversion.sch" 59
$EndSheet
Text Notes 7650 5050 2    118  ~ 24
Power supplies
Text GLabel 1700 1450 0    60   Input ~ 0
FRAME_GND
$Comp
L GND #PWR01
U 1 1 5889CB56
P 1950 1450
F 0 "#PWR01" H 1950 1200 50  0001 C CNN
F 1 "GND" H 1950 1300 50  0000 C CNN
F 2 "" H 1950 1450 50  0000 C CNN
F 3 "" H 1950 1450 50  0000 C CNN
	1    1950 1450
	1    0    0    -1  
$EndComp
Text GLabel 1200 6000 2    60   Output ~ 0
SCLK
Text GLabel 1200 5900 2    60   Input ~ 0
SDI
Text GLabel 1200 5800 2    60   Output ~ 0
SDO
Text GLabel 1200 6400 2    60   Output ~ 0
CS4
Text GLabel 1200 6100 2    60   Output ~ 0
CS1
Text GLabel 1200 6200 2    60   Output ~ 0
CS2
Text GLabel 1200 6300 2    60   Output ~ 0
CS3
Text GLabel 1200 6500 2    60   Output ~ 0
RST
$Sheet
S 5850 1550 2350 2100
U 58BBBA27
F0 "DC-Controller" 60
F1 "DC-controller.sch" 60
$EndSheet
Text GLabel 1200 4800 2    60   Output ~ 0
DLY_IN
Text GLabel 1200 4700 2    60   Input ~ 0
DLY_OUT
Text GLabel 1900 2600 2    60   BiDi ~ 0
BAT0
Wire Wire Line
	1700 1450 1950 1450
Wire Wire Line
	1200 4600 1200 4600
Wire Wire Line
	1200 3600 1900 3600
Text GLabel 1900 3750 2    60   UnSpc ~ 0
GND_TOP
Wire Wire Line
	1900 3750 1750 3750
Wire Wire Line
	1750 3750 1750 3600
Connection ~ 1750 3600
Wire Wire Line
	1200 2600 1900 2600
Text GLabel 1900 2450 2    60   BiDi ~ 0
GND_BOT
Wire Wire Line
	1900 2450 1500 2450
Wire Wire Line
	1500 2450 1500 2600
Connection ~ 1500 2600
Text Notes 7950 2650 2    118  ~ 24
Balancing DC-control
$Comp
L Molex_conn P101
U 1 1 58D39F6F
P 1000 4950
F 0 "P101" H 1000 5250 60  0000 C CNN
F 1 "Molex_conn" H 1000 5000 60  0000 C CNN
F 2 "" H -300 4750 60  0001 C CNN
F 3 "" H -300 4750 60  0001 C CNN
	1    1000 4950
	0    -1   1    0   
$EndComp
NoConn ~ 1200 7300
NoConn ~ 1200 7200
NoConn ~ 1200 7100
NoConn ~ 1200 7000
NoConn ~ 1200 6900
NoConn ~ 1200 6800
NoConn ~ 1200 6700
NoConn ~ 1200 6600
Text GLabel 1200 4900 2    60   BiDi ~ 0
12VBAT
Text GLabel 1200 5000 2    60   Output ~ 0
12VSYS
Text GLabel 1200 5300 2    60   Output ~ 0
FRAME_GND
$Sheet
S 3450 3900 2350 2150
U 58D2BC93
F0 "Monitoring" 60
F1 "Monitoring.sch" 60
$EndSheet
Text Notes 4150 5000 0    118  ~ 24
Monitoring
$Sheet
S 3450 1550 2350 2100
U 58D2DA34
F0 "Switch Matrix" 60
F1 "Switch_matrix.sch" 60
$EndSheet
Text Notes 4000 2650 0    118  ~ 24
Switch Matrix
Text GLabel 1200 5400 2    60   BiDi ~ 0
MON_SDA
Text GLabel 1200 5500 2    60   BiDi ~ 0
MON_SCL
Text GLabel 2000 6000 2    60   Input ~ 0
FAULT_INT4
Text GLabel 2000 5900 2    60   Input ~ 0
FAULT_INT3
Text GLabel 2000 5800 2    60   Input ~ 0
FAULT_INT2
Text GLabel 2000 5700 2    60   Input ~ 0
FAULT_INT1
$Comp
L D D101
U 1 1 58D60506
P 1850 5700
F 0 "D101" H 1850 5800 50  0000 C CNN
F 1 "D" H 1850 5600 50  0000 C CNN
F 2 "" H 1850 5700 50  0000 C CNN
F 3 "" H 1850 5700 50  0000 C CNN
	1    1850 5700
	1    0    0    -1  
$EndComp
$Comp
L D D102
U 1 1 58D6052B
P 1850 5800
F 0 "D102" H 1850 5900 50  0000 C CNN
F 1 "D" H 1850 5700 50  0000 C CNN
F 2 "" H 1850 5800 50  0000 C CNN
F 3 "" H 1850 5800 50  0000 C CNN
	1    1850 5800
	1    0    0    -1  
$EndComp
$Comp
L D D103
U 1 1 58D60544
P 1850 5900
F 0 "D103" H 1850 6000 50  0000 C CNN
F 1 "D" H 1850 5800 50  0000 C CNN
F 2 "" H 1850 5900 50  0000 C CNN
F 3 "" H 1850 5900 50  0000 C CNN
	1    1850 5900
	1    0    0    -1  
$EndComp
$Comp
L D D104
U 1 1 58D60560
P 1850 6000
F 0 "D104" H 1850 6100 50  0000 C CNN
F 1 "D" H 1850 5900 50  0000 C CNN
F 2 "" H 1850 6000 50  0000 C CNN
F 3 "" H 1850 6000 50  0000 C CNN
	1    1850 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 6000 1600 6000
Wire Wire Line
	1600 6000 1600 5700
Wire Wire Line
	1700 5800 1600 5800
Connection ~ 1600 5800
Wire Wire Line
	1600 5900 1700 5900
Connection ~ 1600 5900
Connection ~ 1600 5700
Text GLabel 1200 5100 2    60   Output ~ 0
CUR_SENSE+
Text GLabel 1200 5200 2    60   Output ~ 0
CUR_SENSE-
NoConn ~ 1200 5600
Text GLabel 1200 2700 2    60   BiDi ~ 0
BAT1
Text GLabel 1200 2800 2    60   BiDi ~ 0
BAT2
Text GLabel 1200 2900 2    60   BiDi ~ 0
BAT3
Text GLabel 1200 3000 2    60   BiDi ~ 0
BAT4
Text GLabel 1200 3100 2    60   BiDi ~ 0
BAT5
Text GLabel 1200 3200 2    60   BiDi ~ 0
BAT6
Text GLabel 1200 3300 2    60   BiDi ~ 0
BAT7
Text GLabel 1200 3400 2    60   BiDi ~ 0
BAT8
Text GLabel 1200 3500 2    60   BiDi ~ 0
BAT9
Text GLabel 1900 3600 2    60   BiDi ~ 0
BAT10
Text GLabel 1200 3700 2    60   BiDi ~ 0
BAT11
Text GLabel 1200 3800 2    60   BiDi ~ 0
BAT12
Text GLabel 1200 3900 2    60   BiDi ~ 0
BAT13
Text GLabel 1200 4000 2    60   BiDi ~ 0
BAT14
Text GLabel 1200 4100 2    60   BiDi ~ 0
BAT15
Text GLabel 1200 4200 2    60   BiDi ~ 0
BAT16
Text GLabel 1200 4300 2    60   BiDi ~ 0
BAT17
Text GLabel 1200 4400 2    60   BiDi ~ 0
BAT18
Text GLabel 1200 4500 2    60   BiDi ~ 0
BAT19
Text GLabel 1200 4600 2    60   BiDi ~ 0
BAT20
Wire Wire Line
	1200 5700 1700 5700
$EndSCHEMATC
