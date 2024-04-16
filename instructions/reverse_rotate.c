/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/01 16:07:32 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Shift down all elements of stack by 1.  The last element becomes the 1st one.
// Ex : {30, 1000, -42, 1}
//   -> {1, 30, 1000, -42}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	reverse_rotate_a(t_stack **a, bool print)
{
	if (!(a) || !(*a) || !(*a)->next)
		return ;
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b, bool print)
{
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, bool print)
{
	if (!(a) || !(*a) || !(*a)->next)
		return ;
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
