/*Karol Siedlaczek I8X1N1
LAB 3.5
Zaimplementuj klasê Funkcja posiadaj¹c¹ publiczne pole x oraz czysto wirtualn¹ metodê wartoœæ,
która w klasach pochodnych bêdzie zwraca³a wartoœæ funkcji przechowywanej w obiekcie w punkcie.
Spróbj utworzyæ obiekt tej klasy (wyjaœnij dzia³anie)*/
#include <iostream>

using namespace std;

class Funkcja{//klasa bazowa
	public:
		double x;
		
		virtual ~Funkcja(){}
		
		virtual double wartosc(double x) = 0;// 0?
		virtual void getter();
};

class MnozenieX2:public Funkcja{//klasa pochodna X2
	public:
		virtual double wartosc(double x);	
};

class MnozenieX3:public Funkcja{//klasa pochodna X3
	public:
		virtual double wartosc(double x);	
};

class MnozenieX4:public Funkcja{//klasa pochodna X4
	public:
		virtual double wartosc(double x);	
};

void Funkcja::getter(){
	cout << endl << "x: " << x;
}

double MnozenieX2::wartosc(double dana){
	return x = dana*2;
}

double MnozenieX3::wartosc(double dana){
	return x = dana*3;
}

double MnozenieX4::wartosc(double dana){
	return x = dana*4;
}

int main(){
	double dana = 0;
	double zmienna = 0;
	Funkcja *X2_obiekt_1 = new MnozenieX2;
	Funkcja *X3_obiekt_1 = new MnozenieX3;
	Funkcja *X4_obiekt_1 = new MnozenieX4;
	cout << "Podaj liczbe: ";
	cin >> dana;
	//Trojkat obiekt_1(m_x);
	
	X2_obiekt_1->wartosc(dana);
	X3_obiekt_1->wartosc(dana);
	X4_obiekt_1->wartosc(dana);
	
	X2_obiekt_1->getter();
	X3_obiekt_1->getter();
	X4_obiekt_1->getter();
	//cout << "X2: " << X2_obiekt_1->x;
	return 0;
}
