/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelise <anelise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:46:10 by coder             #+#    #+#             */
/*   Updated: 2022/03/31 12:59:42 by anelise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// get line with the buffer return
static char *get_buffer_return(char fd, char *line)
{
    char    *buffer;
    int     size;
    char    *pos;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    // printf("out of while >> %s <<\n" , buffer);
    size = read(fd, buffer, BUFFER_SIZE);
    while (!ft_strchr(line, '\n') || !ft_strchr(line, '\0'))
    {
        pos = line;
        line = ft_strjoin(pos, buffer);
        size = read(fd, buffer, BUFFER_SIZE);
    }
    printf("\n pos > %s", line);
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
        size = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n') + 1);
        return (ft_substr(line, 0, size));
    }
    else
        return (ft_substr(line, 0, ft_strlen(line)));
}

// update line


char        *get_next_line(int fd)
{
    static char	*line; // string buffer for the next function call
    char		*get_line; // string to be returned at current function call

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = get_buffer_return(fd, &line);
    if (!line)
        return (NULL);
    get_line = save_line(line);
    // printf("%d", get_line);
    return (line);
}
