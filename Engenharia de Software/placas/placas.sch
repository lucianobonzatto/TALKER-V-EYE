EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Placas Talker V-Eye"
Date "2022-04-13"
Rev ""
Comp "UTFPR"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:C C?
U 1 1 6257C7E4
P 6450 2500
F 0 "C?" H 6565 2546 50  0000 L CNN
F 1 "680uF" H 6565 2455 50  0000 L CNN
F 2 "" H 6488 2350 50  0001 C CNN
F 3 "~" H 6450 2500 50  0001 C CNN
	1    6450 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Top_Bottom J?
U 1 1 625834DC
P 5250 1950
F 0 "J?" H 5300 2167 50  0000 C CNN
F 1 "bot_obj" H 5300 2076 50  0000 C CNN
F 2 "" H 5250 1950 50  0001 C CNN
F 3 "~" H 5250 1950 50  0001 C CNN
	1    5250 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Top_Bottom J?
U 1 1 62584318
P 5900 1950
F 0 "J?" H 5950 2167 50  0000 C CNN
F 1 "bot_obst" H 5950 2076 50  0000 C CNN
F 2 "" H 5900 1950 50  0001 C CNN
F 3 "~" H 5900 1950 50  0001 C CNN
	1    5900 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Top_Bottom J?
U 1 1 62585616
P 4600 1950
F 0 "J?" H 4650 2167 50  0000 C CNN
F 1 "bot_on/of" H 4650 2076 50  0000 C CNN
F 2 "" H 4600 1950 50  0001 C CNN
F 3 "~" H 4600 1950 50  0001 C CNN
	1    4600 1950
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP2955 Q?
U 1 1 625A0582
P 6100 3650
F 0 "Q?" H 6291 3604 50  0000 L CNN
F 1 "TIP32" H 6291 3695 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-218-3_Vertical" H 6300 3575 50  0001 L CIN
F 3 "" H 6100 3650 50  0001 L CNN
	1    6100 3650
	1    0    0    1   
$EndComp
$Comp
L Isolator:PC817 U?
U 1 1 625A1577
P 5100 3750
F 0 "U?" H 5100 4075 50  0000 C CNN
F 1 "PC817" H 5100 3984 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 4900 3550 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 5100 3750 50  0001 L CNN
	1    5100 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 625A6BA4
P 4550 3650
F 0 "R?" V 4757 3650 50  0000 C CNN
F 1 "910" V 4666 3650 50  0000 C CNN
F 2 "" V 4480 3650 50  0001 C CNN
F 3 "~" H 4550 3650 50  0001 C CNN
	1    4550 3650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 625A70A1
P 5650 3650
F 0 "R?" V 5443 3650 50  0000 C CNN
F 1 "510" V 5534 3650 50  0000 C CNN
F 2 "" V 5580 3650 50  0001 C CNN
F 3 "~" H 5650 3650 50  0001 C CNN
	1    5650 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 3650 4700 3650
Wire Wire Line
	5400 3650 5500 3650
Wire Wire Line
	5800 3650 5900 3650
Wire Wire Line
	5400 3850 5550 3850
Wire Wire Line
	5550 3850 5550 4000
Wire Wire Line
	6200 3450 6200 3350
Wire Wire Line
	4400 3650 3650 3650
Wire Wire Line
	6200 3350 4350 3350
Wire Wire Line
	4350 3350 4350 3550
Wire Wire Line
	5550 4000 7050 4000
Connection ~ 5550 4000
$Comp
L Diode:1N4007 D?
U 1 1 625C52B1
P 7050 3750
F 0 "D?" V 7004 3830 50  0000 L CNN
F 1 "1N4007" V 7095 3830 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7050 3575 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7050 3750 50  0001 C CNN
	1    7050 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 3500 7050 3600
Wire Wire Line
	7050 3900 7050 4000
Wire Wire Line
	6200 3850 6900 3850
Wire Wire Line
	6900 3850 6900 3500
Wire Wire Line
	6900 3500 7050 3500
$Comp
L power:GND #PWR?
U 1 1 625D34EF
P 4800 3850
F 0 "#PWR?" H 4800 3600 50  0001 C CNN
F 1 "GND" H 4805 3677 50  0000 C CNN
F 2 "" H 4800 3850 50  0001 C CNN
F 3 "" H 4800 3850 50  0001 C CNN
	1    4800 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 625D3E2A
