/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:10 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/21 12:06:56 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
