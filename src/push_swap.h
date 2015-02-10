/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:52:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/10 18:49:46 by rdestreb         ###   ########.fr       */
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
	char	name;
};

void	print_error(char *msg);
void	is_duplicate(int *stack, int size);
int		*create_stack(char **av, int ac);
void	print_stack(int *stack, int size, char *name);
int		*swap(int *stack, int size);

#endif
