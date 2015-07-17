#include <cstring>
#include <stdexcept>

#include "CRingLogger.h"


/***************************************************************************/
template <class T, class S> int CRingLogger<T, S>::s_ring_index = -1;

template <class T, class S>
CRingLogger<T, S>::CRingLogger(T *t, std::string filename):
    m_source(t),
    m_is_ring_full(false),
    m_min_dump_index(0),
    m_max_dump_index(0),
    m_outstream(filename.c_str()),
    m_filename(filename.c_str())
{
     if (not m_outstream.is_open()) {
          std::string s("\""); s+=m_filename; s+="\"";
          throw std::runtime_error("CRingLogger: unable to open file "+s);
     }
    std::cout<<"Created logger with output to file: "<<m_filename<<std::endl;
}

template <class T, class S>
T CRingLogger<T, S>::get() {
    if (-1 == s_ring_index) {
        std::cout<<"CRingLogger: cannot get() from an empty buffer!"<<std::endl;
        return T();
    }
    return(m_ring[s_ring_index]);
}

template <class T, class S>
void CRingLogger<T, S>::store(T element) {
     updateRingIndex();
     m_ring[s_ring_index] = element;
//     std::cout<<"-------------> appended at "<<s_ring_index<<std::endl;
}

template <class T, class S>
void CRingLogger<T, S>::store(string msg) {
     updateRingIndex();
     if (not msg.empty())
    	 std::cout<<msg<<" - s_ring_index: "<<s_ring_index<<std::endl;
     memcpy((void*)&(m_ring[s_ring_index]), (void*)(this->m_source), sizeof(T));
}

template <class T, class S>
void CRingLogger<T, S>::dump() {
     updateDumpIndex();
     m_dumper.dumpHeader(m_outstream);

     int j, k, id=0;
     std::cout<<"Writing log to file "<<m_filename<<"... \n";
     for (k=m_min_dump_index; k<m_max_dump_index; k++, id++) {
          j=k%LOG_RING_SIZE;
          std::cout<<"dump j: "<<j<<" id: "<<id<<"\n";
          m_dumper.dumpContent(m_ring[j], m_outstream, id);
     }
     std::cout<<"done"<<std::endl;
}

template <class T, class S>
void CRingLogger<T, S>::updateRingIndex() {
    ++s_ring_index;
    s_ring_index = s_ring_index%LOG_RING_SIZE;
    if (((LOG_RING_SIZE-1) == s_ring_index) && !m_is_ring_full) {
        m_is_ring_full = true;
        std::cout<<"ring FULL!"<<std::endl;
    }
}

template <class T, class S>
void CRingLogger<T, S>::updateDumpIndex() {
     if (m_is_ring_full) {
          m_min_dump_index = s_ring_index+1;
          m_max_dump_index = LOG_RING_SIZE+m_min_dump_index;
     }
     else {
          m_min_dump_index = 0;
          m_max_dump_index = s_ring_index;
     }
     std::cout<<"dump index [m,M]: "<<m_min_dump_index<<" "<<m_max_dump_index<<std::endl;
}

template <class T, class S>
CRingLogger<T, S>::~CRingLogger() {
     m_outstream.close();
}

/* DECLARATION OF CLASSES USED, SO AS TO GET THE COMPILER PRODUCING ACTUAL CODE */
template class CRingLogger<TEST_STRUCTURE_1_TYPE, TEST_STRUCTURE_1_DUMP>;
template class CRingLogger<TEST_STRUCTURE_2_TYPE, TEST_STRUCTURE_2_DUMP>;

