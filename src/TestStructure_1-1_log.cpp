#include "CRingLogger.h"
#include <iomanip>

namespace TEST_STRUCTURE_1_CHARS {
     std::ostream &operator<<(std::ostream &os, char c) {
          return os << (std::is_signed<char>::value ? static_cast<int>(c)
                        : static_cast<unsigned int>(c));
     }

     std::ostream &operator<<(std::ostream &os, signed char c) {
          return os << static_cast<int>(c);
     }

     std::ostream &operator<<(std::ostream &os, unsigned char c) {
          return os << static_cast<unsigned int>(c);
     }
}

using namespace TEST_STRUCTURE_1_CHARS;

void TEST_STRUCTURE_1_DUMP::dumpHeader(ofstream &m_os) { m_os
    <<"INDEX"
    <<", timetag";
    for (int t1=0; t1<20; t1++) { m_os //struct alpha (cardinality 20)
        <<", alpha["<<t1<<"].tamarillo"
        <<", alpha["<<t1<<"].papaya";
        //struct bravo (cardinality 1)
        for (int t2=0; t2<5; t2++) { m_os //struct charlie (cardinality 5)
            <<", alpha["<<t1<<"].bravo.charlie["<<t2<<"].banana";}
        for (int t2=0; t2<3; t2++) { m_os //struct delta (cardinality 3)
            <<", alpha["<<t1<<"].bravo.delta["<<t2<<"].banana"
            <<", alpha["<<t1<<"].bravo.delta["<<t2<<"].potato";}} m_os
    <<", tomato"
    <<", papaya";
    for (int t1=0; t1<10; t1++) { m_os //struct epsilon (cardinality 10)"
        <<", epsilon["<<t1<<"].report_code"
        <<", epsilon["<<t1<<"].value";} m_os
    <<", performance"<<std::endl;
}


void TEST_STRUCTURE_1_DUMP::dumpContent(const TEST_STRUCTURE_1_TYPE src, ofstream &m_os, const int id) { m_os
    <<id
    <<", " <<src.timetag;
    for (int t1=0; t1<20; t1++) { m_os //struct alpha (cardinality 20)
        <<", "  <<src.alpha[t1].tamarillo
        <<", "  <<src.alpha[t1].papaya;
        //struct bravo (cardinality 1)
        for (int t2=0; t2<5; t2++) { m_os //struct charlie (cardinality 5)
            <<", " <<src.alpha[t1].bravo.charlie[t2].banana;}
        for (int t2=0; t2<3; t2++) { m_os //struct delta (cardinality 3)
            <<", "<<src.alpha[t1].bravo.delta[t2].banana
            <<", "<<src.alpha[t1].bravo.delta[t2].potato;}} m_os
    <<", "<<src.tomato
    <<", "<<src.papaya;
    for (int t1=0; t1<10; t1++) { m_os //struct epsilon (cardinality 10)
        <<", "<<src.epsilon[t1].report_code
        <<", "<<src.epsilon[t1].value;} m_os
    <<", "<<src.performance<<std::endl;
}
