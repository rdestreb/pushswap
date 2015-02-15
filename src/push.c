/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:46:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/15 16:40:25 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push(t_stack *sender, t_stack *receiver)
{
	if (sender->size > 0)
	{
		receiver->stack[receiver->size] = sender->stack[sender->size - 1];
		sender->stack[sender->size - 1] = 0;
		receiver->size++;
		sender->size--;
		if (receiver->name == 'a')
			add_link("pa");
		if (receiver->name == 'b')
			add_link("pb");
	}
	return (sender);
}
