/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:56:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/02 10:06:53 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	initialize_pt(int i, int j, t_window *win, char dir)
{
	t_point	pt;
	int		seg;

	seg = (win->win_h / 30);
	if (dir == 'x')
	{
		pt.x0 = j * seg;
		pt.x1 = (j * seg) + seg;
		pt.y0 = i * seg;
		pt.y1 = i * seg;
	}
	else
	{
		pt.x0 = j * seg;
		pt.x1 = j * seg;
		pt.y0 = i * seg;
		pt.y1 = (i * seg) + seg;
	}
	pt.xinc = 0;
	pt.yinc = 0;
	return (pt);
}

void	read_map(int fd, t_window *win, t_image *img, t_map *map)
{
	char	*stash;
	int		i;
	int		j;

	stash = ft_flatmap(fd, map);
	ft_fillmatrice(stash, map);
	i = -1;
	j = -1;
	while (++i <= map->y)
	{
		j = -1;
		while (++j <= map->x)
		{
			if (j < map->x)
				bresenhams(img, initialize_pt(i, j, win, 'x'), 'x');
			if (i < map->y)
				bresenhams(img, initialize_pt(i, j, win, 'y'), 'y');
		}
	}
}
