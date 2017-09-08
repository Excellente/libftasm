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
		printf("%c isalpha_ft\n", c);
	else
		printf("%c is not alpha_ft\n", c);
}

void	printIsdigit(int c)
{
	int ret = 0;
	int ret2 = 0;

	/************************ isdigit *********************/
	ret = isdigit(c);
	if (ret)
		printf("%d isdigit\n", c);
	else
		printf("%d is not digit\n", c);

	/************************ ft_isdigit *********************/
	ret2 = ft_isdigit(c);
	if (ret2)
		printf("%d isdigit_ft\n", c);
	else
		printf("%d is not digit_ft\n", c);
}

void	printIsalnum(int c)
{
	int ret = 0;
	int ret2 = 0;

	/************************ isalnum *********************/
	ret = isalnum(c);
	if (ret)
		printf("%c isalnum\n", c);
	else
		printf("%c is not alnum\n", c);

	/************************ ft_isalnum *********************/
	ret2 = ft_isdigit(c) | ft_isalpha(c);
	if (ret2)
		printf("%c isalnum_ft\n", c);
	else
		printf("%c is not alnum_ft\n", c);
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
	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test strlen                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
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

	printf("\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test puts                              *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("************************* puts Test 1 *************************\n");
	ret = puts("");
	printf("puts ret: %d\n", ret);
	ret = ft_puts("");
	printf("ft_puts ret: %d\n", ret);

	printf("\n************************* puts Test 2 *************************\n");
	ret = puts(ptr);
	printf("puts ret: %d\n", ret);
	ret = ft_puts(ptr);
	printf("ft_puts ret: %d\n", ret);

	printf("\n************************* puts Test 3 *************************\n");
	ret = puts("Zamani");
	printf("puts ret: %d\n", ret);
	ret = ft_puts("ft_Zamani");
	printf("ft_puts ret: %d\n", ret);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test bzero                             *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("************************* bzero Test 1 *************************\n");	
	bzero(ptr, 4);
	printf("bzero: %s\n", ptr);
	ft_bzero(fptr, 4);
	printf("ft_bzero: %s\n", fptr);

	printf("\n************************* bzero Test 2 *************************\n");
	printf("before bzero: %s\n", bptr);
	bzero(bptr, 4);
	printf("after bzero: %s\n\n", bptr);

	printf("before ft_bzero: %s\n", sfptr);
	ft_bzero(sfptr, 4);
	printf("after ft_bzero: %s\n", sfptr);

	printf("\n************************* bzero Test 3 *************************\n");
	printf("before bzero: ");
	print_int(num);
	bzero(num, 5);
	printf("after bzero: ");
	print_int(num);

	printf("\nbefore ft_bzero: ");
	print_int(num2);
	ft_bzero(num2, 5);
	printf("after bzero: ");
	print_int(num2);
	
	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test isalpha                           *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("************************* isalpha Test 1 *************************\n");
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

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test isdigit                           *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("\n\n************************* isditit Test 1 *************************\n");
	printIsdigit(EOF);
	printf("\n************************* isditit Test 2 *************************\n");
	printIsdigit(48);
	printf("\n************************* isditit Test 3 *************************\n");
	printIsdigit(57);
	printf("\n************************* isdigit Test 4 *************************\n");
	printIsdigit(58);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test isalnum                           *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("\n\n************************* isalnum Test 1 *************************\n");
	printIsalnum(EOF);
	printf("\n************************* isalnum Test 2 *************************\n");
	printIsalnum(48);
	printf("\n************************* isalnum Test 3 *************************\n");
	printIsalnum(57);
	printf("\n************************* isalnum Test 4 *************************\n");
	printIsalnum(58);
	printf("************************* isalnum Test 5 *************************\n");
	printIsalnum(13);
	printf("\n************************* isalnum Test 6 *************************\n");
	printIsalnum(65);
	printf("\n************************* isalnum Test 7 *************************\n");
	printIsalnum(79);
	printf("\n************************* isalnum Test 8 *************************\n");
	printIsalnum(90);
	printf("\n************************* isalnum Test 9 *************************\n");
	printIsalnum(94);
	printf("\n************************* isalnum Test 10 *************************\n");
	printIsalnum(97);
	printf("\n************************* isalnum Test 11 *************************\n");
	printIsalnum(89);
	printf("\n************************* isalnum Test 12 *************************\n");
	printIsalnum(122);
	printf("\n************************* isalnum Test 13 *************************\n");
	printIsalnum(124);
	printf("\n************************* isalnum Test 14 *************************\n");
	printIsalnum((unsigned char)'G');
	return (0);
}
