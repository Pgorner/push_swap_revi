/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:16:03 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/08 15:09:02 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_s *stacks)
{
	if (size(stacks->a) != 0 || size(stacks->a) != 1)
	{
		stacks->tmp[0] = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = stacks->tmp[0];
	}
}

void	pa(t_s *stacks)
{
	int i;

	i = size(stacks->a) + 1;
	if (size(stacks->b) != -1)
	{
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			--i;
		}
		i = 0;
		stacks->a[0] = stacks->b[0];
		while (i <= size(stacks->b))
		{
			stacks->b[i] = stacks->b[i + 1];
			++i;
		}
		stacks->b[i] = NULL;
	}
}

void	ra(t_s *stacks)
{
	int	i;
	int	j;

	j = 0;
	i = size(stacks->a);
	stacks->tmp[0] = stacks->a[0];
	while (j < i)
	{
		stacks->a[j] = stacks->a[j + 1];
		++j;
	}
	stacks->a[i] = stacks->tmp[0];
}

void	rra(t_s *stacks)
{
	int	i;

	i = size(stacks->a);
	stacks->tmp[0] = stacks->a[i];
	while (i >= 1)
	{
		stacks->a[i] = stacks->a[i - 1];
		--i;
	}
	stacks->a[0] = stacks->tmp[0];
}
