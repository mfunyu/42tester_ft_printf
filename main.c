#include <stdio.h>
#include "ft_printf.h"

#ifdef REAL
# define P(...) printf(__VA_ARGS__)
#else
# define P(...) ft_printf(__VA_ARGS__)

int		main()
{
	int		ret;

	ret = 0;
	r += P("---Start Test---\n");
	printf("written total: %d", ret);
}