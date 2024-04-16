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

// Verify if it is a digit or not
static int	is_digit(int str)
{
	return (str >= '0' && str <= '9');
}

// Verify if it has a sign
static int	has_sign(int str)
{
	return (str == '+' || str == '-');
}

//Verify if '+' / '-' and it is a number
int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!(has_sign(str[i]) || is_digit(str[i])))
		return (1);
	if ((has_sign(str[i])) && !(is_digit(str[1])))
		return (1);
	while (str[i])
	{
		if (!(((str[i] == '-' || str[i] == '+') && (i == 0))) && !(is_digit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

//Verify if the number is duplicate
int	has_duplicate(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

//Verify if the stack is sorted
int	stack_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
