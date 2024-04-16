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

//If first is the biggest
static void	first_biggest(t_stack **a, int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second < third)
			rotate_a(a, false);
		else
		{
			rotate_a(a, false);
			swap_a(a, false);
		}
	}
}

//If second is the biggest
static void	second_biggest(t_stack **a, int first, int second, int third)
{
	if (first < second && second > third)
	{
		if (first > third)
			reverse_rotate_a(a, false);
		else
		{
			reverse_rotate_a(a, false);
			swap_a(a, false);
		}
	}
}

//Sort if there is just 3 numbers in stack 'a'
void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	first_biggest(a, first, second, third);
	second_biggest(a, first, second, third);
	if (first > second && second < third && first < third)
		swap_a(a, false);
}
