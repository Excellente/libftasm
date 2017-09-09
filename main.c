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

void	printIsascii(int c)
{
	int ret = 0;
	int ret2 = 0;

	/************************ isascii *********************/
	ret = isascii(c);
	if (ret)
		printf("%c isascii\n", c);
	else
		printf("%c is not ascii\n", c);

	/************************ ft_isascii *********************/
	ret2 = ft_isascii(c);
	if (ret2)
		printf("%c isascii_ft\n", c);
	else
		printf("%c is not ascii_ft\n", c);
}

void	printIsprint(int c)
{
	int ret = 0;
	int ret2 = 0;

	/************************ isascii *********************/
	ret = isprint(c);
	if (ret)
		printf("%c isprint\n", c);
	else
		printf("%c is not print\n", c);

	/************************ ft_isascii *********************/
	ret2 = ft_isprint(c);
	if (ret2)
		printf("%c isprint_ft\n", c);
	else
		printf("%c is not print_ft\n", c);
}

void	assign(char *s, char *st)
{
	int i = 0;

	while (i < 4)
	{
		s[i] = 'j' + i;
		i++;
	}
	s[i] = '\0';
	i = 0;
	while (i < 5)
	{
		st[i] = 'f' + i;
		i++;
	}
	st[i] = '\0';
}

