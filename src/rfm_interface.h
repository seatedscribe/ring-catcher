#ifndef RFM_INTERFACE_H
#define RFM_INTERFACE_H

#include <stdint.h>
#include "namespace.h"
#include "TestStructure_1.h"
#include "TestStructure_2.h"

typedef struct
{
    TEST_STRUCTURE_1_TYPE aa_reference_1;
    TEST_STRUCTURE_2_TYPE bb_reference_1;
    //[...cut...]
} t_input;


typedef struct
{
//[...cut...]
} t_output;


typedef struct
{
    t_input  structInput;
    t_output structOutput;
} RFM_IF;

#endif
