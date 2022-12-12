/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:54:05 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 20:46:45 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	placeb(t_s *stacks, int i)
{
	int hi;
	int lo;
	int o;

	hi = 0;
	lo = 0;
	o = i;
	while (o <= size(stacks->b))
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

void	placea(t_s *stacks, int i)
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

int	actionreturnb(t_s *stacks, int i)
{
	int hi;
	int lo;
	int o;

	hi = 0;
	lo = 0;
	o = i;
	while (o <= size(stacks->b))
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

void	operationsb(t_s *stacks)
{
	int i;

	stacks->num = 0;
	stacks->ispeed = INT_MAX;
	stacks->prevspeed = INT_MAX;
	i = 0;
		while (i <= size(stacks->b))
	{
		placeb(stacks, i); // finds out fastest way to get num from a to top
		placea(stacks, i);
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

void	sortitb(t_s *stacks)
{
	int i;
	int j;

	j = 0;
	i = ft_atoi(stacks->b[stacks->num]);
	if (actionreturnb(stacks, stacks->num) == 1)
		while (i != ft_atoi(stacks->b[0]))
			flags(stacks, RR, B);
	if (actionreturnb(stacks, stacks->num) == 2)
		while (i != ft_atoi(stacks->b[0]))
			flags(stacks, R, B);
	//printf("next lower number in stack to %s is %s\n", stacks->a[stacks->num], stacks->b[nextlowernumber(stacks, i)]);
	//printf("next higher number in stack to %s is %s\n", stacks->a[stacks->num], stacks->b[nexthighernumber(stacks, i)]);
	j = 0;
	while (j<4)
	{
		//printf("stack a: %s stack b: %s\n", stacks->a[j], stacks->b[j]);
		j++;
	}
	//j = actionhilowb(stacks, stacks->num);
	//printf("j: %i\n", j);
	printf("hilo: %i\n", actionhilowb(stacks, stacks->num));
	//printf("here?\n");
	printf("j %i\n", ft_atoi(stacks->a[actionhilowb(stacks, stacks->num)]));
	j = ft_atoi(stacks->a[actionhilowb(stacks, stacks->num)]);
	if (j > ft_atoi(stacks->a[0]))
		while (j != ft_atoi(stacks->a[size(stacks->a)]))
			flags(stacks, R, A);
	if (j < ft_atoi(stacks->b[0]))
		while (j != ft_atoi(stacks->a[0]))
			flags(stacks, RR, A);
	flags(stacks, P, A);
}

void	sortb(t_s *stacks)
{
	int j;

	while (size(stacks->b) != -1)
	{
		j = 0;
		while (j<4)
		{
			printf("stack a: %s stack b: %s\n", stacks->a[j], stacks->b[j]);
			j++;
		}

		operationsb(stacks);
		sortitb(stacks);
	}
}