P 6450 2650
F 0 "#PWR?" H 6450 2400 50  0001 C CNN
F 1 "GND" H 6455 2477 50  0000 C CNN
F 2 "" H 6450 2650 50  0001 C CNN
F 3 "" H 6450 2650 50  0001 C CNN
	1    6450 2650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 625D56F1
P 6450 2350
F 0 "#PWR?" H 6450 2200 50  0001 C CNN
F 1 "VCC" H 6465 2523 50  0000 C CNN
F 2 "" H 6450 2350 50  0001 C CNN
F 3 "" H 6450 2350 50  0001 C CNN
	1    6450 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 625D2582
P 4150 3250
F 0 "#PWR?" H 4150 3000 50  0001 C CNN
F 1 "GND" H 4155 3077 50  0000 C CNN
F 2 "" H 4150 3250 50  0001 C CNN
F 3 "" H 4150 3250 50  0001 C CNN
	1    4150 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3550 4350 3550
Wire Wire Line
	3650 3450 4300 3450
Wire Wire Line
	4300 3450 4300 3100
Wire Wire Line
	4350 3750 4350 4000
Wire Wire Line
	4350 4000 5550 4000
Wire Wire Line
	3650 3750 4350 3750
Wire Wire Line
	3650 3250 4150 3250
$Comp
L power:GND #PWR?
U 1 1 625ED3CA
P 4850 2400
F 0 "#PWR?" H 4850 2150 50  0001 C CNN
F 1 "GND" H 4855 2227 50  0000 C CNN
F 2 "" H 4850 2400 50  0001 C CNN
F 3 "" H 4850 2400 50  0001 C CNN
	1    4850 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2350 4850 2350
Wire Wire Line
	4850 2350 4850 2400
Wire Wire Line
	4900 1900 4900 1950
$Comp
L Connector:Conn_01x11_Male J?
U 1 1 625F113A
P 3450 3250
F 0 "J?" H 3558 3931 50  0000 C CNN
F 1 "entrada de sinais" H 3558 3840 50  0000 C CNN
F 2 "" H 3450 3250 50  0001 C CNN
F 3 "~" H 3450 3250 50  0001 C CNN
	1    3450 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 625FA7F6
P 4050 3050
F 0 "#PWR?" H 4050 2900 50  0001 C CNN
F 1 "+3.3V" H 4065 3223 50  0000 C CNN
F 2 "" H 4050 3050 50  0001 C CNN
F 3 "" H 4050 3050 50  0001 C CNN
	1    4050 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3050 3650 3050
$Comp
L power:+3.3V #PWR?
U 1 1 625FCFEA
P 4900 1900
F 0 "#PWR?" H 4900 1750 50  0001 C CNN
F 1 "+3.3V" H 4915 2073 50  0000 C CNN
F 2 "" H 4900 1900 50  0001 C CNN
F 3 "" H 4900 1900 50  0001 C CNN
	1    4900 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3350 4250 3350
Wire Wire Line
	3650 3150 4150 3150
$Comp
L power:+5V #PWR?
U 1 1 625F5F3D
P 4150 3150
F 0 "#PWR?" H 4150 3000 50  0001 C CNN
F 1 "+5V" H 4165 3323 50  0000 C CNN
F 2 "" H 4150 3150 50  0001 C CNN
F 3 "" H 4150 3150 50  0001 C CNN
	1    4150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3350 4250 3000
$Comp
L Device:R R?
U 1 1 625EC21B
P 4650 2350
F 0 "R?" V 4443 2350 50  0000 C CNN
F 1 "1k" V 4534 2350 50  0000 C CNN
F 2 "" V 4580 2350 50  0001 C CNN
F 3 "~" H 4650 2350 50  0001 C CNN
	1    4650 2350
	0    -1   1    0   
$EndComp
Wire Wire Line
	4400 2350 4500 2350
Wire Wire Line
	4400 2050 4400 2350
$Comp
L power:GND #PWR?
U 1 1 626061A6
P 5500 2400
F 0 "#PWR?" H 5500 2150 50  0001 C CNN
F 1 "GND" H 5505 2227 50  0000 C CNN
F 2 "" H 5500 2400 50  0001 C CNN
F 3 "" H 5500 2400 50  0001 C CNN
	1    5500 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2350 5500 2350
