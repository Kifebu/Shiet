#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "klasy.h"
#include "funkcje.h"

int szerokosc_ekranu = 960;
int wysokosc_ekranu = 960;

// Zmienne globalne ogólne
SDL_Window* gWindow = NULL;

// Globalne Surface
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* tlo_menu_glownego = NULL;
SDL_Surface* start_gry = NULL;
SDL_Surface* koniec_gry = NULL;
SDL_Surface* tlo_w_grze = NULL;
SDL_Surface* kupa = NULL;

// ZJEBANE FUNKCJE

void loadmedia();
void loadmedia()
{
	kupa = SDL_LoadBMP("kupa.bmp");
	start_gry = SDL_LoadBMP("start_gry.bmp");
	koniec_gry = SDL_LoadBMP("koniec.bmp");
	tlo_menu_glownego = SDL_LoadBMP("tlo_menu_glownego.bmp");
	tlo_w_grze = SDL_LoadBMP("tlo_w_grze.bmp");
}

void init();
void init()
{
	gWindow = SDL_CreateWindow("Shit Happens", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, szerokosc_ekranu, wysokosc_ekranu, SDL_WINDOW_SHOWN);

	gScreenSurface = SDL_GetWindowSurface(gWindow);
}

// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN 

int main(int argc, char** argv)
{
	//srand(time(NULL));

	int y_przesuwania = -960;

	bool quit = false; // Flaga zamykająca główną pętle
	bool pierwszy_raz = false; // Flaga zamykająca wyświetlenie przycisków w manu
	bool quit_z_gry = false; // Flaga zamykająca pętlę z grą.

	przycisk zaczyjanacy_gre;
	przycisk konczacy_gre;

	SDL_Event wydarzenie;

	init(); // Tworzy okno
	loadmedia(); // Wczytuje wszystkie obrazy

	while (!quit) // Główna Pętla
	{
		SDL_BlitSurface(tlo_menu_glownego, NULL, gScreenSurface, NULL);
		if (!pierwszy_raz) // Wgrywa przyciski z głównego menu na obraz
		{
			zaczyjanacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, 200, start_gry, gScreenSurface, gWindow);
			konczacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, 500, koniec_gry, gScreenSurface, gWindow);
			pierwszy_raz = true;
		}
		if (SDL_PollEvent(&wydarzenie)) // Sprawdzacy
		{
			if (zaczyjanacy_gre.wydarzenie(wydarzenie) == true) // GRA ZACZYNA SIĘ TUTAJ WOWOkdodkaofjesioafesagnveiznvjsznbjbjdsbnekbsbnjbnodsbns
			{
				while (!quit_z_gry)
				{
					y_przesuwania += 1;
					if (y_przesuwania == 0) y_przesuwania = -960;
					wgraj_surface(0, y_przesuwania, tlo_w_grze, gScreenSurface, gWindow);
					wgraj_surface(losowanie(660, 100), y_przesuwania,kupa, gScreenSurface, gWindow);







				}
			}
			if (konczacy_gre.wydarzenie(wydarzenie) == true)
			{
				quit = true;
			}
		}

	}

	return 0;
}
