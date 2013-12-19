#include <SDL.h>
#include "klasy.h"

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

void gowno::wgrywaj_gonwo(int stale , SDL_Surface* obrazek, SDL_Surface* oknoSurface, SDL_Window* window)
{
	ksztalt.y = stale;

	SDL_BlitSurface(obrazek, NULL, oknoSurface, &ksztalt);
	SDL_UpdateWindowSurface(window);
}

void gowno::licznik(int losowe,SDL_Surface* obrazek, SDL_Surface* oknoSurface, SDL_Window* window)
{
	ksztalt.y += 3;
	ksztalt.x = losowe;

	SDL_BlitSurface(obrazek, NULL, oknoSurface, &ksztalt);
	//SDL_UpdateWindowSurface(window);
}

//bool gowno::klikanie(SDL_Event wydarzenie) // nie udane gówno
//{
//	int mouse_x = 0;
//	int mouse_y = 0;
//
//	mouse_x = wydarzenie.button.x;
//	mouse_y = wydarzenie.button.y;
//	if (wydarzenie.type == SDL_MOUSEBUTTONDOWN)
//	{
//		if (ksztalt.x < mouse_x && (ksztalt.x + 60) > mouse_x && ksztalt.y < mouse_y && (ksztalt.y + 60) > mouse_y)
//		{
//			zycie--;
//		}
//
//		if (zycie == 0)
//		{
//			return true;
//			zycie = 3;
//		}
//	}
//
//	return false;
//}
