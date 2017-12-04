################################################################################
# Makefile for the Onvif protocol		                                       #
# Tested with ARM cross compiler on Ubuntu 16.04 LTS                     	   #
#                                                                              #
# Created (2017) by Stjepan Mocilac <mocilac.stjepan@gmail.com>		           #
# 					          												   #
#                                                                              #
# Feel free to use this makefile without any warranty on your own risk.        #
################################################################################

include env.txt

# This is the name of the binaries that will be generated
TARGET                  = onvif_app

# Here we add all *.c files that we want to compile
CSRCS                   =

# Here we add all *.cpp files that we want to compile
CPPSRCS                 = gsoap/gsoap/runtime/dom.cpp \
							gsoap/gsoap/runtime/duration.cpp \
							gsoap/gsoap/runtime/mecevp.cpp \
							gsoap/gsoap/runtime/smdevp.cpp \
							gsoap/gsoap/runtime/stdsoap2.cpp \
							gsoap/gsoap/runtime/threads.cpp \
							gsoap/gsoap/runtime/wsaapi.cpp \
							gsoap/gsoap/runtime/wsseapi.cpp \
							onvifgen/nsmap.cpp  \
							onvifgen/soapC.cpp \
							onvifgen/soapDeviceBindingProxy.cpp \
							onvifgen/soapDeviceBindingService.cpp \
							onvifgen/soapPTZBindingProxy.cpp \
							onvifgen/soapPTZBindingService.cpp \
							onvifgen/soapMediaBindingProxy.cpp \
							include/onvifclientdevice.cpp \
							include/onvifclientmedia.cpp \
							include/onvifclientptz.cpp \
							Qt/onvif_master/ptzcontrol.cpp \
							Qt/onvif_master/main.cpp
							
							
# Here we add the paths to all include directories
INCS                    = ./gsoap/gsoap/runtime ./onvifgen ./include ./Qt/onvif_master ./openssl-1.0.2m/openssl/include																																																																																																																																																																																													include/

# Parameters for SCP upload. Set up SSH keys to bypass password prompt
SCP_TARGET_IP           = 192.168.1.210
SCP_USER                = root
SCP_TARGET_PATH         = /root
SCP                     = scp
SCP_FLAGS               =


################################################################################
# Don't change anything below this line                                        #
################################################################################

# Some directory and file magic
ifneq (,$(filter $(MAKECMDGOALS),target upload))
  BUILDDIR          = build-target
	OBJDIR            = $(BUILDDIR)/obj-target
	LD                = $(CROSS_COMPILE_PATH)/$(CROSS_ARCH)-g++
	CC                = $(CROSS_COMPILE_PATH)/$(CROSS_ARCH)-gcc
	CPPC              = $(CROSS_COMPILE_PATH)/$(CROSS_ARCH)-g++
	SIZE              = $(CROSS_COMPILE_PATH)/$(CROSS_ARCH)-size
  CFLAGS            = -Wall ${CROSS_EXTRA_CFLAGS}
  CPPFLAGS          = -Wall ${CROSS_EXTRA_CPPFLAGS}  
  LDFLAGS           = -Wall ${CROSS_EXTRA_LDFLAGS}
else
  BUILDDIR          = build
  OBJDIR            = $(BUILDDIR)/obj
  LD                = $(COMPILE_PATH)/g++
  CC                = $(COMPILE_PATH)/gcc
  CPPC              = $(COMPILE_PATH)/g++
  SIZE              = $(COMPILE_PATH)/size
  CFLAGS            = -g -Wall ${EXTRA_CFLAGS} -O3
  CPPFLAGS          = -g -Wall ${EXTRA_CPPFLAGS} -O3
  LDFLAGS           = -g -Wall ${EXTRA_LDFLAGS}
endif

# Generate the object names
OBJS                    = $(addprefix $(OBJDIR)/,$(addsuffix .o,$(basename $(CSRCS:%.c=%.o))))
OBJS                    += $(addprefix $(OBJDIR)/,$(addsuffix .o,$(basename $(CPPSRCS:%.cpp=%.o))))

 
# Add some paths
CFLAGS                  += $(INCS:%=-I%) 
CPPFLAGS                += $(INCS:%=-I%)
LDFLAGS                 += $(INCS:%=-I%) 

 
# This is the default target if the user does just calls 'make'
all: build size

prebuild:
	$(SHELL) ./build_openssl.sh

target: prebuild build copy size

# Build all the files
build:  builddirs $(BUILDDIR)/$(TARGET)

# Create the required directories (if not already existing)
builddirs:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

# Link everything together
$(BUILDDIR)/$(TARGET): $(OBJS)
	@echo Linking $@
	@$(LD) $(LDFLAGS) -o $(BUILDDIR)/$(TARGET) $(OBJS)

# Compile c files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo Compiling $^
	@$(CC) $(CFLAGS) -c -o $@ $^

# Compile cpp files
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo Compiling $^
	@$(CPPC) $(CPPFLAGS) -c -o $@ $^

# Print size information
size: $(BUILDDIR)/$(TARGET)
	@echo
	$(SIZE) $^

# Build all the files
copy: $(BUILDDIR)/$(TARGET)

# Clean up
clean:
	@rm -rf build build-target $(OBJS) $(TARGET) $(TARGET).* *.a *.o *~
	@echo Done

# Clean must be a phony target so make knows this never exists as a file
.PHONY: clean

# Upload to target
upload:
	sshpass -p "glx" $(SCP) $(SCP_FLAGS) $(BUILDDIR)/$(TARGET) $(SCP_USER)@$(SCP_TARGET_IP):$(SCP_TARGET_PATH) 
