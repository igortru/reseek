#!/usr/bin/python3

import os
import sys

OBJDIR = "o"
BINDIR = "../bin"

LRT = False
DEBUG = False
SVNVER = False

ProjFileName = None
HdrNames = []
for FileName in os.listdir("."):
    if FileName.endswith(".vcxproj"):
        ProjFileName = FileName
    elif FileName.endswith(".h"):
        HdrNames.append(FileName)
if ProjFileName is None:
    print("Project file not found in current directory", file=sys.stderr)

Fields = ProjFileName.split("/")
n = len(Fields)
Name = Fields[n-1]
Fields = Name.split(".")
progname = Fields[0]

CXXNames = []
CNames = []
with open(ProjFileName) as File:
    for Line in File:
        Line = Line.strip()
        Line = Line.replace('"', '')
        Line = Line.replace(' ', '')
        # <ClCompile Include="betadiv.cpp" />
        if Line.startswith("<ClCompileInclude"):
            Fields = Line.split("=")
            if len(Fields) != 2:
                continue
            FileName = Fields[1]
            FileName = FileName.replace("/>", "")
            if FileName.endswith(".cpp"):
                FileName = FileName.replace(".cpp", "")
                CXXNames.append(FileName)
            elif FileName.endswith(".c"):
                FileName = FileName.replace(".c", "")
                CNames.append(FileName)
        #     <ProjectName>usearch</ProjectName>
        elif Line.startswith("<ProjectName"):
            Line = Line.replace("<ProjectName>", "")
            Line = Line.replace("</ProjectName>", "")
            progname = Line

assert len(CXXNames) > 0 or len(CNames) > 0

with open("Makefile", "w") as f:
    def Out(s):
        print(s, file=f)

    BINPATH = "$(BINDIR)/%s" % (progname) 

    Out("BINDIR := %s" % BINDIR)
    Out("OBJDIR := %s" % OBJDIR)
    Out("BINPATH := %s" % BINPATH)

    # Out("")
    # Out("CPPFLAGS := $(CPPFLAGS) -DNDEBUG -pthread")

    if CNames:
        Out("")
        Out("CC = ccache gcc")
        Out("CFLAGS := $(CFLAGS) -O3 -ffast-math -march=native")

    if CXXNames:
        Out("")
        Out("CXX = ccache g++")
        Out("CXXFLAGS := $(CFLAGS) -DNDEBUG -pthread -O3 -ffast-math -march=native --std=c++11")

    Out("")
    Out("UNAME_S := $(shell uname -s)")
    Out("LDFLAGS := $(LDFLAGS) -O3 -pthread -lpthread")
    Out("ifeq ($(UNAME_S),Linux)")
    Out("    LDFLAGS += -static")
    Out("endif")

    Out("")
    Out("HDRS = \\")
    for Name in sorted(HdrNames):
        Out("  %s \\" % Name)

    Out("")
    Out("OBJS = \\")
    for Name in CXXNames:
        Out("  $(OBJDIR)/%s.o \\" % (Name))

    for Name in CNames:
        Out("  $(OBJDIR)/%s.o \\" % (Name))

    Out("")
    Out(".PHONY: clean")

    Out("")
    Out("$(BINPATH) : $(BINDIR)/ $(OBJDIR)/ $(OBJS)")

    if len(CXXNames) > 0:
        Cmd = "\t$(CXX) $(LDFLAGS) $(OBJS) -o $(BINPATH)"
    else:
        Cmd = "\t%(CC) $(LDFLAGS) $(OBJS) -o $(BINPATH)"

    if LRT:
        Cmd += " -lrt"
    Out(Cmd)

    Out("	strip $(BINPATH)")

    Out("")
    Out("$(OBJDIR)/ :")
    Out("	mkdir -p $(OBJDIR)/")

    Out("")
    Out("$(BINDIR)/ :")
    Out("	mkdir -p $(BINDIR)/")

    if CNames:
        Out("")
        Out("$(OBJDIR)/%.o : %.c $(HDRS)")
        Out("	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<")

    if CXXNames:
        Out("")
        Out("$(OBJDIR)/%.o : %.cpp $(HDRS)")
        Out("	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<")

    Out("")
    Out("clean:")
    Out("	rm -rf $(OBJDIR)/ $(BINPATH)")
