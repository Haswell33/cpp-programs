#include <iostream>

using namespace std;

class Rachunek{
	public:
		string imie, nazwisko, numer_konta;
		double saldo;
	
	Rachunek(string k_imie="", string k_nazwisko="", string k_numer_konta=""){//konstruktor
		imie = k_imie;
		nazwisko = k_nazwisko;
		numer_konta = k_numer_konta;
		saldo = 0;
	}
	
	public:
		void dodaj_saldo();
		void odejmij_saldo();
		void pokaz_saldo();
		double zwroc_saldo();
		void edytuj_konto();	
};

void Rachunek::dodaj_saldo(){
	double kwota_dodania;
	cout << "Powieksz saldo o kwote: ";
	cin >> kwota_dodania; 
	this->saldo=this->saldo+kwota_dodania;	
}

void Rachunek::odejmij_saldo(){
	double kwota_usuniecia;
	cout << "Zmniejsz saldo o kwote: ";
	cin >> kwota_usuniecia; 
	this->saldo=this->saldo-kwota_usuniecia;	
}

void Rachunek::pokaz_saldo(){
	cout << this->imie << endl << this->nazwisko << endl << this->numer_konta << endl << this->saldo << endl << endl;
}

double Rachunek::zwroc_saldo(){
	return saldo;
	
}

void Rachunek::edytuj_konto(){
	string imie_edytuj, nazwisko_edytuj, numer_konta_edytuj;
	cout << "Podaj imie nowego klienta: " << endl;
	cin >> imie;
	cout << "Podaj nazwisko nowego klienta: " << endl;
	cin >> nazwisko;
	cout << "Podaj numer rachunku bankowego nowego klienta: " << endl;
	cin >> numer_konta;	
}

int main(){
	string imie, nazwisko, numer_konta;
	
	cout << "Podaj imie nowego klienta: " << endl;
	cin >> imie;
	cout << "Podaj nazwisko nowego klienta: " << endl;
	cin >> nazwisko;
	cout << "Podaj numer rachunku bankowego nowego klienta: " << endl;
	cin >> numer_konta; 
	Rachunek rachunek_1(imie, nazwisko, numer_konta);
	
	rachunek_1.dodaj_saldo();
	rachunek_1.dodaj_saldo();
	rachunek_1.pokaz_saldo();
	rachunek_1.odejmij_saldo();	
	rachunek_1.pokaz_saldo();
	rachunek_1.zwroc_saldo();
	rachunek_1.edytuj_konto();
	rachunek_1.pokaz_saldo();
	
	return 0;	
}
