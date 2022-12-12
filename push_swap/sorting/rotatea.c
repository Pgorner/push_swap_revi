/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:14:42 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 20:40:41 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotatea(t_s *stacks)
{
	int j;
	int k;

	j = 1;
	k = ft_atoi(stacks->a[0]);
	while (j <= size(stacks->a))
	{
		if (k < ft_atoi(stacks->a[j]))
			k = ft_atoi(stacks->a[j]);
		j++;
	}
	while (ft_atoi(stacks->a[size(stacks->a)]) != k)
		flags(stacks, RR, A);
}
