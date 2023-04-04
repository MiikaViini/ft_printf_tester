/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   007percentage_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:21:11 by mviinika          #+#    #+#             */
/*   Updated: 2023/03/17 13:53:30 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <limits.h>

static void loop_implementation()
{
	int pad = 0;
	int ret = 0;
	int	i = 0;

	dup2(open("results/ft_printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i <= 127)
	{
		ret =	ft_printf("This is a test [%*%] [%50.*%] [% *%] [%-100.*%] [%100.*%] [% 100.%]\n", pad, pad, pad, pad, pad);
		ft_printf("%d\n", ret);
		pad += 2;
		i++;
	}
}

static void loop_original()
{
	int pad = 0;
	int ret = 0;
	int	i = 0;

	dup2(open("results/printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i <= 127)
	{
		ret = printf("This is a test og[%*%] [%50.*%] [% *%] [%-100.*%] [%100.*%] [% 100.%]\n", pad, pad, pad, pad, pad);
		printf("%d\n", ret);
		pad += 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	loop_implementation();
	loop_original();
	return (0);
}