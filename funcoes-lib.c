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

// para usar meu join precisaria de mais uma função... além das que eu já coloquei no projeto
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