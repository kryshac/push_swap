/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_min_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryshac <kryshac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:15:51 by kryshac           #+#    #+#             */
/*   Updated: 2018/02/06 19:31:21 by kryshac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

static void     ft_stacka_pa(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[list->i_a];
		(*ret)++;
	}
	else if (list->l_a[list->i_a] > list->l_b[list->i_b])
	{
		*min = list->l_a[list->i_a] + list->l_b[list->i_b];
		(*ret)++;
	}
}

static void     ft_stacka_pb(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[list->i_a - 1];
		(*ret)++;
	}
	else if (list->l_a[list->i_a - 1] > list->l_b[list->i_b])
	{
		*min = list->l_a[list->i_a - 1] + list->l_b[list->i_b];
		(*ret)++;
	}
}

static void     ft_stacka_pc(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[list->i_a - 2];
		(*ret)++;
	}
	else if (list->l_a[list->i_a - 2] > list->l_b[list->i_b])
	{
		*min = list->l_a[list->i_a - 2] + list->l_b[list->i_b];
		(*ret)++;
	}
}

static void     ft_stacka_pf(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[list->i_a - 3];
		(*ret)++;
	}
	else if (list->l_a[list->i_a - 3] > list->l_b[list->i_b])
	{
		*min = list->l_a[list->i_a - 3] + list->l_b[list->i_b];
		(*ret)++;
	}
}
static void     ft_stacka_pg(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[2];
		(*ret)++;
	}
	else if (list->l_a[2] > list->l_b[list->i_b])
	{
		*min = list->l_a[2] + list->l_b[list->i_b];
		(*ret)++;
	}
}
static void     ft_stacka_pd(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[1];
		(*ret)++;
	}
	else if (list->l_a[1] > list->l_b[list->i_b])
	{
		*min = list->l_a[1] + list->l_b[list->i_b];
		(*ret)++;
	}
}
static void     ft_stacka_pe(t_swap *list, int *min, int *ret)
{
    if (list->i_b == -1)
	{
		*min = list->l_a[0];
		(*ret)++;
	}
	else if (list->l_a[0] > list->l_b[list->i_b])
	{
		*min = list->l_a[0] + list->l_b[list->i_b];
		(*ret)++;
	}
}

int	ft_stack_a_min_b(t_swap *list)
{
	int	min;
	int min_tmp;
	int	ret;
	int ret_tmp;
	int	cas;

	min_tmp = 0;
	ret = 0;
	ret_tmp = 0;
	min = 0;
	ft_stacka_pa(list, &min_tmp, &ret_tmp);
	if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	{
		min = min_tmp;
		cas = 'a';
		ret = ret_tmp;
	}
	ft_stacka_pb(list, &min_tmp, &ret_tmp);
	if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	{
		min = min_tmp;
		cas = 'b';
		ret = ret_tmp;
	}
	ft_stacka_pc(list, &min_tmp, &ret_tmp);
	if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	{
		min = min_tmp;
		cas = 'c';
		ret = ret_tmp;
	}
	ft_stacka_pd(list, &min_tmp, &ret_tmp);
	if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	{
		min = min_tmp;
		cas = 'd';
		ret = ret_tmp;
	}
	ft_stacka_pe(list, &min_tmp, &ret_tmp);
	if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	{
		min = min_tmp;
		cas = 'e';
		ret = ret_tmp;
	}
	// ft_stacka_pf(list, &min_tmp, &ret_tmp);
	// if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	// {
	// 	min = min_tmp;
	// 	cas = 'f';
	// 	ret = ret_tmp;
	// }
	// ft_stacka_pg(list, &min_tmp, &ret_tmp);
	// if (ret != ret_tmp && (ret_tmp == 1 || min_tmp < min))
	// {
	// 	min = min_tmp;
	// 	cas = 'g';
	// 	ret = ret_tmp;
	// }

	ft_printf("-->ret: %c\n", cas);
	return (cas);
}