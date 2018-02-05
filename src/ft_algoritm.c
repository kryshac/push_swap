/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:05:09 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/30 18:27:49 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

int		ft_pos(t_swap *list, int nb)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (i <= list->i_a)
	{
		if (nb > list->max_a)
		{
			if (list->l_a[i] == list->max_a)
				pos = i > 0 ? i - 1 : list->i_a;
		}
		else if (nb < list->min_a)
		{
			if (list->l_a[i] == list->min_a)
				pos = i;
		}
		else if (i == 0 && nb > list->l_a[0] && nb < list->l_a[list->i_a])
			pos = list->i_a;
		else if (i < list->i_a && nb < list->l_a[i] && nb > list->l_a[i + 1])
			pos = i;
		i++;
	}
	return (pos);
}

int		ft_calc_pos(t_swap *list, int nb, int *dir)
{
	int	pos;
	int	calc;

	pos = ft_pos(list, nb);
	// ft_printf("--->numar - %d, pozitie - %d\n", nb, pos);
	// ft_printf("    pos(%d) > list->i_a / 2(%d)\n", pos, list->i_a / 2);
	if (pos >= list->i_a / 2)
	{
		calc = list->i_a - pos;
		*dir = 1;
	}
	else
	{
		calc = pos + 1;
		*dir = 0;
	}
	// ft_printf("<---numar - %d, pozitie - %d\n", nb, calc);
	return (calc);
}

void	ft_move_a(t_swap *list)
{
	// ft_printf("->ft_move_a\n");
	list->b_1 -= 1;
	if (list->b_1_dir == 1)
		ft_move_top(list, list->b_1);
	else
		ft_move_bootm(list, list->b_1);
	ft_pa(list);
	if (list->l_a[list->i_a] > list->max_a)
		list->max_a = list->l_a[list->i_a];
	else if (list->l_a[list->i_a] < list->min_a)
		list->min_a = list->l_a[list->i_a];
}

void	ft_move_b(t_swap *list)
{
	// ft_printf("->ft_move_b\n");
	list->b_2 -= 2;
	if (list->b_2_dir == 1)
		ft_move_top(list, list->b_2);
	else
		ft_move_bootm(list, list->b_2);
	ft_best_move_b(list);
	//ft_sb(list);
	ft_pa(list);
	if (list->l_a[list->i_a] > list->max_a)
		list->max_a = list->l_a[list->i_a];
	else if (list->l_a[list->i_a] < list->min_a)
		list->min_a = list->l_a[list->i_a];
}

void	ft_move_c(t_swap *list)
{
	// ft_printf("->ft_move_c\n");
	list->b_3 -= 2;
	// ft_printf("<-- %d\n", list->b_3);
	if (list->b_3_dir == 1)
		ft_move_top(list, list->b_3);
	else
		ft_move_bootm(list, list->b_3);
	ft_rrb(list);
	ft_pa(list);
	if (list->l_a[list->i_a] > list->max_a)
		list->max_a = list->l_a[list->i_a];
	else if (list->l_a[list->i_a] < list->min_a)
		list->min_a = list->l_a[list->i_a];
}

void	ft_min_three_pos(t_swap *list)
{
	list->b_1 = ft_calc_pos(list, list->l_b[list->i_b], &list->b_1_dir) + 1;
	list->b_2 = ft_calc_pos(list, list->l_b[list->i_b - 1], &list->b_2_dir) + 2;
	list->b_3 = ft_calc_pos(list, list->l_b[0], &list->b_3_dir) + 2;
	if (list->b_1 < list->b_2)
	{
		if (list->b_1 < list->b_3)
			ft_move_a(list);
		else
			ft_move_c(list);
	}
	else if (list->b_2 < list->b_3)
		ft_move_b(list);
	else
		ft_move_c(list);
}

void	ft_min_two_pos(t_swap *list)
{
	list->b_1 = ft_calc_pos(list, list->l_b[list->i_b], &list->b_1_dir) + 1;
	list->b_2 = ft_calc_pos(list, list->l_b[list->i_b - 1], &list->b_2_dir) + 2;
	if (list->b_1 < list->b_2)
		ft_move_a(list);
	else
		ft_move_b(list);
}

