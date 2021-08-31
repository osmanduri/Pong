#include "main.h"
void collision(int i,bool collision_boule_rectangle1,bool collision_boule_rectangle,SDL_Rect& positionRectangle,SDL_Rect& positionBoule,bool& vers_droite,bool& vers_gauche,bool& vers_haut,bool& vers_bas)
{
     if(vers_droite == true)
             {
                 positionBoule.x+=i;
                  if(collision_boule_rectangle1)
                  {
                      vers_droite = false;
                      vers_gauche = true;
                  }
             }
             if(vers_gauche == true)
             {

                 positionBoule.x-=i;
                 if(collision_boule_rectangle)
                 {
                     vers_droite = true;
                     vers_gauche = false;
                 }

             }
             if(vers_haut == true)
             {
                 positionBoule.y-=i;
                 if(positionBoule.y < 5)
                 {
                     vers_haut = false;
                     vers_bas = true;
                 }
             }
             if(vers_bas == true)
             {
                 positionBoule.y+=i;
                 if(positionBoule.y > 550)
                 {
                     vers_bas = false;
                     vers_haut = true;
                 }
             }

             if(positionBoule.x <= 0 || positionBoule.x >= 955)
             {
                    SDL_Delay(2000);
                    exit(0);
             }


}
