/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:19:21 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 16:13:06 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_sa(t_swap *list)
{
	int	i;

	i = list->i_a;
	list->l_a[i] += list->l_a[i - 1];
	list->l_a[i - 1] = list->l_a[i] - list->l_a[i - 1];
	list->l_a[i] -= list->l_a[i - 1];
	list->oper++;
}