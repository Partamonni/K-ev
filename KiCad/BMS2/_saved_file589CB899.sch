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
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 1750 1700 0    60   Input ~ 0
BAT24
Text GLabel 1700 2250 0    60   Input ~ 0
BAT0
$Comp
L C C?
U 1 1 589DCF46
P 2350 1950
F 0 "C?" H 2375 2050 50  0000 L CNN
F 1 "10u" H 2375 1850 50  0000 L CNN
F 2 "" H 2388 1800 50  0000 C CNN
F 3 "" H 2350 1950 50  0000 C CNN
	1    2350 1950
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 589DCF75
P 2650 1950
F 0 "C?" H 2675 2050 50  0000 L CNN
F 1 "100n" H 2675 1850 50  0000 L CNN
F 2 "" H 2688 1800 50  0000 C CNN
F 3 "" H 2650 1950 50  0000 C CNN
	1    2650 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 1700 2650 1700
Wire Wire Line
	2350 1700 2350 1800
Wire Wire Line
	1700 2250 2650 2250
Wire Wire Line
	2350 2250 2350 2100
Wire Wire Line
	2650 1700 2650 1800
Connection ~ 2350 1700
Wire Wire Line
	2650 2250 2650 2100
Connection ~ 2350 2250
$EndSCHEMATC
