/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:31:50 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/26 19:50:01 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_list(t_stack	*stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

void	ft_print_list(t_stack *stack)
{
	printf ("\nLista :");
	while (stack != NULL)
	{
		printf ("%d - ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*ft_lst_last(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

///borro 1ª nodo
/* t_stack	*ft_delete_first(t_stack *lista)
{
	t_stack	*aux;

	aux = lista;
	lista = lista->next;
	free(aux);
	return (lista);
} */

/// Añado el 1 al fin. Localizo ultimo nodo, hago q apunte al nuevo

t_stack	*ft_add_back(t_stack *stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL)
		stack = new;
	else
	{
		last = (ft_lst_last (stack));
		last->next = new;
		new->next = NULL;
	}
	return (stack);
}
