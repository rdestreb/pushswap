/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:31:32 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/19 14:34:31 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	is_duplicate(t_stack *st)
{
	int	i;
	int	j;

	i = -1;
	while (++i < st->size)
	{
		//printf("is_duplicate 1\n");
		j = 0;
		while (i + ++j < st->size - 1)
		{
			//printf("is_duplicate 2\n");
			if (st->stack[i] == st->stack[i + j])
				print_error ("Duplicates in the stack !\n");
		}
	}
}

t_stack	*create_stack(char **av, int size, char name)
{
	t_stack	*st;
	int 	i;

	if(!(st = (t_stack *)ft_memalloc(sizeof(t_stack))))
		print_error ("malloc failed\n");
	st->size = size;
	st->name = name;
	if(!(st->stack = (int *)ft_memalloc(sizeof(int) * (st->size))))
		print_error ("malloc failed\n");
	if (st->name == 'a')
	{
		i = -1;
		while (++i < st->size){
			//printf("create_stack 1\n");
			st->stack[i] = ft_atoi(av[st->size - i]);
		}
	}
	return (st);
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
