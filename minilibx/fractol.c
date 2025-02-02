/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:44:52 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/02 09:15:28 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "stdlib.h"


int main()
{
    
    
    // int i = 50;
    // int a = 50;
    void *mlx_connection;
    void *mlx_window;
    mlx_connection = mlx_init();
    if(!mlx_connection)
        return (1);
    mlx_window = mlx_new_window(mlx_connection,
                    500,
                    500,
                    "My Fucking first window huho");
    // while (a < 450)
    // {
    //     i = 50;
    //     while (i < 450)
    //     {
    //         // mlx_pixel_put(mlx_connection,
    //         //                 mlx_window,
    //         //                 250 + i,
    //         //                 250 + i,
    //         //                 0xf7fcfc);
    //         // mlx_pixel_put(mlx_connection,
    //         //                 mlx_window,
    //         //                 250 + i,
    //         //                 a,
    //         //                 0xf7fcfc);
    //         mlx_pixel_put(mlx_connection,
    //                         mlx_window,
    //                         a,
    //                         i,
    //                         rand() % 0x1000000);
    //         i++;
    //     }
    //     a++;
    // }
    // mlx_string_put(mlx_connection,
    //                 mlx_window,
    //                 500 * 0.8,
    //                 500 * 0.98,
    //                 0xff0000,
    //                 "My project");
    // i = 0;
    // while (i > -100)
    // {
    //     mlx_pixel_put(mlx_connection,
    //                     mlx_window,
    //                     250 + i,
    //                     250 + i,
    //                     0xf7fcfc);
    //     mlx_pixel_put(mlx_connection,
    //                     mlx_window,
    //                     250 + i,
    //                     250,
    //                     0xf7fcfc);
    //     mlx_pixel_put(mlx_connection,
    //                     mlx_window,
    //                     250,
    //                     250 + i,
    //                     0xf7fcfc);
    //     i--;
    // }
    // free(mlx)
    mlx_loop(mlx_connection);
    mlx_destroy_window(mlx_connection, mlx_window);
}