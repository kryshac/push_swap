/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:47:13 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 22:58:32 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_order_three(t_swap *list)
{
	if (list->l_a[2] > list->l_a[0])
		ft_ra(list);
	if (list->l_a[2] > list->l_a[1])
		ft_sa(list);
	if (list->l_a[1] > list->l_a[0])
		ft_rra(list);
	if (list->l_a[2] > list->l_a[1])
		ft_sa(list);
	list->max_a = ft_max_three(list->l_a[0], list->l_a[1], list->l_a[2]);
	list->min_a = ft_min_three(list->l_a[0], list->l_a[1], list->l_a[2]);
}