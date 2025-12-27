/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:50:28 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:50:30 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	add_to_tail(t_stack_node **head, t_stack_node *new_node)
{
	t_stack_node	*last;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	last = last_node(*head);
	last->next = new_node;
}

static t_stack_node	*parse_single_arg(char *arg, t_stack_node **a)
{
	char	**split;
	long	num;
	int		i;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		free_split(split);
		return (NULL);
	}
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
		{
			free_split(split);
			return (NULL);
		}
		num = ft_atol(split[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_split(split);
			return (NULL);
		}
		add_to_tail(a, create_node((int)num));
		i++;
	}
	free_split(split);
	return (*a);
}

t_stack_node	*parse_args(int argc, char **argv)
{
	t_stack_node	*a;
	long			num;
	int				i;

	a = NULL;
	if (argc == 2)
		return (parse_single_arg(argv[1], &a));
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(&a);
			return (NULL);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_stack(&a);
			return (NULL);
		}
		add_to_tail(&a, create_node((int)num));
		i++;
	}
	return (a);
}

int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	has_duplicates(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->data == checker->data)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
