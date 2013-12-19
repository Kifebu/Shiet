#include <SDL.h>
#include <cstdlib>
#include "funkcje.h"
#include "klasy.h"

// Wczytuje na ekran obrazek z Surface
void wgraj_surface(int x, int y, SDL_Surface* surface, SDL_Surface* przeznaczenie, SDL_Window* okno)
{
	SDL_Rect polozenie;

	polozenie.x = x;
	polozenie.y = y;

	SDL_BlitSurface(surface, NULL, przeznaczenie, &polozenie);
	SDL_UpdateWindowSurface(okno);
}
//funkcja losujaca -> przedzial + poczatek 
int losowanie(int przedzial, int liczba_poczatek)
{
	int b = (rand() % przedzial) + liczba_poczatek;
	return  b;
}
