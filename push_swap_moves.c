/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:22:05 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 17:50:31 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// ROTAMOS LA LISTA, EL 1º PASA A SER EL ÚLIMO
t_stack	*ra(t_stack *stack)
{
	t_stack	*aux;
	int		len;

	len = ft_len_list(stack);
	if (len < 2)
		return (stack);
	aux = stack;
	stack = stack->next;
	ft_add_back (stack, aux);
	return (stack);
}

// ROTO EL ÚLTIMO AL PRIMERO. (t_stack	*ft_lst_last(t_stack *lst))
t_stack	*rra(t_stack *stack)
{
	t_stack	*penultimo;
	t_stack	*fin;
	int		len;
	int		i;

	len = ft_len_list(stack);
	if (len < 2)
		return (stack);
	i = 1;
	penultimo = stack;
	while (i < (len - 1))
	{
		penultimo = penultimo->next;
		i++;
	}
	fin = ft_lst_last(stack);
	fin->next = stack;
	penultimo->next = NULL;
	stack = fin;
	return (stack);
}

t_stack	*sa(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = ft_len_list(stack);
	if (len < 2)
		return (stack);
	tmp = stack->next;
	stack->next = stack->next->next;
	tmp->next = stack;
	stack = tmp;
	return (stack);
}
