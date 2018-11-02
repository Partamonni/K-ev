EESchema Schematic File Version 4
LIBS:bms-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L Device:R R205
U 1 1 58871EBA
P 2600 5500
F 0 "R205" V 2680 5500 50  0000 C CNN
F 1 "130k" V 2600 5500 50  0000 C CNN
F 2 "" V 2530 5500 50  0001 C CNN
F 3 "" H 2600 5500 50  0000 C CNN
	1    2600 5500
	0    1    1    0   
$EndComp
$Comp
L Device:R R201
U 1 1 58871EC1
P 2100 5400
F 0 "R201" V 2180 5400 50  0000 C CNN
F 1 "130k" V 2100 5400 50  0000 C CNN
F 2 "" V 2030 5400 50  0001 C CNN
F 3 "" H 2100 5400 50  0000 C CNN
	1    2100 5400
	0    1    1    0   
$EndComp
$Comp
L Device:R R203
U 1 1 58871EC8
P 2250 5800
F 0 "R203" V 2330 5800 50  0000 C CNN
F 1 "130k" V 2250 5800 50  0000 C CNN
F 2 "" V 2180 5800 50  0001 C CNN
F 3 "" H 2250 5800 50  0000 C CNN
	1    2250 5800
	-1   0    0    1   
$EndComp
$Comp
L Omat:LM5018 IC201
U 1 1 58871ECF
P 3300 5350
F 0 "IC201" H 3300 5650 60  0000 C CNN
F 1 "LM5018" H 3300 5750 60  0000 C CNN
F 2 "" H 3300 5400 60  0001 C CNN
F 3 "" H 3300 5400 60  0001 C CNN
	1    3300 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C203
U 1 1 58871ED6
P 4000 5300
F 0 "C203" H 4025 5400 50  0000 L CNN
F 1 "0.01u" H 4025 5200 50  0000 L CNN
F 2 "" H 4038 5150 50  0001 C CNN
F 3 "" H 4000 5300 50  0000 C CNN
	1    4000 5300
	0    1    1    0   
$EndComp
$Comp
L bms-rescue:TRANSFO T201
U 1 1 58871EDD
P 5050 4800
F 0 "T201" H 5050 5050 50  0000 C CNN
F 1 "47u" H 5050 4500 50  0000 C CNN
F 2 "" H 5050 4800 50  0001 C CNN
F 3 "" H 5050 4800 50  0000 C CNN
	1    5050 4800
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D201
U 1 1 58871EE4
P 4550 5400
F 0 "D201" H 4550 5500 50  0000 C CNN
F 1 "D_Schottky" H 4550 5300 50  0000 C CNN
F 2 "" H 4550 5400 50  0001 C CNN
F 3 "" H 4550 5400 50  0000 C CNN
	1    4550 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C205
U 1 1 58871EEB
P 4200 5750
F 0 "C205" H 4225 5850 50  0000 L CNN
F 1 "1u" H 4225 5650 50  0000 L CNN
F 2 "" H 4238 5600 50  0001 C CNN
F 3 "" H 4200 5750 50  0000 C CNN
	1    4200 5750
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky D203
U 1 1 58871EF2
P 5400 4050
F 0 "D203" H 5400 4150 50  0000 C CNN
F 1 "D_Schottky" H 5400 3950 50  0000 C CNN
F 2 "" H 5400 4050 50  0001 C CNN
F 3 "" H 5400 4050 50  0000 C CNN
	1    5400 4050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C210
U 1 1 58871EF9
P 5600 4200
F 0 "C210" H 5625 4300 50  0000 L CNN
F 1 "1u" H 5625 4100 50  0000 L CNN
F 2 "" H 5638 4050 50  0001 C CNN
F 3 "" H 5600 4200 50  0000 C CNN
	1    5600 4200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R211
U 1 1 58871F00
P 5850 4200
F 0 "R211" V 5930 4200 50  0000 C CNN
F 1 "2k" V 5850 4200 50  0000 C CNN
F 2 "" V 5780 4200 50  0001 C CNN
F 3 "" H 5850 4200 50  0000 C CNN
	1    5850 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R207
