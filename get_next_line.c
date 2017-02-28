/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:10 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/23 13:57:21 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strndup(const char *s, int n)
{
	char	*s_dup;
	int		i;

	s_dup = (char *)malloc(n * sizeof(char) + 1);
	if (s_dup != NULL)
	{
		i = 0;
		while (i < n)
		{
			s_dup[i] = s[i];
			i++;
		}
		s_dup[i] = '\0';
	}
	return (s_dup);
}

int		get_next_line(int const fd, char **line)
{
	static char		*current_line = NULL;
	char			*tmp;
	char			buf[BUF_SIZE + 1];
	int				n;

	current_line = (current_line == NULL) ? ft_strnew(1) : current_line;
	while (!ft_strchr(buf, '\n') && (n = read(fd, buf, BUF_SIZE)))
	{
		buf[n] = '\0';
		tmp = current_line;
		current_line = ft_strjoin(current_line, buf);
		free(tmp);
	}
	if ((tmp = ft_strchr(current_line, '\n')))
	{
		*line = ft_strndup(current_line, tmp - current_line);
		tmp = current_line;
		current_line = ft_strdup(ft_strchr(current_line, '\n') + 1);
		free(tmp);
		return (1);
	}
	if (ft_strcmp(current_line, ft_strnew(1)) && (*line = current_line))
		return (1);	
	return (0);
}
