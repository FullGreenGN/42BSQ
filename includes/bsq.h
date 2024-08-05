/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 17:34:06 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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