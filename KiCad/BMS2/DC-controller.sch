EESchema Schematic File Version 4
LIBS:bms-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L bms-rescue:EMB1499Q-RESCUE-bms IC302
U 1 1 58C33901
P 4150 4200
F 0 "IC302" H 4150 4100 50  0000 C CNN
F 1 "EMB1499Q" H 4150 4250 50  0000 C CNN
F 2 "" H 4150 4200 50  0001 C CNN
F 3 "" H 4200 4950 50  0001 C CNB
	1    4150 4200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C305
U 1 1 58C33908
P 6050 2000
F 0 "C305" H 6075 2100 50  0000 L CNN
F 1 "C" H 6075 1900 50  0000 L CNN
F 2 "" H 6088 1850 50  0001 C CNN
F 3 "" H 6050 2000 50  0000 C CNN
	1    6050 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R312
U 1 1 58C3390F
P 7150 2750
F 0 "R312" V 7230 2750 50  0000 C CNN
F 1 "0.01" V 7150 2750 50  0000 C CNN
F 2 "" V 7080 2750 50  0001 C CNN
F 3 "" H 7150 2750 50  0000 C CNN
	1    7150 2750
	0    1    1    0   
$EndComp
$Comp
L Device:CP1 C306
U 1 1 58C33916
P 7400 2100
F 0 "C306" H 7425 2200 50  0000 L CNN
F 1 "10u" H 7425 2000 50  0000 L CNN
F 2 "" H 7400 2100 50  0001 C CNN
F 3 "" H 7400 2100 50  0000 C CNN
	1    7400 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:D D309
U 1 1 58C3391D
P 6400 2200
F 0 "D309" H 6400 2300 50  0000 C CNN
F 1 "D" H 6400 2100 50  0000 C CNN
F 2 "" H 6400 2200 50  0001 C CNN
F 3 "" H 6400 2200 50  0000 C CNN
	1    6400 2200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D307
U 1 1 58C33924
P 5500 2400
F 0 "D307" H 5500 2500 50  0000 C CNN
F 1 "D" H 5500 2300 50  0000 C CNN
F 2 "" H 5500 2400 50  0001 C CNN
F 3 "" H 5500 2400 50  0000 C CNN
	1    5500 2400
	0    1    1    0   
$EndComp
$Comp
L Device:D D306
U 1 1 58C3392B
P 4750 2250
F 0 "D306" H 4750 2350 50  0000 C CNN
F 1 "D" H 4750 2150 50  0000 C CNN
F 2 "" H 4750 2250 50  0001 C CNN
F 3 "" H 4750 2250 50  0000 C CNN
	1    4750 2250
	0    1    1    0   
$EndComp
$Comp
L Device:D D304
U 1 1 58C33932
P 3750 1800
F 0 "D304" H 3750 1900 50  0000 C CNN
F 1 "D" H 3750 1700 50  0000 C CNN
F 2 "" H 3750 1800 50  0001 C CNN
F 3 "" H 3750 1800 50  0000 C CNN
	1    3750 1800
	0    1    1    0   
$EndComp
$Comp
L Device:R R303
U 1 1 58C33939
P 2800 2450
F 0 "R303" V 2880 2450 50  0000 C CNN
F 1 "0.01" V 2800 2450 50  0000 C CNN
F 2 "" V 2730 2450 50  0001 C CNN
F 3 "" H 2800 2450 50  0000 C CNN
	1    2800 2450
	0    1    1    0   
$EndComp
$Comp
L bms-rescue:INDUCTOR L301
U 1 1 58C33940
P 2700 1600
F 0 "L301" V 2650 1600 50  0000 C CNN
F 1 "6.8u" V 2800 1600 50  0000 C CNN
F 2 "" H 2700 1600 50  0001 C CNN
F 3 "" H 2700 1600 50  0000 C CNN
	1    2700 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP1 C303
