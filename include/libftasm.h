#ifndef	LIBFTASM_H
#define	LIBFTASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int     ft_isalpha(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
int     ft_islower(int c);
int     ft_isupper(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
int     ft_puts(const char *s);
size_t	ft_strlen(const char *s);

char*   ft_strcat(char *restrict s1, const char *restrict s2);
void	ft_bzero(void *s, size_t n);

#endif
