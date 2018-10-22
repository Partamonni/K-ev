EESchema Schematic File Version 4
LIBS:12vstepdown-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Regulator_Switching:LM5017MR U1
U 1 1 5BBC5F88
P 2600 2600
F 0 "U1" H 2600 3067 50  0000 C CNN
F 1 "LM5017MR" H 2600 2976 50  0000 C CNN
F 2 "Package_SO:SOIC-8-1EP_3.9x4.9mm_P1.27mm_EP2.35x2.35mm" H 2650 2150 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm5017.pdf" H 2600 2600 50  0001 C CNN
	1    2600 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+VDC #PWR02
U 1 1 5BBC604B
P 900 2050
F 0 "#PWR02" H 900 1950 50  0001 C CNN
F 1 "+VDC" H 900 2325 50  0000 C CNN
F 2 "" H 900 2050 50  0001 C CNN
F 3 "" H 900 2050 50  0001 C CNN
	1    900  2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2300 2200 2400
$Comp
L Device:R R2
U 1 1 5BBC6086
P 1750 2500
F 0 "R2" V 1650 2650 50  0000 C CNN
F 1 "562K" V 1650 2450 50  0000 C CNN
F 2 "" V 1680 2500 50  0001 C CNN
F 3 "~" H 1750 2500 50  0001 C CNN
	1    1750 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5BBC60DC
P 1350 2550
F 0 "R1" H 1420 2596 50  0000 L CNN
F 1 "16K" H 1420 2505 50  0000 L CNN
F 2 "" V 1280 2550 50  0001 C CNN
F 3 "~" H 1350 2550 50  0001 C CNN
	1    1350 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5BBC616F
P 900 2550
F 0 "C1" H 1015 2596 50  0000 L CNN
F 1 "1uF" H 1015 2505 50  0000 L CNN
F 2 "" H 938 2400 50  0001 C CNN
F 3 "~" H 900 2550 50  0001 C CNN
	1    900  2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5BBC61BB
P 3400 2350
F 0 "C3" H 3515 2396 50  0000 L CNN
F 1 "10nF" H 3515 2305 50  0000 L CNN
F 2 "" H 3438 2200 50  0001 C CNN
F 3 "~" H 3400 2350 50  0001 C CNN
	1    3400 2350
	-1   0    0    1   
$EndComp
$Comp
L Device:L L1
U 1 1 5BBC622A
P 3750 2500
F 0 "L1" V 3572 2500 50  0000 C CNN
F 1 "560uH" V 3663 2500 50  0000 C CNN
F 2 "" H 3750 2500 50  0001 C CNN
F 3 "~" H 3750 2500 50  0001 C CNN
	1    3750 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5BBC639A
P 4400 2650
F 0 "R3" H 4330 2604 50  0000 R CNN
F 1 "10K" H 4330 2695 50  0000 R CNN
F 2 "" V 4330 2650 50  0001 C CNN
F 3 "~" H 4400 2650 50  0001 C CNN
	1    4400 2650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R4
U 1 1 5BBC6425
P 4400 3050
F 0 "R4" H 4330 3004 50  0000 R CNN
F 1 "1.2K" H 4330 3095 50  0000 R CNN
F 2 "" V 4330 3050 50  0001 C CNN
F 3 "~" H 4400 3050 50  0001 C CNN
	1    4400 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C5
U 1 1 5BBC6459
P 4850 2650
F 0 "C5" H 4965 2696 50  0000 L CNN
F 1 "22uF" H 4965 2605 50  0000 L CNN
F 2 "" H 4888 2500 50  0001 C CNN
F 3 "~" H 4850 2650 50  0001 C CNN
	1    4850 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2300 900  2400
Wire Wire Line
	1350 2400 1350 2300
Connection ~ 1350 2300
Wire Wire Line
	1350 2300 1600 2300
Wire Wire Line
	1350 2700 2200 2700
Wire Wire Line
	2200 2500 1900 2500
Wire Wire Line
	1600 2500 1600 2300
Connection ~ 1600 2300
Wire Wire Line
	1600 2300 2200 2300
