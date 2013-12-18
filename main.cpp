#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <iostream>
#include <string>
#include "klasy.h"
#include "funkcje.h"

int szerokosc_ekranu = 1920;
int wysokosc_ekranu = 1080;

// Zmienne globalne ogólne
SDL_Window* gWindow = NULL;

// Globalne Surface
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* tlo_menu_glownego = NULL;
SDL_Surface* start_gry = NULL;
SDL_Surface* koniec_gry = NULL;

// ZJEBANE FUNKCJE

void loadmedia();
void loadmedia()
{
	start_gry = SDL_LoadBMP( "start_gry.bmp" );
	koniec_gry = SDL_LoadBMP( "koniec.bmp" );
	tlo_menu_glownego = SDL_LoadBMP( "tlo_menu_glownego.bmp" );
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
	bool quit = false; // Flaga zamykająca główną pętle
	bool pierwszy_raz = false; // Flaga zamykająca wyświetlenie przycisków w manu

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
			zaczyjanacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, wysokosc_ekranu / 4, start_gry, gScreenSurface, gWindow);
			konczacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, wysokosc_ekranu / 2, koniec_gry, gScreenSurface, gWindow);
			pierwszy_raz = true;
		}
		if (SDL_PollEvent(&wydarzenie)) // Sprawdzacy
		{
			zaczyjanacy_gre.wydarzenie;
		}

	}

	return 0;
	//asdasffrgadfgaerggrgra
}
