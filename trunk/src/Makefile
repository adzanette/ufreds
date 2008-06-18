
TO_COMPILE = createUfred.o changeUfred.o
CC = gcc -shared
CC_LIBS = 
RM = rm -f
RESULT_FILE = uthread.o
CP = cp
BIN_DIR = /usr/bin

ifdef DIRS
	COMP_FILES = $(patsubst %/,%/*.o,$(DIRS))
	DIROBJ = $(patsubst %/,%,$(DIRS))
	OBJTEXT = $(patsubst %,%_text,$(DIROBJ))
	OBJCLEAN = $(patsubst %,%_clean,$(DIROBJ))
else
	COMP_FILES = 
	DIROBJ = 
	OBJTEXT = 
	OBJCLEAN = 
endif

all: $(OBJTEXT) $(TO_COMPILE)

$(OBJTEXT):
	$(MAKE) -C $(patsubst %_text,%,$@)/

clean: $(OBJCLEAN)
	$(RM) $(TO_COMPILE) $(RESULT_FILE)

$(OBJCLEAN):
	$(MAKE) -C $(patsubst %_clean,%,$@)/ clean