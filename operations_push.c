/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:28:18 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 21:33:58 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_stack_node **first, t_stack_node **second)
{
	t_stack_node	temp;

	temp = pop(first);
	add_to_stack(second, temp);
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	if (*b == NULL)
		return ;
	push_from_to(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	if (*a == NULL)
		return ;
	push_from_to(a, b);
	write(1, "pb\n", 3);
}
