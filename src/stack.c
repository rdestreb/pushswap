/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:31:32 by rdestreb          #+#    #+#             */
/*   Updated: 2015/03/30 14:42:15 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **av, int ac, int size, char name)
{
	t_stack	*st;
	int		i;

	if (!(st = (t_stack *)ft_memalloc(sizeof(t_stack))))
		print_error ("malloc failed\n");
	st->size = size;
	st->name = name;
	if (!(st->stack = (int *)ft_memalloc(sizeof(int) * (st->size))))
		print_error ("malloc failed\n");
	if (st->name == 'a')
	{
		i = -1;
		while (++i < st->size)
			st->stack[i] = ft_atoi(av[ac - 1 - i]);
	}
	return (st);
}

t_stack	*dup_stack(t_stack *st)
{
	t_stack	*dup;
	int		i;

	if (!(dup = (t_stack *)ft_memalloc(sizeof(t_stack))))
		print_error ("malloc failed\n");
	dup->size = st->size;
	dup->name = st->name;
	if (!(dup->stack = (int *)ft_memalloc(sizeof(int) * (st->size))))
		print_error ("malloc failed\n");
	i = -1;
	while (++i < st->size)
		dup->stack[i] = st->stack[i];
	return (dup);
}

void	print_stack(t_stack *st)
{
	int	i;

	i = -1;
	ft_putchar(st->name);
	ft_putstr(" :");
	while (++i < st->size)
	{
		ft_putstr(" ");
		ft_putnbr(st->stack[i]);
	}
	ft_putendl("");
}