U 1 1 58C33947
P 2400 2000
F 0 "C303" H 2425 2100 50  0000 L CNN
F 1 "10u" H 2425 1900 50  0000 L CNN
F 2 "" H 2400 2000 50  0001 C CNN
F 3 "" H 2400 2000 50  0000 C CNN
	1    2400 2000
	1    0    0    -1  
$EndComp
NoConn ~ 5050 4650
$Comp
L Device:R R301
U 1 1 58C3394F
P 2200 4000
F 0 "R301" V 2280 4000 50  0000 C CNN
F 1 "10K" V 2200 4000 50  0000 C CNN
F 2 "" V 2130 4000 50  0001 C CNN
F 3 "" H 2200 4000 50  0000 C CNN
	1    2200 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R302
U 1 1 58C33956
P 2200 4450
F 0 "R302" V 2280 4450 50  0000 C CNN
F 1 "2K" V 2200 4450 50  0000 C CNN
F 2 "" V 2130 4450 50  0001 C CNN
F 3 "" H 2200 4450 50  0000 C CNN
	1    2200 4450
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 58C3395D
P 6100 4050
F 0 "#PWR09" H 6100 3800 50  0001 C CNN
F 1 "GND" H 6100 3900 50  0000 C CNN
F 2 "" H 6100 4050 50  0000 C CNN
F 3 "" H 6100 4050 50  0000 C CNN
	1    6100 4050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 58C33963
P 2200 4700
F 0 "#PWR010" H 2200 4450 50  0001 C CNN
F 1 "GND" H 2200 4550 50  0000 C CNN
F 2 "" H 2200 4700 50  0000 C CNN
F 3 "" H 2200 4700 50  0000 C CNN
	1    2200 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 58C33969
P 7400 2750
F 0 "#PWR011" H 7400 2500 50  0001 C CNN
F 1 "GND" H 7400 2600 50  0000 C CNN
F 2 "" H 7400 2750 50  0000 C CNN
F 3 "" H 7400 2750 50  0000 C CNN
	1    7400 2750
	1    0    0    -1  
$EndComp
$Comp
L Omat:PA3856.005NL T301
U 1 1 58C3396F
P 5000 1600
F 0 "T301" H 5000 2100 50  0000 C CNN
F 1 "PA3856.005NL" H 5000 2250 50  0000 C CNN
F 2 "" H 5000 1600 50  0001 C CNN
F 3 "" H 5000 1600 50  0000 C CNN
	1    5000 1600
	-1   0    0    -1  
$EndComp
NoConn ~ 5300 1700
NoConn ~ 5300 2000
Text GLabel 2400 2550 3    60   Input ~ 0
GNDF
$Comp
L Device:R R309
U 1 1 58C33979
P 4250 2700
F 0 "R309" V 4330 2700 50  0000 C CNN
F 1 "5.1" V 4250 2700 50  0000 C CNN
F 2 "" V 4180 2700 50  0001 C CNN
F 3 "" H 4250 2700 50  0000 C CNN
	1    4250 2700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R304
U 1 1 58C33980
P 3150 2650
F 0 "R304" V 3230 2650 50  0000 C CNN
F 1 "5.1" V 3150 2650 50  0000 C CNN
F 2 "" V 3080 2650 50  0001 C CNN
F 3 "" H 3150 2650 50  0000 C CNN
	1    3150 2650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R305
U 1 1 58C33987
P 3300 2200
F 0 "R305" V 3380 2200 50  0000 C CNN
F 1 "100K" V 3300 2200 50  0000 C CNN
F 2 "" V 3230 2200 50  0001 C CNN
F 3 "" H 3300 2200 50  0000 C CNN
	1    3300 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R R308
U 1 1 58C3398E
P 4100 2250
F 0 "R308" V 4180 2250 50  0000 C CNN
F 1 "100K" V 4100 2250 50  0000 C CNN
F 2 "" V 4030 2250 50  0001 C CNN
F 3 "" H 4100 2250 50  0000 C CNN
	1    4100 2250
	0    1    1    0   
