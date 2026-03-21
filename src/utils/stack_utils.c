/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:23:46 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:23:49 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_max(t_stack *s)
{
	int	i;
	int	max;

	if (!s || s->size == 0)
		return (0);
	max = s->arr[0];
	i = 1;
	while (i < s->size)
	{
		if (s->arr[i] > max)
			max = s->arr[i];
		i++;
	}
	return (max);
}

int	stack_index(t_stack *s, int value)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (i < s->size)
	{
		if (s->arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
