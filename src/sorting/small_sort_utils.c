/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:20:50 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:20:53 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_index(t_stack *a)
{
	int	i;
	int	min_index;

	if (a->size == 0)
		return (-1);
	min_index = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	small_sort_five(t_stack *a, t_stack *b)
{
	int	idx;
	int	i;

	while (a->size > 3)
	{
		idx = find_min_index(a);
		if (idx <= a->size / 2)
		{
			i = 0;
			while (i++ < idx)
				do_ra(a);
		}
		else
		{
			i = 0;
			while (i++ < a->size - idx)
				do_rra(a);
		}
		do_pb(a, b);
	}
	small_sort(a);
	while (b->size > 0)
		do_pa(a, b);
}
