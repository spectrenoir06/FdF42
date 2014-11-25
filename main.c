/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:37:23 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/25 17:37:26 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int		mouse_press(int button, int x, int y, void *param)
{
	return (0);
}

int		key_press(int keycode, void *param)
{
	printf("%d = %c\n", keycode, keycode);
	return (0);
}

int		loop(void *param)
{
	printf("test\n");
	sleep(1);
	return (0);
}

int		main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	t_env	env = {mlx, win};

	mlx_key_hook(env.win, key_press, &env);
	mlx_mouse_hook(env.win, mouse_press, &env);
	mlx_loop_hook(env.mlx, loop, &env);
	mlx_loop(env.mlx);

}