/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:44:59 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 22:12:33 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_rrb(t_swap *list)
{
	int	tmp;
	int	i;

	tmp = list->l_b[0];
	i = 0;
	while (i < list->i_b)
	{
		list->l_b[i] = list->l_b[i + 1];
		i++;
	}
	list->l_b[list->i_b] = tmp;
	list->oper++;
	ft_printf("(--->ft_rrb<---)\n");
}