U 1 1 58871F07
P 5000 5750
F 0 "R207" V 5080 5750 50  0000 C CNN
F 1 "46.4k" V 5000 5750 50  0000 C CNN
F 2 "" V 4930 5750 50  0001 C CNN
F 3 "" H 5000 5750 50  0000 C CNN
	1    5000 5750
	0    1    1    0   
$EndComp
$Comp
L Device:C C207
U 1 1 58871F0E
P 5250 6000
F 0 "C207" H 5275 6100 50  0000 L CNN
F 1 "0.1u" H 5275 5900 50  0000 L CNN
F 2 "" H 5288 5850 50  0001 C CNN
F 3 "" H 5250 6000 50  0000 C CNN
	1    5250 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R209
U 1 1 58871F15
P 5750 6000
F 0 "R209" V 5830 6000 50  0000 C CNN
F 1 "8.25k" V 5750 6000 50  0000 C CNN
F 2 "" V 5680 6000 50  0001 C CNN
F 3 "" H 5750 6000 50  0000 C CNN
	1    5750 6000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R210
U 1 1 58871F1C
P 5750 6500
F 0 "R210" V 5830 6500 50  0000 C CNN
F 1 "1k" V 5750 6500 50  0000 C CNN
F 2 "" V 5680 6500 50  0001 C CNN
F 3 "" H 5750 6500 50  0000 C CNN
	1    5750 6500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C213
U 1 1 58871F23
P 6050 5350
F 0 "C213" H 6075 5450 50  0000 L CNN
F 1 "4.7u" H 6075 5250 50  0000 L CNN
F 2 "" H 6088 5200 50  0001 C CNN
F 3 "" H 6050 5350 50  0000 C CNN
	1    6050 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C209
U 1 1 58871F2A
P 5500 5750
F 0 "C209" H 5525 5850 50  0000 L CNN
F 1 "1n" H 5525 5650 50  0000 L CNN
F 2 "" H 5538 5600 50  0001 C CNN
F 3 "" H 5500 5750 50  0000 C CNN
	1    5500 5750
	0    1    1    0   
$EndComp
$Comp
L Device:C C201
U 1 1 58871F31
P 1600 5450
F 0 "C201" H 1625 5550 50  0000 L CNN
F 1 "15u" H 1625 5350 50  0000 L CNN
F 2 "" H 1638 5300 50  0001 C CNN
F 3 "" H 1600 5450 50  0000 C CNN
	1    1600 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R206
U 1 1 58871F38
P 2750 2200
F 0 "R206" V 2830 2200 50  0000 C CNN
F 1 "130k" V 2750 2200 50  0000 C CNN
F 2 "" V 2680 2200 50  0001 C CNN
F 3 "" H 2750 2200 50  0000 C CNN
	1    2750 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R R202
U 1 1 58871F3F
P 2250 2100
F 0 "R202" V 2330 2100 50  0000 C CNN
F 1 "130k" V 2250 2100 50  0000 C CNN
F 2 "" V 2180 2100 50  0001 C CNN
F 3 "" H 2250 2100 50  0000 C CNN
	1    2250 2100
	0    1    1    0   
$EndComp
$Comp
L Device:R R204
U 1 1 58871F46
P 2400 2500
F 0 "R204" V 2480 2500 50  0000 C CNN
F 1 "130k" V 2400 2500 50  0000 C CNN
F 2 "" V 2330 2500 50  0001 C CNN
F 3 "" H 2400 2500 50  0000 C CNN
	1    2400 2500
	-1   0    0    1   
$EndComp
$Comp
L Omat:LM5018 IC202
U 1 1 58871F4D
P 3450 2050
F 0 "IC202" H 3450 2350 60  0000 C CNN
F 1 "LM5018" H 3450 2450 60  0000 C CNN
F 2 "" H 3450 2100 60  0001 C CNN
F 3 "" H 3450 2100 60  0001 C CNN
	1    3450 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C204
