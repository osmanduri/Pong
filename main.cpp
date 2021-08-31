#include "main.h"
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *boule = NULL;
    SDL_Surface *rectangle;
    SDL_Surface *rectangle1;

    SDL_Rect positionBoule;
    SDL_Rect positionRectangle;
    SDL_Rect positionRectangle1;
    SDL_Event event;

    int continuer = 1,tempActuel,tempPrecedent=0,i=1,y=1;
    bool vers_droite =true;
    bool vers_gauche =false;
    bool vers_haut = true;
    bool vers_bas = false;
    bool collision_boule_rectangle = false;
    bool collision_boule_rectangle1 = false;
    SDL_Init(SDL_INIT_VIDEO);


    ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    boule = SDL_LoadBMP("boule1.bmp");
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 200, 32, 0, 0, 0, 0);
    rectangle1 = SDL_CreateRGBSurface(SDL_HWSURFACE,30,200,32,0,0,0,0);
    SDL_SetColorKey(boule, SDL_SRCCOLORKEY, SDL_MapRGB(boule->format, 255, 255, 255));

    positionBoule.x = ecran->w / 2 - boule->w / 2;
    positionBoule.y = ecran->h / 2 - boule->h / 2;
    positionRectangle.x = 0;
    positionRectangle.y = 0;
    positionRectangle1.x = (1000-30);
    positionRectangle1.y = 0;

    SDL_EnableKeyRepeat(10, 10);
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        positionRectangle.y-=y;
                        if(positionRectangle.y < 0)
                            positionRectangle.y = 0;
                        break;

                    case SDLK_DOWN:
                        positionRectangle.y+=y;
                        if(positionRectangle.y > 400)
                            positionRectangle.y = 400;
                        break;

                    case SDLK_e:
                        positionRectangle1.y-=y;
                        if(positionRectangle1.y < 0)
                            positionRectangle1.y = 0;
                        break;

                    case SDLK_d:
                        positionRectangle1.y+=y;
                        if(positionRectangle1.y > 400)
                            positionRectangle1.y = 400;
                        break;

                    case SDLK_p:
                        do{

                        }while(!SDLK_p);

                }

        }
        tempActuel = SDL_GetTicks();
        if(tempActuel - tempPrecedent > 0.01)
        {
            collision_boule_rectangle = collision_gauche(positionRectangle,positionBoule);
            collision_boule_rectangle1 = collision_droite(positionRectangle1,positionBoule);

            collision(i,collision_boule_rectangle1,collision_boule_rectangle,positionRectangle,positionBoule,vers_droite,vers_gauche,vers_haut,vers_bas);

            tempPrecedent = tempActuel;
        }
        else
        {
           SDL_Delay(0.01 - (tempActuel - tempPrecedent));
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_FillRect(rectangle,NULL, SDL_MapRGB(ecran->format,255,255,255));
        SDL_FillRect(rectangle1,NULL, SDL_MapRGB(ecran->format,255,255,255));

        SDL_BlitSurface(boule, NULL, ecran, &positionBoule);
        SDL_BlitSurface(rectangle,NULL,ecran,&positionRectangle);
        SDL_BlitSurface(rectangle1,NULL,ecran,&positionRectangle1);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(boule);
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(rectangle1);
    SDL_Quit();

    return EXIT_SUCCESS;
}


