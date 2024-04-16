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

//Find and set the target node of 'a' in 'b'
static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a != NULL)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content
				&& current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_biggest(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

//Analyse the number of movements
static void	analysis_move_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a != NULL)
	{
		if (a->above_median)
			a->nb_move = a->index;
		else
			a->nb_move = len_a - (a->index);
		if (a->target_node->above_median)
			a->nb_move += a->target_node->index;
		else
			a->nb_move += len_b - (a->target_node->index);
		a = a->next;
	}
}

//Initialise stack 'a'
void	init_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	analysis_move_a(a, b);
	set_cheapest(a);
}
