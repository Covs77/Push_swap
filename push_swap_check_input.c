/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:47:22 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/17 16:45:21 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		write (2, "Error", 5);
		write (2, "\n", 1);
	}
}

int	ft_check_num(char **str)
{
	int	error;
	int	i;
	int	j;

	error = 0;
	i = 0;
	j = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		while (str[i][j] != '\0')
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			error = ft_isdigit(str[i][j]);
			if (error == 1)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (error);
}

int	ft_check_repe(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT_MAX || (ft_atoi(str[i]) < INT_MIN))
			return (1);
		else
			j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[j]) > INT_MAX || (ft_atoi(str[j]) < INT_MIN))
				return (1);
			else if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_inputs(char **str)
{
	int	error;

	error = 0;
	error = ft_check_num(str);
	if (error == 0)
	{
		error = error + ft_check_repe(str);
	}
	if (error == 1)
		return (1);
	return (0);
}

void	ft_free(t_stack **s)
{
	t_stack	*aux;

	if (s)
	{
		while (*s != NULL)
		{
			aux = *s;
			*s = (*s)->next;
			free(aux);
		}
	}
}
