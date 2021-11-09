/*Karol Siedlaczek I8X1N1 
ZAD 2.9
Utworz klase Dog zaprzyjaŸnion¹ z klas¹ Osoba. Klasa Dog powinna zaiweraæ pola nazwa, czy_jadl oraz konstruktor i getter do pobrania nazwy zwierzêcia. 
Klasa Osoba powinna zawieraæ m.in informcje o w³Aœcicielu i jego psach (Dog) - maX 5 psów oraz konstruktor i metody do dopisywania i usuwania psa, 
karmienia wybranego psa i wszystkich g³odnych oraz inne gettery. Program powininen wykorzystac zaprzyjaŸnienie klas

To Pan mi zaliczyl na zajeciach, ale moze nie zostalo to wpisane, dlatego profilaktycznie wysylam*/
#include <iostream>

using namespace std;

class Dog{
	friend class Osoba;
	string nazwa;
	bool czy_jadl;
		
	public:
		Dog(){
			czy_jadl=false;		
		};
	string set_imie();
	void get_imie();	
};

class Osoba{
	string imie, nazwisko;
	Dog psy[5];
	int n;
		
	public:	
		Osoba(){
			n=0;
		};
	
	void dodaj_psa();
	void usun_psa();
	void nakarm_psa();	
};

string Dog::set_imie(){
	return nazwa;
}

void Dog::get_imie(){
	cout << "Imie psa: " << nazwa;
}
void Osoba::usun_psa(){
	for(int i=0; i<n; i++)
		psy[i] = psy[i-1];	
}

void Osoba::nakarm_psa(){
	int x=0;
	cout << endl << "Ktory pies do nakarmienia?";
	cin >> x;
	if(psy[x].czy_jadl == false){
		psy[x].czy_jadl = true;		
	} 
	else cout << endl << "pies najedzony" << endl;
}

void Osoba::dodaj_psa(){
	if(n<5){
		cout << "nazwa nowego psa: ";
		cin >> psy[n].nazwa;
		psy[n].czy_jadl=false;
		n++;
	}else cout << endl << "za duzo psow";
	
}

int main(){
	Osoba osoba1;
	
	osoba1.dodaj_psa();
	osoba1.dodaj_psa();
	osoba1.dodaj_psa();
	osoba1.dodaj_psa();
	osoba1.dodaj_psa();
	
	osoba1.dodaj_psa();
	osoba1.nakarm_psa();
	osoba1.nakarm_psa();
	osoba1.usun_psa();
	return 0;
}


// setter ustawia imie a getter zwraca imie
