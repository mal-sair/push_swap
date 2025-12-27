/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:36:00 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:37:34 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Structures

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack_node;

// Stack operations (stack_op.c)
t_stack_node	*create_node(int i);
void			add_to_stack(t_stack_node **head, t_stack_node *new_node);
t_stack_node	*last_node(t_stack_node *head);
int				stack_size(t_stack_node *stack);
t_stack_node	*pop(t_stack_node **head);

// Swap operations (operations_swap.c)
void			swap_stack(t_stack_node **head);
void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);

// Push operations (operations_push.c)
void			push_from_to(t_stack_node **from, t_stack_node **to);
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

// Rotate operations (operations_rotate.c)
void			rotate(t_stack_node **head);
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_rr(t_stack_node **a, t_stack_node **b);

// Reverse rotate operations (operations_rev_rotate.c)
void			rev_rotate(t_stack_node **head);
void			rev_rotate_a(t_stack_node **a);
void			rev_rotate_b(t_stack_node **b);
void			rev_rotate_rr(t_stack_node **a, t_stack_node **b);

// Utility functions (utils.c)
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
int				ft_isdigit(int c);
void			free_stack(t_stack_node **stack);
void			error_exit(t_stack_node **a, t_stack_node **b);
char			**ft_split(char const *s, char c);
void			free_split(char **split);

// Parsing functions (parsing.c)
t_stack_node	*parse_args(int argc, char **argv);
int				is_sorted(t_stack_node *stack);
int				has_duplicates(t_stack_node *stack);

// Sorting algorithm functions (push_swap.c)
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
int				find_min(t_stack_node *stack);
int				find_max(t_stack_node *stack);
int				find_min_pos(t_stack_node *stack);

#endif
