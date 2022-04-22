/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestevam <aestevam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:55 by aestevam          #+#    #+#             */
/*   Updated: 2022/04/22 08:04:27 by aestevam         ###   ########.fr       */
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

	file = open("musica_do_dia.txt", 500);
	line = get_next_line(file);
	// printf("%s", line);
	free(line);
	return (0);
}
