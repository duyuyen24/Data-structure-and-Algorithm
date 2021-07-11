###############################################################################
# Author: ThanNT
# Date: 06/01/2017
###############################################################################
RPI_SYS_DIR	=
TOOLS_DIR	=
NAME_MODULE	= linux_app
OPTIMIZE	= -g -Os
CXX		= g++
CC		= gcc
OBJ_DIR		= $(NAME_MODULE)_build

-include source/app/Makefile.mk

CXXFLAGS	+= -I/usr/local/include
CXXFLAGS	+= -I/usr/include
# CXX compiler option
CXXFLAGS	+=	$(OPTIMIZE)	\
		--std=c++11		\
		-Wall			\
		-Winline		\
		-pipe			\
		-g			\
		-DRPI			\
		-Wl,--no-as-needed

# Library paths
LDFLAGS	+= -L/usr/local/lib
LDFLAGS	+= -L/usr/lib
#Library libs
LDLIBS	+=	-lpthread		\
		-lrt			\
		-lm			\

all: create $(OBJ_DIR)/$(NAME_MODULE)

create:
	@echo mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@echo CXX $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	@echo CXX $<
	@$(CC) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/$(NAME_MODULE): $(OBJ)
	@echo ---------- START LINK PROJECT ----------
	@echo $(CXX) -o $@ $^ $(CXXFLAGS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
copy:
	scp -r ./raspi.zip root@192.168.2.80:/tmp/apps

flash:
	$(OBJ_DIR)/$(NAME_MODULE)

debug:
	sudo gdb $(OBJ_DIR)/$(NAME_MODULE)

install:
	cp $(OBJ_DIR)/$(NAME_MODULE) /usr/local/bin

clean:
	@echo rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
