/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelise <anelise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:55 by aestevam          #+#    #+#             */
/*   Updated: 2022/03/31 11:00:16 by anelise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		file;
	char	*line;
	int		i;

	file = open("musica_do_dia.txt", 256);
	for (i = 0; i <= 1; i++)
	{
		line = get_next_line(file);
		// printf("%s", line);
		free(line);
	}
	return (0);
}
