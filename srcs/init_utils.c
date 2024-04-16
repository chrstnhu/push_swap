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

//Adjust the index and find if is above the median or not
void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

//Find and set the cheapest with the less movements
void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	if (!stack)
		return ;
	while (stack != NULL)
	{
		if (stack->nb_move < cheapest_value)
		{
			cheapest_value = stack->nb_move;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

//Get the cheapest node and return it
t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (0);
}
