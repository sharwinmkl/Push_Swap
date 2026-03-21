/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:21:43 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:21:45 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	total;
	int	top;

	total = a->size;
	pushed = 0;
	while (pushed < total)
	{
		top = a->arr[0];
		if (top <= pushed)
		{
			do_pb(a, b);
			do_rb(b);
			pushed++;
		}
		else if (top <= pushed + chunk_size)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
	}
}
