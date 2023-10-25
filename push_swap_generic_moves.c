/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_generic_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:40:35 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 17:56:52 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// intercambia dos primeros elementos de la lista

void	interchange(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

// Pone el último el 1º
void	rotate(t_stack **stack)
{
	t_stack	*penultimo;
	t_stack	*fin;
	int		len;
	int		i;

	len = ft_len_list(*stack);
	if (len > 2)
	{
		i = 1;
		penultimo = *stack;
		while (i < (len - 1))
		{
			penultimo = penultimo->next;
			i++;
		}
		fin = ft_lst_last(*stack);
		fin->next = *stack;
		penultimo->next = NULL;
		*stack = fin;
	}
}

//pasa el 1er elemento al último lugar

void	to_last(t_stack **stack)
{
	t_stack	*aux;
	int		len;

	len = ft_len_list(*stack);
	if (len > 2)
	{
		aux = *stack;
		*stack = (*stack)->next;
		ft_add_back (*stack, aux);
	}
}

// mueve de una lista a la otra

void	push(t_stack **stack_origin, t_stack **stack_dest)
{
	t_stack	*aux;

	aux = *stack_origin;
	*stack_origin = (*stack_origin)->next;
	aux -> next = *stack_dest;
	*stack_dest = aux;
}
