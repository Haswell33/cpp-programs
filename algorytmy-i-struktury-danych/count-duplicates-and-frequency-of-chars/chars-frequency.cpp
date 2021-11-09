//Karol Siedlaczek Zad 1
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

fstream plik_odczyt, plik_ile, plik_licz, plik_msort;

int wyznaczenie_symboli(int bufor[], string input)
{
	for(int j=0; j<input.length(); j++)
	{
		bufor[input[j]]++;
	}
	return bufor[127];
}

void zapisz_do_ile(int bufor[], bool wynik, string nazwa_pliku_wejsciowego)
{
	plik_odczyt.open(nazwa_pliku_wejsciowego.c_str(), ios::in | ios::binary);
	plik_ile.open("wyjscie.ile", ios::binary | ios::out);
	unsigned char bajt_8b;
	
	wynik=plik_ile.is_open();
	if(!wynik)
	{
		cout << endl << "Blad otwierania pliku .ile w trybie tekstowym!" << endl;
		exit(1);
	}
	
	while(true)
	{
		bajt_8b=plik_odczyt.get();
		wynik=plik_odczyt.good();
		if(!wynik)
		{
			cout << endl << "Zliczono ilosc uzytych symboli(bajtow 8-bitowych) w pliku wejsciowym i zapisano je w pliku wyjscie.ile" << endl;
			break;
		} 
		//cout << hex << int(bajt_8b) << " ";	
		plik_ile << hex << int(bajt_8b) << " ";
	}
	plik_odczyt.close();
	plik_ile.close();
}

int zapisz_do_licz(int bufor[], bool wynik)
{
	plik_licz.open("wyjscie.licz", ios::out);	
	wynik=plik_licz.is_open();
	
	if(!wynik)
	{
		cout << "Blad otwierania pliku do .licz w trybie tekstowym!" << endl;
		exit(1);
	} else cout << "Zliczono ilosc uzytych symboli wraz z ich iloscia wystapien i zapisano je w pliku wyjscie.licz" << endl;
	
	for(size_t i=0; i<127; i++)
    {
    	if(bufor[i]>0)
    	{
			plik_licz << i << " " << bufor[i] << endl;	
		}					
	}	
	plik_licz.close();
}

void zapisz_do_msort(int bufor[], bool wynik, string input)
{
	plik_msort.open("wyjscie.msort", ios::out);
	wynik=plik_msort.is_open();
	
	if(!wynik)
	{
		cout << "Blad otwierania pliku .msort w trybie tekstowym!" << endl;
		exit(1);
	} else cout << "Zliczono ilosc uzytych symboli wraz z ich iloscia wystapien, posortowano je malejaco i zapisano w pliku wyjscie.msort" << endl;
	
	for(size_t i=127; i>0; i--)
    {
    	if(bufor[i]>0)
    	{
    		plik_msort << i << " " << bufor[i] << endl;	
		}		
	}
	plik_msort.close();
}

int main()
{
	string input, nazwa_pliku_wejsciowego;
	int i=0;
	int bufor[127]={};
	bool wynik;	
	nazwa_pliku_wejsciowego = "test1.txt";
	cout << "Podana nazwa pliku: " << nazwa_pliku_wejsciowego << endl;
	plik_odczyt.open(nazwa_pliku_wejsciowego.c_str(), ios::in);
	
	wynik=plik_odczyt.is_open();
	if(!wynik)
	{
		cout << "Blad otwierania pliku .odczyt w trybie tekstowym!" << endl;
		exit(1);
	} else cout << "Odczytana zawartosc z pliku wejsciowego: " << endl;	
	while(true)
	{
		i++;
		plik_odczyt >> input;
		wynik=plik_odczyt.good();
		if (!wynik) 
			break;
		wyznaczenie_symboli(bufor, input);
		cout << input << " ";
		if(i==10)
		{
			cout << endl;
			i=0;
		}
	}	
	plik_odczyt.close();
	zapisz_do_ile(bufor, wynik, nazwa_pliku_wejsciowego);
	zapisz_do_licz(bufor, wynik);
	zapisz_do_msort(bufor, wynik, input);
    	
	return 0;
}
