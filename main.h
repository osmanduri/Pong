#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif



#include <SDL/SDL.h>

void collision(int i,bool collision_boule_rectangle1,bool collision_boule_rectangle,SDL_Rect& positionRectangle,SDL_Rect& positionBoule,bool& vers_droite,bool& vers_gauche,bool& vers_haut,bool& vers_bas);
bool collision_gauche(SDL_Rect& positionRectangle,SDL_Rect& positionBoule);
bool collision_droite(SDL_Rect& positionRectangle1,SDL_Rect& positionBoule);


