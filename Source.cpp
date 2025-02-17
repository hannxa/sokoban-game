#include <iostream>
#include <cstdlib> // tam jest funkcja w ktorej znajduje sie czysczenie ekranu
#include <fstream>

using namespace std;

// symbole na planszy
const char gracz = 2; //  ☻
const char sciana = 219; // caly zamalowany prostokacik
const char skrzynia = 176; //  ░
const char skrzyniaNaMiejscuDocelowym = 178; // bardziej zamalowana skrzynia
const char miejsceDocelowe = 3;  // ♥
const char graczNaMiejscuDocelowym = 1; // inna emotka twarzy
const char puste = ' ';

// plansza max rozmiar
const int maxRozmiarPlanszyX = 100;
const int maxRozmiarPlanszyY = 100;


void wypiszPlansze(char plansza[maxRozmiarPlanszyX][maxRozmiarPlanszyY], int xPrzesuniecie, int yPrzesuniecie, int xEkran, int yEkran)
{
	for (int y = yPrzesuniecie; y < yPrzesuniecie + yEkran; y++) {
		for (int x = xPrzesuniecie; x < xPrzesuniecie + xEkran; x++) {
			cout << plansza[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

void wypiszInformacjeOAutorze() {
	cout << "SOKOBAN" << endl << "Autor: Hanna Baranowska Index: 193531 " << endl;
}


void wypiszInformacjeOPoruszaniu() {
	cout << "Poruszanie: w, s, a, d" << endl;
	cout << "Menu: q" << endl;
	cout << "Poruszanie kamera: i, m, j, k" << endl;
	cout << "Twoj ruch: ";
}

void uzupelnijMiejsceKtoreGraczOpuszcza(char plansza[maxRozmiarPlanszyX][maxRozmiarPlanszyY], int yGracza, int xGracza) {
	// miejsce ktore gracz opuszcza
	if (plansza[yGracza][xGracza] == graczNaMiejscuDocelowym) {
		plansza[yGracza][xGracza] = miejsceDocelowe;
	}
	else {
		plansza[yGracza][xGracza] = puste;
	}

}

int sprawdzIleZostaloSkrzyn(char plansza[maxRozmiarPlanszyX][maxRozmiarPlanszyY], int rozmiarX, int rozmiarY)
{
	int ileSkrzynZostalo = 0;
	for (int y = 0; y < rozmiarY; y++) {
		for (int x = 0; x < rozmiarX; x++) {
			if (plansza[y][x] == skrzynia) {
				ileSkrzynZostalo++;
			}
		}
	}

	return ileSkrzynZostalo;
}

void ustawPlansze1(char plansza[maxRozmiarPlanszyY][maxRozmiarPlanszyX], int& xGracza, int& yGracza, int& rozmiarY, int& rozmiarX, int& liczbaRuchow) {

	const int plansza1RozmiarY = 9;
	const int plansza1RozmiarX = 8;

	xGracza = 2;
	yGracza = 2;
	rozmiarY = plansza1RozmiarY;
	rozmiarX = plansza1RozmiarX;
	liczbaRuchow = 40;

	// szablon planszy1
	char plansza1[plansza1RozmiarY][plansza1RozmiarX] = {
			{puste, puste, sciana, sciana, sciana, sciana, sciana, puste},
			{sciana, sciana, sciana, puste, puste, puste, sciana, puste},
			{sciana, miejsceDocelowe, gracz, skrzynia, puste, puste, sciana},
			{sciana, sciana, sciana, puste, skrzynia, miejsceDocelowe, sciana, puste},
			{sciana, miejsceDocelowe, sciana, sciana, skrzynia, puste, sciana, puste},
			{sciana, puste, sciana, puste, miejsceDocelowe, puste, sciana, sciana},
			{sciana, skrzynia, puste, skrzyniaNaMiejscuDocelowym, skrzynia, skrzynia, miejsceDocelowe, sciana},
			{sciana, puste, puste, puste, miejsceDocelowe, puste, puste, sciana},
			{sciana, sciana, sciana, sciana, sciana, sciana, sciana, sciana}
	};

	// ustawienie planszy 1
	for (int y = 0; y < rozmiarY; y++) {
		for (int x = 0; x < rozmiarX; x++) {
			plansza[y][x] = plansza1[y][x];
		}
	}
}

void ustawPlansze2(char plansza[maxRozmiarPlanszyY][maxRozmiarPlanszyX], int& xGracza, int& yGracza, int& rozmiarY, int& rozmiarX, int& liczbaRuchow) {
	const int plansza2RozmiarY = 30;
	const int plansza2RozmiarX = 85;

	xGracza = 2;
	yGracza = 2;
	rozmiarY = plansza2RozmiarY;
	rozmiarX = plansza2RozmiarX;
	liczbaRuchow = 200;

	char plansza2[plansza2RozmiarY][plansza2RozmiarX];

	for (int y = 0; y < plansza2RozmiarY; y++) {
		for (int x = 0; x < plansza2RozmiarX; x++) {
			plansza2[y][x] = puste;
		}
	}

	for (int y = 0; y < rozmiarY; y++) {
		plansza2[y][0] = sciana;
	}

	for (int y = 0; y < rozmiarY; y++) {
		plansza2[y][rozmiarX - 1] = sciana;
	}

	for (int x = 0; x < rozmiarX; x++) {
		plansza2[0][x] = sciana;
	}

	for (int x = 0; x < rozmiarX; x++) {
		plansza2[rozmiarY - 1][x] = sciana;
	}


	plansza2[yGracza][xGracza] = gracz;
	plansza2[4][3] = skrzynia;
	plansza2[10][15] = skrzynia;
	plansza2[15][40] = skrzynia;
	plansza2[5][30] = skrzynia;

	plansza2[5][8] = miejsceDocelowe;
	plansza2[15][8] = miejsceDocelowe;
	plansza2[3][60] = miejsceDocelowe;
	plansza2[5][31] = miejsceDocelowe;

	plansza2[4][60] = sciana;
	plansza2[4][61] = sciana;
	plansza2[4][62] = sciana;
	plansza2[25][41] = sciana;
	plansza2[26][40] = sciana;
	plansza2[27][40] = sciana;

	plansza2[12][40] = sciana;
	plansza2[13][40] = sciana;
	plansza2[14][40] = sciana;

	// ustawienie planszy 2
	// kopiowanie elementow z planszy tymczasowej
	// z danymi do oryginalnej planszy na ktorej gramy

	for (int y = 0; y < rozmiarY; y++) {
		for (int x = 0; x < rozmiarX; x++) {
			plansza[y][x] = plansza2[y][x];
		}
	}
}

void ustawPlansze3(char plansza[maxRozmiarPlanszyY][maxRozmiarPlanszyX], int& xGracza, int& yGracza, int& rozmiarY, int& rozmiarX, int& liczbaRuchow) {

	const int plansza3RozmiarY = 9;
	const int plansza3RozmiarX = 9;

	xGracza = 4;
	yGracza = 4;
	rozmiarY = plansza3RozmiarY;
	rozmiarX = plansza3RozmiarX;
	liczbaRuchow = 13;

	// szablon planszy1
	char plansza3[plansza3RozmiarY][plansza3RozmiarX] = {

			{puste, puste, sciana, sciana, sciana, puste, puste, puste, puste},
			{puste, puste, sciana, miejsceDocelowe, sciana, puste, puste, puste, puste},
			{puste, puste, sciana, puste, sciana, sciana, sciana, sciana, puste},
			{sciana, sciana, sciana, skrzynia, puste, skrzynia,miejsceDocelowe, sciana, puste},
			{sciana, miejsceDocelowe, puste, skrzynia, gracz, sciana, sciana, sciana, puste},
			{sciana, sciana, sciana, sciana, skrzynia, sciana, puste, puste, puste},
			{puste, puste, puste, sciana, miejsceDocelowe, sciana, puste, puste, puste},
			{puste, puste, puste, sciana, sciana, sciana, puste, puste, puste},
			{puste, puste, puste, puste, puste, puste, puste, puste, puste},


	};

	// ustawienie planszy 1
	for (int y = 0; y < rozmiarY; y++) {
		for (int x = 0; x < rozmiarX; x++) {
			plansza[y][x] = plansza3[y][x];
		}
	}
}


// czytamy ile jest dostepnych planszy
int sprawdzIleJestDostepnychPlanszy() {
	int liczbaDostepnychPlanszy = 1;
	fstream plik;
	plik.open("dane.txt", ios::in);
	if (plik.good())
	{
		plik >> liczbaDostepnychPlanszy;
		plik.close();
	}
	else {
		fstream plik2;
		plik2.open("dane.txt", ios::out);
		plik2 << 1;
		plik2.close();
	}

	return liczbaDostepnychPlanszy;
}

// zapisuje do pliku ile jest dostepnych planszy
void zwiekszLiczbeDostepnychPlanszy(int numerPlanszyKtoraTerazWygralismy) {
	fstream plik;
	plik.open("dane.txt", ios::in);

	// czytam z pliku ile jest dostepnych planszy
	int liczbaDostepnychPlanszy = 1;
	if (plik.good()) {
		plik >> liczbaDostepnychPlanszy;
		plik.close();
	}
	// scenariusz gracz ma 3 dostepnych
	// gracz wybiera plansze 1
	// gdy gracz wygra plansze 1 -> probujemy zaaktualizowac liczbe dostepnych planszy

	// 1. <-- w pliku 1
	// wygral plansze 1. 
	// numerPlanszyKtoraTerazWygralismy == 1
	// liczbaDostepnychPlanszy == 1

	if (numerPlanszyKtoraTerazWygralismy >= liczbaDostepnychPlanszy) {
		liczbaDostepnychPlanszy++;
		fstream plik;
		plik.open("dane.txt", ios::out);
		if (plik.good()) {
			plik << liczbaDostepnychPlanszy;
			plik.close();
		}
	}
}


int menu(int& numerPlanszy) {

	system("cls"); // czyszczenie ekranu
	cout << "MENU" << endl;
	cout << "1. Rozpoczecie rozgrywki od nowa" << endl;
	cout << "2. Wyjscie z gry" << endl;
	cout << "3. Wybor planszy" << endl;

	int wybor = 0;

	cout << "Wybor:";
	cin >> wybor;

	while (wybor != 1 && wybor != 2 && wybor != 3) {
		cout << "Wybrales zla opcje, wybor:";
		cin >> wybor;
	}
	
	system("cls"); // czyszczenie ekranu

	int liczbaDostepnychPlanszy = sprawdzIleJestDostepnychPlanszy();

	if (wybor == 3) {
		cout << "Dostepne plansze:" << endl;

		cout << "1: plansza 1" << endl;
		if (liczbaDostepnychPlanszy > 1) {
			cout << "2: plansza 2" << endl;
		}
		if (liczbaDostepnychPlanszy > 2) {
			cout << "3. plansza 3" << endl;
		}
		cout << "Twoj wybor:";
		int wyborPlanszy = 1;
		cin >> wyborPlanszy;
		// wybrana plansza przez gracza
		numerPlanszy = wyborPlanszy;
	}

	return wybor;
}


int main()
{

	int numerPlanszy = 1;

	while (true)	// petla jednej gry
	{
		char plansza[maxRozmiarPlanszyY][maxRozmiarPlanszyX];

		int xGracza = 0;
		int yGracza = 0;
		int rozmiarY = 0;
		int rozmiarX = 0;
		int liczbaRuchow = 0;


		if (numerPlanszy == 1) {
			ustawPlansze1(plansza, xGracza, yGracza, rozmiarY, rozmiarX, liczbaRuchow);
		}
		else if (numerPlanszy == 2) {
			ustawPlansze2(plansza, xGracza, yGracza, rozmiarY, rozmiarX, liczbaRuchow);
		}
		else if (numerPlanszy == 3) {
			ustawPlansze3(plansza, xGracza, yGracza, rozmiarY, rozmiarX, liczbaRuchow);
		}
		else if (numerPlanszy == 4) {
			cout << "Gratulacje! Przeszedles wszystkie plansze! ";
			return 0;
		}


		int xPrzesuniecie = 0;
		int yPrzesuniecie = 0;
		int xEkran = 80;
		int yEkran = 25;

		// jesli plansza jest mniejsza niz ekran
		// to ustaw ekran na wielkosc planszy
		if (xEkran > rozmiarX) {
			xEkran = rozmiarX;
		}
		if (yEkran > rozmiarY) {
			yEkran = rozmiarY;
		}

		int liczbaRuchowWykonanych = 0;
		int liczbaPozostalychRuchow = liczbaRuchow;
		
		while (true) {	// petla w jednej tury w grze
			system("cls"); // czyszczenie ekranu
			wypiszInformacjeOAutorze();
			wypiszPlansze(plansza, xPrzesuniecie, yPrzesuniecie, xEkran, yEkran);

			cout << "Liczba wykonanych ruchow:" << liczbaRuchowWykonanych << endl;
			cout << "Liczba pozostalych ruchow:" << liczbaPozostalychRuchow << endl;

			// warunek wygrania
			// oblicz ile zostalo skrzyn
			int zostaloSkrzyn = sprawdzIleZostaloSkrzyn(plansza, rozmiarX, rozmiarY);
			if (zostaloSkrzyn == 0) {
				if (numerPlanszy < 3) {
					cout << "Wygrana!" << endl;
					cout << "Wcisnij enter, aby rozpoczac kolejna plansze" << endl;
					char rozpocznijOdNowa;
					cin >> rozpocznijOdNowa;
					zwiekszLiczbeDostepnychPlanszy(numerPlanszy);
				}
				
				// jesli gracz wygral, przechodzimy do kolejnej planszy
				numerPlanszy++;
				break;	// wyjscie z petli
			}

			// warunek przegrania
			if (liczbaPozostalychRuchow == 0) {
				cout << "Przegrana!" << endl;
				cout << "Wcisnij enter, aby rozpoczac plansze od nowa" << endl;
				char rozpocznijOdNowa;
				cin >> rozpocznijOdNowa;
				break;	// wyjscie z petli
			}

			// pobierz ruch
			wypiszInformacjeOPoruszaniu();

			char ruch;
			cin >> ruch;

			// wyswietl menu
			if (ruch == 'q' || ruch == 'Q') {
				int wyborGracza = menu(numerPlanszy);

				if (wyborGracza == 2) {
					return 0;
				}
				else if (wyborGracza == 1) {
					break;	// rozpocznij gre od nowa na tej samej planszy
				}
				else if (wyborGracza == 3) {
					break;	// rozpocznij gre od nowa na wybranej planszy
				}
			}


			int xNoweGracza = xGracza;
			int yNoweGracza = yGracza;

			int xPozycjaOJedenDalejNizNowa = xGracza;
			int yPozycjaOJedenDalejNizNowa = yGracza;

			// poruszanie po planszy
			if (ruch == 'w' || ruch == 'W') {
				yNoweGracza--;
				yPozycjaOJedenDalejNizNowa = yPozycjaOJedenDalejNizNowa - 2;
			}
			else if (ruch == 's' || ruch == 'S') {
				yNoweGracza++;
				yPozycjaOJedenDalejNizNowa = yPozycjaOJedenDalejNizNowa + 2;
			}
			else if (ruch == 'a' || ruch == 'A') {
				xNoweGracza--;
				xPozycjaOJedenDalejNizNowa = xPozycjaOJedenDalejNizNowa - 2;
			}
			else if (ruch == 'd' || ruch == 'D') {
				xNoweGracza++;
				xPozycjaOJedenDalejNizNowa = xPozycjaOJedenDalejNizNowa + 2;
			}

			// poruszanie kamera
			else if (ruch == 'j' || ruch == 'J') {
				xPrzesuniecie--;
				if (xPrzesuniecie < 0) {
					xPrzesuniecie = 0;
				}
				continue;// przechodzimy do poczatku petli, zeby nie sprawdzac poruszania sie graczem
			}
			else if (ruch == 'k' || ruch == 'K') {
				if (xPrzesuniecie + xEkran < rozmiarX) {
					xPrzesuniecie++;
				}
				continue;
			}
			else if (ruch == 'i' || ruch == 'I') {
				yPrzesuniecie--;
				if (yPrzesuniecie < 0) {
					yPrzesuniecie = 0;
				}
				continue;
			}
			else if (ruch == 'm' || ruch == 'M') {
				if (yPrzesuniecie + yEkran < rozmiarY) {
					yPrzesuniecie++;
				}
				continue;
			}

			// zwieksz liczbe wykonanych ruchow
			liczbaRuchowWykonanych++;
			liczbaPozostalychRuchow--;

			// sprawdzamy czy mozemy sie tam ruszyc
			if (plansza[yNoweGracza][xNoweGracza] == sciana) {
				// weszlismy w sciane nic sie nie dzieje
			}
			else if ((plansza[yNoweGracza][xNoweGracza] == skrzynia) || (plansza[yNoweGracza][xNoweGracza] == skrzyniaNaMiejscuDocelowym)) {
				// popchac skrzynke 
				int x = xPozycjaOJedenDalejNizNowa;
				int y = yPozycjaOJedenDalejNizNowa;

				// sprawdzamy czy mozemy popchac skrzynke
				if (plansza[y][x] == puste || plansza[y][x] == miejsceDocelowe) {
					// mozemy popchac skrzynke
					// uzupelnij plansze

					if (plansza[y][x] == miejsceDocelowe) {
						plansza[y][x] = skrzyniaNaMiejscuDocelowym;
					}
					else {
						plansza[y][x] = skrzynia;
					}

					if (plansza[yNoweGracza][xNoweGracza] == skrzyniaNaMiejscuDocelowym) {
						plansza[yNoweGracza][xNoweGracza] = graczNaMiejscuDocelowym;
					}
					else {
						plansza[yNoweGracza][xNoweGracza] = gracz;
					}

					// miejsce ktore gracz opuszcza
					uzupelnijMiejsceKtoreGraczOpuszcza(plansza, yGracza, xGracza);

					yGracza = yNoweGracza;
					xGracza = xNoweGracza;

				}
				else {
					// nie mozemy popchac
				}
			}
			else { // zwykle poruszanie 

				// miejsce ktore opuscilismy
				uzupelnijMiejsceKtoreGraczOpuszcza(plansza, yGracza, xGracza);

				// nowe miejsce dla gracza
				if (plansza[yNoweGracza][xNoweGracza] == miejsceDocelowe) {
					plansza[yNoweGracza][xNoweGracza] = graczNaMiejscuDocelowym;
				}
				else {
					plansza[yNoweGracza][xNoweGracza] = gracz;
				}

				yGracza = yNoweGracza;
				xGracza = xNoweGracza;
			}
		} // koniec petli gry	
	}

	// wyjscie z gry
	return 0;
}