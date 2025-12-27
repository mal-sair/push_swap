/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:50:32 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:50:33 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack_node *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack_node *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	find_min_pos(t_stack_node *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!stack)
		return (0);
	min = stack->data;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rev_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		rev_rotate_a(a);
}

static void	push_min_to_b(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	min_pos;

	min_pos = find_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			rotate_a(a);
	}
	else
	{
		while (min_pos++ < size)
			rev_rotate_a(a);
	}
	push_b(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		push_min_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}

static void	assign_indices(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				idx;

	current = stack;
	while (current)
	{
		idx = 0;
		compare = stack;
		while (compare)
		{
			if (compare->data < current->data)
				idx++;
			compare = compare->next;
		}
		current->index = idx;
		current = current->next;
	}
}

static void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	assign_indices(*a);
	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		error_exit(NULL, NULL);
	if (has_duplicates(a))
		error_exit(&a, NULL);
	b = NULL;
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
