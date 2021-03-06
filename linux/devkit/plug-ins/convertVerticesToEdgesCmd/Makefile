#-
# ==========================================================================
# Copyright (c) 2011 Autodesk, Inc.
# All rights reserved.
# 
# These coded instructions, statements, and computer programs contain
# unpublished proprietary information written by Autodesk, Inc., and are
# protected by Federal copyright law. They may not be disclosed to third
# parties or copied or duplicated in any form, in whole or in part, without
# the prior written consent of Autodesk, Inc.
# ==========================================================================
#+

ifndef INCL_BUILDRULES

#
# Include platform specific build settings
#
TOP := ..
include $(TOP)/buildrules


#
# Always build the local plug-in when make is invoked from the
# directory.
#
all : plugins

endif

#
# Variable definitions
#

SRCDIR := $(TOP)/convertVerticesToEdgesCmd
DSTDIR := $(TOP)/convertVerticesToEdgesCmd

convertVerticesToEdgesCmd_SOURCES  := $(TOP)/convertVerticesToEdgesCmd/convertVerticesToEdgesCmd.cpp
convertVerticesToEdgesCmd_OBJECTS  := $(TOP)/convertVerticesToEdgesCmd/convertVerticesToEdgesCmd.o
convertVerticesToEdgesCmd_PLUGIN   := $(DSTDIR)/convertVerticesToEdgesCmd.$(EXT)
convertVerticesToEdgesCmd_MAKEFILE := $(DSTDIR)/Makefile

#
# Include the optional per-plugin Makefile.inc
#
#    The file can contain macro definitions such as:
#       {pluginName}_EXTRA_CFLAGS
#       {pluginName}_EXTRA_C++FLAGS
#       {pluginName}_EXTRA_INCLUDES
#       {pluginName}_EXTRA_LIBS
-include $(SRCDIR)/Makefile.inc


#
# Set target specific flags.
#

$(convertVerticesToEdgesCmd_OBJECTS): CFLAGS   := $(CFLAGS)   $(convertVerticesToEdgesCmd_EXTRA_CFLAGS)
$(convertVerticesToEdgesCmd_OBJECTS): C++FLAGS := $(C++FLAGS) $(convertVerticesToEdgesCmd_EXTRA_C++FLAGS)
$(convertVerticesToEdgesCmd_OBJECTS): INCLUDES := $(INCLUDES) $(convertVerticesToEdgesCmd_EXTRA_INCLUDES)

depend_convertVerticesToEdgesCmd:     INCLUDES := $(INCLUDES) $(convertVerticesToEdgesCmd_EXTRA_INCLUDES)

$(convertVerticesToEdgesCmd_PLUGIN):  LFLAGS   := $(LFLAGS) $(convertVerticesToEdgesCmd_EXTRA_LFLAGS) 
$(convertVerticesToEdgesCmd_PLUGIN):  LIBS     := $(LIBS)   -lOpenMaya -lFoundation -lGL $(convertVerticesToEdgesCmd_EXTRA_LIBS) 

#
# Rules definitions
#

.PHONY: depend_convertVerticesToEdgesCmd clean_convertVerticesToEdgesCmd Clean_convertVerticesToEdgesCmd


$(convertVerticesToEdgesCmd_PLUGIN): $(convertVerticesToEdgesCmd_OBJECTS) 
	-rm -f $@
	$(LD) -o $@ $(LFLAGS) $^ $(LIBS)

depend_convertVerticesToEdgesCmd :
	makedepend $(INCLUDES) $(MDFLAGS) -f$(DSTDIR)/Makefile $(convertVerticesToEdgesCmd_SOURCES)

clean_convertVerticesToEdgesCmd:
	-rm -f $(convertVerticesToEdgesCmd_OBJECTS)

Clean_convertVerticesToEdgesCmd:
	-rm -f $(convertVerticesToEdgesCmd_MAKEFILE).bak $(convertVerticesToEdgesCmd_OBJECTS) $(convertVerticesToEdgesCmd_PLUGIN)


plugins: $(convertVerticesToEdgesCmd_PLUGIN)
depend:	 depend_convertVerticesToEdgesCmd
clean:	 clean_convertVerticesToEdgesCmd
Clean:	 Clean_convertVerticesToEdgesCmd

