#!/bin/sh

gcc -D BUFFER_SIZE=42 -g get_next_line.c get_next_line.h get_next_line_utils.c main.c && ./a.out