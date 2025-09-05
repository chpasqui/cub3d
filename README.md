# cub3d
cub3d

ETAPE A FAIRE
- Parse args :
    - check_file / okay
    - Read file (avec char **file lines)
    - Parse config(file_lines)
    - Extract_map(file_lines)
    - check_texture_validity()
    - check_map_validity()

Definir la direction du raycasting
Implementer la logique du raycasting
Imprimer les images
Gerer les mouvements du joueur

Donc il y aura plusieurs structures :

game qui rameute toutes les autres structs
mlx
raycasting (je sais pas comment appeler car je ne sais pas comment faire encore, qui gere donc les x et y)
draw pour dessiner (est ce quil faut separer les textures ?)
player pour gerer les mouvements


Sites interessants :
- https://hackmd.io/@nszl/H1LXByIE2#player-direction-vector-and-camera-vector
- https://lodev.org/cgtutor/graycasting.html


Travail en cours :

charlotte : 
verifier que le main tourne
pars_arg



sylvain :
pars_file : mettre les differentes infos(grid, texture, couleurs) dans la structure map


a faire :
afficher la grid en 2D
algo de verification de grid fermee

