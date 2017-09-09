#ifndef	LIBFTASM_H
#define	LIBFTASM_H

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/fcntl.h>

int     ft_isalpha(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
int     ft_islower(int c);
int     ft_isupper(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
int     ft_puts(const char *s);
size_t  ft_strlen(const char *s);

char    *ft_strdup(const char *s);
char    *ft_strcat(char *s1, const char *s2);

void    ft_cat(const int fd);
void    ft_bzero(void *s, size_t n);
void    *ft_memset(void *b, int c, size_t n);
void    *ft_memcpy(void *d, const void *s, size_t n);

#endif
