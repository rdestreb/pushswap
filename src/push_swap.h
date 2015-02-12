/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:52:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/12 12:55:09 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack	t_stack;
typedef struct s_ans	t_ans;

struct	s_stack
{
	int		*stack;
	int		size;
	char	name;
};

struct	s_ans
{
	char 	*cmd;
	t_ans	*next;
};

void	print_error(char *msg);
void	is_duplicate(t_stack *st);
t_stack	*create_stack(char **av, int size, char name);
void	print_stack(t_stack *st);
t_stack	*swap(t_stack *st);
t_stack	*rotate(t_stack *st);
t_stack	*rev_rotate(t_stack *st);
t_stack	*push(t_stack *sender, t_stack *reciever);
void	swap_swap(t_stack *sta, t_stack *stb);
void	rotate_rotate(t_stack *sta, t_stack *stb);
void	rev_rev(t_stack *sta, t_stack *stb);
t_ans	*singleton(void);
t_ans	*add_link(char *cmd);
int		lst_size(t_ans *lst);
void	print_ans(void);
void	delete_list(t_ans *lst);

#endif
