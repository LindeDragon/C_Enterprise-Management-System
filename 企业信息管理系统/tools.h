#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <getch.h>
#include <cstdlib>
#include <cstring>

using namespace std;

void clear_scr(void);

void clear_stdin(void);

char* get_lim(char* str,int num);

char* get_key_lim(char* str,int num);

void show_msg(char* msg,size_t sec);

char get_cmd(char start,char end);

void press_anykey(void);

char y_or_n(void);

int generator_MgrId();

int generator_DeptId(void);

int generator_EmpId(void);

#endif// TOOLS_H
