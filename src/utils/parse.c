/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:22:57 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:22:59 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_numbers(char **argv, int start, int end)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = start;
	count = 0;
	while (i < end)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_error();
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	if (argc < 2)
		return (0);
	a->capacity = count_numbers(argv, 1, argc);
	a->size = 0;
	a->arr = malloc(sizeof(int) * a->capacity);
	if (!a->arr)
		exit_error();
	if (!process_args(a, argv, 1, argc))
	{
		free(a->arr);
		a->arr = NULL;
		return (0);
	}
	return (1);
}
