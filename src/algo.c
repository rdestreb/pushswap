/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:21:12 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/16 19:33:48 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_2(t_stack *stack)
{
	if (is_sorted(stack) == stack->size - 2)
		swap(stack);
}

void	rot_swap(t_stack *a)
{
	int pos;
	int	nb_rot;

	while ((pos = is_sorted(a) + 1))
	{
		if (pos > (a->size / 2) + 1)
		{
			nb_rot = a->size - pos;
			printf("pos : %d\npos_max : %d\nnb_rot : %d\n",pos, get_max(a), nb_rot);
//			if (nb_rot == 0 && pos == a->size)
			//			rotate(a);
			while ((--nb_rot > -1 && is_sorted(a) != -1) || pos == get_max(a) + 1)
				rotate(a);
			if ((is_sorted(a) != -1))
				swap(a);
			while (++nb_rot < a->size - pos && (is_sorted(a) != -1))
				rev_rotate(a);
		}
		else
		{
			nb_rot = pos;
			while (--nb_rot > -1 && (is_sorted(a) != -1))
				rev_rotate(a);
			if ((is_sorted(a) != -1))
				swap(a);
			while (++nb_rot < pos && (is_sorted(a) != -1))
				rotate(a);
		}
	}
}

int		get_max(t_stack *stack)
{
	int	i;
	int	max;
	int	pos_max;

	i = -1;
	max = stack->stack[0];
	pos_max = 0;
	while (++i < stack->size)
	{
		if (stack->stack[i] > max)
		{
			max = stack->stack[i];
			pos_max = i;
		}
	}
	return (pos_max);
}

int		get_min(t_stack *stack)
{
	int	i;
	int	min;
	int	pos_min;

	i = -1;
	min = stack->stack[0];
	pos_min = 0;
	while (++i < stack->size)
	{
		if (stack->stack[i] < min)
		{
			min = stack->stack[i];
			pos_min = i;
		}
	}
	return (pos_min);
}

void	push_min(t_stack *a, t_stack *b)
{
	while (is_sorted(a) != -1 && b->size == 0)
	{
		while (a->size > 0)
		{
			if (get_min(a) == a->size - 1)
				push(a, b);
			else
			{
				if (get_min(a) > ((a->size / 2) - 2))
					rotate(a);
				else
					rev_rotate(a);
			}
		}
		while (b->size > 0)
			push(b, a);
	}
}

