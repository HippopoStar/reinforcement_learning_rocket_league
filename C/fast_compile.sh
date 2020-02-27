#!/bin/bash

_GCC=/usr/bin/gcc

SRC_NAME=main_mem_read.c

${_GCC} -o memory_reader.out -Wall -Wextra ${SRC_NAME}

