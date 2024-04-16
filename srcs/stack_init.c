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

// Attach every new node to stack 'a'
void	attach_node_to_stack(t_stack **a, int number)
{
	t_stack	*last_node;
	t_stack	*node;

	node = ft_lstnew(number);
	if (!node)
		return ;
	if (!(*a))
		*a = node;
	else
	{
		last_node = ft_lstlast(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

//Initialise stack 'a' and find error
void	stack_init(t_stack **a, char **argv, bool argc_2)
{
	long	number;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (is_valid(argv[i]))
			free_argv(a, argv, argc_2);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_argv(a, argv, argc_2);
		if (has_duplicate(*a, (int)number))
			free_argv(a, argv, argc_2);
		attach_node_to_stack(a, (int)number);
		i++;
	}
}
