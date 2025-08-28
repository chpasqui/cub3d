/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:17:17 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/28 13:55:46 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//ARGUMENTS
# define WRONG_ARGS "not the right amount of arguments"
# define BAD_EXTENSION_CUB "map file must end with .cub"
# define BAD_EXTENSION_XPM "texture file must end with .xpm"
# define CANNOT_OPEN "cannot open map file"
# define CANNOT_OPEN_XPM "cannot open texture file"
# define INVALID_NAME "invalid file name"
# define EMPTY_FILE	"file is empty"
# define MISSING_SPACE "missing space between identifier"
# define WRONG_IDENTIFIER "wrong identifier"
# define MISSING_IDENTIFIER "missing identifiers (NO, SO, WE, EA, F, C)"
# define MISSING_TEXTURE_PATH "missing one or more texture path"
# define INVALID_COLOR "invalid color values, must be in RGB format"
# define GRID_LAST	"grid is not the last in .cub"
# define GRID_CHAR	"grid must contain only '10 ', and exactly one player 'NSEW'"
# define GRID_CLOSE "grid not closed"


//GENERIC
# define PARSE_FAIL	"parsing failed"
# define MALLOC_FAIL "malloc failed"

#endif
