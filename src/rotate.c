/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:14:14 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/19 15:24:04 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*rotate(t_stack *st, t_ans *lst)
{
	int	i;
	int	tmp;

	if (st->size > 1)
	{
		tmp = st->stack[st->size - 1];
		i = st->size;
		while (--i > 0) {
			//printf("rotate\n");
			st->stack[i] = st->stack[i - 1];
		}
		st->stack[i] = tmp;
		if (st->name == 'a')
			add_link(lst, "ra");
		if (st->name == 'b')
			add_link(lst, "rb");
	}
	return (st);
}

void	rotate_rotate(t_stack *sta, t_stack *stb, t_ans *lst)
{
	int	i;
	int	tmp;

	if (sta->size > 1 && stb->size > 1)
	{
		tmp = sta->stack[sta->size - 1];
		i = sta->size;
		while (--i > 0){
			//printf("rotate_rotate 1\n");
			sta->stack[i] = sta->stack[i - 1];
		}
		sta->stack[i] = tmp;
		tmp = stb->stack[stb->size - 1];
		i = stb->size;
		while (--i > 0) {
			//printf("rotate_rotate 2\n");
			stb->stack[i] = stb->stack[i - 1];
		}
		stb->stack[i] = tmp;
		add_link(lst, "rr");
	}
}

t_stack	*rev_rotate(t_stack *st, t_ans *lst)
{
	int	i;
	int	tmp;

	if (st->size > 1)
	{
		tmp = st->stack[0];
		i = -1;
		while (++i < st->size - 1)
		{
			//printf("rev_rotate\n");
			st->stack[i] = st->stack[i + 1];
		}
		st->stack[i] = tmp;
		if (st->name == 'a')
			add_link(lst, "rra");
		if (st->name == 'b')
			add_link(lst, "rrb");
	}
	return (st);
}

void	rev_rev(t_stack *sta, t_stack *stb, t_ans *lst)
{
	int	i;
	int	tmp;

	if (sta->size > 1 && stb->size > 1)
	{
		tmp = sta->stack[0];
		i = -1;
		while (++i < sta->size - 1){
			//printf("rev_rev 1\n");
			sta->stack[i] = sta->stack[i + 1];
		}
		sta->stack[i] = tmp;
		tmp = stb->stack[0];
		i = -1;
		while (++i < stb->size - 1) {
			//printf("rev_rev 2\n");
			stb->stack[i] = stb->stack[i + 1];
		}
		stb->stack[i] = tmp;
		add_link(lst, "rrr");
	}
}
