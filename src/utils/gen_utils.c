/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:22:29 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:22:31 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_op(const char *s)
{
	if (SILENT)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *s)
{
	if (s && s->arr)
	{
		free(s->arr);
		s->arr = NULL;
	}
	s->size = 0;
	s->capacity = 0;
}
