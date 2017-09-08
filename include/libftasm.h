#ifndef	LIBFTASM_H
#define	LIBFTASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int     ft_isalpha(int c);
int     ft_puts(const char *s);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
