#ifndef klasy_h
#define klasy_h

// Postać
class postac
{
private:
	SDL_Rect ksztalt;

	int x = 0;
	int y = 0;

public:
	void zderzenie(); // Poruszanie się postacią

};

// Przycisk

class przycisk
{
private:
	SDL_Rect ksztalt;

	int x = 0;
	int y = 0;
public:

	void wgraj_przycisk(int , int , SDL_Surface* , SDL_Surface* , SDL_Window*);

	bool wydarzenie(SDL_Event);
};

// Gówno

class gowno
{
private:
	int x = 0;
	int y = 0;

	int zycie = 3;

public:

	SDL_Rect ksztalt;

	void wgrywaj_gonwo(int, SDL_Surface*, SDL_Surface*, SDL_Window*);

	void licznik(int,SDL_Surface*, SDL_Surface*, SDL_Window*);

	void zderzenie();

	//bool klikanie(SDL_Event);
};


#endif