$EndComp
$Comp
L bms-rescue:ZENER D302
U 1 1 58C33995
P 2600 1150
F 0 "D302" H 2600 1250 50  0000 C CNN
F 1 "30V" H 2600 1050 50  0000 C CNN
F 2 "" H 2600 1150 50  0001 C CNN
F 3 "" H 2600 1150 50  0000 C CNN
	1    2600 1150
	1    0    0    -1  
$EndComp
$Comp
L bms-rescue:ZENER D303
U 1 1 58C3399C
P 3000 1150
F 0 "D303" H 3000 1250 50  0000 C CNN
F 1 "30V" H 3000 1050 50  0000 C CNN
F 2 "" H 3000 1150 50  0001 C CNN
F 3 "" H 3000 1150 50  0000 C CNN
	1    3000 1150
	-1   0    0    1   
$EndComp
Connection ~ 6600 2750
Wire Wire Line
	6600 2400 6600 2750
Connection ~ 5750 4050
Wire Wire Line
	5750 3750 5750 4050
Wire Wire Line
	5050 3750 5750 3750
Wire Wire Line
	5050 4050 6100 4050
Connection ~ 5850 4150
Wire Wire Line
	5850 3650 5850 4150
Wire Wire Line
	5050 3650 5850 3650
Wire Wire Line
	5050 4150 6100 4150
Connection ~ 5750 4850
Wire Wire Line
	5750 4250 5750 4850
Wire Wire Line
	5050 4250 5750 4250
Wire Wire Line
	5050 4850 6100 4850
Connection ~ 5850 4750
Wire Wire Line
	5050 4750 6100 4750
Wire Wire Line
	5850 4450 5850 4750
Wire Wire Line
	5050 4450 5850 4450
Wire Wire Line
	7400 2750 7300 2750
Wire Wire Line
	7400 2250 7400 2750
Wire Wire Line
	5700 2750 7000 2750
Wire Wire Line
	5700 2600 5700 3550
Wire Wire Line
	5700 3550 5050 3550
Wire Wire Line
	6900 3850 5050 3850
Wire Wire Line
	6200 2000 6600 2000
Wire Wire Line
	5700 1500 5700 2200
Wire Wire Line
	5500 2250 5500 2200
Wire Wire Line
	5500 2200 5700 2200
Wire Wire Line
	5500 2550 5500 2600
Wire Wire Line
	5500 2600 5700 2600
Wire Wire Line
	6400 2350 6400 2400
Wire Wire Line
	6400 2400 6600 2400
Wire Wire Line
	6400 2050 6400 2000
Connection ~ 6400 2000
Wire Wire Line
	4600 1500 4600 2050
Wire Wire Line
	2950 2450 4750 2450
Wire Wire Line
	3550 2000 3550 2450
Wire Wire Line
	4600 2050 4750 2050
Wire Wire Line
	4750 2450 4750 2400
Connection ~ 4600 2450
Wire Wire Line
	3750 1600 3750 1650
Connection ~ 3750 1600
Wire Wire Line
	3750 1950 3750 2000
Wire Wire Line
	3750 2000 3550 2000
Wire Wire Line
	3250 2450 3250 3550
Connection ~ 3550 2450
Connection ~ 3250 2450
Connection ~ 3550 1600
Wire Wire Line
	2400 1150 2400 1850
Wire Wire Line
	2400 2150 2400 2550
Wire Wire Line
	1300 2450 2650 2450
Wire Wire Line
	2150 3650 3250 3650
Wire Wire Line
	2150 1600 2150 3650
Wire Wire Line
	1300 1600 2400 1600
Connection ~ 2400 2450
Connection ~ 5700 2750
Wire Wire Line
	5050 4350 5100 4350
Wire Wire Line
	5100 4350 5100 3100
Wire Wire Line
	5100 3100 3150 3100
Wire Wire Line
	3150 1800 3250 1800
