CC := gcc
CFLAGS := -Wall -Wextra

BIN_PATH := bin
OBJ_PATH := obj
REL_PATH := ${OBJ_PATH}/rel
DBG_PATH := ${OBJ_PATH}/dbg
SRC_PATH := src

TARGET := ${BIN_PATH}/fasm

SRC_FILES := $(wildcard ${SRC_PATH}/*.c)
REL_FILES := $(addprefix ${REL_PATH}/, $(notdir ${SRC_FILES:.c=.o}))
DBG_FILES := $(addprefix ${DBG_PATH}/, $(notdir ${SRC_FILES:.c=.o}))

.PHONY: all clean release

all: ${DBG_FILES}
	@mkdir -p ${BIN_PATH}
	@${CC} ${CFLAGS} -g -o ${TARGET} ${DBG_FILES}

clean:
	@rm -rf ${BIN_PATH} ${OBJ_PATH}

release: ${REL_FILES}
	@mkdir -p ${BIN_PATH}
	@${CC} ${CFLAGS} -O3 -s -o ${TARGET}-release ${REL_FILES}

${REL_PATH}/%.o: ${SRC_PATH}/%.c
	@mkdir -p ${REL_PATH}
	@${CC} ${CFLAGS} -O3 -s -c -o $@ $<

${DBG_PATH}/%.o: ${SRC_PATH}/%.c
	@mkdir -p ${DBG_PATH}
	@${CC} ${CFLAGS} -g -c -o $@ $<