Wire Wire Line
	5500 2350 5500 2400
$Comp
L Device:R R?
U 1 1 626061AE
P 5300 2350
F 0 "R?" V 5093 2350 50  0000 C CNN
F 1 "1k" V 5184 2350 50  0000 C CNN
F 2 "" V 5230 2350 50  0001 C CNN
F 3 "~" H 5300 2350 50  0001 C CNN
	1    5300 2350
	0    -1   1    0   
$EndComp
Wire Wire Line
	5050 2350 5150 2350
Wire Wire Line
	5050 2050 5050 2350
$Comp
L power:GND #PWR?
U 1 1 626079EC
P 6150 2400
F 0 "#PWR?" H 6150 2150 50  0001 C CNN
F 1 "GND" H 6155 2227 50  0000 C CNN
F 2 "" H 6150 2400 50  0001 C CNN
F 3 "" H 6150 2400 50  0001 C CNN
	1    6150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2350 6150 2350
Wire Wire Line
	6150 2350 6150 2400
$Comp
L Device:R R?
U 1 1 626079F4
P 5950 2350
F 0 "R?" V 5743 2350 50  0000 C CNN
F 1 "1k" V 5834 2350 50  0000 C CNN
F 2 "" V 5880 2350 50  0001 C CNN
F 3 "~" H 5950 2350 50  0001 C CNN
	1    5950 2350
	0    -1   1    0   
$EndComp
Wire Wire Line
	5700 2350 5800 2350
Wire Wire Line
	5700 2050 5700 2350
$Comp
L power:+3.3V #PWR?
U 1 1 62608961
P 5550 1900
F 0 "#PWR?" H 5550 1750 50  0001 C CNN
F 1 "+3.3V" H 5565 2073 50  0000 C CNN
F 2 "" H 5550 1900 50  0001 C CNN
F 3 "" H 5550 1900 50  0001 C CNN
	1    5550 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 62609568
P 6200 1900
F 0 "#PWR?" H 6200 1750 50  0001 C CNN
F 1 "+3.3V" H 6215 2073 50  0000 C CNN
F 2 "" H 6200 1900 50  0001 C CNN
F 3 "" H 6200 1900 50  0001 C CNN
	1    6200 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1900 6200 1950
Wire Wire Line
	5550 1900 5550 1950
Wire Wire Line
	3650 2950 3950 2950
Wire Wire Line
	3950 2950 3950 2800
Connection ~ 5700 2350
Wire Wire Line
	3650 2850 3900 2850
Connection ~ 5050 2350
Connection ~ 4400 2350
Wire Wire Line
	4400 2350 4400 2700
Wire Wire Line
	5050 2350 5050 2750
Wire Wire Line
	5700 2350 5700 2800
Wire Wire Line
	3950 2800 5700 2800
Wire Wire Line
	3900 2750 3900 2850
Wire Wire Line
	3900 2750 5050 2750
Wire Wire Line
	4400 2700 3850 2700
Wire Wire Line
	3850 2700 3850 2750
Wire Wire Line
	3850 2750 3650 2750
$Comp
L Motor:Motor_DC_ALT M?
U 1 1 62649DFF
P 7250 5400
F 0 "M?" V 7534 5350 50  0000 C CNN
F 1 "Motor_vib" V 7443 5350 50  0000 C CNN
F 2 "" H 7250 5310 50  0001 C CNN
F 3 "~" H 7250 5310 50  0001 C CNN
	1    7250 5400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP2955 Q?
U 1 1 62649E05
P 5800 5350
F 0 "Q?" H 5991 5304 50  0000 L CNN
F 1 "TIP32" H 5991 5395 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-218-3_Vertical" H 6000 5275 50  0001 L CIN
F 3 "" H 5800 5350 50  0001 L CNN
	1    5800 5350
	1    0    0    1   
$EndComp
$Comp
L Isolator:PC817 U?
U 1 1 62649E0B
P 4800 5450
F 0 "U?" H 4800 5775 50  0000 C CNN
F 1 "PC817" H 4800 5684 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 4600 5250 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 4800 5450 50  0001 L CNN
	1    4800 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62649E11
P 4250 5350
F 0 "R?" V 4457 5350 50  0000 C CNN
F 1 "910" V 4366 5350 50  0000 C CNN
F 2 "" V 4180 5350 50  0001 C CNN
F 3 "~" H 4250 5350 50  0001 C CNN
	1    4250 5350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 62649E17
