#ifndef __REMOVE_H
#define __REMOVE_H
#define _XOPEN_SOURCE 500

#include <stdlib.h>

#include <stdio.h>

#include <ftw.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


void rm(const char * path);

#endif