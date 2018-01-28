/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:22:13 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 22:12:39 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_ra(t_swap *list)
{
	int	tmp;
	int	i;

	tmp = list->l_a[list->i_a];
	i = list->i_a;
	while (i > 0)
	{
		list->l_a[i] = list->l_a[i - 1];
		i--;
	}
	list->l_a[0] = tmp;
	list->oper++;
	ft_printf("(--->ft_ra<---)\n");
}