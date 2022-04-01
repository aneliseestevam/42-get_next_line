/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-legacy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelise <anelise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:46:10 by coder             #+#    #+#             */
/*   Updated: 2022/03/31 22:04:55 by anelise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// get line with the buffer return
static char *get_buffer_return(char fd, char *line)
{
    char    *buffer;
    char    *pos;
    int     size;
    int     control;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    // printf("buffer :: %d\n", buffer);
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    size = 1;
    control = 0;
    while (size != 0)
    {
        size = read(fd, buffer, BUFFER_SIZE);
        if (size == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[size] = '\0';
        pos = line;
        line = ft_strjoin(pos, buffer);
        free(pos);
        if (ft_strchr(line, '\n'))
            control = 1;
    }
    printf("line > %s", line);
    free(buffer);
    return (line);
}

// save line
static char *save_line(char *line)
{
    size_t  size;
    
    if (line[0] == '\0')
        return (NULL);
    if (ft_strchr(line, '\n'))
    {
        size = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n'));
        return (ft_substr(line, 0, size));
    }
    else
        return (ft_substr(line, 0, ft_strlen(line)));
}

// update line
static char	*upgrade_line(char *line)
{
	size_t	size;
	char	*pos;

	if (ft_strchr(line, '\n'))
	{
		size = ft_strlen(ft_strchr(line, '\n'));
		if (size != 1)
		{
			pos = line;
			line = ft_substr(ft_strchr(pos, '\n'), 1, size - 1);
			free(pos);
			return (line);
		}
	}
	free(line);
	return (NULL);
}

char        *get_next_line(int fd)
{
    static char	*line; // string buffer for the next function call
    char		*get_line; // string to be returned at current function call

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = get_buffer_return(fd, line);
    if (!line)
        return (NULL);
    get_line = save_line(line);
    // line = upgrade_line(line);
    // printf("%d", get_line);
    return (get_line);
}
