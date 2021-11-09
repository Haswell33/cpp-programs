/*Karol Siedlaczek I8X1N1 
ZAD 3.2
Napisz klas� Atrakcja posiadaj�c� chronione pola cena, nazwa i opis oraz publiczne metody zwracaj�ce warto�ci tych p�l. 
Napisz klasy Kolejka, Zamek, Film (pochodne klasy Atrakcja). Klasy pochodne powinny posiada� nast�puj�ce pola prywatne Kolejka pola godz_odjazdu i godz_przyjazdu,
Zamek pole czas_zwiedzania, Film pola czas_trwania i tytul. Napisz w klasach pochodnych metody zwracaj�ce warto�ci tych ww. nowych p�l. Zde?niuj w klasach konstruktory.

r�wniez zaliczone*/
#include <iostream>

using namespace std;

class Atrakcja{
	protected:
		string nazwa, 
			   opis;
		double cena;
		
	public:
		Atrakcja(string k_nazwa = "", string k_opis = "", double k_cena = 0){
			nazwa = k_nazwa;
			opis = k_opis;
			cena = k_cena;
		}	
		
		void getter();
};

class Kolejka:public Atrakcja{
	private:
		double godz_odjazdu, 
			   godz_przyjazdu;
		
	public:
		Kolejka(double k_godz_odjazdu = 0, double k_godz_przyjazdu = 0, string k_nazwa = "", string k_opis = "", double k_cena = 0)
		:Atrakcja(k_nazwa, k_opis, k_cena), godz_odjazdu(k_godz_odjazdu), godz_przyjazdu(k_godz_przyjazdu){}
		
		void getter();
		void wyswietl();
};

class Zamek:public Atrakcja{
	private:
		double czas_zwiedzania;
	
	public:
		Zamek();
		
		void getter();
};

class Film:public Atrakcja{
	private:
		string tytul;
		double czas_trwania;
	
	public:
		Film();
		
		void getter();
};


void Kolejka::wyswietl(){
	cout << "Atrakcja o nazwie " << Atrakcja::nazwa << " ktora kosztuje " << Atrakcja::cena << "zl odjezdza o " << godz_odjazdu << " i konczy o " << godz_przyjazdu;
}

void Atrakcja::getter(){
	cout << nazwa << endl << opis << endl << cena;
}

void Kolejka::getter(){
	cout << godz_odjazdu << endl << godz_przyjazdu;
}

void Zamek::getter(){
	cout << czas_zwiedzania;
}

void Film::getter(){
	cout << tytul << endl << czas_trwania;
}

int main(){
	Kolejka kolejka_1(15, 30, "Karuzela", "krecenie", 150);
	kolejka_1.wyswietl();
	
	return 0;
}
