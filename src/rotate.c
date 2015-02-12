/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:14:14 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/12 12:22:43 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack *st)
{
	int	i;
	int	tmp;

	if (st->size > 1)
	{
		tmp = st->stack[st->size - 1];
		i = st->size;
		while (--i > 0)
			st->stack[i] = st->stack[i - 1];
		st->stack[i] = tmp;
		if (st->name == 'a')
			add_link("ra");
		if (st->name == 'b')
			add_link("rb");
	}
	return (st);
}

void	rotate_rotate(t_stack *sta, t_stack *stb)
{
	int	i;
	int	tmp;

	if (sta->size > 1 && stb->size > 1)
	{
		tmp = sta->stack[sta->size - 1];
		i = sta->size;
		while (--i > 0)
			sta->stack[i] = sta->stack[i - 1];
		sta->stack[i] = tmp;
		tmp = stb->stack[stb->size - 1];
		i = stb->size;
		while (--i > 0)
			stb->stack[i] = stb->stack[i - 1];
		stb->stack[i] = tmp;
		add_link("rr");
	}
}

t_stack	*rev_rotate(t_stack *st)
{
	int	i;
	int	tmp;

	if (st->size > 1)
	{
		tmp = st->stack[0];
		i = -1;
		while (++i < st->size - 1)
			st->stack[i] = st->stack[i + 1];
		st->stack[i] = tmp;
		if (st->name == 'a')
			add_link("rra");
		if (st->name == 'b')
			add_link("rrb");
	}
	return (st);
}

void	rev_rev(t_stack *sta, t_stack *stb)
{
	int	i;
	int	tmp;

	if (sta->size > 1 && stb->size > 1)
	{
		tmp = sta->stack[0];
		i = -1;
		while (++i < sta->size - 1)
			sta->stack[i] = sta->stack[i + 1];
		sta->stack[i] = tmp;
		tmp = stb->stack[0];
		i = -1;
		while (++i < stb->size - 1)
			stb->stack[i] = stb->stack[i + 1];
		stb->stack[i] = tmp;
		add_link("rrr");
	}
}
