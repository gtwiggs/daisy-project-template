# Project Name
TARGET = Template

# Uncomment if you depend on components in project electro-smith/DaisySP/DaisySP-LGPL
# USE_DAISYSP_LGPL = 1

# Uncomment to include a separate Source folder within your project. Good practice.
# C_INCLUDES = -ISource/

# Sources
CPP_SOURCES = Template.cpp

# Library Locations
LIBDAISY_DIR = ../electro-smith/libDaisy
DAISYSP_DIR = ../electro-smith/DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
