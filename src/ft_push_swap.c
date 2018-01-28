/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:34:59 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/27 00:13:12 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_push_swap(int size, char **str)
{
	t_swap	list;
	int		i;

	list.oper = 0;
	list.i_a = size - 1;
	list.i_b = -1;
	list.max = size - 1;
	i = size - 1;
	list.l_a = (int *)malloc(sizeof(int) * size);
	list.l_b = (int *)malloc(sizeof(int) * size);
	while (*str)
	{
		list.l_a[i] = ft_atoi(*str++);
		list.l_b[i] = 0;
		i--;
	}
	ft_algoritm(&list);
}
