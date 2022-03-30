/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelise <anelise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 06:13:14 by aestevam          #+#    #+#             */
/*   Updated: 2022/03/30 14:12:09 by anelise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str_c;
	unsigned char	c_c;

	str_c = (char *)s;
	c_c = (unsigned char)c;
	while (*str_c)
	{
		if (*str_c == c_c)
			return (str_c);
		str_c++;
	}
	if (c_c == '\0' && *str_c == '\0')
		return (str_c);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (dup == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(dup, s1, len);
	return (dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc ((len1 + len2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcat(dst, s2, (len1 + len2 + 1));
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc (sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
