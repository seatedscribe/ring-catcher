// Automatically generated. DO NOT MODIFY!
// Memory Area Name: AA_REFERENCE_1 (ver: 1) 
// In memory, this struct is repeated: 1 times. Please code accordingly!

#ifndef __cplusplus
#ifndef bool
#define bool uint32_t
#endif
#endif

#ifndef AA_REFERENCE_1_DEF
#define AA_REFERENCE_1_DEF

#define AA_REFERENCE_1_VERSION 1

#if defined (_MSC_VER) || defined (__MINGW32__)
#define __attribute__(x)
#pragma pack(push)
#pragma pack(1)
#endif

typedef struct __attribute__((packed)) // This struct will be repeated 5 times in memory
{
	// ---> offset: 6
	uint8_t banana; //(req. size: 1) banana - Unit: n/a - min: 0, max: 0, init: 0 - 
} AA_REFERENCE_1_alpha_bravo_charlie_TYPE;
// ---> Struct size is: 1

typedef struct __attribute__((packed)) // This struct will be repeated 3 times in memory
{
	// ---> offset: 11
	uint8_t banana; //(req. size: 1) banana - Unit: n/a - min: 0, max: 0, init: 0 - 
	// ---> offset: 12
    uint8_t potato; //(req. size: 1) potato - Unit: n/a - min: 0, max: 0, init: 0
} AA_REFERENCE_1_alpha_bravo_delta_TYPE;
// ---> Struct size is: 2

typedef struct __attribute__((packed)) // This struct will be repeated 1 times in memory
{
	// ---> offset: 6
	AA_REFERENCE_1_alpha_bravo_charlie_TYPE charlie[5];
	// ---> offset: 11
	AA_REFERENCE_1_alpha_bravo_delta_TYPE delta[3];
} AA_REFERENCE_1_alpha_bravo_TYPE;
// ---> Struct size is: 11

typedef struct __attribute__((packed)) // This struct will be repeated 20 times in memory
{
	// ---> offset: 4
	uint8_t tamarillo; //(req. size: 1) tamarillo - Unit: n/a - min: 0, max: 0, init: 0 - 
	// ---> offset: 5
	uint8_t papaya; //(req. size: 1) papaya - Unit: n/a - min: 0, max: 0, init: 0 - 
	// ---> offset: 6
	AA_REFERENCE_1_alpha_bravo_TYPE bravo;
} AA_REFERENCE_1_alpha_TYPE;
// ---> Struct size is: 13

typedef struct __attribute__((packed)) // This struct will be repeated 10 times in memory
{
	// ---> offset: 269
    uint8_t report_code; //(req. size: 1) report_code - Unit: n/a - min: 0, max: 0, init: 0
	// ---> offset: 270
    double value; //(req. size: 4) value - Unit: n/a - min: 0, max: 0, init: 0
} AA_REFERENCE_1_epsilon_TYPE;
// ---> Struct size is: 5

typedef struct __attribute__((packed)) // This struct will be repeated 1 times in memory
{
	// ---> offset: 0
	uint32_t timetag; //(req. size: 4) timetag - Unit: n/a - min: 0, max: 0, init: 0 - 
	// ---> offset: 4
	AA_REFERENCE_1_alpha_TYPE alpha[20];
	// ---> offset: 264
    uint8_t tomato; //(req. size: 1) tomato - Unit: n/a - min: 0, max: 0, init: 0
	// ---> offset: 265
    double papaya; //(req. size: 4) papaya - Unit: n/a - min: 0, max: 0, init: 0
	// ---> offset: 269
	AA_REFERENCE_1_epsilon_TYPE epsilon[10];
	// ---> offset: 319
    uint8_t performance; //(req. size: 1) performance - Unit: n/a - min: 0, max: 0, init: 0
} TEST_STRUCTURE_1_TYPE;

#define AA_REFERENCE_1_COUNT 1

typedef struct __attribute__((packed)) // This is the top-level struct mapping all repetitions of the memory area
{
    TEST_STRUCTURE_1_TYPE AA_REFERENCE_1[ AA_REFERENCE_1_COUNT ];
} AA_REFERENCE_1_ARRAY;

#if defined (_MSC_VER) || defined (__MINGW32__)
#pragma pack(pop)
#endif

#endif
