#ifndef TEMPERATURE_H
#define TEMPERATURE_H

// The temperature control dead zone in deg C

#define HALF_DEAD_ZONE 5

// we'll ignore this file unless we are using a thermistor soemwhere? 
#ifdef USE_THERMISTOR

#define NUMTEMPS 20

// for heated beds OR direct PIC temperature control of the extruder without a separate CPU. 
#if ( EXTRUDER_CONTROLLER == EXTRUDER_CONTROLLER_INTERNAL )  || ( EXTRUDER_CONTROLLER == EXTRUDER_CONTROLLER_DC ) 

// This is the extruder thermistor...

// Farnell code for this thermistor: 882-9586
// Made with createTemperatureLookup.py (http://svn.reprap.org/trunk/reprap/firmware/Arduino/utilities/createTemperatureLookup.py)
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4066 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4066
// max adc: 1023

short temptable[NUMTEMPS][2] = {
   {1, 841},
   {54, 255},
   {107, 209},
   {160, 184},
   {213, 166},
   {266, 153},
   {319, 142},
   {372, 132},
   {425, 124},
   {478, 116},
   {531, 108},
   {584, 101},
   {637, 93},
   {690, 86},
   {743, 78},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 3}
};

#endif 


#if HEATED_BED == HEATED_BED_ON 
// ... And this is the heated bed thermistor (if any)
/*
//HSBNE heated bed settings
// using Jaycar 125deg 10k thermistor and 4.7k R
short bedtemptable[NUMTEMPS][2] = {
  {1, 599},
   {40, 130},       //130 0.29 60
   {60, 120},     //120 0.37  81
   {81, 110},    //110 0.51  106
   {106, 100},   //100  0.64  133
   {133, 90},    //90 0.85  177
   {177, 80},   //80 1.13  235
   {235, 70},   //70 1.42  295
   {295, 60},    //60 1.69  346
   {346, 55},   //55 1.82 373
   {373, 50}, //real 
   {309, 45}, //real
   {451, 43},
   {490, 37},
   {637, 31},
   {690, 25},
   {743, 19},
   {796, 12},
   {849, 5},
    {999, 0}
};


#endif
*/
// RS thermistor 484-0149; EPCOS B57550G103J
// Made with createTemperatureLookup.py (http://svn.reprap.org/trunk/reprap/firmware/Arduino/utilities/createTemperatureLookup.py)
// ./createTemperatureLookup.py --r0=10000 --t0=25 --r1=0 --r2=4700 --beta=3480 --max-adc=1023
// r0: 10000
// t0: 25
// r1: 0
// r2: 4700
// beta: 3480
// max adc: 1023

short bedtemptable[NUMTEMPS][2] = {
   {1, 599},
   {54, 160},
   {107, 123},
   {160, 103},
   {213, 90},
   {266, 79},
   {319, 70},
   {372, 62},
   {425, 55},
   {478, 49},
   {531, 43},
   {584, 37},
   {637, 31},
   {690, 25},
   {743, 19},
   {796, 12},
   {849, 5},
   {902, -3},
   {955, -16},
   {1008, -42}
};
#endif
 
/*
 * Other thermistors...
// Thermistor lookup table for RepRap Temperature Sensor Boards 
// See this page:  
// http://dev.www.reprap.org/bin/view/Main/Thermistor
// for details of what goes in this table.

// Farnell code for this thermistor: 882-9586
// Made with createTemperatureLookup.py (http://svn.reprap.org/trunk/reprap/firmware/Arduino/utilities/createTemperatureLookup.py)
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4066 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4066
// max adc: 1023


#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 841},
   {54, 255},
   {107, 209},
   {160, 184},
   {213, 166},
   {266, 153},
   {319, 142},
   {372, 132},
   {425, 124},
   {478, 116},
   {531, 108},
   {584, 101},
   {637, 93},
   {690, 86},
   {743, 78},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 3}
};


 
// RS thermistor 528-8592; EPCOS NTC G540 
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4036 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4036
// max adc: 1023
#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 864},
   {54, 258},
   {107, 211},
   {160, 185},
   {213, 168},
   {266, 154},
   {319, 143},
   {372, 133},
   {425, 125},
   {478, 116},
   {531, 109},
   {584, 101},
   {637, 94},
   {690, 87},
   {743, 79},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 2}
};
 
// Farnell code for this thermistor: 882-9586
// Made with createTemperatureLookup.py (http://svn.reprap.org/trunk/reprap/firmware/Arduino/utilities/createTemperatureLookup.py)
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4066 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4066
// max adc: 1023


#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 841},
   {54, 255},
   {107, 209},
   {160, 184},
   {213, 166},
   {266, 153},
   {319, 142},
   {372, 132},
   {425, 124},
   {478, 116},
   {531, 108},
   {584, 101},
   {637, 93},
   {690, 86},
   {743, 78},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 3}
};

// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4066 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4066
// max adc: 1023
#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 841},
   {54, 255},
   {107, 209},
   {160, 184},
   {213, 166},
   {266, 153},
   {319, 142},
   {372, 132},
   {425, 124},
   {478, 116},
   {531, 108},
   {584, 101},
   {637, 93},
   {690, 86},
   {743, 78},
   {796, 70},
   {849, 61},
   {902, 50},
   {955, 34},
   {1008, 3}
};





// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=3960 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 3960
// max adc: 1023
#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
   {1, 929},
   {54, 266},
   {107, 217},
   {160, 190},
   {213, 172},
   {266, 158},
   {319, 146},
   {372, 136},
   {425, 127},
   {478, 119},
   {531, 111},
   {584, 103},
   {637, 96},
   {690, 88},
   {743, 80},
   {796, 71},
   {849, 62},
   {902, 50},
   {955, 34},
   {1008, 2}
};





// ./createTemperatureLookup.py --r0=10000 --t0=25 --r1=680 --r2=1600 --beta=3964 --max-adc=305
// r0: 10000
// t0: 25
// r1: 680
// r2: 1600
// beta: 3964
// max adc: 305
#define NUMTEMPS 19
short temptable[NUMTEMPS][2] = {
   {1, 601},
   {17, 260},
   {33, 213},
   {49, 187},
   {65, 170},
   {81, 156},
   {97, 144},
   {113, 134},
   {129, 125},
   {145, 117},
   {161, 109},
   {177, 101},
   {193, 94},
   {209, 86},
   {225, 78},
   {241, 69},
   {257, 59},
   {273, 46},
   {289, 28}
};






// ./createTemperatureLookup.py --r0=10000 --t0=25 --r1=680 --r2=1600 --beta=3964 --max-adc=305
// r0: 10000
// t0: 25
// r1: 680
// r2: 1600
// beta: 3964
// max adc: 305
#define NUMTEMPS 19
short temptable[NUMTEMPS][2] = {
   {1, 601},
   {17, 260},
   {33, 213},
   {49, 187},
   {65, 170},
   {81, 156},
   {97, 144},
   {113, 134},
   {129, 125},
   {145, 117},
   {161, 109},
   {177, 101},
   {193, 94},
   {209, 86},
   {225, 78},
   {241, 69},
   {257, 59},
   {273, 46},
   {289, 28}
};



*/

#endif //USE_THERMISTOR

#endif


