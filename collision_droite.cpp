#include "main.h"
bool collision_droite(SDL_Rect& positionRectangle1,SDL_Rect& positionBoule)
{
    bool collision_boule = false;
    if(positionBoule.y >= positionRectangle1.y-40 && positionBoule.y <= (positionRectangle1.y+200))
    {
       if(positionBoule.x >= (positionRectangle1.x-50))
       {
           collision_boule = true;
       }
    }

        return collision_boule;
}
