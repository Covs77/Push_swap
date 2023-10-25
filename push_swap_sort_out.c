/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:40:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/25 18:46:39 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

//No ordena bien la pila de 5, no chequea la entrada del segundo elemento de B
// para eso tendría que mover forzosamente los menores de A siempre.

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
			to_last(stack_a);
			write(1, "ra\n", 3);
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			rotate(stack_a);
			write(1, "rra\n", 4);
		}
		else
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
	}
}

void	ft_sort_out(t_stack **stack_a, int nums)
{
	t_stack	**stack_b;

	nums--;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	stack_b = NULL;
	if (nums == 2)
		ft_sort_2(stack_a);
	else if (nums == 3)
		ft_sort3(stack_a);
	else if (nums > 3)
		ft_sort5(stack_a, stack_b);
	/* else
	{
		// programa de ordenacion completo
		// ft_3tower(&stack_a, &stack_b);
	} */	
	ft_free(stack_b);
	ft_print_list(*stack_a);
}
