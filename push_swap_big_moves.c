/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:42 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/06 20:41:50 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

int ft_max3(t_stack *s)
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

void	ft_up_or_down(t_stack **a, t_stack **b)
{
	int max;
	int medium;

	max = ft_max3(*a);
	medium = ft_len_list(*a) / 2;
	while (ft_len_list(*a) > 3)
	{
		if ((*a)->data >= max)
		{
			to_last(a);
			write(1, "ra\n", 3);
		}
		else if ((*a)->pos >= medium) //lo paso abajo de B
		{
			push(a, b);
			write(1, "pb\n", 3);
			ft_print_list(*b);
			if ((*b)->next && (*b)->pos > (*b)->next->pos)
			{
				to_last(b);
				ft_print_list(*b);
				write(1, "rb\n", 3);
			}
		}
		else // lo paso arriba de B
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
		///los pasa a b dejando abajo los mas grandes (no muy fino)
	}
}