Wire Wire Line
	2500 3100 2550 3100
Wire Wire Line
	2550 3100 2550 3350
Connection ~ 2550 3100
Wire Wire Line
	2550 3100 2600 3100
Wire Wire Line
	3000 2400 3000 2200
Wire Wire Line
	3000 2200 3400 2200
Wire Wire Line
	3900 2500 4000 2500
Wire Wire Line
	4400 2900 4400 2850
Wire Wire Line
	4400 2850 4000 2850
Wire Wire Line
	3400 2850 3400 2700
Wire Wire Line
	3400 2700 3000 2700
Connection ~ 4400 2850
Wire Wire Line
	4400 2850 4400 2800
Wire Wire Line
	4850 3200 4500 3200
Wire Wire Line
	4500 3200 4500 3350
Connection ~ 4500 3200
Wire Wire Line
	4500 3200 4400 3200
$Comp
L power:Earth #PWR01
U 1 1 5BBC7284
P 900 2750
F 0 "#PWR01" H 900 2500 50  0001 C CNN
F 1 "Earth" H 900 2600 50  0001 C CNN
F 2 "" H 900 2750 50  0001 C CNN
F 3 "~" H 900 2750 50  0001 C CNN
	1    900  2750
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR04
U 1 1 5BBC72AA
P 2550 3350
F 0 "#PWR04" H 2550 3100 50  0001 C CNN
F 1 "Earth" H 2550 3200 50  0001 C CNN
F 2 "" H 2550 3350 50  0001 C CNN
F 3 "~" H 2550 3350 50  0001 C CNN
	1    2550 3350
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR06
U 1 1 5BBC72C9
P 4500 3350
F 0 "#PWR06" H 4500 3100 50  0001 C CNN
F 1 "Earth" H 4500 3200 50  0001 C CNN
F 2 "" H 4500 3350 50  0001 C CNN
F 3 "~" H 4500 3350 50  0001 C CNN
	1    4500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2700 900  2750
$Comp
L Device:C C2
U 1 1 5BBC77FD
P 3000 3150
F 0 "C2" H 3115 3196 50  0000 L CNN
F 1 "1uF" H 3115 3105 50  0000 L CNN
F 2 "" H 3038 3000 50  0001 C CNN
F 3 "~" H 3000 3150 50  0001 C CNN
	1    3000 3150
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR05
U 1 1 5BBC7865
P 3000 3350
F 0 "#PWR05" H 3000 3100 50  0001 C CNN
F 1 "Earth" H 3000 3200 50  0001 C CNN
F 2 "" H 3000 3350 50  0001 C CNN
F 3 "~" H 3000 3350 50  0001 C CNN
	1    3000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3300 3000 3350
Wire Wire Line
	3000 3000 3000 2900
$Comp
L Device:R R5
U 1 1 5BBD72FE
P 4850 3050
F 0 "R5" H 4780 3004 50  0000 R CNN
F 1 "0.5R" H 4780 3095 50  0000 R CNN
F 2 "" V 4780 3050 50  0001 C CNN
F 3 "~" H 4850 3050 50  0001 C CNN
	1    4850 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4850 2800 4850 2900
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5BBD8743
P 1750 1250
F 0 "J1" H 1856 1528 50  0000 C CNN
F 1 "Fan conn" H 1856 1437 50  0000 C CNN
F 2 "" H 1750 1250 50  0001 C CNN
F 3 "~" H 1750 1250 50  0001 C CNN
	1    1750 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1150 2200 1150
Wire Wire Line
	2200 1150 2200 1100
$Comp
L power:Earth #PWR03
U 1 1 5BBD8B49
P 2200 1100
F 0 "#PWR03" H 2200 850 50  0001 C CNN
F 1 "Earth" H 2200 950 50  0001 C CNN
F 2 "" H 2200 1100 50  0001 C CNN
F 3 "~" H 2200 1100 50  0001 C CNN
	1    2200 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	1950 1250 4850 1250
Wire Wire Line
	4850 1250 4850 2500
