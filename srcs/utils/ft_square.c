/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:27 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/05 16:53:29 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(char *str, char *charset);
int	nb_word(char *str, char *charset);

char **ft_square(char **map, int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            map[y + i][x + j] = 'x';
            j++;
        }
        i++;
    }
    return (map);
}