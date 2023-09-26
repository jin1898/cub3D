/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:42:17 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 21:59:12 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it_set(const char *location, const char *set)
{
	size_t	set_strlen;
	size_t	index;

	index = 0;
	set_strlen = ft_strlen(set);
	while (index < set_strlen)
	{
		if (set[index] == *location)
			return (1);
		index++;
	}
	return (0);
}

static char	*mal(const char *start, const char *end)
{
	int		i;
	int		string_strlen;
	char	*box;

	string_strlen = end - start;
	i = 0;
	box = malloc(sizeof(char) * (string_strlen + 2));
	if (box == NULL)
		return (NULL);
	box[string_strlen + 1] = 0;
	while (i <= string_strlen)
	{
		box[i] = start[i];
		i++;
	}
	return (box);
}

static char	*no_mal(void)
{
	char	*box;

	box = malloc(sizeof(char));
	if (box == NULL)
		return (NULL);
	box[0] = 0;
	return (box);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		i;
	const char	*start;
	const char	*end;

	i = 0;
	start = NULL;
	end = NULL;
	while (s1[i] != '\0')
	{
		if (is_it_set(&s1[i], set) == 0 && start == NULL)
			start = &s1[i];
		if (is_it_set(&s1[i], set) == 0)
			end = &s1[i];
		i++;
	}
	if (start && end)
		return (mal(start, end));
	else
		return (no_mal());
}
