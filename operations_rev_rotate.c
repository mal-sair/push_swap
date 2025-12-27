/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:42:33 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:50:21 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!head || !*head || !(*head)->next)
		return ;
	second_last = *head;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rev_rotate_a(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_rr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
