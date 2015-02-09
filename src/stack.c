/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:31:32 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/09 19:28:07 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_duplicate(int *stack)
{
	int	i;
	int	j;

	i = -1;
	while(stack[++i])
	{
		j = 0;
		while (stack[i + ++j])
		{
			if (stack[i] == stack[i + j])
				print_error ("Duplicates in the stack !\n");
		}
	}
}

int	*create_stack(char **av, int ac)
{
	int	*stack;
	int i;

	if(!(stack = (int *)ft_memalloc(sizeof(int *) * (ac - 1))))
		print_error ("malloc failed\n");
	i = -1;
	while (++i < ac - 1)
		stack[i] = ft_atoi(av[ac - 1 - i]);
	return (stack);
}

void	print_stack(int *stack, char *name)
{
//	int	i;

//	i = -1;
	ft_putstr(name);
	ft_putstr(" :");
	while (*stack)
	{
		ft_putstr(" ");
		ft_putnbr(*stack++);
	}
	ft_putendl("");
}