U 1 1 58871F54
P 4150 2000
F 0 "C204" H 4175 2100 50  0000 L CNN
F 1 "0.01u" H 4175 1900 50  0000 L CNN
F 2 "" H 4188 1850 50  0001 C CNN
F 3 "" H 4150 2000 50  0000 C CNN
	1    4150 2000
	0    1    1    0   
$EndComp
$Comp
L bms-rescue:TRANSFO T202
U 1 1 58871F5B
P 5200 1500
F 0 "T202" H 5200 1750 50  0000 C CNN
F 1 "47u" H 5200 1200 50  0000 C CNN
F 2 "" H 5200 1500 50  0001 C CNN
F 3 "" H 5200 1500 50  0000 C CNN
	1    5200 1500
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D202
U 1 1 58871F62
P 4700 2100
F 0 "D202" H 4700 2200 50  0000 C CNN
F 1 "D_Schottky" H 4700 2000 50  0000 C CNN
F 2 "" H 4700 2100 50  0001 C CNN
F 3 "" H 4700 2100 50  0000 C CNN
	1    4700 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C206
U 1 1 58871F69
P 4350 2450
F 0 "C206" H 4375 2550 50  0000 L CNN
F 1 "1u" H 4375 2350 50  0000 L CNN
F 2 "" H 4388 2300 50  0001 C CNN
F 3 "" H 4350 2450 50  0000 C CNN
	1    4350 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky D204
U 1 1 58871F70
P 5550 750
F 0 "D204" H 5550 850 50  0000 C CNN
F 1 "D_Schottky" H 5550 650 50  0000 C CNN
F 2 "" H 5550 750 50  0001 C CNN
F 3 "" H 5550 750 50  0000 C CNN
	1    5550 750 
	-1   0    0    1   
$EndComp
$Comp
L Device:C C212
U 1 1 58871F77
P 5750 900
F 0 "C212" H 5775 1000 50  0000 L CNN
F 1 "1u" H 5775 800 50  0000 L CNN
F 2 "" H 5788 750 50  0001 C CNN
F 3 "" H 5750 900 50  0000 C CNN
	1    5750 900 
	-1   0    0    1   
$EndComp
$Comp
L Device:R R214
U 1 1 58871F7E
P 6000 900
F 0 "R214" V 6080 900 50  0000 C CNN
F 1 "2k" V 6000 900 50  0000 C CNN
F 2 "" V 5930 900 50  0001 C CNN
F 3 "" H 6000 900 50  0000 C CNN
	1    6000 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R208
U 1 1 58871F85
P 5150 2450
F 0 "R208" V 5230 2450 50  0000 C CNN
F 1 "46.4k" V 5150 2450 50  0000 C CNN
F 2 "" V 5080 2450 50  0001 C CNN
F 3 "" H 5150 2450 50  0000 C CNN
	1    5150 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C208
U 1 1 58871F8C
P 5400 2700
F 0 "C208" H 5425 2800 50  0000 L CNN
F 1 "0.1u" H 5425 2600 50  0000 L CNN
F 2 "" H 5438 2550 50  0001 C CNN
F 3 "" H 5400 2700 50  0000 C CNN
	1    5400 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R212
U 1 1 58871F93
P 5900 2700
F 0 "R212" V 5980 2700 50  0000 C CNN
F 1 "8.25k" V 5900 2700 50  0000 C CNN
F 2 "" V 5830 2700 50  0001 C CNN
F 3 "" H 5900 2700 50  0000 C CNN
	1    5900 2700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R213
U 1 1 58871F9A
P 5900 3200
F 0 "R213" V 5980 3200 50  0000 C CNN
F 1 "1k" V 5900 3200 50  0000 C CNN
F 2 "" V 5830 3200 50  0001 C CNN
F 3 "" H 5900 3200 50  0000 C CNN
	1    5900 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C214
