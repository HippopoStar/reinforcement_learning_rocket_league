#include <unistd.h>
#include <string.h>

#define MEM_LINE_LENGTH 69

static size_t	ft_strlen(char *str)
{
	size_t			i;

	i = 0;
	while (!(*(str + i) == '\0'))
	{
		i++;
	}
	return (i);
}

static void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

static void		prepare_mem_line(char *mem_line)
{
	size_t			i;

	*(mem_line + 0) = '0';
	*(mem_line + 1) = 'x';
	*(mem_line + 10) = '\t';
	i = 0;
	while (i < 8)
	{
		*(mem_line + (5 * i) + 15) = ' ';
		i++;
	}
	*(mem_line + 67) = '\n';
	*(mem_line + 68) = '\0';
}

static void		fill_memory_addr_hexa(unsigned char *addr, char *mem_line, const char *hexabase)
{
	size_t			j;

	j = 8;
	while (j > 0)
	{
		j--;
		*(mem_line + 9 - j) = (char)(*(hexabase + ((((unsigned long int)addr) >> (2 * j)) % 16)));
	}
}

static void		fill_memory_bytes_hexa(unsigned char *addr, size_t length, char *mem_line, const char *hexabase)
{
	size_t			j;
	unsigned char	c;

	j = 0;
	while (j < 16 && j < length)
	{
		c = *(addr + j);
		*(mem_line + (2 * j) + (j / 2)) = (char)(*(hexabase + ((c >> 4) % 16)));
		*(mem_line + (2 * j) + (j / 2) + 1) = (char)(*(hexabase + (c % 16)));
		j++;
/*
**		if (j % 2 == 0)
**		{
**			*(mem_line + (2 * j)) = ' ';
**		}
*/
	}
	j = (2 * j) + (j / 2);
	while (j < 40)
	{
		*(mem_line + j) = ' ';
		j++;
	}
}

static void		fill_memory_bytes_char(unsigned char *addr, size_t length, char *mem_line)
{
	size_t			j;
	unsigned char	c;

	j = 0;
	while (j < 16 && j < length)
	{
		c = *(addr + j);
		*(mem_line + j) = (32 <= c && c <= 126) ? (char)c : '.';
		j++;
	}
	if (j < 16)
	{
		*(mem_line + j) = '\n';
		*(mem_line + j + 1) = '\0';
	}
}

/*
** 1 ligne :
** -> 8 * (2 octets) * (4 caracteres + 1 espace)
** -> 16 caracteres + 1 retour a la ligne
** -> 1 caractere de fin de chaine
*/

void			print_memory(const void *addr, size_t size)
{
	char			mem_line[MEM_LINE_LENGTH];
	size_t			i;

	prepare_mem_line((char *)mem_line);
	i = 0;
	while (i < size)
	{
		fill_memory_addr_hexa(&(*(((unsigned char *)addr) + i)), &(*(((char *)mem_line) + 0)), "0123456789abcdef");
		fill_memory_bytes_hexa(&(*(((unsigned char *)addr) + i)), size - i, &(*(((char *)mem_line) + 11)), "0123456789abcdef");
		fill_memory_bytes_char(&(*(((unsigned char *)addr) + i)), size - i, &(*(((char *)mem_line) + 51)));
//		write(1, (char *)mem_line, 57);
		ft_putstr((char *)mem_line);
		i = i + 16;
	}
}

/*
**int	main(void)
**{
**	int	tab[10] = {0, 23, 150, 255,
**	              12, 16,  42, 103};
**
**	print_memory(tab, sizeof(tab));
**	return (0);
**}
*/

