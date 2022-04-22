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
    int         b_read;
    int         find;
    char        *temp;

    b_read = 1;
    find = 0;
    while (find == 0 && b_read != 0)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        // printf("buffer :: %s\n", buffer);
        // printf("fd :: %d\n", fd);
        // printf("line :: %s\n", line);
        if (b_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[b_read] = '\0';
        // printf("buffer :: %s\n", buffer);
        // printf("line :: %s", line);
        if (!line)
            line = ft_strdup("");
            // printf("line :: %s", line);
        temp = line;
        // printf("line :: %s", line);
        line = ft_strjoin(temp, buffer);
        // printf("line :: %s", line);
        // printf("temp :: %s", temp);
        free(temp);
        // printf("temp :: %s", temp);
        if (ft_strchr(line, '\n'))
            find = 1;
            // printf("line :: %s", line);
    }
    free(buffer);
    return (line);
}

static char     *save_line(char *temp)
{
    int         i;
    char        *line;
    
    i = 0;
    while (temp[i] && temp[i] != '\0')
        i++;
    line = (char *) malloc(sizeof(char) * (i + 2));
    // printf("line :: %s", line);
    if (!line)
        return (NULL);
    ft_strlcpy(line, temp, i + 2);
    if (line[0] == '\0') 
    {
        // printf("line :: %s", line);
        free(line);
        return (NULL);
    }
    // printf("line :: %s", line);
    return (line);
}

static char     *upgrade_temp(char *temp)
{
    int     i;
    char    *new_temp;

    i = 0;
    while (temp[i] && temp[i] != '\n')
        i++;
    if  (temp[i] == '\0')
    {
        free(temp);
        return (NULL);
    }
    new_temp = (char *) malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
    if (!new_temp)
        return (NULL);
    ft_strlcpy(new_temp, temp + i + 1, ft_strlen(temp) - i + 1);
    free(temp);
    return (new_temp);
}

char            *get_next_line(int fd)
{
    static char *line;
    char        *buffer;
    char		*get_line;
    
    get_line = NULL;
    // printf("fd :: %d\n", fd);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    // printf("line :: %s", line);
    line = get_buffer_return(fd, line, buffer);
    // printf("buffer :: %s", buffer);
    // printf("line :: %s", line);
    if (!line)
        return (NULL);
    get_line = save_line(line);
    printf("line :: %s", get_line);
    line = upgrade_temp(line);
    // printf("line :: %s", line);
    // printf("line :: %s", get_line);
    return (get_line);
}
