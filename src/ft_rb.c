/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:22:13 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/29 15:44:21 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_rb(t_swap *list)
{
	int	tmp;
	int	i;

	tmp = list->l_b[list->i_b];
	i = list->i_b;
	while (i > 0)
	{
		list->l_b[i] = list->l_b[i - 1];
		i--;
	}
	list->l_b[0] = tmp;
	list->oper++;
	ft_printf("rb\n");
}