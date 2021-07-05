/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/05 14:54:10 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_putendl_color(char *str, char *color)
** Same as ft_putendl, but will write the str string
** in the specified color, then reset the color to default
** If *color is an invalid colour, the argument will be written instead!
** Always returns to_return argument
*/

int	ft_putendl_color(char *str, char *color, int to_return, int fd)
{
	ft_putstr(color, fd);
	ft_putendl(str, fd);
	ft_putstr(COLOR_RESET, fd);
	return (to_return);
}
