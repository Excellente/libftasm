#include <stdio.h>
#include <string.h>
#include "libftasm.h"
#include <stdlib.h>

int print(char *str, int len);

int main(void)
{
	int ret;
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * 5);
	/*************************************
	**	test my strlen 
	*************************************/
	printf("************************* strlen Test 1 *************************\n");	
	ret = strlen(ptr);
	printf("strlen ret: %d\n", ret);
	ret = ft_strlen(ptr);
	printf("ft_strlen ret: %d\n", ret);
	
	printf("\n************************* strlen Test 2 *************************\n");
	ret = strlen("");
	printf("strlen ret: %d\n", ret);
	ret = ft_strlen("");
	printf("ft_strlen ret: %d\n", ret);

	printf("\n************************* strlen Test 3 *************************\n");
	ret = strlen("Zamani");
	printf("strlen ret: %d\n", ret);
	ret = ft_strlen("Zamani");
	printf("ft_strlen ret: %d\n\n", ret);
	// /*************************************
	// **	test my puts 
	// *************************************/
	// printf("************************* puts Test 1 *************************\n");	
	// ret = puts(ptr);
	// printf("puts ret: %d\n", ret);
	// ret = ft_strlen(ptr);
	// printf("ft_puts ret: %d\n", ret);

	// printf("\n************************* puts Test 2 *************************\n");
	// ret = puts("Zamani");
	// printf("puts ret: %d\n", ret);
	// ret = ft_puts("ft_Zamani");
	// ret = ft_strlen("ft_Zamani");
	// printf("ft_strlen ret: %d\n", ret);
	return (0);
}
