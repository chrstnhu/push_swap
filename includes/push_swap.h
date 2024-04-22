/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:16 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 14:00:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				nb_move;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target_node;
}	t_stack;

//----- FREE -----

void	free_argv(t_stack **a, char **argv, bool argc_2);
void	ft_free(t_stack **a);
void	ft_free_split(char **split_argv);
void	ft_lstclear(t_stack **lst);

//----- UTILS -----

int		is_valid(char *str);
int		has_duplicate(t_stack *a, int nbr);
int		stack_is_sorted(t_stack *stack);
void	stack_init(t_stack **a, char **argv, bool argc_2);
int		stack_len(t_stack *stack);
/// @brief Find the smallest node
/// @param stack stack
/// @return smallest node
t_stack	*find_smallest(t_stack *stack);
/// @brief Find the biggest node
/// @param stack stack
/// @return biggest node
t_stack	*find_biggest(t_stack *stack);

//----- INITIALISE STACK -----

void	init_a(t_stack *a, t_stack *b);
void	init_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
// Prepare stack A for pushing the cheapest_node by adjusting its position
// Prepare stack B for push target_node of cheapest by adjusting its position
void	move_a_to_b(t_stack **a, t_stack **b);
// Prepare stack 'a' for pushing the target_node of the top element
// in stack B by adjusting its position.
void	move_b_to_a(t_stack **a, t_stack **b);
void	prep_for_push(t_stack **stack, t_stack *first, char stack_name);

//----- SORT ALGORITHM -----

void	attach_node_to_stack(t_stack **a, int number);
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	min_on_top(t_stack **a);

//----- LIBFT -----

t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
long	ft_atol(const char *str);
char	**ft_split(char *str, char c);

//----- INSTRUCTIONS -----

//Swap first 2 elements at the top
void	swap(t_stack **stack);
void	swap_a(t_stack **a, bool print);
void	swap_b(t_stack **b, bool print);
void	swap_ab(t_stack **a, t_stack **b, bool print);

//Push top source to top destination
void	push(t_stack **dest, t_stack **source);
void	push_a(t_stack **a, t_stack **b, bool print);
void	push_b(t_stack **b, t_stack **a, bool print);

//Rotate first
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a, bool print);
void	rotate_b(t_stack **b, bool print);
void	rotate_ab(t_stack **a, t_stack **b, bool print);

//Reverse rotate last number to the first
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **a, bool print);
void	reverse_rotate_b(t_stack **b, bool print);
void	reverse_rotate_ab(t_stack **a, t_stack **b, bool print);

#endif
