/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:50 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/01 16:11:14 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap 2 elements at the top of stack

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first->next = second->next;
	second->prev = first->prev;
	if (first->next)
		first->next->prev = first;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	swap_a(t_stack **a, bool print)
{	
	if (!a || !(*a) || !(*a)->next)
		return ;
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, bool print)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stack **a, t_stack **b, bool print)
{
	if (!(a) || !(*a) || !(*a)->next)
		return ;
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
