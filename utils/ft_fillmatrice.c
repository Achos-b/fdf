/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmatrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:20:51 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/30 03:23:25 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fillmatrice(char *stash, t_map *map)
{
	int		i;
	int		j;
	char	**rows;
	char	**column;

	map->matrice = malloc(sizeof(int *) * map->y);
	i = -1;
	while (++i < map->y)
		map->matrice[i] = malloc(sizeof(int) * map->x);
	rows = ft_split(stash, '\n');
	i = -1;
	while (rows[++i])
	{
		column = ft_split(rows[i], ' ');
		j = -1;
		while (column[++j])
			map->matrice[i][j] = ft_atoi(column[j]);
		ft_freematrice(column);
	}
	ft_freematrice(rows);
	free(stash);
}
