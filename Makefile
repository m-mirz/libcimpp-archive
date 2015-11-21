# This is the makefile for the redland examples

# Linux
ifeq ($(SYSTEM),linux)
	# Set Compiler
	CC = gcc++
endif
# Mac OS X
ifeq ($(SYSTEM),osx)
	# Set Compiler
	CC = clang++

        # Include directories
        INCDIR = \
        -I/usr/local/Cellar/libxml++/2.40.0/include/libxml++-2.6 \
        -I/usr/local/Cellar/libxml++/2.40.0/lib/libxml++-2.6/include \
        -I/usr/local/Cellar/glibmm/2.46.1/include/glibmm-2.4 \
        -I/usr/local/Cellar/glibmm/2.46.1/lib/glibmm-2.4/include \
        -I/usr/local/Cellar/glib/2.46.1/include/glib-2.0 \
        -I/usr/local/Cellar/glib/2.46.1/lib/glib-2.0/include \
        -I/usr/local/opt/gettext/include \
        -I/usr/local/Cellar/libsigc++/2.6.1/include/sigc++-2.0 \
        -I/usr/local/Cellar/libsigc++/2.6.1/lib/sigc++-2.0/include \
        -I/usr/include/libxml2

        # Library directories
        LIBDIR = \
        -L/usr/local/Cellar/libxml++/2.40.0/lib \
        -L/usr/local/Cellar/glibmm/2.46.1/lib \
        -L/usr/local/Cellar/glib/2.46.1/lib \
        -L/usr/local/opt/gettext/lib \
        -L/usr/local/Cellar/libsigc++/2.6.1/lib
endif

CFLAGS = -Wall -Wno-inconsistent-missing-override -g -std=c++11
LDFLAGS = \
        -lxml++-2.6 \
        -lxml2 \
        -lglibmm-2.4 \
        -lgobject-2.0 \
        -lglib-2.0 \
        -lintl \
        -lsigc-2.0

# Project Name
PROJECT_NAME = Cim2Obj

# Directories
PROJDIR = ./
SRCDIR = $(PROJDIR)/src
OBJDIR = $(PROJDIR)/obj
BINDIR = $(PROJDIR)/build
DOCDIR = $(PROJDIR)/documentation

OBJ = $(OBJDIR)/main.o $(OBJDIR)/task.o $(OBJDIR)/myparser.o $(OBJDIR)/commchannel.o $(OBJDIR)/DSLModem.o $(OBJDIR)/LTEModem.o $(OBJDIR)/Modem.o $(OBJDIR)/PowerSystemResource.o $(OBJDIR)/base.o
BIN = $(BINDIR)/main
DOXYFILE = $(PROJDIR)/Doxyfile

# First target which should be called to build
default: directories $(BIN)

# Build all including documentation
all: directories $(BIN) documentation

# Directories target
.PHONY: directories
directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

# Clean target
.PHONY: clean
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)
	@rm -rf $(DOCDIR)
	@rm -f $(DOXYFILE)
	@echo Finished cleaning up

# Documentation target
documentation: $(DOCDIR)/html/index.html
$(DOCDIR)/html/index.html: $(SRCDIR)/*.cpp $(SRCDIR)/*.h $(DOXYFILE)
	doxygen $(DOXYFILE)

# Doxyfile
$(DOXYFILE):
	@rm -f $(DOXYFILE)
	@echo PROJECT_NAME = "$(PROJECT_NAME)" >> $(DOXYFILE)
	@echo OUTPUT_DIRECTORY = $(DOCDIR) >> $(DOXYFILE)
	@echo INPUT = $(SRCDIR) >> $(DOXYFILE)
	@echo GENERATE_LATEX = NO >> $(DOXYFILE)
	@echo Generated Doxyfile

# Pattern rule for source
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<

# Linking pattern
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) $(OBJ) -o $(BIN) $(LDFLAGS)
