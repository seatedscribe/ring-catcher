#ifndef CRINGLOGGER_H
#define CRINGLOGGER_H

#include <iostream>
#include <fstream>

#include "rfm_interface.h"
#include "namespace.h"


using std::string;
using std::ofstream;
using std::cout;
using std::endl;


#define LOG_RING_SIZE 10000


class LoggerBehaviour {
public:
    virtual void store(string msg = "") = 0;
    virtual void dump() = 0;
    virtual ~LoggerBehaviour() {}
};

template <class T, class S>
        class CRingLogger : public LoggerBehaviour {
private:
    T*         m_source;
    T          m_ring[LOG_RING_SIZE];
    static int s_ring_index;
    bool       m_is_ring_full;
    int        m_min_dump_index;
    int        m_max_dump_index;
    ofstream   m_outstream;
    string     m_filename;
    void       updateRingIndex();
    void       updateDumpIndex();
    //a structure-specific class provides dump methods for its (kn)own structure
    S          m_dumper;

public:

    virtual ~CRingLogger();
    //CRingLogger(T *t);
    CRingLogger(T *t, std::string filename);
    //T get(int index = -1);
    T get();
    virtual void store(string msg = "");
    virtual void store(T element);
    void dump();
};

class TEST_STRUCTURE_1_DUMP {
public:
    void dumpHeader(ofstream &m_os);
    void dumpContent(const TEST_STRUCTURE_1_TYPE src, ofstream &m_os, const int id);
};

class TEST_STRUCTURE_2_DUMP {
public:
    void dumpHeader(ofstream &m_os);
    void dumpContent(const TEST_STRUCTURE_2_TYPE src, ofstream &m_os, const int id);
};

#endif // CRINGLOGGER_H
