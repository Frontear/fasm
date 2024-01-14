# Compiler + build flags
CC := gcc
CFLAGS := -Wall -Wextra

# Paths for binaries, object files, and source files
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src

# Final binary path
TARGET := ${BIN_PATH}/fasm

# https://stackoverflow.com/a/18258352
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC_FILES := $(call rwildcard, ${SRC_PATH}, *.c)
OBJ_FILES := $(patsubst ${SRC_PATH}/%.c, ${OBJ_PATH}/%.o, ${SRC_FILES})

.PHONY: all clean

all: ${OBJ_FILES}
	@mkdir -p $(dir ${TARGET})
	@${CC} ${CFLAGS} -o ${TARGET} ${OBJ_FILES}

clean:
	@rm -rf ${BIN_PATH} ${OBJ_PATH}

${OBJ_FILES}: ${OBJ_PATH}/%.o : ${SRC_PATH}/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c -o $@ $<
