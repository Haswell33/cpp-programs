/*Karol Siedlaczek I8X1N1
LAB 3.6
Zaimplementuj klas� Funkcja_liniowa pochodn� klasy funkcja z zadania 3.5. 
Klasa funkcja_liniowa powinna zawiera� publiczne pola a i b oraz przeci��on� metod� wartosc() w taki spos�b, 
�eby zwraca�a warto�� funkcji a*x+b*/
#include <iostream>
 
using namespace std;
 
class Funkcja{
	public:
		double x;
		
	    double wartosc(double x){
			cout << "to jest jeden parametr: ";
			return x;
	    }
	 
	    double wartosc(double a, double b, double x){
	        cout << "to jest a*x+b: ";
			return a * x + b;
	    }
};
 
class Funkcja_liniowa:public Funkcja{
	public:
		double a, b;
	
		double wartosc(double x){
			cout << "to jest jeden parametr: ";
			return x;
	    }
	 
	    double wartosc(double a, double b, double x){
	        cout << "to jest a*x+b: ";
	        return a * x + b;
	    }
};

int main(){
    Funkcja_liniowa obiekt_1;
    cout << obiekt_1.wartosc(5) << endl;
    cout << obiekt_1.wartosc(10,20,3) << endl;
    return 0;
}
