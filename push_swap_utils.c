/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:31:50 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:41 by cleguina         ###   ########.fr       */
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

void	ft_bubble_sort(char **str)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) > ft_atoi(str[j]))
			{
				aux = str[j];
				str[j] = str[i];
				str[i] = aux;
			}
			j++;
		}
		i++;
	}
}

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

void	ft_free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free (str);
	}
}
