#include "CRingLogger.h"
#include <iomanip>

namespace TEST_STRUCTURE_2_CHARS {
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

using namespace TEST_STRUCTURE_2_CHARS;

void TEST_STRUCTURE_2_DUMP::dumpHeader(ofstream &m_os) { m_os
    <<"INDEX"
    <<", timetag"
    <<", kayak"
    <<", hovercraft";
    for (int t1=0; t1<2; t1++) { m_os //struct epsilon (cardinality 2)
        <<", epsilon["<<t1<<"].report_code"
        <<", epsilon["<<t1<<"].value";} m_os
    <<", performance"<<std::endl;
}


void TEST_STRUCTURE_2_DUMP::dumpContent(const TEST_STRUCTURE_2_TYPE src, ofstream &m_os, const int id) { m_os
    <<id
    <<", " <<src.timetag
    <<", " <<src.kayak
    <<", " <<src.hovercraft;
    for (int t1=0; t1<2; t1++) { m_os //struct epsilon (cardinality 2)
        <<", "<<src.epsilon[t1].report_code
        <<", "<<src.epsilon[t1].value;} m_os
    <<", "<<src.performance<<std::endl;
}