int main(void)
{
	int	fd;
	int ret;
	char ch;
	char *ptr;
	char *fptr;
	char bptr[7] = "Zamani\0";
	char sfptr[10] = "ft_Zamani\0";
	int	 num[7] = {1, 2, 3, 5, 6, 7, 8};
	int	 num2[7] = {1, 2, 3, 5, 6, 7, 8};

	ret = 0;
	ch = 32;
	fd = open("main.c", O_RDONLY);
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

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test isascii                           *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("\n\n************************* isascii Test 1 *************************\n");
	printIsascii(EOF);
	printf("\n************************* isascii Test 2 *************************\n");
	printIsascii(48);
	printf("\n************************* isascii Test 3 *************************\n");
	printIsascii(57);
	printf("\n************************* isascii Test 4 *************************\n");
	printIsascii(58);
	printf("************************* isascii Test 5 *************************\n");
	printIsascii(13);
	printf("\n************************* isascii Test 6 *************************\n");
	printIsascii(65);
	printf("\n************************* isascii Test 7 *************************\n");
	printIsascii(79);
	printf("\n************************* isascii Test 8 *************************\n");
	printIsascii(167);
	printf("\n************************* isascii Test 9 *************************\n");
	printIsascii(94);
	printf("\n************************* isascii Test 10 *************************\n");
	printIsascii(97);
	printf("\n************************* isascii Test 11 *************************\n");
	printIsascii(89);
	printf("\n************************* isascii Test 12 *************************\n");
	printIsascii(122);
	printf("\n************************* isascii Test 13 *************************\n");
	printIsascii(124);
	printf("\n************************* isascii Test 14 *************************\n");
	printIsascii((unsigned char)'G');
	printf("\n************************* isascii Test 15 *************************\n");
	printIsascii((unsigned char)723);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test isprint                           *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m\n");
	printf("\n\n************************* isprint Test 1 *************************\n");
	printIsprint(EOF);
	printf("\n************************* isprint Test 2 *************************\n");
	printIsprint(48);
	printf("\n************************* isprint Test 3 *************************\n");
	printIsprint('~');
	printf("\n************************* isprint Test 4 *************************\n");
	printIsprint(58);
	printf("\n************************* isprint Test 5 *************************\n");
	printIsprint(13);
	printf("\n************************* isprint Test 6 *************************\n");
	printIsprint(65);
	printf("\n************************* isprint Test 7 *************************\n");
	printIsprint(79);
	printf("\n************************* isprint Test 8 *************************\n");
	printIsprint(167);
	printf("\n************************* isprint Test 9 *************************\n");
	printIsprint(94);
	printf("\n************************* isprint Test 10 *************************\n");
	printIsprint(97);
	printf("\n************************* isprint Test 11 *************************\n");
	printIsprint(89);
	printf("\n************************* isprint Test 12 *************************\n");
	printIsprint(127);
	printf("\n************************* isprint Test 13 *************************\n");
	printIsprint(124);
	printf("\n************************* isprint Test 14 *************************\n");
	printIsprint(32);
	printf("\n************************* isprint Test 15 *************************\n");
	printIsprint((unsigned char)28);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test toupper                          *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* toupper Test 1 *************************\n");
	ch = 'a';
	printf("ch before: %c\n", ch);
	ch = toupper(ch);
	printf("ch after: %c\n", ch);
	
	ch = 'a'	;
	printf("\nft_ch before: %c\n", ch);
	ch = ft_toupper(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* toupper Test 2 *************************\n");
	ch = 13;
	printf("ch before: %c\n", ch);
	ch = toupper(ch);
	printf("ch after: %c\n", ch);
	
	ch = 13;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_toupper(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* toupper Test 3 *************************\n");
	ch = 78;
	printf("ch before: %c\n", ch);
	ch = toupper(ch);
	printf("ch after: %c\n", ch);

	ch = 78;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_toupper(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* toupper Test 4 *************************\n");
	ch = 50;
	printf("ch before: %c\n", ch);
	ch = toupper(ch);
	printf("ch after: %c\n", ch);

	ch = 50;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_toupper(ch);
	printf("ft_ch after: %c\n", ch);
	

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test tolower                          *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* tolower Test 1 *************************\n");
	ch = 'a';
	printf("ch before: %c\n", ch);
	ch = tolower(ch);
	printf("ch after: %c\n", ch);
	
	ch = 'a';
	printf("\nft_ch before: %c\n", ch);
	ch = ft_tolower(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* tolower Test 2 *************************\n");
	ch = 13;
	printf("ch before: %c\n", ch);
	ch = tolower(ch);
	printf("ch after: %c\n", ch);
	
	ch = 13;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_tolower(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* tolower Test 3 *************************\n");
	ch = 67;
	printf("ch before: %c\n", ch);
	ch = tolower(ch);
	printf("ch after: %c\n", ch);

	ch = 67;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_tolower(ch);
	printf("ft_ch after: %c\n", ch);

	printf("\n************************* tolower Test 4 *************************\n");
	ch = 50;
	printf("ch before: %c\n", ch);
	ch = tolower(ch);
	printf("ch after: %c\n", ch);

	ch = 50;
	printf("\nft_ch before: %c\n", ch);	
	ch = ft_tolower(ch);
	printf("ft_ch after: %c\n", ch);
	
	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test strcat                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* strcat Test 1 *************************\n");
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	strcat(ptr, fptr);
	printf("strcat res: %s\n\n", ptr);
	ptr[4] = '\0';

	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	ft_strcat(ptr, fptr);
	printf("ft_strcat res: %s\n", ptr);
	ptr[4] = '\0';

	printf("\n************************* strcat Test 2 *************************\n");
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	strcat(ptr, fptr);
	printf("strcat res: %s\n\n", ptr);
	ptr[4] = '\0';

	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	ft_strcat(ptr, fptr);
	printf("ft_strcat res: %s\n", ptr);
	ptr[4] = '\0';
	
	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test memset                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* memset Test 1 *************************\n");
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	memset(ptr, '_', 3);
	printf("memset res: %s\n\n", ptr);

	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	ft_memset(ptr, '_', 3);
	printf("ft_memset res: %s\n", ptr);

	printf("\n\n************************* memset Test 2 *************************\n");
	printf("num before: ");
	print_int(num);
	memset(num, 54, 4);
	printf("memset res: ");
	print_int(num);
	printf("\n\n");
	
	printf("num2 before: ");
	print_int(num2);
	ft_memset(num2, 54, 4);
	printf("ft_memset res: ");
	print_int(num2);
	printf("\n");

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test memcpy                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* memcpy Test 1 *************************\n");
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	memcpy(ptr, fptr, 3);
	printf("memset ptr: %s\n\n", ptr);
	
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	ft_memcpy(ptr, fptr, 3);
	printf("ft_memset res: %s\n", ptr);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test strdup                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* strdup Test 1 *************************\n");
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	free(fptr);
	fptr = strdup(ptr);
	printf("strdup ptr: %s\nstrdup fptr: %s\n\n", ptr, fptr);
	
	assign(ptr, fptr);
	printf("ptr: %s\n", ptr);
	printf("fptr: %s\n", fptr);
	free(fptr);
	fptr = ft_strdup(ptr);
	printf("ft_strdup ptr: %s\nft_strdup fptr: %s\n\n", ptr, fptr);

	printf("\n\033[92m********************************************************************************\033[0m\n");
	printf("\033[92m*	                          start test ft_cat                            *\033[0m\n");
	printf("\033[92m********************************************************************************\033[0m");
	printf("\n\n************************* ft_cat Test 1 *************************\n");
	ft_cat(fd);

	close(fd);
	free(ptr);
	free(fptr);
	return (0);
}