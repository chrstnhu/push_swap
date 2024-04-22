/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 14:00:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// Process sort algorithm if not sorted
static void	process_stack(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a);
	if (!stack_is_sorted(a))
	{
		if (len == 2)
			swap_a(&a, false);
		else if (len == 3)
			sort_three(&a);
		else if (len > 3)
			sort_stacks(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	a = NULL;
	b = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			ft_free(&a);
		stack_init(&a, split_argv, argc == 2);
		ft_free_split(split_argv);
	}
	else
		stack_init(&a, argv + 1, argc == 2);
	process_stack(a, b);
	return (0);
}
