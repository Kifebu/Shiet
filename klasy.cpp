#include <SDL.h>
#include "klasy.h"

void postac::poruszanie()
{


}

void przycisk::wgraj_przycisk(int x, int y, SDL_Surface* surface, SDL_Surface* przeznaczenie, SDL_Window* okno)
{
	ksztalt.x = x;
	ksztalt.y = y;

	SDL_BlitSurface(surface, NULL, przeznaczenie, &ksztalt);
	SDL_UpdateWindowSurface(okno);
}

bool przycisk::wydarzenie(SDL_Event wydarzenie)
{
	int mouse_x = 0;
	int mouse_y = 0;

	mouse_x = wydarzenie.button.x;
	mouse_y = wydarzenie.button.y;
	if (wydarzenie.type == SDL_MOUSEBUTTONUP)
	{
		if (ksztalt.x < mouse_x && (ksztalt.x + 500) > mouse_x && ksztalt.y < mouse_y && (ksztalt.y + 200) > mouse_y)
		{
			return true;
		}
		else{
			return false;
		}
	}
}
