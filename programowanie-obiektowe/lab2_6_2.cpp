#include <iostream>

using namespace std;

class Kolejka{
	private:
		int n; //rozmiar 
		int *tab; //kolejka
		int ostatni;
		
	public:
		Kolejka(int n_konstruktor=10){//konstruktor
			n = n_konstruktor;
			tab = new int [n];
			ostatni = 0;
		}
		Kolejka(const Kolejka &n_kopiowane){//konstrktor kopiujacy
			n=n_kopiowane.n;
			tab = new int [n];
			ostatni = 0;
		}

	public:
		void usun_pierwszy();
		void dodaj_na_koniec();
		bool czy_pusta();
		void wyswietl();
};

void Kolejka::dodaj_na_koniec(){
	int x;
	if(n != ostatni){
		cout << "liczba: ";
		cin >> x;
		x = tab[ostatni];
		ostatni++;
	}
	else{
		cout << "max_dodawanie";
	}
}

void Kolejka::usun_pierwszy(){
	if(ostatni > 0){
		for(int i=1; i<ostatni; i++)
			tab[i-1] = tab[i];
	ostatni--;	
	}
	else{
		cout << "max_usuwanie" << endl;
	}	
}

bool Kolejka::czy_pusta(){
	if(ostatni>0){
		cout << "Kolejka nie jest pusta";
		return false;
	}
	else{
		return true;
	} 
}

void Kolejka::wyswietl(){
	cout << "Zawartosc kolejki: " << endl;
	//cout << " tu " << ostatni << " tu "; 
	for(int i=1; i<=ostatni; i++)
			cout << &tab[i]<< " ";
}
int main(){
	int x;
	Kolejka kolejka_1;
	
	kolejka_1.dodaj_na_koniec();
	kolejka_1.dodaj_na_koniec();
	kolejka_1.dodaj_na_koniec();
	//kolejka_1.dodaj_na_koniec();
	//kolejka_1.dodaj_na_koniec();
//	kolejka_1.dodaj_na_koniec();
	//kolejka_1.dodaj_na_koniec();
	kolejka_1.wyswietl();
	
	
	
	return 0;
}


/*void Kolejka::usun_pierwszy(){
	element *pom = pierwszy ;
	if (pierwszy == ostatni)
		pierwszy=ostatni=NULL;
	else
		pierw=pier
}*/
