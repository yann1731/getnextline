#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	count;

	start = ft_strlen(dst);
	count = 0;
	if (start + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	while (*src && start < (dstsize - 1))
	{
		dst[start] = *src;
		src++;
		start++;
	}
	dst[start] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cd;

	cd = 0;
	if (dstsize == 0)
	{
		while (src[cd])
			cd++;
		return (cd);
	}
	cd = 0;
	while (cd < dstsize - 1 && src[cd])
	{
		dst[cd] = src[cd];
		cd++;
	}
	if (dstsize != 0)
		dst[cd] = '\0';
	cd = 0;
	while (src[cd])
		cd++;
	return (cd);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	count;

	start = ft_strlen(dst);
	count = 0;
	if (start + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	while (*src && start < (dstsize - 1))
	{
		dst[start] = *src;
		src++;
		start++;
	}
	dst[start] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ns;
	size_t		start;
	size_t		i;
	size_t		k;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	start = ft_strlen(s1);
	i = 0;
	k = 0;
	ns = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	ft_strlcat(ns, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	return (ns);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}