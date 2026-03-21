/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:23:14 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:23:20 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parse_digits(char *str, int sign, long *res)
{
	int	digits;

	digits = 0;
	*res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		*res = *res * 10 + (*str - '0');
		if (!check_overflow(*res, sign))
			return (0);
		digits++;
		str++;
	}
	if (digits == 0)
		return (0);
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	process_split(t_stack *a, char **split)
{
	int	j;
	int	current_num;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (0);
		if (!safe_atoi(split[j], &current_num))
			return (0);
		if (is_duplicate(a, current_num, a->size))
			return (0);
		a->arr[a->size++] = current_num;
		j++;
	}
	return (1);
}

int	process_args(t_stack *a, char **argv, int start, int end)
{
	int		i;
	char	**split;

	i = start;
	while (i < end)
	{
		if (!argv[i])
			return (0);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!process_split(a, split))
			return (free_split(split), 0);
		free_split(split);
		i++;
	}
	return (1);
}
