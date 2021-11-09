/*Karol Siedlaczek I8X1N1
LAB 3.7
Zaimplementuj klasê Funkcja_kwadratowa pochodn¹ klasy funkcja z zadania 3.5.
Klasa Funkcja_kwadratowa powinna zawieraæ publiczne pola a, b i c oraz przeci¹¿on¹ metodê wartosc w taki sposób, ¿eby zwraca³a wartoœæ funkcji a*x2+b*x+c*/
#include <iostream>
 
using namespace std;
 
class Funkcja{
	public:
		double x;
		
	    double wartosc(double x){
	        cout << "to jest jeden parametr: ";
			return x;
	    }
	 
	    double wartosc(double a, double b, double c, double x){
	        cout << "to jest jeden a*2*x+b*x+c: ";
	        return a * 2*x + b * x + c;
	    }
};
 
class Funkcja_kwadratowa:public Funkcja{
	public:
		double a, 
			   b,
			   c;
	
		double wartosc(double x){
	        cout << "to jest jeden parametr: ";
			return x;
	    }
	 
	    double wartosc(double a, double b, double c, double x){
	        cout << "to jest jeden a*2*x+b*x+c: ";
	        return a * 2*x + b * x + c;
	    }
};

int main(){
	double main_a = 0,
		   main_b = 0,
		   main_c = 0, 
		   main_x = 0;	   
	cout << "a: ";
	cin >> main_a;
	cout << "b: ";
	cin >> main_b;
	cout << "c: ";
	cin >> main_c;
	cout << "x: ";
	cin >> main_x;
	
    Funkcja_kwadratowa obiekt_1;
    cout << obiekt_1.wartosc(main_x) << endl;
    cout << obiekt_1.wartosc(main_a, main_b, main_c, main_x) << endl;
 
    std::cin.get();
    return 0;
}
