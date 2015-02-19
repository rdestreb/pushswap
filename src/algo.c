
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:21:12 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/18 13:55:39 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_2(t_stack *stack, t_ans *lst)
{
	if (is_sorted(stack) == stack->size - 2)
		swap(stack, lst);
}

void	rot_swap(t_stack *a, t_ans *lst)
{
	int pos;
	int	nb_rot;

	while ((pos = is_sorted(a) + 1))
	{
		//printf("rot_swap 1\n");
		if (pos > (a->size / 2) + 1)
		{
			nb_rot = a->size - pos;
//			//printf("pos 1 : %d\n",  pos);
//			if (nb_rot == 0 && pos == a->size)
			//			rotate(a);
			while ((--nb_rot > -1 && is_sorted(a) != -1) || pos == get_max(a) + 1) {
				//printf("rot_swap 2\n");
				rotate(a, lst);
			}
			if ((is_sorted(a) != -1))
				swap(a, lst);
			while (++nb_rot < a->size - pos && (is_sorted(a) != -1)) {
				//printf("rot_swap 3\n");
				rev_rotate(a, lst);
			}
		}
		else
		{
			nb_rot = pos;
//			//printf("pos : %d\npos_min : %d\nnb_rot : %d\n",pos, get_min(a), nb_rot);
			while ((--nb_rot > -1 && is_sorted(a) != -1) || rev_is_sorted(a) == get_min(a)) {
				//printf("rot_swap 4\n");
				rev_rotate(a, lst);
			}
			if ((is_sorted(a) != -1))
				swap(a, lst);
			while (++nb_rot < pos && (is_sorted(a) != -1)) {
				//printf("rot_swap 5\n");
				rotate(a, lst);
			}
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
		//printf("get_max\n");
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
		//printf("get_min\n");
		if (stack->stack[i] < min)
		{
			min = stack->stack[i];
			pos_min = i;
		}
	}
	return (pos_min);
}

void	push_min(t_stack *a, t_stack *b, t_ans *lst)
{
//	int	pos;

//	while ((pos = is_sorted(a) + 1) && b->size == 0)
//	{
	while (a->size > 1 && is_sorted(a) != -1)
	{
		//printf("push_min 1\n");
		if (a->size == 2 && is_sorted(a) != -1)
			swap(a, lst);
		else if (get_min(a) == a->size - 1 && is_sorted(a) != -1)
			push(a, b, lst);
		else
		{
			if (get_min(a) > ((a->size / 2) - 2))
				rotate(a, lst);
			else
				rev_rotate(a, lst);
		}
	}
	while (b->size > 0) {
		//printf("push_min 2\n");
		push(b, a, lst);
	}
//	}
}

