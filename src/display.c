#include "push_swap.h"

static void	disp_algo(t_ans *ans1, t_ans *ans2)
{
	int		*flag;

	flag = get_flag();
	if (*flag & INS && *flag & R_S)
	{
		ft_putstr("Rot-swap : ");
		print_ans(ans1);
		ft_putstr("\nInsertion : ");
		print_ans(ans2);
	}
	else if (*flag & R_S)
		print_ans(ans1);
	else if (*flag & INS)
		print_ans(ans2);
	else
		(ans1->cpt > ans2->cpt) ? print_ans(ans2) : print_ans(ans1);
}

static void	disp_nb_op(t_ans *ans1, t_ans *ans2)
{
	int		*flag;

	flag = get_flag();
	if (*flag & NB_OP)
	{
		if (*flag & INS && *flag & R_S)
		{
			ft_putstr("\nRot-swap : ");
			ft_putnbr(ans1->cpt);
			ft_putendl(" operations done");
			ft_putstr("Insertion : ");
			ft_putnbr(ans2->cpt);
		}
		else if (*flag & R_S)
			ft_putnbr(ans1->cpt);
		else if (*flag & INS)
			ft_putnbr(ans2->cpt);
		else
			(ans1->cpt > ans2->cpt) ? ft_putnbr(ans2->cpt)
				: ft_putnbr(ans1->cpt);
		ft_putendl(" operations done");
	}
}

void		display(t_ans *ans1, t_ans *ans2, t_stack *a, t_stack *b)
{
	int		*flag;

	flag = get_flag();
	disp_algo(ans1, ans2);
	if (*flag & VERBOSE)
	{
		print_stack(a);
		print_stack(b);
	}
	disp_nb_op(ans1, ans2);
	if (*flag & BEST_ALGO)
	{
		ft_putstr("Best algo : ");
		if (ans1->cpt == 0)
			ft_putendl("'Insertion'");
		else if (ans2->cpt == 0)
			ft_putendl("'Rot-Swap'");
		else
			(ans1->cpt < ans2->cpt) ? ft_putendl("'Rot-swap'")
				: ft_putendl("'Insertion'");
	}
}