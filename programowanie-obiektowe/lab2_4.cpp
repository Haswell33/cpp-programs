#include <iostream>

#define rozmiar_macierz 10

using namespace std;

class Macierz{
	public:
		int **tab; //pole tab, wskaznik do macierzy
		int n; //rozmiar macierzy
	
	Macierz(int konstruktor_n=1, int obiekt=1){
		n=konstruktor_n;
		tab = new int * [n];
		for(int i=0; i<n; i++)
		{
			tab[i] = new int [n];
			for(int j=0; j<n; j++)
				tab[i][j]=obiekt;		
		}	
	}
	~Macierz();
	
	public:
		void porownaj();
		void wyswietl();
};

Macierz::~Macierz(){
	delete tab[n];
}

void Macierz::wyswietl(){
    for(int i=0; i<this->n; i++){
           for(int j=0; j<this->n; j++)
                cout << tab[i][j] << " ";
            cout << endl;
        }
}

Macierz porownaj(Macierz macierz_1, Macierz macierz_2){
	int ile_macierz_1=0, ile_macierz_2=0;
    for(int i=0; i<rozmiar_macierz; i++){
        for(int j=0; j<rozmiar_macierz; j++){
            if(macierz_1.tab[i][j] == 0)
                ile_macierz_1++;
            if(macierz_2.tab[i][j] == 0)
                ile_macierz_2++;
        }
    }
    if(ile_macierz_1>=ile_macierz_2)
        return macierz_1;
    else
        return macierz_2;
}

int main(){
	int obiekt;
	cout << "Podaj obiekty macierzy 1: " << endl;
	cin >> obiekt;
	Macierz macierz_1(rozmiar_macierz, obiekt);	
	cout << "Podaj obiekty macierzy 2: " << endl;
	cin >> obiekt;
	Macierz macierz_2(rozmiar_macierz, obiekt);
	
    /*for(int i=0; i<rozmiar_macierz; i++)
    {
       for(int j=0; j<rozmiar_macierz; j++)	
			cout << macierz_1.tab[i][j] << " ";
       cout << endl;
	}
	cout << endl;
	
	for(int i=0; i<rozmiar_macierz; i++)
    {
       for(int j=0; j<rozmiar_macierz; j++)
			cout << macierz_2.tab[i][j] << " ";
       cout << endl;
	}*/

	cout << "Macierz w ktorej jest wiecej 0: " << endl;
	porownaj(macierz_1, macierz_2).wyswietl();
	return 0;
}
