# fdf

---

## 42-Subject

"Fil de fer" in french. This project is the first 3D project in our curriculum at 42 school.

---

## How to use it ?

`make` and `./fdf MAP_PATH`

Like `./fdf France.XXL.fdf`

All maps are stored in `maps` directory

---

## Main topics learned in this project

- Library MLX (MiniLibX) : Graphical windows, images and hooks among other things. An important notion is that usually a pixel is a 4 bytes int (it is a color), containing trgb properties. 

- Structures can't be avoided here. A huge structure containing all the mlx's requirements, and the map's parameters, that might be called fdf, is required because some functions such as hooks can have only one argument. 

- Parsing: Some maps are tricky to parse. They can start with a space, some others contain hex colors alongside the altitude, etc.

- Line drawing : there comes the bresenham's alogrithm. It's well explained on Wikipedia, but it need to be the fastest possible in order to have the most fluid program. It can be reducted to 4 functions, and even 2 if well optimized.  

---

## Useful links to realize this project

https://harm-smits.github.io/42docs/libs/minilibx/hooks.html 

3D rendering : https://www.kmjn.org/notes/3d_rendering_intro.html 

Download the good MLX : https://github.com/42Paris/minilibx-linux/blob/master/mlx.h 

Bresenham: https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham#:~:text=L'algorithme%20de%20trac%C3%A9%20de,attach%C3%A9%20%C3%A0%20une%20console%20texte. 

Pixel drawing : https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx 

Pixel drawing : https://github.com/lavrenovamaria/42-fract-ol 

Hex char to int : https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int
