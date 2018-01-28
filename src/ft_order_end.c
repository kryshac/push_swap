/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:14:27 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 23:21:58 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_order_end(t_swap *list)
{
	int	i;

	i = 0;
	while (list->l_a[i] != list->min_a)
		i++;
	if (i > list->i_a / 2)
		ft_move_top(list, list->i_a - i);
	else
		ft_move_bootm(list, i + 1);
}