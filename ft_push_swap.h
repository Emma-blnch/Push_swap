/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:06 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 14:01:28 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
    int value;              // valeur stocker dans le node
    struct s_node   *next;  // pointeur sur prochain node
}   t_node;

typedef struct s_stak {
    t_node  *top;           // pointeur sur haut de pile
    int size;               // nombre d'elements dans la pile
}   t_stack;

t_stack *init_stack(void);
int main(int argc, char **argv);

#endif