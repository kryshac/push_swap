/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:32:24 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 16:13:10 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftpushswap.h"

void	ft_sb(t_swap *list)
{
	int	i;

	i = list->i_b;
	list->l_b[i] += list->l_b[i - 1];
	list->l_b[i - 1] = list->l_b[i] - list->l_b[i - 1];
	list->l_b[i] -= list->l_b[i - 1];
	list->oper++;
}