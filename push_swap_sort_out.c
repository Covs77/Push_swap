/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:40:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/15 20:48:35 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_sort5(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	ft_3tower (stack_a, stack_b);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->data > (*stack_a)->data)
		{
			move_to_last(stack_a, stack_b, "ra");
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			move_rotate(stack_a, NULL, "rra");
		}
		else
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
	}
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	ft_up_or_down(a, b);
	ft_sort3(a);
	ft_sort(a, b);
}

void	ft_sort_out(t_stack **stack_a, int nums)
{
	t_stack	**stack_b;

	nums--;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	if (nums == 2)
		ft_sort_2(stack_a);
	else if (nums == 3)
		ft_sort3(stack_a);
	else if (nums <= 5)
		ft_sort5(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
	ft_free(stack_b);
}

/// no ordena eficientemente, no chequeo cuál es 
// el más barato
void	ft_sort(t_stack **a, t_stack **b)
{
	int		to_move_a;
	int		to_move_b;
	int		min;
	
	
	min = 0;
	
	while (*b)
	{
		ft_cost_a(a);
		ft_cost_b(b);
		//ft_print_list(*a); 
		//ft_print_list(*b); 
		to_move_b = ft_find_lower_cost(*a, *b);
		to_move_a = ft_find_hole(*a, (*b)->pos);
		ft_sort_on_top_both(a, b, to_move_a, to_move_b);
		push(b, a);
		write(1, "pa\n", 3);
		
	}
	while ((*a)->pos != 0)
	{
		if ((*a)->cost > 0)
			move_to_last(a, NULL, "ra");
		else
			move_rotate(a, NULL, "rra");
	} 
	//printf ("ordenada\n");
	//ft_print_list(*a); 
}