#include "cub3d.h"

int render_frame(t_game *g)
{
  for (int x = 0; x < g->w; ++x) {
    double cameraX = 2.0*x/g->w - 1.0;
    double rayDirX = g->dirX + g->planeX * cameraX;
    double rayDirY = g->dirY + g->planeY * cameraX;

    int mapX = (int)g->posX;
    int mapY = (int)g->posY;

    double deltaDistX = sqrt(1 + (rayDirY*rayDirY)/(rayDirX*rayDirX));
    double deltaDistY = sqrt(1 + (rayDirX*rayDirX)/(rayDirY*rayDirY));
    double sideDistX, sideDistY; int stepX, stepY;

    if (rayDirX < 0) { stepX=-1; sideDistX=(g->posX-mapX)*deltaDistX; }
    else             { stepX= 1; sideDistX=(mapX+1.0-g->posX)*deltaDistX; }
    if (rayDirY < 0) { stepY=-1; sideDistY=(g->posY-mapY)*deltaDistY; }
    else             { stepY= 1; sideDistY=(mapY+1.0-g->posY)*deltaDistY; }

    int hit=0, side=0;
    while (!hit) {
      if (sideDistX < sideDistY) { sideDistX += deltaDistX; mapX += stepX; side = 0; }
      else                        { sideDistY += deltaDistY; mapY += stepY; side = 1; }
      if (g->map[mapY][mapX] > 0) hit = 1;
    }

    double perpWallDist = (side==0) ? (sideDistX - deltaDistX) : (sideDistY - deltaDistY);
    int lineH = (int)(g->h / perpWallDist);
    int y0 = -lineH/2 + g->h/2; if (y0 < 0) y0 = 0;
    int y1 =  lineH/2 + g->h/2; if (y1 >= g->h) y1 = g->h-1;

    // texturing :
    int texId = g->map[mapY][mapX] - 1;
    double wallX = (side==0) ? (g->posY + perpWallDist*rayDirY) : (g->posX + perpWallDist*rayDirX);
    wallX -= floor(wallX);
    int texX = (int)(wallX * g->texW[texId]);
    if (side==0 && rayDirX>0) texX = g->texW[texId] - texX - 1;
    if (side==1 && rayDirY<0) texX = g->texW[texId] - texX - 1;

    double step = 1.0 * g->texH[texId] / lineH;
    double texPos = (y0 - g->h/2 + lineH/2) * step;

    // plafond
    draw_vert_line(g, x, 0, y0-1, g->ceil_color);
    // mur
    for (int y=y0; y<=y1; ++y) {
      int texY = (int)texPos & (g->texH[texId]-1);
      texPos += step;
      uint32_t c = sample_texel(g, texId, texX, texY);
      if (side==1) c = shade_half(c); // assombrir faces EW
      put_px(g, x, y, c);
    }
    // sol
    draw_vert_line(g, x, y1+1, g->h-1, g->floor_color);
  }
  mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
  return 0;
}
