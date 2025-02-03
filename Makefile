# Joseph Erlinger (jerling2@uoregon.edu)
# --------------------------------------------------------------------------- #
# Reminder: These are lazily evaulated variables.
BINARY = parahash
CC = gcc
ROOT = src
DIRS = $(ROOT)/ $(call searchTree,$(ROOT))
SRCDIRS = $(filter %src/,$(DIRS))
INCDIRS = $(filter %inc/,$(DIRS))
CFILES = $(foreach d,$(SRCDIRS),$(wildcard $(d)*.c))
OBJECTS = $(patsubst %.c,%.o,$(CFILES))
DEPFILES = $(patsubst %.c,%.d,$(CFILES)) 
DEPFLAGS = -MP -MD
INCFLAGS = $(foreach d,$(INCDIRS),-I$(d))
OPENSSL = -lssl -lcrypto
CFLAGS = -Wall -Wextra -g $(INCFLAGS) $(DEPFLAGS)
LDFLAGS = $(OPENSSL)
# --------------------------------------------------------------------------- #
# Rule to recursively collect all directories.
define searchTree
	$(wildcard $1/*/) $(foreach d, $(wildcard $1/*), $(call searchTree, $(d)))
endef
# --------------------------------------------------------------------------- #
.PHONY : all clean

all : $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean : 
	@rm $(BINARY) $(DEPFILES) $(OBJECTS)