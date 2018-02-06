/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryshac <kryshac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:15:51 by kryshac           #+#    #+#             */
/*   Updated: 2018/02/06 19:11:17 by kryshac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

int	ft_stack_a_min(t_swap *list)
{
	int min;
	int ret;

	min = list->l_a[list->i_a];
	ret = 'a';
	if (list->l_a[list->i_a - 1] < min)
	{
		min = list->l_a[list->i_a - 1];
		ret = 'b';
	}
	if (list->l_a[list->i_a - 2] < min)
	{
		min = list->l_a[list->i_a - 2];
		ret = 'c';
	}
	if (list->l_a[1] < min)
	{
		min = list->l_a[1];
		ret = 'd';
	}
	if (list->l_a[0] < min)
	{
		min = list->l_a[0];
		ret = 'e';
	}
	return (ret);
}