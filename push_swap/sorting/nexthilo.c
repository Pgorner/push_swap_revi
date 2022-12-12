/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexthilo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:29 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 19:46:58 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nextlowernumber(t_s *stacks, int i)
{
	int	low;
	int	j;

	j = 0;
	low = 0;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[low]) < ft_atoi(stacks->b[j])
			&& ft_atoi(stacks->b[j]) < ft_atoi(stacks->a[i]))
			low = j;
		++j;
	}
	if (ft_atoi(stacks->b[low]) > ft_atoi(stacks->a[i]))
		return (-1);
	else
		return (low);
}

int	nexthighernumber(t_s *stacks, int i)
{
	int hi;
	int j;

	hi = 0;
	j = 0;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[hi]) < ft_atoi(stacks->b[j]))
			hi = j;
		++j;
	}
	j = 0;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[hi]) > ft_atoi(stacks->b[j])
		&& ft_atoi(stacks->b[j]) > ft_atoi(stacks->a[i]))
				hi = j;
		++j;
	}
	if (ft_atoi(stacks->b[hi]) < ft_atoi(stacks->a[i]))
		return (-1);
	else
		return (hi);
}

void	position(t_s *stacks, int i)
{
	int k;
	int j;

	k = (0 - nextlowernumber(stacks, i)) * -1;
	j = size(stacks->b) - nextlowernumber(stacks, i) + 1;
	if (i > j)
		stacks->speed = stacks->speed + j;
	else
		stacks->speed = stacks->speed + k;
}

int	actionhilow(t_s *stacks, int i)
{
	if (placereturn(stacks, nexthighernumber(stacks, i))
	> placereturn(stacks, nextlowernumber(stacks, i))
	|| (nexthighernumber(stacks, i) == -1))
		if (nextlowernumber(stacks, i) != -1)
			return (nextlowernumber(stacks, i));
	if (placereturn(stacks, nexthighernumber(stacks, i))
	< placereturn(stacks, nextlowernumber(stacks, i))
	|| (nextlowernumber(stacks, i) == -1))
		return (nexthighernumber(stacks, i));
	if (nextlowernumber(stacks, i) != -1)
		return (nextlowernumber(stacks, i));
	else
		return (nexthighernumber(stacks, i));
}
