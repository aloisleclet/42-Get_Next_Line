/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:13 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/14 12:06:18 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 8
//buff 7 problem 1/4
# include <stdio.h>

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.c"

int get_next_line(int const fd, char **line);

#endif

