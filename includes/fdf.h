/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:19:59 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/27 18:18:38 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_window
{
	int		win_w;
	int		win_h;
	void	*mlx_win;
	void	*mlx;
}	t_window;

typedef struct s_map
{
	int	x;
	int	y;
	int	**matrice;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

void	read_map(int fd, t_map *map);
void	ft_error(char *err);
char	*ft_newline(char *str);
char	*get_next_line(int fd);

#endif
