/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:34:48 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 17:47:40 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_check_moves(t_stack *stack_a, t_stack *stack_b)
{
/* 
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
	ft_print_list(stack_a);*/
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	//stack_a = sa(stack_b); 
	//printf("sa: ");
	//ft_print_list(stack_a);
	//printf("tras sa (b): ");
	//ft_print_list(stack_b);
	printf("Pb");
	printf("%d \n", stack_a->data);
	//pb(&stack_a, &stack_b); /////
	//printf("Stack_a tras pa:");
	//ft_print_list(stack_a);
	//printf("Stack_b tras pa:");
	//ft_print_list(stack_b);
}

// devuelve el valor medio
int	ft_medium(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack != NULL)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max / 2);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = __INT16_MAX__;
	while (stack != NULL)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

// COMPRUEBO SI LA LISTA ESTÁ ORDENADA, DEVUELVE 1 SI OK, 0 SI NO ESTÁ ORDENADA
int	ft_order(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data < stack->next->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	ft_back_order(t_stack *stack)
{
	int	len;

	len = ft_len_list(stack);
	while (len > 0)
	{
		if (stack->data > stack->next->data)
		{
			stack = stack->next;
			len--;
		}
		else
			return (0);
	}
	return (1);
}