Wire Wire Line
	5050 4550 5150 4550
Wire Wire Line
	5150 4550 5150 3050
Wire Wire Line
	5150 3050 4250 3050
Wire Wire Line
	4250 2250 4300 2250
Wire Wire Line
	2200 4600 2200 4700
Wire Wire Line
	2200 4150 2200 4300
Wire Wire Line
	2200 3850 2050 3850
Wire Wire Line
	3250 4050 2350 4050
Wire Wire Line
	2350 4050 2350 4250
Wire Wire Line
	2350 4250 2200 4250
Connection ~ 2200 4250
Wire Wire Line
	3150 3750 3250 3750
Wire Wire Line
	3150 3750 3150 4150
Wire Wire Line
	3150 3950 3250 3950
Wire Wire Line
	3050 3850 3250 3850
Connection ~ 3150 3850
Wire Wire Line
	3150 4150 3250 4150
Connection ~ 3150 3950
Connection ~ 6600 2400
Connection ~ 3550 2000
Connection ~ 4600 2050
Connection ~ 5700 2200
Connection ~ 5700 2600
Connection ~ 7400 1600
Wire Wire Line
	5300 1500 5700 1500
Wire Wire Line
	3000 1600 4150 1600
Wire Wire Line
	4600 1500 4700 1500
Wire Wire Line
	4700 1200 4150 1200
Wire Wire Line
	4150 1200 4150 1700
Wire Wire Line
	7750 1600 7400 1600
Wire Wire Line
	7400 1200 7400 1950
Wire Wire Line
	4700 2000 4600 2000
Wire Wire Line
	4600 2000 4600 1950
Connection ~ 4600 2000
Wire Wire Line
	4150 1700 4700 1700
Connection ~ 4150 1600
Wire Wire Line
	5700 2000 5900 2000
Connection ~ 5700 2000
Wire Wire Line
	5300 1200 7400 1200
Wire Wire Line
	4250 3050 4250 2850
Wire Wire Line
	4250 2250 4250 2550
Wire Wire Line
	3150 1800 3150 2500
Wire Wire Line
	3150 3100 3150 2800
Wire Wire Line
	3450 2200 3550 2200
Connection ~ 3550 2200
Wire Wire Line
	3950 2250 3950 2450
Connection ~ 3950 2450
Connection ~ 2400 1600
Wire Wire Line
	3200 1150 3200 1600
Connection ~ 3200 1600
$Comp
L bms-rescue:ZENER D301
U 1 1 58C33A11
P 1800 2050
F 0 "D301" H 1800 2150 50  0000 C CNN
F 1 "6.2V" H 1800 1950 50  0000 C CNN
F 2 "" H 1800 2050 50  0001 C CNN
F 3 "" H 1800 2050 50  0000 C CNN
	1    1800 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 1850 1800 1600
Connection ~ 1800 1600
Wire Wire Line
	1800 2250 1800 2450
Connection ~ 1800 2450
Text GLabel 7750 1600 2    60   BiDi ~ 0
12VBAT
Wire Wire Line
	5250 3950 5050 3950
$Comp
L Device:R R311
U 1 1 58C33A1E
P 6900 2450
F 0 "R311" V 6980 2450 50  0000 C CNN
F 1 "10K" V 6900 2450 50  0000 C CNN
F 2 "" V 6830 2450 50  0001 C CNN
F 3 "" H 6900 2450 50  0000 C CNN
	1    6900 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 2200 6900 2300
Wire Wire Line
	6900 2600 6900 2750
Connection ~ 6900 2750
$Comp
L bms-rescue:ZENER D308
U 1 1 58C33A28
P 5900 1500
F 0 "D308" H 5900 1600 50  0000 C CNN
F 1 "100V" H 5900 1400 50  0000 C CNN
F 2 "" H 5900 1500 50  0001 C CNN
F 3 "" H 5900 1500 50  0000 C CNN
	1    5900 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 58C33A2F
