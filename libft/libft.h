/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:27:20 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/30 18:02:49 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);
void	writer(const char *str, int *i);
void	ft_putchar(int c, int *i);
void	ft_putnbr(int nb, int *len);
void	ft_putunsigned(unsigned int nb, int *len);
void	ft_puthexa(unsigned int n, int *len);

#endif