//after Sulej correction
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX 256

//const int max = 256;

using namespace std;

ifstream plik_wej;

struct element
{
    unsigned char znak;
    int ilosc_wystapien;
}   tablica_znakow[MAX];

void sortowanie_babelkowe()
{	    
	for(int i=0; i < MAX; i++)
	{	
        for(int j=0; j < MAX - 1; j++)
		{
            if(tablica_znakow[i].ilosc_wystapien > tablica_znakow[j].ilosc_wystapien ||
			   tablica_znakow[i].ilosc_wystapien == tablica_znakow[j].ilosc_wystapien && tablica_znakow[i].znak < tablica_znakow[j].znak)
			{
                swap(tablica_znakow[i], tablica_znakow[j]);
            }	
        }
    }
}

void zapisz_znak_licz(string nazwa_pliku_wejsciowego, string nowa_nazwa_pliku)
{
    ofstream plik_licz;
    nazwa_pliku_wejsciowego.erase(nazwa_pliku_wejsciowego.find_last_of("."), nazwa_pliku_wejsciowego.length());
	nowa_nazwa_pliku = nazwa_pliku_wejsciowego + ".licz";
    plik_licz.open(nowa_nazwa_pliku.c_str(), ios::out);

    for(int i=0;i < MAX; i++)
	{
        if(tablica_znakow[i].ilosc_wystapien!=0)     
            plik_licz << (int)tablica_znakow[i].znak << " " << tablica_znakow[i].ilosc_wystapien << endl;
    }
    cout << "Zliczono ilosc uzytych symboli(bajtow 8-bitowych) wraz z ich iloscia wystapien i zapisano je w pliku " << nowa_nazwa_pliku << endl;
    plik_licz.close();
}

void zapisz_znak_msort(string nazwa_pliku_wejsciowego, string nowa_nazwa_pliku)
{
	ofstream plik_msort;
    nazwa_pliku_wejsciowego.erase(nazwa_pliku_wejsciowego.find_last_of("."), nazwa_pliku_wejsciowego.length());
	nowa_nazwa_pliku = nazwa_pliku_wejsciowego + ".msort";
    plik_msort.open(nowa_nazwa_pliku.c_str(), ios::out);
    sortowanie_babelkowe();
	
	for(int i=0; i<MAX; i++)
	{
        if(tablica_znakow[i].ilosc_wystapien!=0)
            plik_msort << (int)tablica_znakow[i].znak << " " << tablica_znakow[i].ilosc_wystapien << endl;
    }
    cout << "Zliczono ilosc uzytych symboli(bajtow 8-bitowych) wraz z ich iloscia wystapien i posortowano je malejaco w pliku " << nowa_nazwa_pliku << endl;
	plik_msort.close();		
}

void zapisz_znak_ile(string nazwa_pliku_wejsciowego, string nowa_nazwa_pliku, int ilosc_wystapien)
{
	ofstream plik_ile;	
	nazwa_pliku_wejsciowego.erase(nazwa_pliku_wejsciowego.find_last_of("."), nazwa_pliku_wejsciowego.length());
	nowa_nazwa_pliku = nazwa_pliku_wejsciowego + ".ile";
    plik_ile.open(nowa_nazwa_pliku.c_str(), ios::out);
	plik_ile << ilosc_wystapien << endl;
	cout << "Zliczono ilosc uzytych symboli(bajtow 8-bitowych) w pliku " << nowa_nazwa_pliku << endl;
	plik_ile.close();
}

int main(int argc, char *argv[])
{
	string nazwa_pliku_wejsciowego, nowa_nazwa_pliku;
	bool wynik;
	
	if (argc<2)
	{
		cout << "Nie podano nazwy pliku jako parametru wejsciowego!" << endl;
		return -1;
	}
	nazwa_pliku_wejsciowego = argv[1];
	
	for(int i=0; i < MAX; i++)
	{
        tablica_znakow[i].znak = i;
        tablica_znakow[i].ilosc_wystapien = 0;
    }
	cout << endl << "Podana nazwa pliku: " << nazwa_pliku_wejsciowego << endl;
	plik_wej.open(nazwa_pliku_wejsciowego.c_str(), ios::binary);
	
	wynik=plik_wej.good();
    if(!plik_wej.good())
	{
        cout << "Blad otwierania pliku wejsciowego!" << endl;
        return 1;
    }
    unsigned char bufor;
    int ilosc_wystapien = 0;
   
	while(true)
    {
    	bufor = plik_wej.get();
    	
    	wynik=plik_wej.good();
    	if(!wynik)
		{
			cout << "Odczytano plik wejsciowy" << endl << endl;
			break;
		}
        
        ilosc_wystapien++;
        tablica_znakow[(int)bufor].ilosc_wystapien++;      
    }
    
    zapisz_znak_licz(nazwa_pliku_wejsciowego, nowa_nazwa_pliku);
    zapisz_znak_msort(nazwa_pliku_wejsciowego, nowa_nazwa_pliku);
    zapisz_znak_ile(nazwa_pliku_wejsciowego, nowa_nazwa_pliku, ilosc_wystapien);
    plik_wej.close();
    cout << endl << "Zakonczono prace programu." << endl;
	return 0;
}
