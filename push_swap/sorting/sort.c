/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:54:05 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 20:43:23 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small(t_s *stacks)
{
	if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[1]) < ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[2]) > ft_atoi(stacks->a[0]))
		flags(stacks, S, A);
	else if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[2]) < ft_atoi(stacks->a[0]))
	{
		flags(stacks, S, A);
		flags(stacks, RR, A);
	}
	else if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[1]) < ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[2]) < ft_atoi(stacks->a[0]))
		flags(stacks, R, A);
	else if (ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[2]) > ft_atoi(stacks->a[0]))
	{
		flags(stacks, S, A);
		flags(stacks, R, A);
	}
	else if (ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[2]) < ft_atoi(stacks->a[0]))
		flags(stacks, RR, A);
}

void	place(t_s *stacks, int i)
{
	int hi;
	int lo;
	int o;

	hi = 0;
	lo = 0;
	o = i;
	while (o <= size(stacks->a))
	{
		++o;
		++lo;
	}
	o = i;
	while (o > 0)
	{
		--o;
		++hi;
	}
	//if ()
	if (hi > lo)
		stacks->speed = lo;
	else if (lo > hi)
		stacks->speed = hi;
	else if (lo == hi)
		stacks->speed = lo;
}

int	placereturn(t_s *stacks, int i)
{
	int hi;
	int lo;
	int o;

	hi = 0;
	lo = 0;
	o = i;
	while (o <= size(stacks->a))
	{
		++o;
		++lo;
	}
	o = i;
	while (o > 0)
	{
		--o;
		++hi;
	}
	if (hi > lo)
		return (lo);
	else if (lo > hi)
		return (hi);
	else if (lo == hi)
		return (lo);
	return (0);
}

int	actionreturn(t_s *stacks, int i)
{
	int hi;
	int lo;
	int o;

	hi = 0;
	lo = 0;
	o = i;
	while (o <= size(stacks->a))
	{
		++o;
		++lo;
	}
	o = i;
	while (o > 0)
	{
		--o;
		++hi;
	}
	if (hi > lo)
		return (1);
	else if (lo > hi)
		return (2);
	else if (lo == hi)
		return (1);
	return (0);
}

void	operations(t_s *stacks)
{
	int i;

	stacks->num = 0;
	stacks->ispeed = INT_MAX;
	stacks->prevspeed = INT_MAX;
	i = 0;
		while (i <= size(stacks->a))
	{
		place(stacks, i); // finds out fastest way to get num from a to top
		placeb(stacks, i);
		if (stacks->speed < stacks->prevspeed
			&& stacks->speed < stacks->ispeed)
		{
			stacks->ispeed = stacks->speed;
			stacks->num = i;
		}
/* 		printf("bfprevspeed: %d\n", stacks->prevspeed);
		printf("    speed: %d\n", stacks->speed);
		printf("      num: %d\n\n", stacks->num); */
		stacks->prevspeed = stacks->speed;
		stacks->speed = 0;
		++i;
	}
}

void	sortit(t_s *stacks)
{
	int i;
	int j;

	j = 0;
	i = ft_atoi(stacks->a[stacks->num]);
	if (actionreturn(stacks, stacks->num) == 1)
		while (i != ft_atoi(stacks->a[0]))
			flags(stacks, RR, A);
	if (actionreturn(stacks, stacks->num) == 2)
		while (i != ft_atoi(stacks->a[0]))
			flags(stacks, R, A);
	//printf("next lower number in stack to %s is %s\n", stacks->a[stacks->num], stacks->b[nextlowernumber(stacks, i)]);
	//printf("next higher number in stack to %s is %s\n", stacks->a[stacks->num], stacks->b[nexthighernumber(stacks, i)]);
	j = ft_atoi(stacks->b[actionhilow(stacks, stacks->num)]);
	if (j > ft_atoi(stacks->a[0]))
		while (j != ft_atoi(stacks->b[size(stacks->b)]))
			flags(stacks, R, B);
	if (j < ft_atoi(stacks->a[0]))
		while (j != ft_atoi(stacks->b[0]))
			flags(stacks, RR, B);
	flags(stacks, P, B);
}

void	sort(t_s *stacks)
{
	int j;

	flags(stacks, P, B);
	while (size(stacks->a) != 2)
	{
		j = 0;
		while (j<4)
		{
			//printf("stack a: %s stack b: %s\n", stacks->a[j], stacks->b[j]);
			j++;
		}
		operations(stacks);
		sortit(stacks);
	}
	j = 0;
	while (j<4)
	{
		//printf("stack a: %s stack b: %s\n", stacks->a[j], stacks->b[j]);
		j++;
	}
	sort_small(stacks);
}
