/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexthilo_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:29 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 20:41:48 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nextlowernumberb(t_s *stacks, int i)
{
	int	low;
	int	j;

	j = 0;
	low = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[low]) < ft_atoi(stacks->a[j])
			&& ft_atoi(stacks->a[j]) < ft_atoi(stacks->b[i]))
			low = j;
		++j;
	}
	if (ft_atoi(stacks->a[low]) > ft_atoi(stacks->b[i]))
		return (-1);
	else
		return (low);
}

int	nexthighernumberb(t_s *stacks, int i)
{
	int hi;
	int j;

	hi = 0;
	j = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[hi]) < ft_atoi(stacks->a[j]))
			hi = j;
		++j;
	}
	j = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[hi]) > ft_atoi(stacks->a[j])
		&& ft_atoi(stacks->a[j]) > ft_atoi(stacks->b[i]))
				hi = j;
		++j;
	}
	if (ft_atoi(stacks->a[hi]) < ft_atoi(stacks->b[i]))
		return (-1);
	else
		return (hi);
}

void	positionb(t_s *stacks, int i)
{
	int k;
	int j;

	k = (0 - nextlowernumberb(stacks, i)) * -1;
	j = size(stacks->a) - nextlowernumberb(stacks, i) + 1;
	if (i > j)
		stacks->speed = stacks->speed + j;
	else
		stacks->speed = stacks->speed + k;
}


int	actionhilowb(t_s *stacks, int i)
{
	//printf("placereturnhi: %i placereturnlow: %i\n", placereturn(stacks, nexthighernumberb(stacks, i)), placereturn(stacks, nextlowernumberb(stacks, i)));
	if (placereturn(stacks, nexthighernumberb(stacks, i))
	> placereturn(stacks, nextlowernumberb(stacks, i))
	|| (nextlowernumberb(stacks, i) == -1))
			return (nexthighernumberb(stacks, i));
	if (placereturn(stacks, nexthighernumberb(stacks, i))
	< placereturn(stacks, nextlowernumberb(stacks, i))
	|| (nexthighernumberb(stacks, i) == -1))
			return (nextlowernumberb(stacks, i));
	return (nextlowernumberb(stacks, i));
}
/* int	actionhilowb(t_s *stacks, int i)
{
	if (placereturn(stacks, nexthighernumberb(stacks, i))
	> placereturn(stacks, nextlowernumberb(stacks, i))
	|| (nexthighernumberb(stacks, i) == -1))
		if (nextlowernumberb(stacks, i) != -1)
			return (nexthighernumberb(stacks, i));
	if (placereturn(stacks, nexthighernumberb(stacks, i))
	< placereturn(stacks, nextlowernumberb(stacks, i))
	|| (nextlowernumberb(stacks, i) == -1))
		return (nextlowernumberb(stacks, i));
	else
		return (nexthighernumberb(stacks, i));
} */

