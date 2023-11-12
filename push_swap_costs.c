/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/12 13:33:45 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_midi_list(t_stack *s)
{
	return (ft_len_list(s) / 2);
}

void	ft_cost_b(t_stack **b)
{
	int		i;
	int		j;
	int		midi;
	t_stack	*aux;

	aux = *b;
	i = 0;
	midi = 0;
	j = 0;
	midi = ft_midi_list(*b);
	if (ft_len_list(*b) % 2 != 0)
		j = midi;
	else
		j = midi -1;
	while (aux)
	{
		if (i <= midi)
			aux->cost_b = (i++);
		else
			aux->cost_b = (j--) * -1;
		aux = aux->next;
	}
}


// voy a buscar donde poner el nodo x de B en A
// busco la posición cercana mas alta al que quiero mover.
int ft_find_hole(t_stack **s, int pos)
{
	t_stack	*aux;
	int i;
	
	i = pos+1;
	aux = *s;
	while (aux != NULL)
	{
		if(aux->pos != i)
			i++;
		else 	
			break;
		aux = aux->next;
	}	
	return (i-1);
}
void	ft_cost_a(t_stack **a)
{
	int		i;
	int		j;
	int		midi;
	t_stack	*aux;

	aux = *a;
	i = 0;
	midi = 0;
	j = 0;
	midi = ft_midi_list(*a);
	if (ft_len_list(*a) % 2 != 0)
		j = midi;
	else
		j = midi -1;
	while (aux)
	{
		if (i <= midi)
			aux->cost_a = (i++);
		else
			aux->cost_a = (j--) * -1;
		aux = aux->next;
	}
	printf("A:");
	ft_print_list(*a);
}