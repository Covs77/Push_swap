/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:34:48 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/12 12:47:21 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

// devuelve el valor medio
int	ft_medium(t_stack *stack)
{
	int	sum;
	int	total;
	int	medio;

	sum = 0;
	total = 0;
	medio = 0;
	while (stack != NULL)
	{
		sum = sum + stack->data;
		stack = stack->next;
	}
	total = ft_len_list(stack);
	medio = sum / total;
	printf ("medio: %d\n", medio);
	return (medio);
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

// DEVUELVE 1 SI OK, 0 SI NO ESTÁ ORDENADA
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

int	ft_max(t_stack *s, int max)
{
	while (s != NULL)
	{
		if (max <= s->data)
			max = s->data;
		s = s->next;
	}
	return (max);
}
