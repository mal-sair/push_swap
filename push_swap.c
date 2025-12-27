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

static int	find_max_idx_pos(t_stack_node *stack)
{
	int	max_idx;
	int	pos;
	int	max_pos;

	if (!stack)
		return (0);
	max_idx = stack->index;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b, int size)
{
	int	chunk_size;
	int	i;
	int	chunk_num;

	if (size <= 100)
		chunk_num = 5;
	else
		chunk_num = 11;
	chunk_size = size / chunk_num;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push_b(a, b);
			rotate_b(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
}

static void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_pos;
	int	rotations;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_idx_pos(*b);
		if (max_pos <= size / 2)
		{
			rotations = max_pos;
			while (rotations-- > 0)
				rotate_b(b);
		}
		else
		{
			rotations = size - max_pos;
			while (rotations-- > 0)
				rev_rotate_b(b);
		}
		push_a(a, b);
	}
}

static void	chunk_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;

	assign_indices(*a);
	size = stack_size(*a);
	push_chunks_to_b(a, b, size);
	push_back_to_a(a, b);
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
		chunk_sort(a, b);
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
