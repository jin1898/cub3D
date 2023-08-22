/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:24 by tnam              #+#    #+#             */
/*   Updated: 2023/07/18 19:17:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_sign(t_strtol *v)
{
	v->neg = 0;
	v->c = *(v->s)++;
	if (v->c == '-')
	{
		v->neg = 1;
		v->c = *(v->s)++;
	}
	else if (v->c == '+')
		v->c = *(v->s)++;
}

static void	ft_check_base(t_strtol *v, int *base)
{
	if ((*base == 0 || *base == 16) && v->c == '0'
		&& (*v->s == 'x' || *v->s == 'X'))
	{
		v->c = v->s[1];
		v->s += 2;
		*base = 16;
	}
	else if ((*base == 0 || *base == 2) && v->c == '0'
		&& (*v->s == 'b' || *v->s == 'B'))
	{
		v->c = v->s[1];
		v->s += 2;
		*base = 2;
	}
	if (*base == 0)
	{
		if (v->c == '0')
			*base = 8;
		else
			*base = 10;
	}
}

static void	ft_make_num(t_strtol *v, int *base)
{
	while (1)
	{
		if (ft_isdigit(v->c))
			v->c -= '0';
		else if (ft_isalpha(v->c))
			v->c -= 'A' - 10;
		else
			break ;
		if (v->c >= *base)
			break ;
		if (v->any < 0 || v->acc > v->cutoff
			|| (v->acc == v->cutoff && v->c > v->cutlim))
			v->any = -1;
		else
		{
			v->any = 1;
			v->acc *= *base;
			v->acc += v->c;
		}
		v->c = *(v->s)++;
	}
}

static void	ft_check_overflow(t_strtol *v)
{
	if (v->any < 0)
	{
		if (v->neg)
			v->acc = LONG_MIN;
		else
			v->acc = LONG_MAX;
	}
	else if (v->neg)
		v->acc = -v->acc;
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_strtol	v;

	v.s = nptr;
	while (ft_isspace(*v.s))
		(v.s)++;
	ft_check_sign(&v);
	ft_check_base(&v, &base);
	if (v.neg)
		v.cutoff = -(unsigned long)LONG_MIN;
	else
		v.cutoff = LONG_MAX;
	v.cutlim = v.cutoff % (unsigned long)base;
	v.cutoff /= (unsigned long)base;
	v.acc = 0;
	v.any = 0;
	ft_make_num(&v, &base);
	ft_check_overflow(&v);
	if (endptr != 0)
	{
		if (v.any)
			*endptr = (char *)(v.s - 1);
		else
			*endptr = (char *)nptr;
	}
	return (v.acc);
}
