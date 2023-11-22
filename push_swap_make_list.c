/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:35 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:20 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_new_nodo con el contenido del str y el siguiente-> NULL

void	ft_new_nodo(t_stack **stack, int valor)
{
	t_stack	*new_nodo;
	t_stack	*aux;

	new_nodo = malloc (sizeof (t_stack));
	if (!new_nodo)
		return ;
	new_nodo->data = valor;
	new_nodo->next = NULL;
	new_nodo->cost_a = 0;
	new_nodo->cost_b = 0;
	aux = NULL;
	if (*stack == NULL)
		*stack = new_nodo;
	else
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new_nodo;
	}
}

t_stack	**ft_make_list(char **str)
{
	t_stack	**stack;
	int		i;
	int		valor;

	i = 0;
	stack = malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	while (str[i] != NULL)
	{
		valor = ft_atoi(str[i]);
		ft_new_nodo(stack, valor);
		i++;
	}
	return (stack);
}

char	**ft_read_arg(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**readed;

	i = 1;
	str = malloc (sizeof (char *) * argc);
	if (!str)
		return (0);
	while (i <= argc - 1)
	{
		str = ft_strjoin_free(str, argv[i]);
		str = ft_strjoin_free(str, " ");
		i++;
	}
	readed = ft_split (str, ' ');
	free(str);
	return (readed);
}

// Almaceno la posicion final de cada nodo

void	ft_get_pos(t_stack **s, char **str)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *s;
	ft_bubble_sort(str);
	while (aux != NULL)
	{
		while (str[i] && aux)
		{
			if (aux->data == ft_atoi(str[i]))
			{
				aux->pos = i;
				i++;
				aux = aux->next;
			}
			else
				i++;
		}
		i = 0;
	}
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s3;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l_s3;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l_s3 = l_s1 + l_s2;
	if (!s1 && !s2)
		return (0);
	s3 = malloc (sizeof(char) * l_s3 + 1);
	if (s3 == NULL)
		return (0);
	s3 = ft_memcpy(s3, s1, l_s1);
	s3 = s3 + l_s1;
	s3 = ft_memcpy(s3, s2, l_s2 + 1);
	free(s1);
	return (s3 - (l_s1));
}
