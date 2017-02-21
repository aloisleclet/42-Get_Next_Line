/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:13 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/21 12:03:36 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 7
//problem 100
# include <stdio.h>

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.c" // to delete
# include "get_next_line.c"

int get_next_line(int const fd, char **line);

#endif

