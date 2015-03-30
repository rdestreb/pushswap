/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:21:12 by rdestreb          #+#    #+#             */
/*   Updated: 2015/03/30 14:45:42 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a, t_stack *b, t_ans *lst)
{
	if (a->stack[0] < a->stack[1] && a->stack[1] < a->stack[2])
	{
		swap(a, b, lst);
		rev_rotate(a, b, lst);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2]
			&& a->stack[0] < a->stack[2])
		rev_rotate(a, b, lst);
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2]
			&& a->stack[0] > a->stack[2])
	{
		rev_rotate(a, b, lst);
		swap(a, b, lst);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2]
			&& a->stack[0] > a->stack[2])
		swap(a, b, lst);
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2]
			&& a->stack[0] < a->stack[2])
		rotate(a, b, lst);
}

static void	rot_swap2(t_stack *a, t_stack *b, t_ans *lst, int pos)
{
	int	nb_rot;

	nb_rot = pos;
	while ((--nb_rot > -1 && is_sorted(a) != -1) ||
			rev_is_sorted(a) == get_min(a))
		rev_rotate(a, b, lst);
	if ((is_sorted(a) != -1))
		swap(a, b, lst);
	while (++nb_rot < pos && (is_sorted(a) != -1))
		rotate(a, b, lst);
}

void		rot_swap(t_stack *a, t_stack *b, t_ans *lst)
{
	int pos;
	int	nb_rot;

	if (a->size == 3)
		sort_3(a, b, lst);
	else
	{
		while ((pos = is_sorted(a) + 1))
		{
			if (pos > (a->size / 2) + 1)
			{
				nb_rot = a->size - pos;
				while ((--nb_rot > -1 && is_sorted(a) != -1) ||
						pos == get_max(a) + 1)
					rotate(a, b, lst);
				if ((is_sorted(a) != -1))
					swap(a, b, lst);
				while (++nb_rot < a->size - pos && (is_sorted(a) != -1))
					rev_rotate(a, b, lst);
			}
			else
				rot_swap2(a, b, lst, pos);
		}
	}
}

void		push_min(t_stack *a, t_stack *b, t_ans *lst)
{
	while (a->size > 1 && is_sorted(a) != -1)
	{
		if (a->size == 2 && is_sorted(a) != -1)
			swap(a, b, lst);
		else if (get_min(a) == a->size - 1 && is_sorted(a) != -1)
			push(a, b, lst);
		else
		{
			if (get_min(a) > ((a->size / 2) - 2))
				rotate(a, b, lst);
			else
				rev_rotate(a, b, lst);
		}
	}
	while (b->size > 0)
		push(b, a, lst);
}
