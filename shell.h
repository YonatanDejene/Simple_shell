#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#define LINE_DELIM " \t\n"
#define SIZE 1024

extern char **environ;
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strlen(const char *str);
int _strncmp(char *str1, char *str2, int n);
void prompt(void);
int stw(const char *str, const char *sub, int index);
void error(char *name, char *cmd_name);
void rm_space(char *str);
void rmv_string(char *str);
int bltin(char *cmd);
int path2ls(char *cmnd, int ac, char **av);
void p_env(void);
int execute(int argc, char **argument, char **av);
int path_ls2bin(char *cmd, char **av);

#endif
