/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:06:51 by shrajan           #+#    #+#             */
/*   Updated: 2026/03/08 13:06:57 by shrajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Just a silent mode for checker
# ifdef CHECKER
#  define SILENT 1
# else
#  define SILENT 0
# endif

// Stack
typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
}		t_stack;

// operations
void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);
void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);
void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);
void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);

// utils
int		is_sorted(t_stack *a);
void	print_op(const char *s);
void	exit_error(void);
void	free_stack(t_stack *s);

// sorting
void	sort_stack(t_stack *a, t_stack *b);
void	push_chunks(t_stack *a, t_stack *b, int chunk_size);
void	small_sort(t_stack *a);
void	small_sort_five(t_stack *a, t_stack *b);

// parsing
int		parse_args(int argc, char **argv, t_stack *a);
int		process_args(t_stack *a, char **argv, int start, int end);
int		check_overflow(long res, int sign);
int		parse_digits(char *str, int sign, long *res);
int		safe_atoi(char *str, int *out);
int		is_valid_number(char *s);
int		is_duplicate(t_stack *a, int val, int size);
void	normalize_stack(t_stack *a);
char	**ft_split(char const *s, char c);
void	free_split(char **arr);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

// helper functions for sorting
int		find_min_index(t_stack *s);
int		stack_max(t_stack *s);
int		stack_index(t_stack *s, int value);

#endif
