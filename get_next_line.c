/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelise <anelise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:46:10 by coder             #+#    #+#             */
/*   Updated: 2022/03/31 22:19:44 by anelise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char            *get_buffer_return(int fd, char *line, char *buffer)
{
    int         size_read;
    int         len;
    char        *pos;

    size_read = 1;
    len = 0;
    while (len == 0 && size_read != 0)
    {
        size_read = read(fd, buffer, BUFFER_SIZE);
        // printf("size_read :: %d\n", size_read);
        if (size_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[size_read] = '\0';
        if (!line)
            line = ft_strdup("");
        pos = line;
        line = ft_strjoin(pos, buffer);
        // printf("line :: %s", line);
        free(pos);
        if (ft_strchr(line, '\n'))
            len = 1;
    }
    free(buffer);
    return (line);
}

static char     *save_line(char *tmp)
{
    int         i;
    char        *line;
    
    i = 0;
    while (tmp[i] && tmp[i] != '\0')
        i++;
    line = (char *) malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    printf("line :: %s", line);
    return (line);
}

static char     *upgrade_tmp(char *tmp)
{
    return (0);
}

char            *get_next_line(int fd)
{
    static char *line;
    char        *buffer;
    char		*get_line;
    
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    line = get_buffer_return(fd, line, buffer);
    // printf("tmp :: %s", tmp);
    if (!line)
        return (NULL);
    get_line = save_line(line);
    line = upgrade_tmp(line);
    // printf("line :: %s", line);
    return (line);
}
