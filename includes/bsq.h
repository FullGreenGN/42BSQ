/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 17:36:13 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_rgs_data
{
	char			empty; // .
	char			obstacle; // O
	char			filler; // x
	unsigned int	nb_lines; // 10
}					t_args_data;

typedef struct s_result_pos
{
	unsigned int	start[2];
	unsigned int	end[2];
}					t_result_pos;

#endif