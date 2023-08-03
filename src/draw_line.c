/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:23:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/03 01:18:47 by bkaztaou         ###   ########.fr       */
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

static int	ft_sp(t_fdf *fdf, t_point *pt, char dir)
{
	int	start_pos;
	int	win_pos;
	int	shape_pos;

	if (dir == 'x')
	{
		win_pos = fdf->win.win_w / 2;
		shape_pos = (fdf->map.x * (fdf->win.win_h / 30)) / 2;
		start_pos = win_pos - shape_pos + pt->x0;
	}
	else
	{
		win_pos = fdf->win.win_h / 2;
		shape_pos = (fdf->map.y * (fdf->win.win_h / 30)) / 2;
		start_pos = win_pos - shape_pos + pt->y0;
	}
	return (start_pos);
}

void	bresenhams(t_fdf *fdf, t_point pt, char dir)
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
		ft_putpixel(fdf, ft_sp(fdf, &pt, 'x'), ft_sp(fdf, &pt, 'y'), 0xFFFFFF);
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
