/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:57:43 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/11 19:25:04 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *st)
{
	int	tmp;

	if (st->size > 1)
	{
		tmp = st->stack[st->size - 1];
		st->stack[st->size - 1] = st->stack[st->size - 2];
		st->stack[st->size - 2] = tmp;
		ft_putendl(ft_strjoin("s", st->name));
	}
	return (st);
}


void	swap_swap(t_stack *sta, t_stack *stb)
{
	int	tmp;

	if (sta->size > 1 && stb->size > 1)
	{
		tmp = sta->stack[sta->size - 1];
		sta->stack[sta->size - 1] = sta->stack[sta->size - 2];
		sta->stack[sta->size - 2] = tmp;
		tmp = stb->stack[stb->size - 1];
		stb->stack[stb->size - 1] = stb->stack[stb->size - 2];
		stb->stack[stb->size - 2] = tmp;
		ft_putendl("ss");
	}
}