void	ft_min_one_pos(t_swap *list)
{
	list->b_1 = ft_calc_pos(list, list->l_b[list->i_b], &list->b_1_dir) + 1;
	ft_move_a(list);
}

void	ft_move_in_b(t_swap *list)
{
	int	a;
	int	b;
	int	c;

	if (list->i_b >= 0)
	{	
		if (list->l_a[list->i_a] > list->l_b[list->i_b] &&
			(list->l_a[list->i_a - 1] < list->l_b[list->i_b] || list->l_a[list->i_a] < list->l_a[list->i_a - 1]) &&
			(list->l_a[0] < list->l_b[list->i_b] || list->l_a[list->i_a] < list->l_a[0]))
			ft_pb(list);
		else if (list->l_a[list->i_a - 1] > list->l_b[list->i_b] &&
			(list->l_a[list->i_a] < list->l_b[list->i_b] || list->l_a[list->i_a - 1] < list->l_a[list->i_a]) &&
			(list->l_a[0] < list->l_b[list->i_b] || list->l_a[list->i_a - 1] < list->l_a[0]))
		{
			ft_sa(list);
			ft_pb(list);
		}
		else if (list->l_a[0] > list->l_b[list->i_b] &&
			(list->l_a[list->i_a] < list->l_b[list->i_b] || list->l_a[0] < list->l_a[list->i_a]) &&
			(list->l_a[list->i_a - 1] < list->l_b[list->i_b] || list->l_a[0] < list->l_a[list->i_a - 1]))
		{
			ft_rra(list);
			ft_pb(list);
		}
		else
		{
			a = list->l_a[list->i_a];
			b = list->l_a[list->i_a - 1];
			c = list->l_a[0];
	
			if (a < b)
			{
				if (a < c)
					ft_pb(list);
				else
				{
					ft_rra(list);
					ft_pb(list);
				}
			}
			else if (b < c)
			{
				if (list->l_a[list->i_a - 2] < list->l_a[0])
					ft_ra(list);
				else
					ft_sa(list);
				ft_pb(list);
			}
			else
			{
				ft_rra(list);
				ft_pb(list);
			}
		}
	}
	else
	{
		a = list->l_a[list->i_a] - list->l_b[list->i_b];
		b = list->l_a[list->i_a - 1] - list->l_b[list->i_b];
		c = list->l_a[0] - list->l_b[list->i_b];

		if (a < b)
		{
			if (a < c)
				ft_pb(list);
			else
			{
				ft_rra(list);
				ft_pb(list);
			}
		}
		else if (b < c)
		{
			if (list->l_a[list->i_a - 2] < list->l_a[0])
				ft_ra(list);
			else
				ft_sa(list);
			ft_pb(list);
		}
		else
		{
			ft_rra(list);
			ft_pb(list);
		}
	}
}

void	ft_algoritm(t_swap *list)
{
	ft_print_stack(list);
	while (list->i_a > 2)
	{
		//ft_print_stack(list);
		ft_move_in_b(list);
		ft_pb(list);
	}
		//ft_pb(list);
	//list->max_a = 15;
	// ft_print_stack(list);
	ft_order_three(list);
	while (list->i_b >= 0)
	{
		ft_print_stack(list);
		if (list->i_b > 1)
			ft_min_three_pos(list);
		else if (list->i_b > 0)
			ft_min_two_pos(list);
		else
			ft_min_one_pos(list);
	}
	//ft_printf("a - %d\n", ft_count_mv(list, list->l_b[list->i_b]));
	// ft_printf("b - %d\n", ft_count_mv(list, 'b'));
	// ft_printf("c - %d\n", ft_count_mv(list, 'c'));
	//ft_print_stack(list);
	ft_order_end(list);
	ft_print_stack(list);
	ft_printf("operatii - %d\n", list->oper);
}
// rra ridica in sus
// 78 25 20 34 92 97 33 93 47 51 63 64 89 26 31 37 38