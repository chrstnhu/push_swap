/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:28:14 by chrhu             #+#    #+#             */
/*   Updated: 2023/01/27 15:47:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"
#include "../includes/push_swap.h"

int	swap_push(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_a(a, 1);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_b(b, 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_ab(a, b, 1);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_a(a, b, 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_b(b, a, 1);
	else
		return (0);
	return (1);
}

int	rotate_reverse(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_a(a, 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_b(b, 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_ab(a, b, 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_a(a, 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_b(b, 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_ab(a, b, 1);
	else
		return (0);
	return (1);
}

//Get the command line and compare it
void	process_commands(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
		if (!swap_push(a, b, line)
			&& !rotate_reverse(a, b, line))
		{
			(void)get_next_line(-42);
			write(2, "Error\n", 6);
			free(line);
			ft_lstclear(a);
			ft_lstclear(b);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

static void	process_stack(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a);
	process_commands(&a, &b);
	if (stack_is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	if (argc <= 1 || !argv[1] || !argv[1][0])
	{
		write(1, "Error\n", 1);
		return (1);
	}
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			ft_free(&a);
		stack_init(&a, split_argv, 1);
		ft_free_split(split_argv);
	}
	else
		stack_init(&a, argv + 1, argc == 2);
	process_stack(a, b);
	return (0);
}