P 6100 1500
F 0 "#PWR012" H 6100 1250 50  0001 C CNN
F 1 "GND" H 6100 1350 50  0000 C CNN
F 2 "" H 6100 1500 50  0000 C CNN
F 3 "" H 6100 1500 50  0000 C CNN
	1    6100 1500
	1    0    0    -1  
$EndComp
Text GLabel 1300 1600 0    60   BiDi ~ 0
MATRIX+
Text GLabel 1300 2450 0    60   BiDi ~ 0
MATRIX-
$Comp
L Device:R R310
U 1 1 58C33A37
P 6000 2600
F 0 "R310" V 6080 2600 50  0000 C CNN
F 1 "100K" V 6000 2600 50  0000 C CNN
F 2 "" V 5930 2600 50  0001 C CNN
F 3 "" H 6000 2600 50  0000 C CNN
	1    6000 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 2400 6000 2450
Wire Wire Line
	4750 2050 4750 2100
$Comp
L Device:Q_NMOS_DGS Q303
U 1 1 58C33A40
P 5800 2400
F 0 "Q303" H 5700 2200 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 6000 2100 50  0001 R CNN
F 2 "" H 6000 2500 50  0001 C CNN
F 3 "" H 5800 2400 50  0000 C CNN
	1    5800 2400
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q304
U 1 1 58C33A47
P 6700 2200
F 0 "Q304" H 6650 2350 50  0000 R CNN
F 1 "Q_PMOS_DGS" H 6700 2400 50  0001 R CNN
F 2 "" H 6900 2300 50  0001 C CNN
F 3 "" H 6700 2200 50  0000 C CNN
	1    6700 2200
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q302
U 1 1 58C33A4E
P 4500 2250
F 0 "Q302" H 4400 2050 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 4700 1950 50  0001 R CNN
F 2 "" H 4700 2350 50  0001 C CNN
F 3 "" H 4500 2250 50  0000 C CNN
	1    4500 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q301
U 1 1 58C33A55
P 3450 1800
F 0 "Q301" H 3350 1600 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 3650 1500 50  0001 R CNN
F 2 "" H 3650 1900 50  0001 C CNN
F 3 "" H 3450 1800 50  0000 C CNN
	1    3450 1800
	1    0    0    -1  
$EndComp
Text GLabel 2050 3850 0    60   Input ~ 0
12VSYS
Text GLabel 3050 3850 0    60   Output ~ 0
GNDF
Text GLabel 3250 4650 0    60   Output ~ 0
FAULT0
Text GLabel 3250 4750 0    60   Output ~ 0
FAULT1
Text GLabel 3250 4850 0    60   Output ~ 0
FAULT2
Text GLabel 3250 4550 0    60   Output ~ 0
DONE
Text GLabel 3250 4450 0    60   Output ~ 0
DIR_RT
Text GLabel 3250 4350 0    60   BiDi ~ 0
DIR
Text GLabel 3250 4250 0    60   Input ~ 0
EN
Text GLabel 6900 2200 2    60   Input ~ 0
CLAMP
Text GLabel 6900 3850 2    60   UnSpc ~ 0
DLY_IN
Text GLabel 5250 3950 2    60   Output ~ 0
GATE_LS
Text GLabel 6100 4150 2    60   Input ~ 0
12VSYS
Text GLabel 6100 4750 2    60   Output ~ 0
GNDF
Text GLabel 6100 4850 2    60   Input ~ 0
12VF
Text GLabel 6000 2400 2    60   Input ~ 0
GATE_LS
$Comp
L bms-rescue:UCC27511 IC301
U 1 1 58C34029
P 3300 6250
F 0 "IC301" H 3300 6750 60  0000 C CNN
F 1 "UCC27511" V 3300 6250 60  0000 C CNN
F 2 "" H 3300 6400 60  0001 C CNN
F 3 "" H 3300 6400 60  0001 C CNN
	1    3300 6250
	1    0    0    -1  
