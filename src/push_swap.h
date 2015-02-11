/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:52:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/11 18:02:47 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack t_stack;

struct	s_stack
{
	int		*stack;
	int		size;
	char	*name;
};

void	print_error(char *msg);
void	is_duplicate(t_stack *st);
t_stack	*create_stack(char **av, int size, char *name);
void	print_stack(t_stack *st);
t_stack	*swap(t_stack *st);
t_stack	*rotate(t_stack *st);
t_stack	*rev_rotate(t_stack *st);
t_stack	*push(t_stack *sender, t_stack *receiver);

#endif
