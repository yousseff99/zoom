#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
int main()
{
int quit=1;
SDL_Surface *ecran=NULL ,*paysage=NULL,*image=NULL  ;
SDL_Event event;
double zoom=1;
double angle=0;
SDL_Init(SDL_INIT_EVERYTHING);
ecran=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE|SDL_RESIZABLE);
image=IMG_Load("back.png");
while (quit)
{
SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));//bch taswira tt3awidich sansback
paysage=rotozoomSurface (image, angle, zoom, 0);
SDL_BlitSurface(paysage,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_FreeSurface (paysage);
SDL_PollEvent (&event);
switch(event.type)
{
	case SDL_QUIT:
	quit=0;//quiti 0
	break;
case SDL_KEYDOWN:
{
switch(event.key.keysym.sym)
{
case SDLK_w:
angle=0;
break;
case SDLK_r:
angle+=15;
break;
/*case SDLK_t:
angle-=90;
break;*/
case SDLK_a:
{
zoom+=0.3;	
}
break;
case SDLK_z:
{
zoom-=0.3;	
}
break;
}
}
break;
}
}
SDL_Quit();
return (0);
}
