/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:31:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/19 01:56:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <fdf.h>
#include <libft.h>

void exitf(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	exitm(void *mem)
{
	if (mem == NULL)
		exitf();
}

void	usage(void)
{
	ft_putendl("Usage: ./fdf file...");
	exit(0);
}
