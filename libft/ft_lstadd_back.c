/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:49:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 13:59:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Add node at the end of the stack
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