U 1 1 58871FA1
P 6150 2050
F 0 "C214" H 6175 2150 50  0000 L CNN
F 1 "4.7u" H 6175 1950 50  0000 L CNN
F 2 "" H 6188 1900 50  0001 C CNN
F 3 "" H 6150 2050 50  0000 C CNN
	1    6150 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C211
U 1 1 58871FA8
P 5650 2450
F 0 "C211" H 5675 2550 50  0000 L CNN
F 1 "1n" H 5675 2350 50  0000 L CNN
F 2 "" H 5688 2300 50  0001 C CNN
F 3 "" H 5650 2450 50  0000 C CNN
	1    5650 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C202
U 1 1 58871FAF
P 1750 2150
F 0 "C202" H 1775 2250 50  0000 L CNN
F 1 "15u" H 1775 2050 50  0000 L CNN
F 2 "" H 1788 2000 50  0001 C CNN
F 3 "" H 1750 2150 50  0000 C CNN
	1    1750 2150
	1    0    0    -1  
$EndComp
$Comp
L regul:7805 U201
U 1 1 58871FB6
P 7000 5600
F 0 "U201" H 7150 5404 50  0000 C CNN
F 1 "7805" H 7000 5800 50  0000 C CNN
F 2 "" H 7000 5600 50  0001 C CNN
F 3 "" H 7000 5600 50  0000 C CNN
	1    7000 5600
	1    0    0    -1  
$EndComp
$Comp
L regul:7805 U202
U 1 1 58871FBD
P 7050 2300
F 0 "U202" H 7200 2104 50  0000 C CNN
F 1 "7805" H 7050 2500 50  0000 C CNN
F 2 "" H 7050 2300 50  0001 C CNN
F 3 "" H 7050 2300 50  0000 C CNN
	1    7050 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2250 6650 2250
Wire Wire Line
	6450 1900 6450 2250
Connection ~ 6400 5200
Wire Wire Line
	6400 5550 6600 5550
Wire Wire Line
	6400 5200 6400 5550
Connection ~ 5400 2950
Wire Wire Line
	3900 2950 3900 2200
Connection ~ 6150 1900
Connection ~ 5900 1900
Connection ~ 5400 1900
Connection ~ 5900 2450
Connection ~ 5000 1900
Connection ~ 5900 2950
Wire Wire Line
	5900 2850 5900 3050
Wire Wire Line
	3900 2950 5900 2950
Wire Wire Line
	5400 2850 5400 2950
Wire Wire Line
	5900 1900 5900 2550
Wire Wire Line
	5800 2450 5900 2450
Connection ~ 5400 2450
Wire Wire Line
	5400 2450 5400 2550
Wire Wire Line
	5300 2450 5500 2450
Connection ~ 6000 1050
Connection ~ 5750 1050
Wire Wire Line
	5000 1050 6600 1050
Wire Wire Line
	5000 1100 5000 1050
Wire Wire Line
	5700 750  6600 750 
Wire Wire Line
	5400 750  5400 1100
Connection ~ 4350 2100
Wire Wire Line
	4350 2300 4350 2100
Wire Wire Line
	5400 2100 4850 2100
Wire Wire Line
	5400 1900 5400 2100
Wire Wire Line
	5400 1900 6600 1900
Connection ~ 4300 1900
Wire Wire Line
	5000 1900 5000 2450
Wire Wire Line
	3900 2100 4550 2100
Wire Wire Line
	4300 1900 4300 2000
Wire Wire Line
	3900 1900 5000 1900
Wire Wire Line
	3900 2000 4000 2000
Connection ~ 2600 2000
Wire Wire Line
	2600 2000 2600 2200
Wire Wire Line
	2400 2100 2400 2350
Wire Wire Line
	2400 2100 3000 2100
Connection ~ 2100 2000
Wire Wire Line
	2100 2100 2100 2000
Wire Wire Line
	1500 2000 3000 2000
Wire Wire Line
	3000 2200 2900 2200
