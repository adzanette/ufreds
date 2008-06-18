
TO_COMPILE = teste.o
DIRS = src/
CC = gcc -ggdb
CC_LIBS = 
RM = rm -f
RESULT_FILE = teste
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
	$(CC) $(CC_LIBS) -o $(RESULT_FILE) $(TO_COMPILE) $(COMP_FILES)

$(OBJTEXT):
	$(MAKE) -C $(patsubst %_text,%,$@)/

clean: $(OBJCLEAN)
	$(RM) $(TO_COMPILE) $(RESULT_FILE)

$(OBJCLEAN):
	$(MAKE) -C $(patsubst %_clean,%,$@)/ clean

install:
	$(CP) $(RESULT_FILE) $(BIN_DIR)
