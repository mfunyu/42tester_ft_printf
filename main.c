#include <stdio.h>

int	ft_printf(const char *format, ...);

#ifdef REAL
# define P(...) printf(__VA_ARGS__)
#else
# define P(...) ft_printf(__VA_ARGS__)
#endif

int	main()
{
	int		ret;

	ret = 0;
	ret += P("---Start Test---\n");
	printf("written total: %d", ret);
}
