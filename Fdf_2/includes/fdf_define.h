/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:28 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 20:11:18 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

/*Touches*/
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define NUMPAD_1	65436
# define NUMPAD_2	65433
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_5	65437
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_8	65431
# define NUMPAD_9	65434

# define NUMKEY_1	49
# define NUMKEY_2	50
# define NUMKEY_3	51
# define NUMKEY_4	52
# define NUMKEY_5	53
# define NUMKEY_6	54
# define NUMKEY_7	55
# define NUMKEY_8	56
# define NUMKEY_9	57

# define MID_CLIC	2
# define PAD_UP		5
# define PAD_DOWN	4
# define PAD_LEFT	7
# define PAD_RIGHT	6

# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_SPACE	32

# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_I		105
# define KEY_O		111
# define KEY_L		108
# define KEY_R		114
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101
# define KEY_ESC    65307

/*Colors*/
# define CO_WHITE	0xFFFFFF
# define CO_BLACK	0x000000
# define CO_GREY	0x505050
# define CO_RED		0xFF0000
# define CO_GREEN	0x00FF00
# define CO_BLUE	0x0000FF
# define CO_YELLOW	0xFFFF00
# define CO_CYAN	0x00FFFF
# define CO_PINK	0xFF00FF
# define CO_ORANGY	0xFFA500
# define CO_BLUEY	0x0492C2
# define CO_GREENY	0x20C292
# define LINE_DEFAULT		CO_WHITE
# define BACKGROUND_DEFAULT	CO_GREY
# define C_TEXT				CO_GREY

/*Projections*/
# define ISOMETRIC		1
# define PERSPECTIVE	2
# define TOP			3

/*Conversion bases & useful angles in rad*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

# define WINDOW_WIDTH		1240
# define WINDOW_HEIGHT		720
# define MAX_PIXEL			892800
# define MENU_WIDTH			245

#endif