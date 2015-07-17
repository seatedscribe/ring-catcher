#include <cstdlib>
#include <signal.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#include "rfm_interface.h"
#include "namespace.h"
#include "CRingLogger.h"

/*#include "CTestSM.h"
#include "CStateMachine.h"
*/

//using namespace FSM;

RFM_IF shared_area;
CRingLogger<TEST_STRUCTURE_1_TYPE, TEST_STRUCTURE_1_DUMP> logReference1(&shared_area.structInput.aa_reference_1, "test_output_1.csv");
CRingLogger<TEST_STRUCTURE_2_TYPE, TEST_STRUCTURE_2_DUMP> logReference2(&shared_area.structInput.bb_reference_1, "test_output_2.csv");
//Machine fsm(&shared_area, &mm_area);


void interrupt_handler(int s) {
    printf("Caught signal %d\n",s);
    //actual file write
    logReference1.dump();
    logReference2.dump();
    exit(EXIT_SUCCESS);
}

int main() {
    long long int loop = 0;

    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = interrupt_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    memset(&shared_area.structInput.aa_reference_1, 0, sizeof(TEST_STRUCTURE_1_TYPE));
    shared_area.structInput.aa_reference_1.papaya = 0.07;


    while(1)
    {
        //operations on struct variables (read inputs/process/write outputs)
        shared_area.structInput.aa_reference_1.timetag = loop++;
        shared_area.structInput.bb_reference_1.timetag = loop++;
        for (int i=0; i<10; i++) {
            shared_area.structInput.aa_reference_1.epsilon[i].value = loop*(M_PI/4 + i/M_PI/(i+0.0465*M_PI));
        }
        //[...]

        logReference1.store();
        logReference2.store();
        usleep(200);
    }
    return EXIT_SUCCESS;
}

