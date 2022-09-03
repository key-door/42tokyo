#include "include/ft_printf.h"
#include <libc.h>

int	main(void)
{
	int		test;
	int		*ptr;
	char	*mallocked;

	// char *null_str = NULL;
	// // printf("%d",ft_printf("%s", null_str));
	// // printf("%d",printf("%s", null_str));
	// printf("%d\n",printf("%s\n", null_str));
	// printf("%d\n",ft_printf("%s\n", null_str));
	// printf("%d\n",printf("%s everywhere\n", null_str));
	// printf("%d\n",ft_printf("%s everywhere\n", null_str));
	// printf("%d\n",printf("everywhere %s\n", null_str));
	// printf("%d\n",ft_printf("everywhere %s\n", null_str));
	test = 42;
	// printf("%d\n", ft_printf("%p\n", &test));
	// printf("%d\n", printf("%p\n", &test));
	// printf("%d\n", ft_printf("%p is a virtual memory address\n", &test));
	// printf("%d\n", printf("%p is a virtual memory address\n", &test));
	// printf("%d\n", ft_printf("The address of the answer is %p\n", &test));
	// printf("%d\n", printf("The address of the answer is %p\n", &test));
	// printf("%d\n", ft_printf("The address is %p, so what?\n", &test));
	// printf("%d\n", printf("The address is %p, so what?\n\n\n", &test));
	ptr = &test;
	// printf("%d\n", ft_printf("A pointer at %p points to %p\t", &test, &ptr));
	// printf("%d\n", printf("A pointer at %p points to %p\t", &test, &ptr));
	// printf("%d\n", ft_printf("This %p is a very strange address\t",(void *)(long int)test));
	// printf("%d\n", printf("This %p is a very strange address\t",(void *)(long int)test));
	// mallocked = malloc(2);
	// printf("%d\n", ft_printf("This %p is an address from the heap",mallocked)); 
	// printf("%d\n", printf("This %p is an address from the heap",mallocked)); 
	// free(mallocked);
	printf("%d\n", ft_printf("%p\t", NULL));
	printf("%d\n", printf("%p\t", NULL));
	printf("%d\n", ft_printf("The NULL macro represents the %p address\t", NULL));
	printf("%d\n", printf("The NULL macro represents the %p address\t", NULL));
	printf("%d\n", ft_printf("This %p is even stranger\t", (void *)-1));
	printf("%d\n", printf("This %p is even stranger\t", (void *)-1));
	printf("%d\n",ft_printf("%d",ft_printf("%p is the address\t", (void *)0)));
	printf("%d\n",printf("%d",printf("%p is the address\t", (void *)0)));
 }
