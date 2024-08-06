/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 12:10:10 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_rgs_data
{
	char			empty; // .
	char			obstacle; // O
	char			filler; // x
	int				nb_lines; // 10
}					t_args_data;

typedef struct s_result_pos
{
	int		start[2];
	int		end[2];
}					t_result_pos;

#endif