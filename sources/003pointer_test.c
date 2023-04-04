/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   003pointer_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:44:13 by mviinika          #+#    #+#             */
/*   Updated: 2023/03/17 13:53:11 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf/ft_printf.h"
#include <fcntl.h>

static void loop_implementation(void *p)
{
	int pad = 0;
	int ret = 0;

	dup2(open("results/ft_printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (pad <= 100)
	{
		ret =	ft_printf("This is a test [%20p] [%*p] [%-*p]\n", p, pad, p, pad, p);
		ft_printf("%d\n", ret);
		pad++;
	}
}

static void loop_original(void *p)
{
	int pad = 0;
	int ret = 0;

	dup2(open("results/printf_result.txt", O_CREAT | O_RDWR, 0755), STDOUT_FILENO);
	while (pad <= 100)
	{
		ret = printf("This is a test [%20p] [%*p] [%-*p]\n", p,pad, p, pad, p);
		printf("%d\n", ret);
		pad++;
	}
}

int	main(void)
{

	char *s = "TestString       1  2  3  4  5  6  8  9  0 TEST    ";
	void *p = s;

	loop_implementation(p);
	loop_original(p);
	return (0);
}
