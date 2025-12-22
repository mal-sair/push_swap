/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:44:23 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 21:19:11 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(int i)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->data = i;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_stack_node **head, t_stack_node *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

t_stack_node	*last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node	*pop(t_stack_node **head)
{
	t_stack_node	*node_to_pop;
	t_stack_node	*before_last;

	if (!head || !*head)
		return (NULL);
	node_to_pop = last_node(*head);
	if (*head == node_to_pop)
	{
		*head = NULL;
		return (node_to_pop);
	}
	before_last = *head;
	while (before_last->next != node_to_pop)
		before_last = before_last->next;
	before_last->next = NULL;
	return (node_to_pop);
}
