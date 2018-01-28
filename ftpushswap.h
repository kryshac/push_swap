/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpushswap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:56:46 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/28 23:18:15 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPUSHSWAP_H
# define FTPUSHSWAP_H

# include "ft_printf/ftprintf.h"

typedef struct	s_swap
{
	int			*l_a;
	int			*l_b;
	int			i_a;
	int			i_b;
	int			max_a;
	int			min_a;
	int			max;
	int			oper;
	int			b_1;
	int			b_2;
	int			b_3;
	int			b_1_dir;
	int			b_2_dir;
	int			b_3_dir;
}				t_swap;

void			ft_push_swap(int size, char **str);
void			ft_sa(t_swap *list);
void			ft_sb(t_swap *list);
void			ft_ss(t_swap *list);
void			ft_pa(t_swap *list);
void			ft_pb(t_swap *list);
void			ft_ra(t_swap *list);
void			ft_rb(t_swap *list);
void			ft_rr(t_swap *list);
void			ft_rra(t_swap *list);
void			ft_rrb(t_swap *list);
void			ft_rrr(t_swap *list);
void			ft_algoritm(t_swap *list);
void			ft_print_stack(t_swap *list);
void			ft_move_top(t_swap *list, int move);
void			ft_move_bootm(t_swap *list, int move);
int				ft_max_three(int a, int b, int c);
int				ft_min_three(int a, int b, int c);
void			ft_order_end(t_swap *list);

void			ft_order_three(t_swap *list);
#endif
