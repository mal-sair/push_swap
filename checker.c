/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:50:49 by mal-sair          #+#    #+#             */
/*   Updated: 2025/12/22 22:50:50 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	get_next_line(char *buf, int size)
{
	int		i;
	char	c;
	int		ret;

	i = 0;
	while (i < size - 1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
		{
			if (i == 0)
				return (0);
			break ;
		}
		if (c == '\n')
			break ;
		buf[i++] = c;
	}
	buf[i] = '\0';
	return (1);
}

static int	exec_op(char *op, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (ft_strcmp(op, "pa") == 0)
		push_from_to(b, a);
	else if (ft_strcmp(op, "pb") == 0)
		push_from_to(a, b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		rev_rotate(a);
	else if (ft_strcmp(op, "rrb") == 0)
		rev_rotate(b);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		return (0);
	return (1);
}

static int	process_ops(t_stack_node **a, t_stack_node **b)
{
	char	buf[16];

	while (get_next_line(buf, 16))
	{
		if (buf[0] == '\0')
			continue ;
		if (!exec_op(buf, a, b))
			return (0);
	}
	return (1);
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
	if (!process_ops(&a, &b))
		error_exit(&a, &b);
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
