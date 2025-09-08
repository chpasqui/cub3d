/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 17:49:13 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

// MOUSE
# define CLICK_L 1
# define CLICK_R 2
# define CLICK_S 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// KEYBOARD MAC
# ifdef __APPLE__
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92

// KEYBOARD LINUX
# elif defined (__linux__)
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_1 65457
# define KEY_2 65458
# define KEY_3 65459
# define KEY_4 65460
# define KEY_5 65461
# define KEY_6 65462
# define KEY_7 65463
# define KEY_8 65464
# define KEY_9 65465

#else
# error "unsupprted platform"
#endif

#endif
