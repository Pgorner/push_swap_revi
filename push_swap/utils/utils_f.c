/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:33:49 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/07 15:24:31 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	let_s(t_s *stacks, int flag)
{
	if (flag == A)
	{
		sa(stacks);
		ft_printf("sa\n");
	}
	if (flag == B)
	{
		sb(stacks);
		ft_printf("sb\n");
	}
	if (flag == S)
	{
		sa(stacks);
		sb(stacks);
		ft_printf("ss\n");
	}
}

void	let_r(t_s *stacks, int flag)
{
	if (flag == A)
	{
		ra(stacks);
		ft_printf("ra\n");
	}
	if (flag == B)
	{
		rb(stacks);
		ft_printf("rb\n");
	}
	if (flag == R)
	{
		ra(stacks);
		rb(stacks);
		ft_printf("rr\n");
	}
}

void	let_rr(t_s *stacks, int flag)
{
	if (flag == A)
	{
		rra(stacks);
		ft_printf("rra\n");
	}
	if (flag == B)
	{
		rrb(stacks);
		ft_printf("rrb\n");
	}
	if (flag == R)
	{
		rra(stacks);
		rrb(stacks);
		ft_printf("rrr\n");
	}
}

void	let_p(t_s *stacks, int flag)
{
	if (flag == A)
	{
		pa(stacks);
		ft_printf("pa\n");
	}
	if (flag == B)
	{
		pb(stacks);
		ft_printf("pb\n");
	}
}

void	flags(t_s *stacks, int let, int flag)
{
	if (let == S)
		let_s(stacks, flag);
	if (let == R)
		let_r(stacks, flag);
	if (let == RR)
		let_rr(stacks, flag);
	if (let == P)
		let_p(stacks, flag);
}
