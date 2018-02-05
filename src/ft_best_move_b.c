/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_move_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:31:25 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/29 15:09:59 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_best_move_b(t_swap *list)
{
	int	a;
	int	b;
	int	c;

	a = ft_abs(list->l_b[list->i_b - 1] - list->l_b[list->i_b]);
	b = ft_abs(list->l_b[list->i_b - 1] - list->l_b[list->i_b - 2]);
	c = ft_abs(list->l_b[list->i_b - 1] - list->l_b[0]);
	if (a < b)
	{
		if (a < c)
			ft_rb(list);
		else
			ft_sb(list);
	}
	else if (b < c)
		ft_rb(list);
	else
		ft_sb(list);
}