/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   001string_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:52 by mviinika          #+#    #+#             */
/*   Updated: 2023/03/17 13:52:57 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf/ft_printf.h"
#include <fcntl.h>

static int loop_implementation(char *str)
{
	int pad = 0;
	int ret = 0;

	dup2(open("results/ft_printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (pad <= 100)
	{
		ret = ft_printf("This is a test [%*s] [%50.*s] [%-100.*s] [%100.*s] \n", pad, str, pad, str, pad, str, pad, str);
		ft_printf("%d\n", ret);
		pad++;
	}
	return (0);
}

static int loop_original(char *str)
{
	int pad = 0;
	int ret = 0;

	dup2(open("results/printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (pad <= 100)
	{
		ret = printf("This is a test [%*s] [%50.*s] [%-100.*s] [%100.*s] \n", pad, str, pad, str, pad, str, pad, str);
		printf("%d\n", ret);
		pad++;
	}
	return (0);
}

int	main(void)
{
	char *s = "TestString       1  2  3  4  5  6  8  9  0 TEST    ";

	loop_implementation(s);
	loop_original(s);
	return (0);
}
