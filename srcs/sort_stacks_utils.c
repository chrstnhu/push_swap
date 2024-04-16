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

//Prepare and adjusts the position of the cheapest target_node
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack, false);
			else
				reverse_rotate_a(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack, false);
			else
				reverse_rotate_b(stack, false);
		}
	}
}

//Move to the cheapest of 'a' and target_node of 'b'
static void	move_stack_to_target(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (!(*a == cheapest)
		&& !(*b == cheapest->target_node))
	{
		if (cheapest->above_median == (*a)->above_median)
			rotate_ab(a, b, false);
		else
			reverse_rotate_ab(a, b, false);
		current_index(*a);
		current_index(*b);
	}
}

// Find the cheapest_node in stack 'a' and prepare pushing 
void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	move_stack_to_target(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(b, a, false);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push_a(a, b, false);
}
