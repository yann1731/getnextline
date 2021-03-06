#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char *re_alloc(int c, size_t len, char *tofree)
{
	char *rstr;
	size_t			cd;
	unsigned char	cout;
	unsigned char	*ptr;

	rstr = NULL;
	rstr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ptr = (unsigned char *) rstr;
	cout = (unsigned char) c;
	cd = 0;
	while (cd < len)
	{
		*ptr = cout;
		ptr++;
		cd++;
	}
	free(tofree);
	return (rstr);
}

size_t	findline(char *s, char c, size_t *i)
{
	size_t	index;

	index = *i;
	while (s[index])
	{
		if (s[index] == c)
		{
			*i = index + 1;
			return (1);
		}
		index++;
	}
	*i = index;
	return (0);
}

char *read_line(char *s, size_t *ptr, char *buffer)
{
	char	*nstr;
	size_t	count;
	size_t	index;

	index = *ptr;
	count = 0;
	if (s[index] == '\0')
	{
		free(buffer);
		free(s);
		return (NULL);
	}
	while (s[index] != '\n' && s[index] != '\0')
	{
		count++;
		index++;
	}
	if (s[index] == '\0')
		*ptr = index;
	if (s[index] == '\n')
		*ptr = index + 1;
	free(buffer);
	nstr = ft_substr(s, (index - count), count + 1);
	return (nstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*ns;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	ns = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	ft_strlcat(ns, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	free(s1);
	s1 = NULL;
	return (ns);
}

char    *get_next_line(int fd)
{
	static char		*str;
	static char		*buf;
	static size_t	index;
	static size_t	index2;
	int				res;

	res = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (index == 0)
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (res != 0 && findline(str, '\n', &index2) != 1)
	{
		buf = re_alloc('\0', (BUFFER_SIZE + 1), buf);
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		str = ft_strjoin(str, buf);
		buf = re_alloc('\0', (BUFFER_SIZE + 1), buf);
	}
	return (buf = read_line(str, &index, buf));
}
