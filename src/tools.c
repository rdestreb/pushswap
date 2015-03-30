/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:57:21 by rdestreb          #+#    #+#             */
/*   Updated: 2015/03/30 14:43:21 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