Connection ~ 5250 6250
Wire Wire Line
	3750 6250 3750 5500
Connection ~ 6050 5200
Connection ~ 5750 5200
Connection ~ 5250 5200
Connection ~ 5750 5750
Connection ~ 4850 5200
Connection ~ 5750 6250
Wire Wire Line
	5750 6150 5750 6350
Wire Wire Line
	3750 6250 5750 6250
Wire Wire Line
	5250 6150 5250 6250
Wire Wire Line
	5750 5200 5750 5850
Wire Wire Line
	5650 5750 5750 5750
Connection ~ 5250 5750
Wire Wire Line
	5250 5750 5250 5850
Wire Wire Line
	5150 5750 5350 5750
Connection ~ 5850 4350
Connection ~ 5600 4350
Wire Wire Line
	4850 4350 6450 4350
Wire Wire Line
	4850 4400 4850 4350
Wire Wire Line
	5550 4050 6450 4050
Wire Wire Line
	5250 4050 5250 4400
Connection ~ 4200 5400
Wire Wire Line
	4200 5600 4200 5400
Wire Wire Line
	5250 5400 4700 5400
Wire Wire Line
	5250 5200 5250 5400
Wire Wire Line
	5250 5200 6450 5200
Connection ~ 4150 5200
Wire Wire Line
	4850 5200 4850 5750
Wire Wire Line
	3750 5400 4400 5400
Wire Wire Line
	4150 5200 4150 5300
Wire Wire Line
	3750 5200 4850 5200
Wire Wire Line
	3750 5300 3850 5300
Connection ~ 2450 5300
Wire Wire Line
	2450 5300 2450 5500
Wire Wire Line
	2250 5400 2250 5650
Wire Wire Line
	2250 5400 2850 5400
Connection ~ 1950 5300
Wire Wire Line
	1950 5400 1950 5300
Wire Wire Line
	1350 5300 2850 5300
Wire Wire Line
	2850 5500 2750 5500
Text GLabel 6600 750  2    60   Input ~ 0
12VF
Text GLabel 6600 1050 2    60   Input ~ 0
GNDF
Text GLabel 6600 1900 2    60   Input ~ 0
12VTOP
Text GLabel 8050 2250 2    60   Input ~ 0
5VTOP
Text GLabel 7050 2550 3    60   Input ~ 0
GND_TOP
Text GLabel 6150 2200 3    60   Input ~ 0
GND_TOP
Text GLabel 5900 3350 3    60   Input ~ 0
GND_TOP
Text GLabel 4350 2600 3    60   Input ~ 0
GND_TOP
Text GLabel 2400 2650 3    60   Input ~ 0
GND_TOP
Text GLabel 1750 2300 3    60   Input ~ 0
GND_TOP
Text GLabel 7000 5850 3    60   Input ~ 0
GND_BOT
Text GLabel 6050 5500 3    60   Input ~ 0
GND_BOT
Text GLabel 5750 6650 3    60   Input ~ 0
GND_BOT
Text GLabel 4200 5900 3    60   Input ~ 0
GND_BOT
Text GLabel 2250 5950 3    60   Input ~ 0
GND_BOT
Text GLabel 1600 5600 3    60   Input ~ 0
GND_BOT
Text GLabel 2850 5200 0    60   Input ~ 0
GND_BOT
Text GLabel 3000 1900 0    60   Input ~ 0
GND_TOP
Text GLabel 1500 2000 0    60   Input ~ 0
BAT24
Text GLabel 1350 5300 0    60   Input ~ 0
BAT12
Text GLabel 8050 5550 2    60   Input ~ 0
5VBOT
Text GLabel 6450 5200 2    60   Input ~ 0
12VBOT
Text GLabel 6450 4050 2    60   Input ~ 0
12VF
Text GLabel 6450 4350 2    60   Input ~ 0
GNDF
$Comp
L conn:CONN_01X02 P201
U 1 1 589E2BC8
P 7750 3650
F 0 "P201" H 7750 3800 50  0000 C CNN
F 1 "RSD-100D-12" V 7850 3650 50  0000 C CNN
F 2 "" H 7750 3650 50  0001 C CNN
F 3 "" H 7750 3650 50  0000 C CNN
	1    7750 3650
	-1   0    0    1   
