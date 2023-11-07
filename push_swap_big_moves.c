/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:42 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/07 18:12:26 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

int	ft_max3(t_stack *s)
{
	int		max_1;
	int		max_2;
	int		max_3;

	max_1 = INT_MIN;
	max_2 = INT_MIN;
	max_3 = INT_MIN;
	while (s != NULL)
	{
		if (s->data > max_1)
		{
			max_3 = max_2;
			max_2 = max_1;
			max_1 = s->data;
		}
		else if (s->data > max_2)
		{
			max_3 = max_2;
			max_2 = s->data;
		}
		else if (s->data > max_3)
			max_3 = s->data;
		s = s->next;
	}
	return (max_3);
}

/// se sigue yendo de líneas. 

/* void	moves(t_stack **a, t_stack **b, char *move)
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
	if (ft_strcmp(move, "rra"))
	{	rotate(a);
		write(1, "rra\n", 4);
	}
	if (ft_strcmp(move, "rrb"))
	{	rotate(b);
		write(1, "rrb\n", 4);
	}
} */


void	ft_up_or_down(t_stack **a, t_stack **b)
{
	int	medium;

	medium = ft_len_list(*a) / 2;
	while (ft_len_list(*a) > 3)
	{
		if ((*a)->data >= ft_max3(*a))
		{
			to_last(a);
			write(1, "ra\n", 3);
		}
		else if ((*a)->pos >= medium)
		{
			push(a, b);
			write(1, "pb\n", 3);
			if ((*b)->next && (*b)->pos > (*b)->next->pos)
			{
				to_last(b);
				write(1, "rb\n", 3);
			}
		}
		else
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
	}
}


