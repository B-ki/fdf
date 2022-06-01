# fdf
"Fil de fer" in french. This project is the first 3D project in our curriculum at 42 school.

Some tips to realize the FDF project : 

- Library MLX (MiniLibX) is required for this project. It allows us to use a graphical windows, images and hooks among other things. 42's mlx is not working perfectly so we need to download another one. 

- First all it is important to understand how the library works, the Harm-Smith's medium is perfect for it. And it's is also esential knowing how pixels are placed (cf lavrenovamari fact-ol's github). An important notion is that usually a pixel is a 4 bytes int (it is a color), containing trgb properties. 

- Structures can't be avoided here. A huge structure containing all the mlx's requirements, and the map's parameters, that might be called fdf, is required because some functions such as hooks can have only one argument. 

- Once mlx is mastered and the structure of the code is created, we need to be able to parse the map given as argument. Ft_split and gnl are perfect for it. Some maps might be tricky (they start with a space, some others contain hex colors alongside the altitude, etc.) I recommend to be sure that all maps are perfectly parsed because the can be written differently. You can store it in a table of table structure, or in just one table with the 0 argument containing the number of lines and columns, solution that I chose, but it might be a bit slower than the first one. 

- Then lines must be drawn, and there comes the bresenham's alogrithm. It's well explained on Wikipedia, but it need to be the fastest possible in order to have the most fluid program. It can be reducted to 4 functions, and even 2 if well optimized. Then the program must be tested to be sure it works for every type of lines that you can have (there are 8 types, but check also verticals and horizontal lines).  

- Once the map can be drawn, it needs to be resized, placed in the middle, and some pixels must not be drawn because there are outside of the image. A good thing is to place this in the my_mlx_pixel_put function. 

- And finally, hooks can be implemented (bonuses) such as rotations, translations, zoom (be careful to the zoom max), colors gradient, etc. 

And here some links that helped me a lot :

Medium : https://harm-smits.github.io/42docs/libs/minilibx/hooks.html 

3D rendering : https://www.kmjn.org/notes/3d_rendering_intro.html 

Download the good MLX : https://github.com/42Paris/minilibx-linux/blob/master/mlx.h 

Bresenham: https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham#:~:text=L'algorithme%20de%20trac%C3%A9%20de,attach%C3%A9%20%C3%A0%20une%20console%20texte. 

Pixel drawing : https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx 

Pixel drawing : https://github.com/lavrenovamaria/42-fract-ol 

Hex char to int : https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int 
