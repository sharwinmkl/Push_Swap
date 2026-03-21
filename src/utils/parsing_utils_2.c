/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:23:30 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:23:33 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
		if (!s[i])
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	safe_atoi(char *str, int *out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!parse_digits(str, sign, &res))
		return (0);
	if (res == 0 && *str == '0')
		*out = 0;
	else
		*out = (int)(res * sign);
	return (1);
}

int	ft_atoi(const char *str, int *error)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*error = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (*str++ - '0');
		if (!check_overflow(res, sign))
		{
			*error = 1;
			return (0);
		}
	}
	return ((int)(res * sign));
}

int	check_overflow(long res, int sign)
{
	if (res * sign > 2147483647 || res * sign < -2147483648)
		return (0);
	return (1);
}
