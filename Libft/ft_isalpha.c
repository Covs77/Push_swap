/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:35:33 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/26 19:39:46 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)

{
	if (((c > 96) && (c < 123)) || ((c > 64) && (c < 91)))
		return (1);
	return (0);
}
