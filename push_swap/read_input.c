/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:25:25 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/07 16:15:11 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	insert_stack(t_s *stacks)
{
	int	i;
	int	s;

//	s = size(stacks->tmp);
	i = 0;
	printf("%i", i);
	while (s != 0)
	{
		stacks->a[i] = stacks->tmp[s];
		++i;
		--s;
	}
} */

int	check_valid(int argc, char *argv[])
{
	if (check_digit(argc, argv) == ERR_INVAL
		|| space_check(argc, argv) == ERR_INVAL
		|| negpos_check(argc, argv) == ERR_INVAL)
		return (ERR_INVAL);
	else
		return (SUCESS);
}

int	read_input(int argc, char *argv[], t_s *stacks)
{
	if (ft_error(check_valid(argc, argv) == ERR_INVAL) == ERR_INVAL)
		return (ERR_INVAL);
	stacks->str = join_inpt(argc, argv);
	stacks->a = ft_split(stacks->str, SPACE);
	if (ft_error(check_double(stacks) == ERR_INVAL) == ERR_INVAL)
		return (ERR_INVAL);
	stacks->tmp = ft_calloc(size(stacks->a), sizeof(char));
	stacks->b = ft_calloc(size(stacks->a), sizeof(char));
	return (0);
}

/* 	i = size(stacks->a);
	while (j <= i)
	{
		printf("\n%s", stacks->a[j]);
		++j;
	} */
