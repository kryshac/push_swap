/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:10:37 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 19:23:15 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_print_stack(t_swap *list)
{
	int	i;
	int	a;
	int	b;

	a = list->i_a;
	b = list->i_b;
	i = ft_max(a, b);
	while (i >= 0)
	{
		if (a >= i)
			ft_printf("%3d ", list->l_a[i]);
		else
			ft_printf("    ");
		if (b >= i)
			ft_printf("%3d", list->l_b[i]);
		else
			ft_printf("   ");
		ft_printf("   %d\n", i);
		i--;
	}
	ft_printf("\n  -   -\n  a   b\n");
}