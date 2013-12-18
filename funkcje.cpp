#include <SDL.h>
#include "funkcje.h"
#include "klasy.h"

// Wczytuje na ekran obrazek z Surface
void wgraj_surface(int x, int y, SDL_Surface* surface, SDL_Surface* przeznaczenie)
{
	SDL_Rect polozenie;

	polozenie.x = x;
	polozenie.y = y;

	SDL_BlitSurface(surface, NULL, przeznaczenie, &polozenie);
}
