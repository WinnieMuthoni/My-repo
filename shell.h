#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <syst/stat.h>
#include <limits.h>
#include <sys/wait>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_AND 2
#define CMD_OR 1
#define CMD_NORM 0
#define CMD_CHAIN 3
