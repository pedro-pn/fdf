/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 03:26:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/20 17:09:25 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_alg(unsigned int n)
{
	unsigned int		num;
	int					counter;

	num = n;
	counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static char	*alloc(unsigned int n)
{
	char	*s;
	int		counter;

	counter = num_alg(n);
	if (n <= 0)
		counter++;
	s = (char *) malloc((counter * sizeof(char)) + 1);
	if (!s)
		return (NULL);
	return (s);
}

static int	power(int x, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (x * power(x, p - 1));
}

static void	convert_itoa(unsigned int n, int cf, char *itoa)
{
	int				index;
	unsigned int	div;

	index = 0;
	div = n;
	while (cf != 0)
	{
		itoa[index] = (div / cf) + 48;
		div = div - (div / cf) * cf;
		index++;
		cf /= 10;
	}
	itoa[index] = 0;
}

char	*ft_utoa(unsigned int n)
{
	char	*itoa;
	int		cf;
	int		n_alg;

	itoa = alloc(n);
	if (!itoa)
		return (NULL);
	if (n == 0)
	{
		itoa[0] = 48;
		itoa[1] = 0;
		return (itoa);
	}
	n_alg = num_alg(n) - 1;
	cf = power(10, n_alg);
	convert_itoa(n, cf, itoa);
	return (itoa);
}