$EndComp
Text GLabel 9300 3600 2    60   Input ~ 0
12VSYS
$Comp
L power:GND #PWR02
U 1 1 589E3FF2
P 8050 3700
F 0 "#PWR02" H 8050 3450 50  0001 C CNN
F 1 "GND" H 8050 3550 50  0000 C CNN
F 2 "" H 8050 3700 50  0000 C CNN
F 3 "" H 8050 3700 50  0000 C CNN
	1    8050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 3700 8050 3700
Wire Wire Line
	7950 3600 9300 3600
$Comp
L Device:C C221
U 1 1 589E4568
P 8500 3750
F 0 "C221" H 8525 3850 50  0000 L CNN
F 1 "10u" H 8525 3650 50  0000 L CNN
F 2 "" H 8538 3600 50  0001 C CNN
F 3 "" H 8500 3750 50  0000 C CNN
	1    8500 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C222
U 1 1 589E46B7
P 8800 3750
F 0 "C222" H 8825 3850 50  0000 L CNN
F 1 "100n" H 8825 3650 50  0000 L CNN
F 2 "" H 8838 3600 50  0001 C CNN
F 3 "" H 8800 3750 50  0000 C CNN
	1    8800 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 589E47A1
P 8500 3900
F 0 "#PWR03" H 8500 3650 50  0001 C CNN
F 1 "GND" H 8500 3750 50  0000 C CNN
F 2 "" H 8500 3900 50  0000 C CNN
F 3 "" H 8500 3900 50  0000 C CNN
	1    8500 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 589E4827
P 8800 3900
F 0 "#PWR04" H 8800 3650 50  0001 C CNN
F 1 "GND" H 8800 3750 50  0000 C CNN
F 2 "" H 8800 3900 50  0000 C CNN
F 3 "" H 8800 3900 50  0000 C CNN
	1    8800 3900
	1    0    0    -1  
$EndComp
$Comp
L regul:7805 U203
U 1 1 589E5281
P 9600 4100
F 0 "U203" H 9750 3904 50  0000 C CNN
F 1 "7805" H 9600 4300 50  0000 C CNN
F 2 "" H 9600 4100 50  0001 C CNN
F 3 "" H 9600 4100 50  0000 C CNN
	1    9600 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 589E5381
P 9600 4350
F 0 "#PWR05" H 9600 4100 50  0001 C CNN
F 1 "GND" H 9600 4200 50  0000 C CNN
F 2 "" H 9600 4350 50  0000 C CNN
F 3 "" H 9600 4350 50  0000 C CNN
	1    9600 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 3600 9100 4050
Wire Wire Line
	9100 4050 9200 4050
Connection ~ 9100 3600
Text GLabel 10550 4050 2    60   Input ~ 0
5VSYS
$Comp
L Device:C C223
U 1 1 589E5885
P 9100 4200
F 0 "C223" H 9125 4300 50  0000 L CNN
F 1 "330n" H 9125 4100 50  0000 L CNN
F 2 "" H 9138 4050 50  0001 C CNN
F 3 "" H 9100 4200 50  0000 C CNN
	1    9100 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 589E5950
P 9100 4350
F 0 "#PWR06" H 9100 4100 50  0001 C CNN
F 1 "GND" H 9100 4200 50  0000 C CNN
F 2 "" H 9100 4350 50  0000 C CNN
F 3 "" H 9100 4350 50  0000 C CNN
	1    9100 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C224
U 1 1 589E5A37
P 9950 4200
F 0 "C224" H 9975 4300 50  0000 L CNN
F 1 "100n" H 9975 4100 50  0000 L CNN
F 2 "" H 9988 4050 50  0001 C CNN
F 3 "" H 9950 4200 50  0000 C CNN
	1    9950 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 4050 10000 4050
