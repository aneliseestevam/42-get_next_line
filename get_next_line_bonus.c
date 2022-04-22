/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestevam <aestevam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:54 by aestevam          #+#    #+#             */
/*   Updated: 2022/04/22 09:09:17 by aestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char     *set_backup(int fd, char *backup, char *buffer)
{
    int         read_buffer;
    int         find_break_line;
    char        *temp;

    read_buffer = 1;
    find_break_line = 0;
    while (find_break_line == 0 && read_buffer != 0)
    {
        read_buffer = read(fd, buffer, BUFFER_SIZE);
        if (read_buffer == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_buffer] = '\0';
        if (!backup)
            backup = ft_strdup("");
        temp = backup;
        backup = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(backup, '\n'))
            find_break_line = 1;
    }
    free(buffer);
    return (backup);
}

static char     *save_line(char *backup)
{
    int         i;
    char        *line;

    i = 0;
    while (backup[i] && backup[i] != '\n')
        i++;
    line = (char *) malloc (sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    ft_strlcpy(line, backup, i + 2);
    if (line[0] == '\0')
    {
        free(line);
        return (NULL);
    }
    return (line);
}

static char     *save_remains(char *backup)
{
    int         i;
    char        *remains;

    i = 0;
    while (backup[i] && backup[i] != '\n')
        i++;
    if (backup[i] == '\0')
    {
        free(backup);
        return (NULL);
    }
    remains = (char *) malloc (sizeof(char) * (ft_strlen(backup) - i + 1));
    if (!remains)
        return (NULL);
    ft_strlcpy(remains, backup + i + 1, ft_strlen(backup) - i + 1);
    free(backup);
    return (remains);
}

char            *get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    static char *backup[OPEN_MAX];

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    backup[fd] = set_backup(fd, backup[fd], buffer);
    if (!backup[fd])
        return (NULL);
    line = save_line(backup[fd]);
    backup[fd] = save_remains(backup[fd]);
    return (line);
}
