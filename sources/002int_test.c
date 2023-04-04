/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   002int_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:52 by mviinika          #+#    #+#             */
/*   Updated: 2023/03/17 13:53:04 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <limits.h>

static void loop_implementation(int list[])
{
	int pad = 0;
	int ret = 0;
	int	i = 0;

	dup2(open("results/ft_printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i <= 9)
	{
		ret =	ft_printf("This is a test [%*d] [%50.*d] [% *d] [%-100.*d] [%100.*d] [% 100.d] [%#100.d]\n", pad, list[i], pad, list[i], pad, list[i], pad, list[i], pad, list[i], list[i], list[i]);
		ft_printf("%d\n", ret);
		pad += 5;
		i++;
	}
}

static void loop_original(int list[])
{
	int pad = 0;
	int ret = 0;
	int	i = 0;

	dup2(open("results/printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i <= 9)
	{
		ret = printf("This is a test [%*d] [%50.*d] [% *d] [%-100.*d] [%100.*d] [% 100.d] [%#100.d]\n", pad, list[i], pad, list[i], pad, list[i], pad, list[i], pad, list[i], list[i], list[i]);
		printf("%d\n", ret);
		pad += 5;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int list[10] = {INT_MIN, 0, 1, 11, 111, 123456, -54321, -1, 999888, INT_MAX};
	
	loop_implementation(list);
	loop_original(list);
	return (0);
}
