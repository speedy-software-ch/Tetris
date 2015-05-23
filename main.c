#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <windows.h>

/*
 PLEASE NOTE: the program will require SDL.dll which is located in
              dev-c++'s dll directory. You have to copy it to you
			  program's home directory or the path.
 */

/* The screen surface */
SDL_Surface *screen = NULL;
SDL_Surface *Background = NULL;
SDL_Surface *Square = NULL;
SDL_Surface *T = NULL;
SDL_Surface *T2 = NULL;

int v[100];
int location[100];
int i=0;
int x=0;
int counter_location=1;
int counter_v=1;
int vertical=1;
int horizontal=1;
int colissionH[100];
int form=0;
int count=0;
int check=0;

/* This function draws to the screen; replace this with your own code! */
void LoadBitmaps();

void LoadBitmaps()
{
     Background = SDL_LoadBMP("BG.tsb");
     Square = SDL_LoadBMP("Square.bmp");
     T = SDL_LoadBMP("T.bmp");
     T2 = SDL_LoadBMP ("T2.bmp");
 }
 
 void DrawIMG(SDL_Surface *img, int x, int y);
 
 void DrawIMG(SDL_Surface *img, int x, int y)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}

int main (int argc, char *argv[])
{
location[1]=71;
v[1]=266;

    char *msg;
    int done;

    /* Initialize SDL */
    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        sprintf (msg, "Couldn't initialize SDL: %s\n", SDL_GetError ());
        MessageBox (0, msg, "Error", MB_ICONHAND); 
        free (msg);
        exit (1);
    }
    atexit (SDL_Quit);

    /* Set 800x600 32-bits video mode */
    screen = SDL_SetVideoMode (800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    if (screen == NULL)
    {
        sprintf (msg, "Couldn't set 800x600x32 video mode: %s\n",
          SDL_GetError ());
        MessageBox (0, msg, "Error", MB_ICONHAND); 
        free (msg);
        exit (2);
    }
    SDL_WM_SetCaption ("Tetris Game", NULL);
        LoadBitmaps();
    done = 0;
    while (!done)
    {
        SDL_Event event;

        /* Check for events */
        while (SDL_PollEvent (&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                 if ( event.key.keysym.sym == SDLK_ESCAPE ) { done = 1; }
                 if ( event.key.keysym.sym == SDLK_RIGHT ) { if(v[counter_v]<500&&location[counter_location]<415) v[counter_v] = v[counter_v] + 44; }
                 if ( event.key.keysym.sym == SDLK_LEFT ) { if(v[counter_v]>226&&location[counter_location]<415) v [counter_v]= v[counter_v] - 44;  }
                 if ( event.key.keysym.sym == SDLK_DOWN ) {
                      check=0;
                      while(colissionH[check]!=colissionH[count]&&check<100)
                      {
                      check++;
                      }
                      if(check==99)
                      {
                       if(location[counter_location]<415) location[counter_location] = location[counter_location] + 44;x++; colissionH[count]++; }}
                       else
                       {
                           count++;
                           }                 
                break;                    
            case SDL_QUIT:
                done = 1;
                break;
            default:
                break;
            }
        }
        DrawIMG(Background,0,0);
            DrawIMG(Square,225,70);
            if(counter_location>=1)
            {            
                                  SDL_SetColorKey(T, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(T->format, 0, 0, 0));
            DrawIMG(T,v[1],location[1]);
            }
            if(x==10)
            {
                     counter_location++;
                     counter_v++;
                     i=0;
                     x=0;
                    location[counter_location]=69;
                    v[counter_v]=226;
                    }
                    if(counter_location>1)
                    {
                    SDL_SetColorKey(T2, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(T2->format, 0, 0, 0));
            DrawIMG(T2,v[2],location[2]);
            }
    SDL_Flip(screen);
    if(location[counter_location]<415)
    {
                 if(location[counter_location]-44==371)
                 {
                                     }
                                     if(location[counter_location]-44==415)
                                     {

                                                         }
                                                         
                    if(i<15)
                    {
                            i++;
                            }
                            else
                            {
                                location[counter_location]=location[counter_location] + 44;
                                x++;
                                i=0;
                                colissionH[count]++;
                                }
        }
    }
    return 0;
}