$EndComp
Text GLabel 1500 5650 0    60   Input ~ 0
12VBAT
$Comp
L Device:C C302
U 1 1 58C34031
P 2100 5800
F 0 "C302" H 2125 5900 50  0000 L CNN
F 1 "4.7u" H 2125 5700 50  0000 L CNN
F 2 "" H 2138 5650 50  0001 C CNN
F 3 "" H 2100 5800 50  0000 C CNN
	1    2100 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C301
U 1 1 58C34038
P 1900 5800
F 0 "C301" H 1925 5900 50  0000 L CNN
F 1 "100n" H 1925 5700 50  0000 L CNN
F 2 "" H 1938 5650 50  0001 C CNN
F 3 "" H 1900 5800 50  0000 C CNN
	1    1900 5800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 58C3403F
P 2000 6050
F 0 "#PWR013" H 2000 5800 50  0001 C CNN
F 1 "GND" H 2000 5900 50  0000 C CNN
F 2 "" H 2000 6050 50  0000 C CNN
F 3 "" H 2000 6050 50  0000 C CNN
	1    2000 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5950 2100 6050
Wire Wire Line
	2100 6050 1900 6050
Wire Wire Line
	1900 6050 1900 5950
Wire Wire Line
	1500 5650 3800 5650
Wire Wire Line
	2800 5650 2800 6000
Connection ~ 2100 5650
Wire Wire Line
	3800 5650 3800 6000
Connection ~ 2800 5650
$Comp
L power:GND #PWR014
U 1 1 58C3404D
P 2800 6500
F 0 "#PWR014" H 2800 6250 50  0001 C CNN
F 1 "GND" H 2800 6350 50  0000 C CNN
F 2 "" H 2800 6500 50  0000 C CNN
F 3 "" H 2800 6500 50  0000 C CNN
	1    2800 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R306
U 1 1 58C34053
P 3950 6250
F 0 "R306" V 4030 6250 50  0000 C CNN
F 1 "10R" V 3950 6250 50  0000 C CNN
F 2 "" V 3880 6250 50  0001 C CNN
F 3 "" H 3950 6250 50  0000 C CNN
	1    3950 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R307
U 1 1 58C3405A
P 3950 6500
F 0 "R307" V 4030 6500 50  0000 C CNN
F 1 "10R" V 3950 6500 50  0000 C CNN
F 2 "" V 3880 6500 50  0001 C CNN
F 3 "" H 3950 6500 50  0000 C CNN
	1    3950 6500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 6250 4100 6500
$Comp
L Device:C C304
U 1 1 58C34062
P 4250 6250
F 0 "C304" H 4275 6350 50  0000 L CNN
F 1 "100n" H 4275 6150 50  0000 L CNN
F 2 "" H 4288 6100 50  0001 C CNN
F 3 "" H 4250 6250 50  0000 C CNN
	1    4250 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Schottky D305
U 1 1 58C34069
P 4600 6400
F 0 "D305" H 4600 6500 50  0000 C CNN
F 1 "0.5V" H 4600 6300 50  0000 C CNN
F 2 "" H 4600 6400 50  0001 C CNN
F 3 "" H 4600 6400 50  0000 C CNN
	1    4600 6400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 58C34070
P 4600 6550
F 0 "#PWR015" H 4600 6300 50  0001 C CNN
F 1 "GND" H 4600 6400 50  0000 C CNN
F 2 "" H 4600 6550 50  0000 C CNN
F 3 "" H 4600 6550 50  0000 C CNN
	1    4600 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6250 4900 6250
Connection ~ 4600 6250
Text GLabel 2800 6250 0    60   Input ~ 0
DLY_OUT
Text GLabel 4900 6250 2    60   Output ~ 0
CLAMP
Connection ~ 1900 5650
Connection ~ 3150 2200
Connection ~ 6100 4050
Connection ~ 2150 1600
$EndSCHEMATC
