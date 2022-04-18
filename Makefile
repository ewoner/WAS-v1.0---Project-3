# Credit line follows....
# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)

###################################################################
#Global Variables - Note this makefile is for TWO different .exe's#
###################################################################
# Set EXE names and base directories for all files
SERVER_EXE_NAME := server.exe
CLIENT_EXE_NAME := client.exe
BUILD_DIR := Build
SOURCE_DIR := Sources
SERVER_DIR := $(BUILD_DIR)/$(SOURCE_DIR)/Server
CLIENT_DIR := $(BUILD_DIR)/$(SOURCE_DIR)/Client
SERVER_SRC_DIRS := $(SOURCE_DIR)/Server
CLIENT_SRC_DIRS := $(SOURCE_DIR)/Client
DATA_DIR := $(BUILD_DIR)/Data
SERVER_EXE := $(BUILD_DIR)/$(SERVER_EXE_NAME)
CLIENT_EXE := $(BUILD_DIR)/$(CLIENT_EXE_NAME)

# Find all the C and C++ files we want to compile
SERVER_SRCS := $(shell find $(SERVER_SRC_DIRS) -name '*.cpp')
CLIENT_SRCS := $(shell find $(CLIENT_SRC_DIRS) -name '*.cpp')
$(info $$SERVER_SRCS is      [${SERVER_SRCS}])                            #--- Debugg print statement
$(info $$CLIENT_SRCS is      [${CLIENT_SRCS}])                            #--- Debugg print statement

# Set all object files we will need from the source files
SERVER_OBJS := $(SERVER_SRCS:%.cpp=$(BUILD_DIR)/%.o)
CLIENT_OBJS := $(CLIENT_SRCS:%.cpp=$(BUILD_DIR)/%.o)
$(info $$SERVER_OBJS is      [${SERVER_OBJS}])
$(info $$CLIENT_OBJS is      [${CLIENT_OBJS}])                             #--- Debugg print statement

# Set all the dependency files need from the object file names
SERVER_DEPS := $(SERVER_OBJS:.o=.d)
CLIENT_DEPS := $(CLIENT_OBJS:.o=.d)
$(info $$SERVER_DEPS is      [${SERVER_DEPS}])
$(info $$CLIENT_DEPS is      [${CLIENT_DEPS}])

# Find the all include directories for g++
SERVER_INC_DIRS := $(shell find $(SERVER_SRC_DIRS) -type d)
CLIENT_INC_DIRS := $(shell find $(CLIENT_SRC_DIRS) -type d)
$(info $$SERVER_INC_DIRS is  [${SERVER_INC_DIRS}])
$(info $$CLIENT_INC_DIRS is  [${CLIENT_INC_DIRS}])

# Set the -I flags for all include directories
SERVER_INC_FLAGS := $(addprefix -I,$(SERVER_INC_DIRS))
CLIENT_INC_FLAGS := $(addprefix -I,$(CLIENT_INC_DIRS))
$(info $$SERVER_INC_FLAGS is [${SERVER_INC_FLAGS}])
$(info $$CLIENT_INC_FLAGS is [${CLIENT_INC_FLAGS}])

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
SERVER_FLAGS := $(SERVER_INC_FLAGS) -MMD -MP -std=c++17 -g -pthread
CLIENT_FLAGS := $(CLIENT_INC_FLAGS) -MMD -MP -std=c++17 -g -pthread
$(info $$SERVER_FLAGS is     [${SERVER_FLAGS}])
$(info $$CLIENT_FLAGS is     [${CLIENT_FLAGS}])

###################################################################
# Make targets for the exe's and object files                     #
###################################################################
# Build the server
.PHONY: server
server: main

# Build both exe's
.PHONY: both
both: client server

# Builds only the server
.PHONY: main
main:  $(SERVER_DIR)/server.o $(SERVER_OBJS)
	@echo -e "\nCreating server...." $(SERVER_DIR)/$(SERVER_EXE_NAME) "\n"
	$(CXX) $(SERVER_OBJS) -o $(BUILD_DIR)/$(SERVER_EXE_NAME) $(SERVER_FLAGS)
	@echo -e "\ncoping data files over...."
	mkdir -p $(DATA_DIR)
	cp Data/*.* $(DATA_DIR)
	@echo "Server Done!!"
	
.PHONY: client
client:  $(CLIENT_DIR)/client.o $(CLIENT_OBJS)
	@echo -e "\nCreating client...." $(CLIENT_DIR)/$(CLIENT_EXE_NAME) "\n"
	$(CXX) $(CLIENT_OBJS) -o $(BUILD_DIR)/$(CLIENT_EXE_NAME) $(CLIENT_FLAGS)
	@echo "Client Done!!"
	
$(BUILD_DIR)/%.o: %.cpp
	@echo -e "\nCompiling ...." $@ "\n"
	mkdir -p $(dir $@)
	$(CXX) $(if $(findstring Client,$@), $(CLIENT_FLAGS),$(SERVER_FLAGS)) -c $< -o $@
	


###################################################################
#Make targets to clean up, build, etc.                            #
###################################################################

.PHONY: clean
clean:
	@echo -e "\nCLeaning and removing Build files....\n"
	$(RM) $(BUILD_DIR) -r

.PHONY: build
build: clean both

# Will only start the server right now
.PHONY: run
run: client main
	$(SERVER_EXE)
	$(CLIENT_EXE)

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(SERVER_DEPS)
-include $(CLIENT_DEPS)
