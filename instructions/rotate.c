/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/01 16:09:10 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Shift up all elements of stack by 1. The 1st element becomes the last one.
// Ex : {30, 1000, -42, 1}
//   -> {1000, -42, 1, 30}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(stack) || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rotate_a(t_stack **a, bool print)
{
	if (!(a) || !(*a) || !(*a)->next)
		return ;
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b, bool print)
{
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **a, t_stack **b, bool print)
{
	if (!(a) || !(*a) || !(*a)->next)
		return ;
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
