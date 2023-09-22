#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	return ((void *) 0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	i;
	char	*res;

	s = 0;
	e = (size_t) ft_strlen(s1);
	while (s1[s] && ft_strchr(set, s1[s]) != 0)
		s++;
	while (e > 0 && ft_strchr(set, s1[e]) != 0)
		e--;
	if (s > e || (s == 0 && e == 0))
		i = 1;
	else
		i = e - s + 2;
	res = (char *) malloc(sizeof(char) * i);
	if (res == (void *) 0)
		return ((void *) 0);
	i = 0;
	while (s <= e)
		res[i++] = s1[s++];
	res[i] = '\0';
	return (res);
}


int main(void)
{
    char *a = "!";
    char *b;
    printf("befor : %s\n",a);
    printf("after : %s\n",ft_strtrim(a, "!"));
}