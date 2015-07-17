
TARGETDIR = .
TARGET = ring-catcher
CC = g++

USE_RFM = true

CPP_FLAGS +=  -std=c++0x -mcmodel=medium -D_REENTRANT -Wall -Wextra #-Wpedantic

INCLUDE_FLAGS += -Iinclude/
	     
COMPILE.cpp = g++ -c $(CPP_FLAGS) $(INCLUDE_FLAGS) $(EIHS_FLAGS)

DBGTARGET = $(TARGETDIR)/$(TARGET)-dbg
RELTARGET = $(TARGETDIR)/$(TARGET)

DBGCFLAGS = -g -DDEBUG
RELCFLAGS = -O2 -fno-strict-aliasing

CPPSOURCES = $(wildcard ./src/*.cpp)

DBGCPPOBJFILES = $(CPPSOURCES:./src/%.cpp=./obj/debug/%.o)
RELCPPOBJFILES = $(CPPSOURCES:./src/%.cpp=./obj/release/%.o)

#.PHONY: clean Debug Release install

all:	Release Debug

install:
	install -d $(TARGETDIR)
	install $(RELTARGET) $(EXEC_DIR)

Release:	$(RELTARGET)

Debug:		$(DBGTARGET)

$(RELTARGET):	$(RELCPPOBJFILES)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $@ $(RELCPPOBJFILES)

$(DBGTARGET):	$(DBGCPPOBJFILES)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $@ $(DBGCPPOBJFILES)


$(RELCPPOBJFILES):	obj/release/%.o: ./src/%.cpp
	@mkdir -p obj/release
	$(COMPILE.cpp) $(RELCFLAGS) -o $@ $<

$(DBGCPPOBJFILES):	obj/debug/%.o: ./src/%.cpp
	@mkdir -p obj/debug
	$(COMPILE.cpp) $(DBGCFLAGS) -o $@ $<

clean:
	-$(RM) -rf $(DBGTARGET) $(RELTARGET) obj/ bin/ *~ *.d *.csv .dep

