/*Karol Siedlaczek I8X1N1
ZAD 3.1
Napisz klasê Ubranie posiadaj¹c¹ publiczne pola material i kolor. Napisz klasy Spodnie, Koszula i Czapka (pochodne klasy Ubranie). 
Klasy pochodne powinny posiadaæ nastêpuj¹ce pola publiczne:
	klasa spodnie pola dlugosc i w_pasie,
	klasa koszula pola dlugosc i w_klatce,
	klasa czapka pole obwod.
	pisz konstruktory i gettery.
	przetestuj dzia³anie
Dokonaj zmiany kwantyfikatorów pól i metod klasy bazowej i przetestuj dostêp z klas pochodnych
(wyjaœnij dzia³anie).*/
#include <iostream>

using namespace std;

class Ubranie{//klasa bazowa
	public:
		string material, kolor;
		
		Ubranie(string k_material = "", string k_kolor = ""){
			material = k_material;
			kolor = k_kolor;
		}
		
		void getter();
};

class Spodnie:public Ubranie{//pochodna klasa Ubranie
	public:
		double spodnie_dlugosc, 
			   w_pasie;
	
		Spodnie(double k_spodnie_dlugosc = 0, double k_w_pasie = 0, string k_material="", string k_kolor="")
		:Ubranie(k_material, k_kolor), spodnie_dlugosc(k_spodnie_dlugosc), w_pasie(k_w_pasie){}
		
		void getter();
};

class Koszula:public Spodnie{//pochodna klasa Ubranie i Spodnie
	public:
		double koszula_dlugosc, 
			   w_klatce;
		
		Koszula(double k_koszula_dlugosc = 0, double k_w_klatce = 0, double k_spodnie_dlugosc = 0, double k_w_pasie = 0, string k_material = "", string k_kolor = "")//tu jeszcze spodnie zagniezdzone
		:Spodnie(k_spodnie_dlugosc, k_w_pasie, k_material, k_kolor), koszula_dlugosc(k_koszula_dlugosc), w_klatce(k_w_klatce){}

		void getter();
};

class Czapka:public Ubranie{//pochodna klasa Ubranie
	public:
		double obwod;
		
		Czapka(double k_obwod = 0, string k_material = "", string k_kolor = "")
		:Ubranie(k_material, k_kolor), obwod(k_obwod){}

		void getter();
};

void Ubranie::getter(){
	cout << material << endl << kolor;
}

void Spodnie::getter(){
	cout << spodnie_dlugosc << endl << w_pasie;
}

void Koszula::getter(){
	cout << "Koszula ma dlugosc " << koszula_dlugosc << "cm, a w klatce " << w_klatce << "cm. Spodnie maja dlugosc " << Spodnie::spodnie_dlugosc << "cm, a w pasie " << Spodnie::w_pasie << "cm. Material to " << Spodnie::material << ", oraz jej kolor jest " << Spodnie::kolor << endl << endl; 
}

void Czapka::getter(){
	cout << "Czapka ma obwod " << obwod << "cm. Material to " << Ubranie::material << ", oraz jej kolor jest " << Ubranie::kolor << endl;
}

int main(){
	double main_obwod;
	string main_material, main_kolor;
	Koszula koszula_1(10, 20, 30, 40, "elanobawelna", "niebieski");
	koszula_1.getter();
	
	cout << "Podaj obwod czapki: ";
	cin >> main_obwod;
	cout << "Podaj material czapki: ";
	cin >> main_material;  
	cout << "Podaj kolor czapki: ";
	cin >> main_kolor;
	
	Czapka czapka_1(main_obwod, main_material, main_kolor);
	czapka_1.getter();
	
	return 0;
}
