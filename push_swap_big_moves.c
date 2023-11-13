/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:42 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:05 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

void move_interchange(t_stack **a, t_stack **b, char *move)
{
	if (ft_strcmp (move, "sa") == 0)
	{
		interchange(a);
		write(1, "sa\n", 3);
	}
	if (ft_strcmp (move, "sb") == 0)
	{
		interchange(b);
		write(1, "sb\n", 3);
	}
	if (ft_strcmp (move, "ss") == 0)
	{
		interchange(a);
		interchange(b);
		write(1, "ss\n", 3);
	}
}

void	move_to_last(t_stack **a, t_stack **b, char *move)
{
	if (ft_strcmp (move, "ra") == 0)
	{
		to_last(a);
		write(1, "ra\n", 3);
	}
	if (ft_strcmp (move, "rb") == 0)
	{
		to_last(b);
		write(1, "rb\n", 3);
	}
	if (ft_strcmp (move, "rr") == 0)
	{
		to_last(a);
		to_last(b);
		write(1, "rr\n", 3);
	}
}

void move_rotate (t_stack **a, t_stack **b, char *move)
{
	if (ft_strcmp (move, "rra") == 0)
	{
		rotate(a);
		write(1, "rra\n", 4);
	}
	if (ft_strcmp (move, "rrb") == 0)
	{
		rotate(b);
		write(1, "rrb\n", 4);
	}
	if (ft_strcmp (move, "rrr") == 0)
	{
		rotate(a);
		rotate(b);
		write(1, "rrr\n", 4);
	}
}



void	ft_up_or_down(t_stack **a, t_stack **b)
{
	int	medium;
	int	max3;

	medium = ft_len_list(*a) / 2;
	max3 = ft_len_list(*a) - 4;
	while (ft_len_list(*a) > 3)
	{
		if ((*a)->pos > max3)
			move_to_last(a, b, "ra");
		else if ((*a)->pos > medium)
		{
			push(a, b);
			write(1, "pb\n", 3);
			//if ((*b)->next && (*b)->pos < (*b)->next->pos)
			//	move_to_last(a, b, "rb");
		}
		else
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
	}
	//ft_print_list(*a);
	//ft_print_list(*b);
}
