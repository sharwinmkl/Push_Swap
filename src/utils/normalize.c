/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:22:39 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:22:44 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*copy_array(t_stack *a)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		exit_error();
	i = 0;
	while (i < a->size)
	{
		arr[i] = a->arr[i];
		i++;
	}
	return (arr);
}

static void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	copy = copy_array(a);
	selection_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i] == copy[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