P 5350 5350
F 0 "R?" V 5143 5350 50  0000 C CNN
F 1 "510" V 5234 5350 50  0000 C CNN
F 2 "" V 5280 5350 50  0001 C CNN
F 3 "~" H 5350 5350 50  0001 C CNN
	1    5350 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 5350 4400 5350
Wire Wire Line
	5100 5350 5200 5350
Wire Wire Line
	5500 5350 5600 5350
Wire Wire Line
	5100 5550 5250 5550
Wire Wire Line
	5250 5550 5250 5700
Wire Wire Line
	5900 5150 5900 5050
Wire Wire Line
	5900 5050 4050 5050
Wire Wire Line
	4050 5050 4050 5250
Wire Wire Line
	5250 5700 6750 5700
Connection ~ 5250 5700
$Comp
L Diode:1N4007 D?
U 1 1 62649E28
P 6750 5450
F 0 "D?" V 6704 5530 50  0000 L CNN
F 1 "1N4007" V 6795 5530 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 6750 5275 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 6750 5450 50  0001 C CNN
	1    6750 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	6750 5200 6750 5300
Wire Wire Line
	6750 5200 7250 5200
Wire Wire Line
	6750 5600 6750 5700
Connection ~ 6750 5700
Wire Wire Line
	6750 5700 7250 5700
Wire Wire Line
	5900 5550 6600 5550
Wire Wire Line
	6600 5550 6600 5200
Wire Wire Line
	6600 5200 6750 5200
Connection ~ 6750 5200
$Comp
L power:GND #PWR?
U 1 1 62649E37
P 4500 5550
F 0 "#PWR?" H 4500 5300 50  0001 C CNN
F 1 "GND" H 4505 5377 50  0000 C CNN
F 2 "" H 4500 5550 50  0001 C CNN
F 3 "" H 4500 5550 50  0001 C CNN
	1    4500 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5450 4050 5700
Wire Wire Line
	4050 5700 5250 5700
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 6264C293
P 3500 5350
F 0 "J?" H 3608 5631 50  0000 C CNN
F 1 "entrada" H 3608 5540 50  0000 C CNN
F 2 "" H 3500 5350 50  0001 C CNN
F 3 "~" H 3500 5350 50  0001 C CNN
	1    3500 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5250 3700 5250
Wire Wire Line
	3700 5350 4100 5350
Wire Wire Line
	4050 5450 3700 5450
$Comp
L Connector:Conn_01x06_Male J?
U 1 1 62575EDF
P 7350 3000
F 0 "J?" H 7322 2882 50  0000 R CNN
F 1 "con_lidar" H 7322 2973 50  0000 R CNN
F 2 "" H 7350 3000 50  0001 C CNN
F 3 "~" H 7350 3000 50  0001 C CNN
	1    7350 3000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 625D99FC
P 7050 3200
F 0 "#PWR?" H 7050 2950 50  0001 C CNN
F 1 "GND" H 7055 3027 50  0000 C CNN
F 2 "" H 7050 3200 50  0001 C CNN
F 3 "" H 7050 3200 50  0001 C CNN
	1    7050 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3200 7150 3200
$Comp
L power:+5VD #PWR?
U 1 1 625F768F
P 7050 2700
F 0 "#PWR?" H 7050 2550 50  0001 C CNN
F 1 "+5VD" H 7065 2873 50  0000 C CNN
F 2 "" H 7050 2700 50  0001 C CNN
F 3 "" H 7050 2700 50  0001 C CNN
	1    7050 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2700 7050 2700
Wire Wire Line
	7150 3100 4300 3100
Wire Wire Line
	4250 3000 7150 3000
Connection ~ 7050 4000
Connection ~ 7050 3500
Wire Wire Line
	7050 4000 8050 4000
Wire Wire Line
	7050 3500 8050 3500
$Comp
L Motor:Motor_DC_ALT M?
U 1 1 62580356
P 8050 3700
F 0 "M?" V 8334 3650 50  0000 C CNN
F 1 "Motor_vib" V 8243 3650 50  0000 C CNN
F 2 "" H 8050 3610 50  0001 C CNN
F 3 "~" H 8050 3610 50  0001 C CNN
	1    8050 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC