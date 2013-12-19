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
SDL_Surface* kupap = NULL;

// ZJEBANE FUNKCJE

void loadmedia();
void loadmedia()
{
	kupap = SDL_LoadBMP("kupa.bmp");
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

	int y_przesuwania = -960, poprzedia = -960;
	int liczby[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool quit = false; // Flaga zamykająca główną pętle
	bool pierwszy_raz = false; // Flaga zamykająca wyświetlenie przycisków w manu
	bool quit_z_gry = false; // Flaga zamykająca pętlę z grą.

	przycisk zaczyjanacy_gre;
	przycisk konczacy_gre;

	SDL_Event wydarzenie;
	SDL_Event wydarzenie2;

	gowno kupa[10];

	init(); // Tworzy okno
	loadmedia(); // Wczytuje wszystkie obrazy

	while (!quit) // Główna Pętla
	{
		SDL_BlitSurface(tlo_menu_glownego, NULL, gScreenSurface, NULL);
		if (!pierwszy_raz) // Wgrywa przyciski z głównego menu na obraz
		{
			zaczyjanacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, wysokosc_ekranu / 2 - 250, start_gry, gScreenSurface, gWindow);
			konczacy_gre.wgraj_przycisk(szerokosc_ekranu / 2 - 250, wysokosc_ekranu/2, koniec_gry, gScreenSurface, gWindow);
			pierwszy_raz = true;
		}
		if (SDL_PollEvent(&wydarzenie)) // Sprawdzacy
		{
			if (zaczyjanacy_gre.wydarzenie(wydarzenie) == true) // GRA ZACZYNA SIĘ TUTAJ WOWOkdodkaofjesioafesagnveiznvjsznbjbjdsbnekbsbnjbnodsbns
			{
				while (!quit_z_gry)
				{
					y_przesuwania += 3;
					if(poprzedia < 1000 ) poprzedia += 3;
					if (poprzedia >= 1000) poprzedia = 1000;
					if (y_przesuwania == 0) y_przesuwania = -960;
					wgraj_surface(0, y_przesuwania, tlo_w_grze, gScreenSurface, gWindow);

					if (poprzedia > -960)
					{
						if (liczby[0] == 0) liczby[0] = losowanie(700, 100);

						kupa[0].licznik(liczby[0], kupap, gScreenSurface, gWindow);


						if (kupa[0].ksztalt.y > wysokosc_ekranu ){ liczby[0] = 0; kupa[0].ksztalt.y = -60; }
					}

					if (poprzedia > -864)
					{
						if (liczby[1] == 0) liczby[1] = losowanie(700, 100);

						kupa[1].licznik(liczby[1], kupap, gScreenSurface, gWindow);



						if (kupa[1].ksztalt.y > wysokosc_ekranu ) { liczby[1] = 0; kupa[1].ksztalt.y = -60; }
					}

					if (poprzedia > -786)
					{
						if (liczby[2] == 0) liczby[2] = losowanie(700, 100);

						kupa[2].licznik(liczby[2], kupap, gScreenSurface, gWindow);


						if (kupa[2].ksztalt.y > wysokosc_ekranu ) { liczby[2] = 0; kupa[2].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96*3)
					{
						if (liczby[3] == 0) liczby[3] = losowanie(700, 100);

						kupa[3].licznik(liczby[3], kupap, gScreenSurface, gWindow);

		

						if (kupa[3].ksztalt.y > wysokosc_ekranu ) { liczby[3] = 0; kupa[3].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 4)
					{
						if (liczby[4] == 0) liczby[4] = losowanie(700, 100);

						kupa[4].licznik(liczby[4], kupap, gScreenSurface, gWindow);

				

						if (kupa[4].ksztalt.y > wysokosc_ekranu ) { liczby[4] = 0; kupa[4].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 5)
					{
						if (liczby[5] == 0) liczby[5] = losowanie(700, 100);

						kupa[5].licznik(liczby[5], kupap, gScreenSurface, gWindow);

			

						if (kupa[5].ksztalt.y > wysokosc_ekranu ) { liczby[5] = 0; kupa[5].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 6)
					{
						if (liczby[6] == 0) liczby[6] = losowanie(700, 100);

						kupa[6].licznik(liczby[6], kupap, gScreenSurface, gWindow);

		

						if (kupa[6].ksztalt.y > wysokosc_ekranu ) { liczby[6] = 0; kupa[6].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 7)
					{
						if(liczby[7] == 0) liczby[7] = losowanie(700, 100);

						kupa[7].licznik(liczby[7], kupap, gScreenSurface, gWindow);

				

						if (kupa[7].ksztalt.y > wysokosc_ekranu ) { liczby[7] = 0; kupa[7].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 8)
					{
						if (liczby[8] == 0) liczby[8] = losowanie(700, 100);

						kupa[8].licznik(liczby[8], kupap, gScreenSurface, gWindow);

		

						if (kupa[8].ksztalt.y > wysokosc_ekranu ){ liczby[8] = 0; kupa[8].ksztalt.y = -60; }
					}

					if (poprzedia > -960 + 96 * 9)
					{
						if (liczby[9] == 0) liczby[9] = losowanie(700, 100);

						kupa[9].licznik(liczby[9], kupap, gScreenSurface, gWindow);


						if (kupa[9].ksztalt.y > wysokosc_ekranu){ liczby[9] = 0; kupa[9].ksztalt.y = -60 ; }
					}



					SDL_UpdateWindowSurface(gWindow);
					
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
