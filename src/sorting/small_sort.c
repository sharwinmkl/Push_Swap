/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:21:03 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:21:06 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0];
	y = a->arr[1];
	z = a->arr[2];
	if (x > y && y < z && x < z)
		do_sa(a);
	else if (x > y && y > z)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (x > y && y < z && x > z)
		do_ra(a);
	else if (x < y && y > z && x < z)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (x < y && y > z && x > z)
		do_rra(a);
}

void	small_sort(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->arr[0] > a->arr[1])
			do_sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
}
