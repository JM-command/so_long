/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoelho- <jcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:28:34 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/08/03 16:38:38 by jcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_data(t_data *data)
{
	data->player.x = 0;
	data->player.y = 0;
	data->player.img_len = 0;
	data->player.step = 0;
	data->money_count = 0;
	data->player.step = 0;
	data->player.count = 0;
	data->max_money_count = 0;
	data->map.exit = 0;
	return (MLX_SSUCCESS);
}

void	malloc_struct(t_data *data, int len, char **s)
{
	char	*name;

	if (len != 2)
		send_error(data, "Argument inccorect.");
	name = ft_strnstr(s[1], ".ber", ft_strlen(s[1]));
	if (name == NULL || ft_strlen(name) != 4)
		send_error(data, "Fail extension");
	if (init_data(data))
		send_error(data, "Init data failed.");
	if (malloc_map(data, s[1]))
		send_error(data, "Malloc failed.");
}

int	ft_close(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	malloc_struct(data, argc, argv);
	data->mlx_ptr = mlx_init();
	data->win_x = (data->map.width - 1) * IMG_RES;
	data->win_y = data->map.height * IMG_RES;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_x, data->win_y, "./so_long");
	if (data->win_ptr == NULL)
		send_error(data, "win_ptr = null");
	init_texture(data);
	render(data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, (void *)data);
	mlx_key_hook(data->win_ptr, deal_key, (void *)data);
	mlx_loop(data->mlx_ptr);
	return (MLX_SSUCCESS);
}
