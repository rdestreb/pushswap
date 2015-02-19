/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:52:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/19 14:48:55 by cmehay           ###   ########.fr       */
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
	t_ans	*last;
};

void	print_error(char *msg);
void	is_duplicate(t_stack *st);
t_stack	*create_stack(char **av, int size, char name);
void	print_stack(t_stack *st);
t_stack	*swap(t_stack *st, t_ans *lst);
t_stack	*rotate(t_stack *st, t_ans *lst);
t_stack	*rev_rotate(t_stack *st, t_ans *lst);
t_stack	*push(t_stack *sender, t_stack *receiver, t_ans *lst);
void	swap_swap(t_stack *sta, t_stack *stb, t_ans *lst);
void	rotate_rotate(t_stack *sta, t_stack *stb, t_ans *lst);
void	rev_rev(t_stack *sta, t_stack *stb, t_ans *lst);
t_ans	*singleton(void);
t_ans	*add_link(t_ans *lst, char *cmd);
int		lst_size(t_ans *lst);
void	print_ans(t_ans *lst);
void	delete_list(t_ans *lst);
int		is_sorted(t_stack *a);
int		rev_is_sorted(t_stack *a);
void	sort_2(t_stack *stack, t_ans *lst);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
void	rot_swap(t_stack *a, t_ans *lst);
void	push_min(t_stack *a, t_stack *b, t_ans *lst);

#endif
