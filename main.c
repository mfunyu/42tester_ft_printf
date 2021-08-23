#include <stdio.h>
#include <limits.h>

int		ft_printf(const char *format, ...);

#ifdef REAL
# define P(...) printf(__VA_ARGS__)
#else
# define P(...) ft_printf(__VA_ARGS__)
#endif

int	mandatory(void)
{
	int		ret;
	char	*nullstr = NULL;
	int		ft = 42;

	ret = 0;
	ret += P("---Start Test---\n");
	ret += P("---%%c---\n");
	ret += P("---%%s---\n");
	ret += P("%s\n", "hello world!");
	ret += P("%s\n", nullstr);
	// ret += P("%s\n", NULL);
	// ret += P("hello %s %s \n", "world", NULL);
	ret += P("---%%d---\n");
	ret += P("%d\n", ft);
	ret += P("---%%i---\n");
	ret += P("---%%u---\n");
	ret += P("---%%x---\n");
	ret += P("---%%X---\n");
	return (ret);
}

int	bonus(void)
{
	int		ret;
	char	*nullstr = NULL;
	int		ft = 42;

	ret = 0;
	ret += P("%-s\n", nullstr);
	ret += P("%2s\n", nullstr);
	ret += P("%10s\n", nullstr);
	ret += P("%2.8s\n", nullstr);
	ret += P("%2.3s\n", nullstr);
	ret += P("%3.0d %3.0d %3.0d %3.0d\n", 0, 42, INT_MAX, INT_MIN);
	ret += P("%.1d\n", ft);
	return (ret);
}

int	main(void)
{
	int		ret;

	ret = 0;
	#ifndef BONUS
		ret += mandatory();
	#else
		ret += bonus();
	#endif
	printf("written total: %d\n", ret);
}
