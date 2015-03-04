/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:52:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/20 19:53:15 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NO_FLAG	(1 << 0)
# define VERBOSE	(1 << 1)
# define NB_OP		(1 << 2)
# define BEST_ALGO	(1 << 3)
# define R_S		(1 << 4)
# define INS		(1 << 5)

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
	t_stack	*a;
	t_stack	*b;
	int		cpt;
	t_ans	*next;
	t_ans	*last;
};

void	print_error(char *msg);
void	is_duplicate(t_stack *st);
t_stack	*create_stack(char **av, int ac, int size, char name);
void	print_stack(t_stack *st);
t_stack	*swap(t_stack *st, t_stack *st2, t_ans *lst);
t_stack	*rotate(t_stack *st, t_stack *st2, t_ans *lst);
t_stack	*rev_rotate(t_stack *st, t_stack *st2, t_ans *lst);
t_stack	*push(t_stack *sender, t_stack *receiver, t_ans *lst);
void	swap_swap(t_stack *sta, t_stack *stb, t_ans *lst);
void	rotate_rotate(t_stack *sta, t_stack *stb, t_ans *lst);
void	rev_rev(t_stack *sta, t_stack *stb, t_ans *lst);
t_ans	*singleton(void);
t_ans	*add_link(t_ans *lst, char *cmd, t_stack *a, t_stack *b);
int		lst_size(t_ans *lst);
void	print_ans(t_ans *lst);
void	delete_list(t_ans *lst);
void	is_valid(char **av, int ac, int nb_opt);
int		is_sorted(t_stack *a);
int		rev_is_sorted(t_stack *a);
void	sort_2(t_stack *stack, t_ans *lst);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
void	rot_swap(t_stack *a, t_stack *b, t_ans *lst);
void	push_min(t_stack *a, t_stack *b, t_ans *lst);
void	display(t_ans *ans1, t_ans *ans2, t_stack *a, t_stack *b);
int		*get_flag(void);
int		init_flags(int ac, char **av);
t_stack	*dup_stack(t_stack *st);

#endif
