/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:05 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/01 16:06:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Take the 1st element at the top of 'source' and push at the top of 'dest'.
// Ex : a = {30, 1000, -42}     b = {10}
//   -> a = {10, 30, 1000, -42} b = { }

void	push(t_stack **dest, t_stack **source)
{
	t_stack	*tmp;

	if (!source || !(*source))
		return ;
	tmp = (*source)->next;
	if (*source)
		ft_lstadd_front(dest, *source);
	*source = tmp;
}

void	push_a(t_stack **a, t_stack **b, bool print)
{
	if (!(b) || !(*b))
		return ;
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	push_b(t_stack **b, t_stack **a, bool print)
{
	if (!(a) || !(*a))
		return ;
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
