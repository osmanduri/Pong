#include "main.h"
bool collision_gauche(SDL_Rect& positionRectangle,SDL_Rect& positionBoule)
{
    bool collision_boule = false;
    if(positionBoule.y >= positionRectangle.y-0 && positionBoule.y <= (positionRectangle.y+200))
    {
       if(positionBoule.x <= (positionRectangle.x+30))
       {
           collision_boule = true;
       }
    }

        return collision_boule;
}