NoConn ~ 1950 1350
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 5BBD964C
P 2350 1450
F 0 "J2" H 2378 1476 50  0000 L CNN
F 1 "PWM conn" H 2378 1385 50  0000 L CNN
F 2 "" H 2350 1450 50  0001 C CNN
F 3 "~" H 2350 1450 50  0001 C CNN
	1    2350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1450 1950 1450
$Comp
L Device:C C4
U 1 1 5BBD9E98
P 4000 2650
F 0 "C4" H 4115 2696 50  0000 L CNN
F 1 "10nF" H 4115 2605 50  0000 L CNN
F 2 "" H 4038 2500 50  0001 C CNN
F 3 "~" H 4000 2650 50  0001 C CNN
	1    4000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2800 4000 2850
Connection ~ 4000 2850
Wire Wire Line
	4000 2850 3400 2850
Connection ~ 4400 2500
Connection ~ 4850 2500
Wire Wire Line
	4400 2500 4850 2500
Wire Wire Line
	3000 2500 3400 2500
Connection ~ 3400 2500
Wire Wire Line
	3400 2500 3600 2500
Connection ~ 4000 2500
Wire Wire Line
	4000 2500 4400 2500
Wire Wire Line
	900  2300 1350 2300
Wire Wire Line
	900  2050 900  2300
Connection ~ 900  2300
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 5BC21811
P 6700 1900
F 0 "J3" V 6760 1940 50  0000 L CNN
F 1 "µC gate output" H 6700 1800 50  0000 L CNN
F 2 "" H 6700 1900 50  0001 C CNN
F 3 "~" H 6700 1900 50  0001 C CNN
	1    6700 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 5BC2192E
P 7900 850
F 0 "J4" V 7960 890 50  0000 L CNN
F 1 "CELL+" H 7750 700 50  0000 L CNN
F 2 "" H 7900 850 50  0001 C CNN
F 3 "~" H 7900 850 50  0001 C CNN
	1    7900 850 
	0    1    1    0   
$EndComp
$Comp
L Device:Q_NMOS_DGS Q1
U 1 1 5BC219C1
P 7800 1900
F 0 "Q1" H 8005 1946 50  0000 L CNN
F 1 "IRLB3034PBF" H 8005 1855 50  0000 L CNN
F 2 "" H 8000 2000 50  0001 C CNN
F 3 "~" H 7800 1900 50  0001 C CNN
	1    7800 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5BC22CC9
P 7900 1500
F 0 "R7" H 7970 1546 50  0000 L CNN
F 1 "500m" H 7970 1455 50  0000 L CNN
F 2 "" V 7830 1500 50  0001 C CNN
F 3 "~" H 7900 1500 50  0001 C CNN
	1    7900 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1050 7900 1150
Wire Wire Line
	7900 1650 7900 1700
$Comp
L power:GND #PWR07
U 1 1 5BC24028
P 7900 2200
F 0 "#PWR07" H 7900 1950 50  0001 C CNN
F 1 "GND" H 7905 2027 50  0000 C CNN
F 2 "" H 7900 2200 50  0001 C CNN
F 3 "" H 7900 2200 50  0001 C CNN
	1    7900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2100 7900 2200
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 5BC2473D
P 8300 1150
F 0 "J5" V 8360 1190 50  0000 L CNN
F 1 "µC voltage measure" H 7800 1050 50  0000 L CNN
F 2 "" H 8300 1150 50  0001 C CNN
F 3 "~" H 8300 1150 50  0001 C CNN
	1    8300 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 1150 7900 1150
Connection ~ 7900 1150
Wire Wire Line
	7900 1150 7900 1350
$Comp
L Device:R R6
U 1 1 5BC257CA
P 7250 1900
F 0 "R6" V 7043 1900 50  0000 C CNN
F 1 "100R" V 7134 1900 50  0000 C CNN
F 2 "" V 7180 1900 50  0001 C CNN
F 3 "~" H 7250 1900 50  0001 C CNN
	1    7250 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 1900 7600 1900
Wire Wire Line
	7100 1900 6900 1900
$EndSCHEMATC
