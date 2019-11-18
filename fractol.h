/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:08:58 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/17 17:27:57 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct t_fractol
{
	void *mlx;
	void *window;
	void *img_ptr;
	int row;
	int col;
	int height;
	int width;
	double c_real;
	double c_imag;
	// double x;
	// double y;

}				t_fractol;
