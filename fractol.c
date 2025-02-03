/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:44:52 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/03 13:39:02 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "stdlib.h"
#include <X11/keysym.h>
#include <stdio.h>
#include "unistd.h"

typedef struct node2
{
    void *img_ptr;
    char *img_pixels_ptr;
    int bits_per_pixel;
    int endian;
    int line_len;
}   t_img;

typedef struct node
{
    void *data1;
    void *data2;
    int color;
    int hieght;
    int width;
    double zoom;
    t_img img;
} t_str;

int close_for_window(int num, t_str *data)
{
    if(num == XK_Escape)
    {
        mlx_destroy_window(data->data1, data->data2);
        mlx_destroy_display(data->data1);
        free(data->data1);
        free(data);
        printf("don\n");
        exit(0);
    }
    printf("the %d key is her\n", num);
    // mlx_destroy_display(data);
    // free(data);
    return (0);
}

int close_window(t_str *data)
{
        mlx_destroy_window(data->data1, data->data2);
        mlx_destroy_image(data->data1, data->img.img_ptr);
        mlx_destroy_display(data->data1);
        // mlx_destroy_display(data->img.img_ptr);
        free(data->data1);
        // free(data->img.img_pixels_ptr);
        free(data);
        exit(0);
        // return (0);

}

void my_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
    *((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void color_change(t_str *data, int color)
{
    for(int x = 0; x < data->width; x++)
    {
        for(int y = 0; y < data->hieght; y++)
        {
            // mlx_pixel_put(data->data1, data->data2, x, y, color);
            my_pixel_put(&data->img, x, y, color);
        }
    }
    // (void)color;
    //  for(int x = 250; x < 750; x++)
    // {
    //     for(int y = 250; y < 750; y++)
    //     {
    //         // mlx_pixel_put(data->data1, data->data2, x, y, color);
    //         my_pixel_put(&data->img, x, y, 0xff0000);
    //     }
    // }
}

int change_color(t_str *data)
{
    mlx_string_put(data->data1, data->data2, 250, 250, data->color, "Brahim");
    if(data->color == 0xff0000)
        data->color = 0x00ff00;
    else if(data->color == 0x00ff00)
        data->color = 0x0000ff;
    else 
        data->color = 0xff0000;
    return (1);
}

int f(int num, t_str *data)
{
    if(num == XK_c)
    {
        color_change(data, rand() % 0x1000000);
    }
    // if(num == XK_r)
    //     color_change(data, 0xff0000);
    // else if(num == XK_g)
    //     color_change(data, 0x00ff00);
    // else if(num == XK_b)
    //     color_change(data, 0x0000ff);
    mlx_put_image_to_window(data->data1, data->data2, data->img.img_ptr,
                                0, 0);
    // (void)data;
    // printf("key %d\n", num);
    // sleep(20);
    return (1);
}


int mouse_hook(int button, int x, int y, t_str *data)
{
    (void)x;
    (void)y;
    if (button == 4)
        data->zoom *= 1.1;
    else if (button == 5)
        data->zoom /= 1.1;
    return (0);
}


int main()
{
    // int i = 50;
    // int a = 50;
    t_str *mlx_data;

    mlx_data = malloc(sizeof(t_str));
    if(!mlx_data)
        return (1);
    // mlx_data = NULL;
    // mlx_data->data1 = NULL;
    // mlx_data->data2 = NULL;
    // void *mlx_win;
    // void *mlx_window;
    // mlx_win = NULL;
    // mlx_window = NULL;
    // mlx_data->color = 0xff0000;
    
    mlx_data->hieght = 1000;
    mlx_data->width = 1000;
    mlx_data->zoom = 1.0;
    mlx_data->data1 = mlx_init();
    if(!mlx_data->data1)
        return (1);
    mlx_data->data2 = mlx_new_window(mlx_data->data1,
                    mlx_data->width,
                    mlx_data->hieght,
                    "My Fucking first window huho");

    mlx_key_hook(mlx_data->data2, f, mlx_data);
    mlx_hook(mlx_data->data2, 17, 0, close_window, mlx_data);
    mlx_data->img.img_ptr = mlx_new_image(mlx_data->data1, mlx_data->width, mlx_data->hieght);
    mlx_data->img.img_pixels_ptr = mlx_get_data_addr(mlx_data->img.img_ptr,
                                                        &mlx_data->img.bits_per_pixel,
                                                        &mlx_data->img.line_len,
                                                        &mlx_data->img.endian);
    mlx_mouse_hook(mlx_data->data2, mouse_hook, mlx_data);
    mlx_loop_hook(mlx_data->data1, change_color, mlx_data);
    mlx_loop(mlx_data->data1);
}