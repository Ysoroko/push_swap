/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 14:52:32 by ysoroko          ###   ########.fr       */
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

int	ft_putendl_color(char *str, char *color, int to_return)
{
	ft_putstr(color);
	ft_putendl(str);
	ft_putstr(COLOR_RESET);
	return (to_return);
}
