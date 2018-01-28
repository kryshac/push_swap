/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:44:59 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 22:12:26 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_rra(t_swap *list)
{
	int	tmp;
	int	i;

	tmp = list->l_a[0];
	i = 0;
	while (i < list->i_a)
	{
		list->l_a[i] = list->l_a[i + 1];
		i++;
	}
	list->l_a[list->i_a] = tmp;
	list->oper++;
	ft_printf("(--->ft_rra<---)\n");
}