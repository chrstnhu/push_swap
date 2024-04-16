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

void	ft_free_split(char **split_argv)
{
	int	i;

	i = 0;
	if (!split_argv || !(*split_argv))
		return ;
	while (split_argv[i])
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

void	free_argv(t_stack **a, char **argv, bool argc_2)
{
	int	i;

	i = 0;
	if (!argv || !(*argv))
		return ;
	if (argc_2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	ft_free(a);
}

void	ft_free(t_stack **a)
{
	ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}