$Comp
L power:GND #PWR07
U 1 1 589E5CC9
P 9950 4350
F 0 "#PWR07" H 9950 4100 50  0001 C CNN
F 1 "GND" H 9950 4200 50  0000 C CNN
F 2 "" H 9950 4350 50  0000 C CNN
F 3 "" H 9950 4350 50  0000 C CNN
	1    9950 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2250 7450 2250
$Comp
L Device:C C215
U 1 1 589E62D4
P 6550 2400
F 0 "C215" H 6575 2500 50  0000 L CNN
F 1 "330n" H 6575 2300 50  0000 L CNN
F 2 "" H 6588 2250 50  0001 C CNN
F 3 "" H 6550 2400 50  0000 C CNN
	1    6550 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C218
U 1 1 589E63BD
P 7500 2400
F 0 "C218" H 7525 2500 50  0000 L CNN
F 1 "100n" H 7525 2300 50  0000 L CNN
F 2 "" H 7538 2250 50  0001 C CNN
F 3 "" H 7500 2400 50  0000 C CNN
	1    7500 2400
	1    0    0    -1  
$EndComp
Text GLabel 7500 2550 3    60   Input ~ 0
GND_TOP
Text GLabel 6550 2550 3    60   Input ~ 0
GND_TOP
$Comp
L Device:C C216
U 1 1 589E70E7
P 6550 5700
F 0 "C216" H 6575 5800 50  0000 L CNN
F 1 "330n" H 6575 5600 50  0000 L CNN
F 2 "" H 6588 5550 50  0001 C CNN
F 3 "" H 6550 5700 50  0000 C CNN
	1    6550 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5550 7400 5550
$Comp
L Device:C C217
U 1 1 589E72EA
P 7400 5700
F 0 "C217" H 7425 5800 50  0000 L CNN
F 1 "100n" H 7425 5600 50  0000 L CNN
F 2 "" H 7438 5550 50  0001 C CNN
F 3 "" H 7400 5700 50  0000 C CNN
	1    7400 5700
	1    0    0    -1  
$EndComp
Text GLabel 6550 5850 3    60   Input ~ 0
GND_BOT
Text GLabel 7400 5850 3    60   Input ~ 0
GND_BOT
$Comp
L Device:C C220
U 1 1 589E9E6C
P 7850 2400
F 0 "C220" H 7875 2500 50  0000 L CNN
F 1 "4.7u" H 7875 2300 50  0000 L CNN
F 2 "" H 7888 2250 50  0001 C CNN
F 3 "" H 7850 2400 50  0000 C CNN
	1    7850 2400
	1    0    0    -1  
$EndComp
Text GLabel 7850 2550 3    60   Input ~ 0
GND_TOP
$Comp
L Device:C C219
U 1 1 589EB61A
P 7750 5700
F 0 "C219" H 7775 5800 50  0000 L CNN
F 1 "4.7u" H 7775 5600 50  0000 L CNN
F 2 "" H 7788 5550 50  0001 C CNN
F 3 "" H 7750 5700 50  0000 C CNN
	1    7750 5700
	1    0    0    -1  
$EndComp
Text GLabel 7750 5850 3    60   Input ~ 0
GND_BOT
$Comp
L Device:C C225
U 1 1 589EC6BE
P 10300 4200
F 0 "C225" H 10325 4300 50  0000 L CNN
F 1 "10u" H 10325 4100 50  0000 L CNN
F 2 "" H 10338 4050 50  0001 C CNN
F 3 "" H 10300 4200 50  0000 C CNN
	1    10300 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 589EC7C7
P 10300 4350
F 0 "#PWR08" H 10300 4100 50  0001 C CNN
F 1 "GND" H 10300 4200 50  0000 C CNN
F 2 "" H 10300 4350 50  0000 C CNN
F 3 "" H 10300 4350 50  0000 C CNN
	1    10300 4350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
