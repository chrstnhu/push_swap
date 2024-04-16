/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:05 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 14:00:07 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Sort the remaining in 'a'
void	min_on_top(t_stack **a)
{
	t_stack	*small;

	small = find_smallest(*a);
	while ((*a)->content != small->content)
	{
		if (small->above_median)
			rotate_a(a, false);
		else
			reverse_rotate_a(a, false);
	}
}

//Sort more than 3 numbers
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		push_b(b, a, false);
	if (len_a-- > 3)
		push_b(b, a, false);
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
