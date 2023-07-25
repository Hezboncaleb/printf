#ifndef MAIN_H_
#define MAIN_H_
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
int _putchar(char c);
int print_int(int n);
int print_unsignedint(int n);
int _printf(const char *format, ...);
int index_percent(char *str, int start_index);
int num_percent(char *str);
int _strlen(const char *str);
void copy_values(const char *format, char *str, unsigned int len);
int print_string(char *str);
#endif
