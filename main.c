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
	void	*addr = (void *)0x105e0a010;

	ret = 0;
	ret += P("---Start Test---\n");
	ret += P("---%%c---\n");
	ret += P("%c\n", 'a');
	ret += P("%c\n", 'A');
	ret += P("%c\n", ' ');
	ret += P("%c\n", '\t');
	ret += P("%c\n", '\n');
	ret += P("%c\n", 128); //        1000 0000
	ret += P("%c\n", 97); //         0110 0001
	ret += P("%c\n", -159); // ...11 0110 0001 (-256 + 97)
	ret += P("%c\n", -415); // ...10 0110 0001 (-512 + 97)
	ret += P("%c\n", 127); //        0111 1111
	ret += P("%c\n", -129); // ...11 0111 1111 (-256 + 127)
	ret += P("%c\n", -385); // ...10 0111 1111 (-512 + 127)

	ret += P("---%%s---\n");
	ret += P("%s\n", "hello world!");
	ret += P("%s\n", "");
	ret += P("%s\n", nullstr);
	ret += P("hello %s %s \n", "world", nullstr);

	ret += P("---%%p---\n");
	ret += P("%p\n", addr);
	ret += P("%p\n", NULL);

	ret += P("---%%d---\n");
	ret += P("%d\n", ft);
	ret += P("%d\n", 0);
	ret += P("%d\n", 1);
	ret += P("%d\n", -1);
	ret += P("%d\n", INT_MAX);
	ret += P("%d\n", INT_MIN);

	ret += P("---%%i---\n");
	ret += P("%i\n", ft);
	ret += P("%i\n", 0);
	ret += P("%i\n", 15);
	ret += P("%i\n", -15);
	ret += P("%i\n", INT_MAX);
	ret += P("%i\n", INT_MIN);

	ret += P("---%%u---\n");
	ret += P("%u\n", ft);
	ret += P("%u\n", 0);
	ret += P("%u\n", 15);
	ret += P("%u\n", -15);
	ret += P("%u\n", INT_MAX);
	ret += P("%u\n", INT_MIN);
	ret += P("%u\n", UINT_MAX);

	ret += P("---%%x---\n");
	ret += P("%x\n", ft);
	ret += P("%x\n", 0);
	ret += P("%x\n", 1);
	ret += P("%x\n", 15);
	ret += P("%x\n", 200);
	ret += P("%x\n", -15);
	ret += P("%x\n", -200);
	ret += P("%x\n", INT_MAX);
	ret += P("%x\n", INT_MIN);
	ret += P("%x\n", UINT_MAX);

	ret += P("---%%X---\n");
	ret += P("%X\n", ft);
	ret += P("%X\n", 0);
	ret += P("%X\n", 1);
	ret += P("%X\n", 42);
	ret += P("%X\n", 300);
	ret += P("%X\n", -1);
	ret += P("%X\n", -42);
	ret += P("%X\n", -300);
	ret += P("%X\n", INT_MAX);
	ret += P("%X\n", INT_MIN);
	ret += P("%X\n", UINT_MAX);

	ret += P("---%%%%---\n");
	ret += P("%%\n");
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
