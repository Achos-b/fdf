/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 07:40:24 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/02 07:43:08 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:23:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/02 07:39:55 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	set_incs(int p0, int p1)
{
	if (p0 < p1)
		return (1);
	return (-1);
}

static int	set_err(int dx, int dy)
{
	if (dx > dy)
		return (dx / 2);
	return (-dy / 2);
}

static int	check_dir(t_point *pt, char dir)
{
	if (dir == 'x')
		return (pt->x0 != pt->x1);
	return (pt->y0 != pt->y1);
}

void	bresenhams(t_image *img, t_point pt, char dir)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs(pt.x1 - pt.x0);
	dy = abs(pt.y1 - pt.y0);
	pt.xinc = set_incs(pt.x0, pt.x1);
	pt.yinc = set_incs(pt.y0, pt.y1);
	err = set_err(dx, dy);
	while (check_dir(&pt, dir))
	{
		ft_putpixel(img, pt.x0, pt.y0, 0xFFFFFF);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pt.x0 += pt.xinc;
		}
		if (e2 < dy)
		{
			err += dx;
			pt.y0 += pt.yinc;
		}
	}
}
