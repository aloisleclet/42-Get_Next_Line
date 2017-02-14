/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:10 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/14 12:32:14 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//len

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// join

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return ((void*)(0));
	res = (char*)(malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))));
	if (res != (void*)(0))
	{
		while (*(s1 + j))
		{
			*(res + (i++)) = *(s1 + j);
			j++;
		}
		j = 0;
		while (*(s2 + j))
		{
			*(res + (i++)) = *(s2 + j);
			j++;
		}
		*(res + i) = '\0';
	}
//	if (s1 != (void*)(0))
//		free(*s1);
	return (res);
}

//chr

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	return (*(s + i) == c) ? (char*)(s + i) : (void*)(0);
}

//cpy

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

////////////////////////////////////////////////////////////////////////////////////////////

char	*ft_drop_first_char(char *str)
{
	int		i;
	char	*res;

	i = 1;
	res = (char*) malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		*(res + i - 1) = str[i];
		i++;
	}
	*(res + i - 1) = '\0';
	return (res);
}

//chr begin

char	*ft_strchr_begin(const char *s, int c)
{
	int		i;
	int		j;
	char	*res;
	
	i = 0;
	j = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	i = 0;
	res = (char*)malloc(sizeof(char) * (i + 1));
	while (*(s + i) != c && *(s + i))
	{
		*(res + i) = *(s + i);
		i++;
	}
	*(res + i) = '\0';
	return (*(s + i) == c) ? (char*)(res) : (void*)(0);
}

void	add_rest(char **line, char **rest)
{
	if (*rest != NULL)
	{
		ft_strcpy(*line, ft_strjoin(*line, *rest));
		*rest = NULL;
	}
}

//int		read_line(int const fd, char **line)
//{
int		get_next_line(int const fd, char **line)
{
	long			n;
	char			buf[BUF_SIZE];
	static char		*rest = NULL;
	char			*tmp;

	n = 0;
	tmp = NULL;

	if (!fd)
		return -1;
	*line = (char *)malloc(sizeof(char) * 100); // todo : create a function to malloc line 
	while ((n = read(fd, buf, BUF_SIZE)) && !ft_strchr(buf, '\n'))
	{
		add_rest(line, &rest);
		ft_strcpy(*line, ft_strjoin(*line, buf));
		printf("0[%s]\n", *line);
	}
	if (ft_strchr(buf, '\n') && !ft_strchr(buf, EOF))
	{
		//join line and before \n
		ft_strcpy(*line, ft_strjoin(*line, ft_strchr_begin(buf, '\n')));
		//retrieve next rest
		rest = ft_drop_first_char(ft_strchr(buf, '\n'));
		printf("rest [%s]\n", rest);
		return 1;
	}
	rest = NULL;
	return 0;
}






