#include <unistd.h>
#include <string.h>

#define BYTES_PER_LINE 16
#define ADDR_FIELD_LENGTH 18
#define HEXA_FIELD_LENGTH (BYTES_PER_LINE * 2) + ((BYTES_PER_LINE / 2) - 1)
#define MEM_LINE_LENGTH (ADDR_FIELD_LENGTH + 1 + HEXA_FIELD_LENGTH + 1 \
					+ BYTES_PER_LINE + 2)

/*
** MEM_LINE_LENGTH = (10 + 1) + (32 + 7 + 1) + (16 + 2)
**                 = 11 + 40 + 18
**                 = 69
*/
/*
** Nombre de caracteres a ecrire sur la sortie standard par ligne :
** (10 + 1) + (32 + 7 + 1) + (? + 1) = 11 + 40 + ? + 1
**                                   = 52 + ?
*/

/*
**static size_t	ft_strlen(char *str)
**{
**	size_t			i;
**
**	i = 0;
**	while (!(*(str + i) == '\0'))
**	{
**		i++;
**	}
**	return (i);
**}
**
**static void		ft_putstr(char *str)
**{
**	write(1, str, ft_strlen(str));
**}
*/

static void		prepare_mem_line(char *mem_line)
{
	size_t			i;

	*(mem_line + 0) = '0';
	*(mem_line + 1) = 'x';
	*(mem_line + ADDR_FIELD_LENGTH) = '\t';
	i = 0;
	while (i < (BYTES_PER_LINE / 2))
	{
		*(mem_line + (5 * i) + (ADDR_FIELD_LENGTH + 5)) = ' ';
		i++;
	}
	*(mem_line + (MEM_LINE_LENGTH - 2)) = '\n';
	*(mem_line + (MEM_LINE_LENGTH - 1)) = '\0';
}

static void		fill_memory_addr_hexa(const void *start_addr, char *mem_line, \
														const char *hexabase)
{
	size_t			j;

	j = ADDR_FIELD_LENGTH - 2;
	while (j > 0)
	{
		j--;
		*(mem_line + (ADDR_FIELD_LENGTH - 1) - j) = (char)(*(hexabase + \
					((((unsigned long int)start_addr) >> (2 * j)) % 16)));
	}
}

static void		fill_memory_bytes_hexa(unsigned char *addr, size_t length, \
										char *mem_line, const char *hexabase)
{
	size_t			j;
	unsigned char	c;

	j = 0;
	while (j < BYTES_PER_LINE && j < length)
	{
		c = *(addr + j);
		*(mem_line + (2 * j) + (j / 2)) = (char)(*(hexabase + ((c >> 4) % 16)));
		*(mem_line + (2 * j) + (j / 2) + 1) = (char)(*(hexabase + (c % 16)));
		j++;
	}
	j = (2 * j) + (j / 2);
	while (j < HEXA_FIELD_LENGTH)
	{
		*(mem_line + j) = ' ';
		j++;
	}
}

static void		fill_memory_bytes_char(unsigned char *addr, size_t length, \
																char *mem_line)
{
	size_t			j;
	unsigned char	c;

	j = 0;
	while (j < BYTES_PER_LINE && j < length)
	{
		c = *(addr + j);
		*(mem_line + j) = (32 <= c && c <= 126) ? (char)c : '.';
		j++;
	}
	if (j < BYTES_PER_LINE)
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

void			print_memory(const void *start_addr, const void *addr, \
																	size_t size)
{
	char			mem_line[MEM_LINE_LENGTH];
	size_t			i;

	prepare_mem_line((char *)mem_line);
	i = 0;
	while (i < size)
	{
		fill_memory_addr_hexa(&(*(((unsigned char *)start_addr) + i)), \
				&(*(((char *)mem_line) + 0)), "0123456789abcdef");
		fill_memory_bytes_hexa(&(*(((unsigned char *)addr) + i)), size - i, \
				&(*(((char *)mem_line) \
					+ (ADDR_FIELD_LENGTH + 1))), "0123456789abcdef");
		fill_memory_bytes_char(&(*(((unsigned char *)addr) + i)), size - i, \
				&(*(((char *)mem_line) \
					+ (ADDR_FIELD_LENGTH + HEXA_FIELD_LENGTH + 2))));
		write(1, (char *)mem_line, (i + BYTES_PER_LINE < size) \
				? MEM_LINE_LENGTH - 1
				: ADDR_FIELD_LENGTH + HEXA_FIELD_LENGTH + (size - i) + 3);
		i = i + BYTES_PER_LINE;
	}
}

/*
** int				main(void)
** {
** 	int	tab[10] = {0, 23, 150, 255,
** 	              12, 16,  42, 103};
** 
** 	print_memory((void *)0, tab, sizeof(tab));
** 	return (0);
** }
*/

