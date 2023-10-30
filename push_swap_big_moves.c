/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:42 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/30 21:26:39 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

int ft_max3(t_stack *s)
{
	int		Max_1;
	int		Max_2;
	int		Max_3;
	t_stack	*current;
	
	current = s;
	Max_1 = INT_MIN;
	Max_2 = INT_MIN;
	Max_3 = INT_MIN;
	while (current != NULL)
	{
		if (current->data > Max_1)
		{
			Max_3 = Max_2;
			Max_2 = Max_1;
			Max_1 = current->data;
		}
		else if (current->data > Max_2)
		{
			Max_3 = Max_2;
			Max_2 = current->data;
		}
		else if (current->data > Max_3) 
		{
			Max_3 = current->data;
		}
		current = current->next;
	}
	return (Max_3);
}

void	ft_up_or_down(t_stack **a, t_stack **b)
{
	int max;

	max = ft_max3(*a);
	while (((*a)->data < max) && a && *a)
	{
		if ((*a)->data > ft_medium(*a))
		{
			push(a, b);
			write(1, "pb\n", 3);
			to_last(b);
			write(1, "rb\n", 3);
		}
		else
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
		//ft_print_list(*a);
		//ft_print_list(*b);
	} 
	//ft_print_list(*a);
	//ft_print_list(*b);
}