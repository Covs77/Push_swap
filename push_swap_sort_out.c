/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:40:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 20:23:34 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_sort5(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = malloc(sizeof(t_stack *));
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
	ft_free_list(stack_b);
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

	if (ft_order(*stack_a) == 1)
		return ;
	stack_b = malloc(sizeof(t_stack *));
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
	ft_free_list(stack_b);
}

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
		to_move_b = ft_find_lower_cost(*a, *b);
		to_move_a = ft_find_hole(*a, to_move_b);
		ft_sort_on_top_both(a, b, to_move_a, to_move_b);
		push(b, a);
		write(1, "pa\n", 3);
	}
	while ((*a)->pos != 0)
	{
		if ((*a)->pos >= (ft_len_list(*a) / 2))
			move_to_last(a, NULL, "ra");
		else
			move_rotate(a, NULL, "rra");
	}
}

int	ft_find_lower_cost(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*aux_b;
	t_stack	*aux_a;
	int		pos_a;
	int		total_cost;

	min = 0;
	aux_b = b;
	aux_a = a;
	total_cost = 0;
	while (aux_b)
	{
		pos_a = ft_find_hole(aux_a, aux_b->pos);
		total_cost = ft_total_cost (pos_a, a, aux_b);
		if (total_cost == min)
			return (aux_b->pos);
		else
			aux_b = aux_b->next;
		if (aux_b == NULL)
		{
			min++;
			aux_b = b;
		}
	}
	return (aux_b->pos);
}
