// Automatically generated. DO NOT MODIFY!
// Memory Area Name: BB_REFERENCE_1 (ver: 1)
// In memory, this struct is repeated: 1 times. Please code accordingly!

#ifndef __cplusplus
#ifndef bool
#define bool uint32_t
#endif
#endif

#ifndef BB_REFERENCE_2_DEF
#define BB_REFERENCE_2_DEF

#define BB_REFERENCE_2_VERSION 1

#if defined (_MSC_VER) || defined (__MINGW32__)
#define __attribute__(x)
#pragma pack(push)
#pragma pack(1)
#endif

typedef struct __attribute__((packed)) // This struct will be repeated 10 times in memory
{
	// ---> offset: 269
    uint8_t report_code; //(req. size: 1) report_code - Unit: n/a - min: 0, max: 0, init: 0
	// ---> offset: 270
    double value; //(req. size: 4) value - Unit: n/a - min: 0, max: 0, init: 0
} BB_REFERENCE_1_epsilon_TYPE;
// ---> Struct size is: 5

typedef struct __attribute__((packed)) // This struct will be repeated 1 times in memory
{
	// ---> offset: 0
	uint32_t timetag; //(req. size: 4) timetag - Unit: n/a - min: 0, max: 0, init: 0 - 
	// ---> offset: 4
    uint8_t kayak; //(req. size: 1) tomato - Unit: n/a - min: 0, max: 0, init: 0
    // ---> offset: 5
    double hovercraft; //(req. size: 4) papaya - Unit: n/a - min: 0, max: 0, init: 0
	// ---> offset: 269
    BB_REFERENCE_1_epsilon_TYPE epsilon[2];
	// ---> offset: 319
    uint8_t performance; //(req. size: 1) performance - Unit: n/a - min: 0, max: 0, init: 0
} TEST_STRUCTURE_2_TYPE;


#define BB_REFERENCE_1_COUNT 1

typedef struct __attribute__((packed)) // This is the top-level struct mapping all repetitions of the memory area
{
    TEST_STRUCTURE_2_TYPE BB_REFERENCE_1[ BB_REFERENCE_1_COUNT ];
} BB_REFERENCE_1_ARRAY;

#if defined (_MSC_VER) || defined (__MINGW32__)
#pragma pack(pop)
#endif

#endif
