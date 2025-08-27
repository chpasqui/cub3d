/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:17:17 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/27 16:30:47 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//ARGUMENTS
# define WRONG_ARGS "not the right amount of arguments"
# define BAD_EXTENSION "map file must end with .cub"
# define CANNOT_OPEN	"cannot open map file"
# define INVALID_NAME "invalid file name"
# define EMPTY_FILE	"file is empty"
# define GRID_LAST	"grid is not the last in .cub"
# define GRID_CHAR	"grid must contain only '10 ', and exactly one player 'NSEW'"
# define GRID_CLOSE "grid not closed"


//GENERIC
# define PARSE_FAIL	"parsing failed"

#endif
