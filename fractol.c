/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reginanureeva <reginanureeva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:08:50 by rnureeva          #+#    #+#             */
/*   Updated: 2019/11/18 13:59:46 by reginanuree      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void put_num(t_fractol *image)
{
	int i;
	int max;
	double x;
	double y;
	double x_new;

	printf("(1)\n");
	max = 100;
	image->height = 500;
	image->width = 500;
	image->row = 0;
	image->col = 0;
	while (image->row < image->height)
	{
		while (image->col < image->width)
		{
			image->c_real = (image->col - image->width / 2) * 4 / image->width;
			image->c_imag = (image->row - image->height / 2) * 4 / image->height;
			x = 0;
			y = 0;
			i = 0;
			while (x * x + y * y <= 16 && i < max)
			{
				x_new = x * x - y * y + image->c_real;
				y = 2 * x * y + image->c_imag;
				x = x_new;
				i++;
			}
			if (i < max)
				mlx_pixel_put(image->mlx, image->window, image->col, image->row, 0xffffff);
			else
				mlx_pixel_put(image->mlx, image->window, image->col, image->row, 0xfffff);
			image->col++;
		}
		// printf("(%d, %d): %d\n", image->row, image->col, i);
		image->col = 0;
		image->row++;
	}
}

int main(void)
{
	t_fractol *image;

	image = (t_fractol *)malloc(sizeof(t_fractol));

	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, 1000, 1000, "Title");
	// image->window = mlx_new_image(image->mlx,1000,1000);
	put_num(image);
	// mlx_pixel_put(image->mlx, image->window, 500,100,0xffffff);
	// mlx_new_image(image->mlx, 500, 500);
	mlx_loop(image->mlx);
	return (0);
}
