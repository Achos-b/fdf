/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:39:45 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/01 01:47:16 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_flatmap(int fd, t_map *map)
{
	char	*line;
	char	*stash;
	char	**rows;
	char	*trim;

	stash = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trim = ft_strtrim(line, "\n");
		rows = ft_split(trim, ' ');
		map->x = ft_matricelen(rows);
		stash = ft_strjoin(stash, line);
		ft_freematrice(rows);
		free(trim);
		map->y++;
	}
	return (stash);
}
