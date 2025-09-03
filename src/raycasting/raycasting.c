/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:31 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/03 18:19:22 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

init_vision
init_rays
prepare_dda
project_walls
    prepare_calculation
        calculation wallx 
        calculate x in texture
        calculate draw end et draw start
    select_texture_or_colors
        if texture :
            define_texture_position
        else if color : 
            define_rgb
    draw_everything
        define where tot start with drawstart, drawend, ... mais pas tres bien compris cela
        if texture : paint_texture -> texture_in_img
        if color : paint_simple -> pixel_in_img

        // faut il faire une struct pour mettre les images des textures ?
        // en sachant que je ne fais pas la DDA et que je nai pas les valeurs,
        // j'ai decide de faire un init de valeur de test, mais comment au cours 
        //de mon avancement je vais pouvoir tester que cela fonctionne ?
        // il faut que je puisse aller petit bout par petit bout