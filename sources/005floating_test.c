/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   005floating_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:30:39 by mviinika          #+#    #+#             */
/*   Updated: 2023/03/17 13:53:19 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <limits.h>

static void loop_implementation(float list[])
{
	int pad = 0;
	int ret = 0;
	int	i = 0;
	int prec = 0;

	dup2(open("results/ft_printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i < 10)
	{
		while (prec <= 20)
		{
			ret = ft_printf("This is a test [%*f] [%*.*f] [%0*f] [%0*.*f] [%-0*.*f]\n", pad, list[i], pad, prec, list[i], pad, list[i], pad, prec, list[i], pad, prec, list[i]);
			ft_printf("%d\n", ret);
			pad += 4;
			prec++;
		}
		pad = 0;
		prec = 0;
		i++;
	}
}

static void loop_original(float list[])
{
	int pad = 0;
	int ret = 0;
	int	i = 0;
	int prec = 0;

	dup2(open("results/printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (i < 10)
	{
		while (prec <= 20)
		{
			ret = printf("This is a test [%*f] [%*.*f] [%0*f] [%0*.*f] [%-0*.*f]\n", pad, list[i], pad, prec, list[i], pad, list[i], pad, prec, list[i], pad, prec, list[i]);
			printf("%d\n", ret);
			pad += 4;
			prec++;
		}
		pad = 0;
		prec = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	float list[10] = {1.00,
					-0.00075, 
					1.0, 
					-1999.999,
					1.79769313486231570,
					-1.79769313486231570,
					23372036854775807.001,
					-0.9999999999999999,
					0.9999999999999999,
					-1.00};
	
	loop_implementation(list);
	loop_original(list);
	return (0);
}

