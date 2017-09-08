#include "libftasm.h"

int print(char *str);

void	print_int(void *ptr)
{
	int	i = 0;
	int	*p = (int *)ptr;
	
	while (i < 7)
		printf("%d ", p[i++]);
	printf("\n");
}

void	printIsalpha(int c)
{
	int ret = 0;
	int ret2 = 0;

	/************************ isalpha *********************/
	ret = isalpha(c);
	if (ret)
		printf("%c isalpha\n", c);
	else
		printf("%c is not alpha\n", c);

	/************************ ft_isalpha *********************/
	ret2 = ft_isalpha(c);
	if (ret2)
		printf("%c ft_isalpha\n", c);
	else
		printf("%c is not ft_alpha\n", c);
}

int main(void)
{
	int ret;
	char *ptr;
	char *fptr;
	char bptr[7] = "Zamani\0";
	char sfptr[10] = "ft_Zamani\0";
	int	 num[7] = {1, 2, 3, 5, 6, 7, 8};
	int	 num2[7] = {1, 2, 3, 5, 6, 7, 8};

	ret = 0;
	ptr = (char *)malloc(sizeof(char) * 5);
	fptr = (char *)malloc(sizeof(char) * 5);
	/**************************************************************************
	**	                             start test strlen                        *
	**************************************************************************/
	// printf("************************* strlen Test 1 *************************\n");	
	// ret = strlen(ptr);
	// printf("strlen ret: %d\n", ret);
	// ret = ft_strlen(ptr);
	// printf("ft_strlen ret: %d\n", ret);
	
	// printf("\n************************* strlen Test 2 *************************\n");
	// ret = strlen("");
	// printf("strlen ret: %d\n", ret);
	// ret = ft_strlen("");
	// printf("ft_strlen ret: %d\n", ret);

	// printf("\n************************* strlen Test 3 *************************\n");
	// ret = strlen("Zamani");
	// printf("strlen ret: %d\n", ret);
	// ret = ft_strlen("Zamani");
	// printf("ft_strlen ret: %d\n\n", ret);

	/**************************************************************************
	**	                             start test puts                          *
	**************************************************************************/
	// printf("************************* puts Test 1 *************************\n");
	// ret = puts("");
	// printf("puts ret: %d\n", ret);
	// ret = ft_puts("");
	// printf("ft_puts ret: %d\n", ret);

	// printf("\n************************* puts Test 2 *************************\n");
	// ret = puts(ptr);
	// printf("puts ret: %d\n", ret);
	// ret = ft_puts(ptr);
	// printf("ft_puts ret: %d\n", ret);

	// printf("\n************************* puts Test 3 *************************\n");
	// ret = puts("Zamani");
	// printf("puts ret: %d\n", ret);
	// ret = ft_puts("ft_Zamani");
	// printf("ft_puts ret: %d\n", ret);

	/**************************************************************************
	**	                           start test bzero                           *
	**************************************************************************/
	// printf("\n************************* bzero Test 1 *************************\n");
	// bzero(ptr, 4);
	// printf("bzero: %s\n", ptr);
	// ft_bzero(fptr, 4);
	// printf("ft_bzero: %s\n", fptr);

	// printf("\n************************* bzero Test 2 *************************\n");
	// printf("before bzero: %s\n", bptr);
	// bzero(bptr, 4);
	// printf("after bzero: %s\n\n", bptr);

	// printf("before ft_bzero: %s\n", sfptr);
	// ft_bzero(sfptr, 4);
	// printf("after ft_bzero: %s\n", sfptr);

	// printf("\n************************* bzero Test 3 *************************\n");
	// printf("before bzero: ");
	// print_int(num);
	// bzero(num, 5);
	// printf("after bzero: ");
	// print_int(num);

	// printf("\nbefore ft_bzero: ");
	// print_int(num2);
	// ft_bzero(num2, 5);
	// printf("after bzero: ");
	// print_int(num2);
	
	/**************************************************************************
	**	                          start test isalpha                          *
	**************************************************************************/
	printf("\n\n************************* isalpha Test 1 *************************\n");
	printIsalpha(13);
	printf("\n************************* isalpha Test 2 *************************\n");
	printIsalpha(65);
	printf("\n************************* isalpha Test 3 *************************\n");
	printIsalpha(79);
	printf("\n************************* isalpha Test 4 *************************\n");
	printIsalpha(90);
	printf("\n************************* isalpha Test 5 *************************\n");
	printIsalpha(94);
	printf("\n************************* isalpha Test 6 *************************\n");
	printIsalpha(97);
	printf("\n************************* isalpha Test 7 *************************\n");
	printIsalpha(89);
	printf("\n************************* isalpha Test 8 *************************\n");
	printIsalpha(122);
	printf("\n************************* isalpha Test 9 *************************\n");
	printIsalpha(124);
	return (0);
}
