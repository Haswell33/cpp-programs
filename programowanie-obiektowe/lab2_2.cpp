#include <iostream>

using namespace std;

class Macierz{
	public:
		int ** tab; //pole tab, wskaznik do macierzy
		int n; //rozmiar macierzy
	
	Macierz(int konstruktor_n=1){
		n=konstruktor_n;
		tab = new int * [n];
		for(int i=0; i<n; i++)
		{
			tab[i] = new int [n];
			for(int j=0; j<n; j++)
				tab[i][j]=1;		
		}	
	}
	
	Macierz(const Macierz &n_kopiowane){ //Konstruktor kopiuj¹cy{ x = wzor.x; y = wzor.y; lPunktow++; nrPunktu= ++nrKolPunktu; } 
		n=n_kopiowane.n;
		tab = new int * [n];
			for(int i=0; i<n; i++)
				tab[i] = new int [n];
	
			for(int i=0; i<n_kopiowane.n; i++)
		    {
		       for(int j=0; j<n_kopiowane.n; j++)
					tab[i][j]=n_kopiowane.tab[i][j];
			}
	}
	~Macierz();
	
	public:
		
};

Macierz::~Macierz(){
	delete tab[n];
}

int main(){
	int rozmiar_macierz;	
	cout << "Okresl rozmiar macierzy: " << endl;
	cin >> rozmiar_macierz;
	Macierz macierz_1(rozmiar_macierz);	
	
    for(int i=0; i<rozmiar_macierz; i++)
    {
       for(int j=0; j<rozmiar_macierz; j++)	
			cout << macierz_1.tab[i][j] << " ";
       cout << endl;
	}
	cout << endl;
	Macierz macierz_2 = macierz_1;
	
	for(int i=0; i<rozmiar_macierz; i++)
    {
       for(int j=0; j<rozmiar_macierz; j++)
			cout << macierz_2.tab[i][j] << " ";
       cout << endl;
	}
	return 0;
}
