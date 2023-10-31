/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:51:18 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_TYPES_H
# define MLX_BOOST_TYPES_H

# include <stddef.h>

# include "mlx_boost_list_types.h"

# define FALSE	(0)
# define TRUE	(1)

# define RDONLY	(0)
# define RDWR	(1)

typedef int				t_boost_color;
typedef int				t_boost_bool;
typedef t_boost_bool	t_boost_err;
typedef int				t_component_mode;

typedef struct s_boost_pixel
{
	int					x;
	int					y;
}	t_boost_pixel;

typedef struct s_boost_component
{
	t_component_mode	mode;
	char				*name;
	void				*mlx_ptr;
	void				*img;
	int					width;
	int					height;
	int					*mlx_data_addr;
	int					bpp;
	int					line_size;
	int					endian;
}	t_boost_component;

typedef struct s_boost
{
	void				*mlx;
	void				*win;
	t_boost_pixel		win_size;
	t_boost_list		components;
}	t_boost;







#endif