#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int		ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (!(*(str1 + i) == '\0' || *(str2 + i) == '\0') \
		&& *(str1 + i) == *(str2 + i))
	{
		i++;
	}
	return ((int)(*(str2 + i) - *(str1 + i)));
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (!(*(str + i) == '\0'))
	{
		i++;
	}
	return (i);
}

static char		*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	if (!(dst = (char *)malloc(ft_strlen(src) * sizeof(char))))
	{
		return (NULL);
	}
	i = 0;
	while (!(*(src + i) == '\0'))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

static void		display_ids(void)
{
	uid_t	ruid;
	uid_t	euid;
	uid_t	suid;
	gid_t	rgid;
	gid_t	egid;
	gid_t	sgid;

	getresuid(&ruid, &euid, &suid);
	getresgid(&rgid, &egid, &sgid);
	printf("ruid: %d | euid: %d | suid: %d\n", ruid, euid, suid);
	printf("rgid: %d | egid: %d | sgid: %d\n", rgid, egid, sgid);
}

int				main(void)
{
	char	*scanf_ret;
	char	str_buf[9] = { 'P', 'a', 't', 'a', 't', 'r', 'a', '\n', '\0' };
	char	*str_ptr;

	display_ids();
	if (!(str_ptr = ft_strdup("Totoro\n")))
	{
		printf("Erreur d'allocation memoire\n");
	}
	else
	{
		printf("Target address: %p\n", str_ptr);
		printf("Type \"exit\" and press ENTER to quit program\n");
		scanf_ret = NULL;
		while (scanf_ret == NULL)
		{
			scanf("%ms", &scanf_ret);
			if (ft_strcmp(scanf_ret, "exit"))
			{
				free(scanf_ret);
				scanf_ret = NULL;
			}
		}
		free(scanf_ret);
		free(str_ptr);
	}
	return (0);
}
