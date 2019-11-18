/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:08:50 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/18 12:00:52 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_num(t_fractol *image)
{
	int i;
	int max;
	double x;
	double y;
	double x_new;

	max = 200;
	image->row = 0;
	image->col = 0;
	while (image->row < image->height)
	{
		while (image->col < image->width)
		{
			image->c_real = (image->col - image->width / 2) * 4 / image->width;
			image->c_imag = (image->row - image->height / 2) * 4 / image->width;
			x = 0;
			y = 0;
			i = 0;
			while (x * x + y * y <= 4 && i < max)
			{
				x_new = x * x - y * y + image->c_real;
				y = 2 * x * y + image->c_real;
				x = x_new;
				i++;
			}
			if (i < max)
				mlx_pixel_put(image->mlx, image->window, image->col, image->row,0xffffff);
			else
				mlx_pixel_put(image->mlx, image->window, image->col, image->row,0xfffff);
			image->col++;
		}
		image->row++;
	}
}

int main(void)
{
	t_fractol *image;

	image = (t_fractol*)malloc(sizeof(t_fractol));

	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, 1000, 1000, "Title");
	// image->window = mlx_new_image(image->mlx,1000,1000);
	put_num(image);
	mlx_pixel_put(image->mlx, image->window, 500,100,0xffffff);
	// mlx_new_image(image->mlx, 500, 500);
	mlx_loop(image->mlx);
	return(0);
}