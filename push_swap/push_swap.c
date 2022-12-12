/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:24:19 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 20:43:53 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int k;
	t_s	stacks;

	read_input(argc, argv, &stacks);
	if (sorted(&stacks) == NO && size(stacks.a) > 2)
			sort(&stacks);
	j = 0;
	i = size(stacks.a);
	k = 0;
	while (j <= i + 1)
	{
		//printf("stack a: %s stack b: %s\n\n", stacks.a[j],stacks.b[j]);
		++j;
	}
	if (sorted(&stacks) == NO && size(stacks.a) == 2)
		sort_small(&stacks);
	sortb(&stacks);
	rotatea(&stacks);

	j = 0;
	i = size(stacks.a);
	k = 0;
	while (j <= i + 1)
	{
		printf("stack a: %s stack b: %s\n", stacks.a[j],stacks.b[j]);
		++j;
	}
	return (0);
}






