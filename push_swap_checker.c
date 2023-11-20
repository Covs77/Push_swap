/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:59:01 by cova              #+#    #+#             */
/*   Updated: 2023/11/20 16:47:03 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	ft_check_moves(t_stack *stack_a, t_stack *stack_b)
{
 
	printf("Input: ");
	ft_print_list(stack_a);
	stack_a = ra(stack_a);
	printf("ra: ");
	ft_print_list(stack_a);
	stack_a = rra(stack_a);
	printf("rra: ");
	ft_print_list(stack_a);
	stack_a = sa(stack_a);
	printf("sa: ");
	ft_print_list(stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	stack_a = sa(stack_b); 
	printf("sa: ");
	ft_print_list(stack_a);
	//printf("tras sa (b): ");
	//ft_print_list(stack_b);
	printf("Pb");
	printf("%d \n", stack_a->data);
	//pb(&stack_a, &stack_b); /////
	//printf("Stack_a tras pa:");
	//ft_print_list(stack_a);
	//printf("Stack_b tras pa:");
	//ft_print_list(stack_b);
} */

void	ft_print_list(t_stack *stack)
{
	while (stack != NULL)
	{
		printf ("%d  ", stack->data);
		printf ("      (pos:%d -", stack->pos);
		printf ("a:%d", stack->cost_a);
		printf (" b:%d)\n", stack->cost_b);
		stack = stack->next;
	}
	printf("\n");
}
