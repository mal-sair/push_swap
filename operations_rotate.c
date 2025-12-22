/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:31:30 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:50:12 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	last = last_node(*head);
	*head = second;
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
