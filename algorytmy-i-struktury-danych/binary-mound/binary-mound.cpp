#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>

#define N 300

using namespace std;
string cr,cl,cp;
int n = 0;
int wielkosc=0;
struct kopiec_binarny
{
    int numer;//po prostu zaladowany z tablicy
    
    //int tab[N];
    
    struct kopiec_binarny *next;
    kopiec_binarny();
};

kopiec_binarny::kopiec_binarny()
{
	next = 0;
}

struct lista
{
	kopiec_binarny *head;
	int dodaj_element(int numer);
	void wyswietl_liste();
	void wczytaj_do_kopca();
	void wyswietl_kopiec(int head);
	void dodaj_do_kopca2(int numer);
	void dodaj_do_kopca3(int numer);
	void wyswietl(int head);
	lista();
};

lista::lista()
{
	head = 0;	
}

int lista::dodaj_element(int numer)
{
	ifstream plik_wejscie;
	plik_wejscie.open("new_tree.txt", ios::in);
	while(!plik_wejscie.eof())
	{
	    kopiec_binarny *nowy_element = new kopiec_binarny;
	    nowy_element->numer = numer;
	    plik_wejscie >> nowy_element->numer;
	    if(head==0)
	        head = nowy_element;
	    else
	    {
	        kopiec_binarny *temp = head;
	        while(temp->next)
	            temp = temp->next;
	        temp->next = nowy_element;  // ostatni element wskazuje na nasz nowy
	        nowy_element->next = 0;     // ostatni nie wskazuje na nic
	    }
	    wielkosc++;
	}
    plik_wejscie.close();
    return wielkosc;
}

void lista::wyswietl_liste()
{
    kopiec_binarny *temp = head;
    while(temp)
    {
        cout << temp->numer << endl;
        temp = temp->next;
    }
}

void lista::wczytaj_do_kopca()
{
	lista *baza = new lista;
	kopiec_binarny *temp = head;
    while(temp)
    {
        baza->dodaj_do_kopca3(temp->numer);
        temp = temp->next;
    }	
}

void lista::dodaj_do_kopca3(int v)
{
	int tab[wielkosc], i, j;

	i = n++;
	j = (i - 1) / 2;
 
	while(i > 0 && tab[j] < v)
	{
		tab[i] = tab[j];
		i = j;
		j = (i - 1) / 2;
	}
	tab[i] = v;
}
/*void lista::wyswietl(int head)
{
	int tab[wielkosc];
	head = numer
	if(head <= wielkosc) 
	{
		cout << head << " : " <<  tab[head] << " \n";
		if(head*2 <= wielkosc) 
			wyswietl(head*2);
		if(head*2+1 <= wielkosc) 
			wyswietl(head*2+1);
	}
}*/


/*void dodaj_do_kopca(int wartosc)
{
	int i,j;
	i = n++;
	j = (i-1)/2;
	int tab[]
	while((i>0) && (tab[j]<wartosc)
	{
		dane_z_pliku *temp = head;
		tab[i] = tab[j];
		i = j;
		j = (i-1)/2;
		temp = temp->next;
	}
	tab[i]=wartosc;
}*/
void printBT(string sp, string sn, kopiec_binarny *temp)
{
  string s;

  if(temp)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, 2 * temp<-numer + 2);

    s = s.substr(0,sp.length()-2);

    cout << s << sn << temp<-numer << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, 2 * temp<-numer + 1);
  }
}
int main()
{	 
cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;
	
	
	
	lista *baza = new lista;
	int wezel_do_dodania;
	char wybor;
	kopiec_binarny *wielkosc = NULL;
	bool czy_istnieje_w_tablicy;

	baza->dodaj_element(0);
	baza->wyswietl_liste();
	baza->wczytaj_do_kopca();
	baza->wyswietl(0);
	printBT("","",0);
	//printBT("","",0);
	
	for(;;)//menu wyboru
	{
		cout << "1. Dodaj wartosc do kopca binarnego" << endl
			 << "2. Wyswietl stan kopca" << endl
			 << "3. Zakoncz dzialanie programu i zapisz wartosci do pliku" << endl
			 << "Wybor: ";			 
		wybor=getch();
		
	    switch(wybor)
		{
			case '1'://dodaj wartosc do kopca
			{
				wezel_do_dodania = 0;
				czy_istnieje_w_tablicy=false;
				cout << "Podaj wartosc wezla ktory chcesz dodac: ";
				cin >> wezel_do_dodania;				 
				for(int i = 0; i<00; i++)//sprawdzenie czy wezel nie znajduje sie w tablicy, nie moze byc powtorzen(AVL)
				{
					if(wezel_do_dodania==00)
						czy_istnieje_w_tablicy=true;	
				}
				if(czy_istnieje_w_tablicy==true)
				{
					cout << "Podana wartosc zawiera sie w tablicy - nie mozna jej dodac. Enter aby kontynowac...";
					getchar();
					break;
				}
				else//jesli nie ma elementu dodaj go do drzewa 
				{
					cout << "Podana wartosc nie zawiera sie w tablicy - wartosc zostala dodana. Enter aby kontynowac...";	
					getchar();
					break;
				}	
			}
			
			case '2'://wyswietl 5 poziomów drzewa
			{
				break;
			}
			
			case '3'://zamknij i zapisz
			{
				cout << "Koniec programu." << endl;
                exit(0);
			}
			
			default: cout << "Nie ma takiej opcji w menu";
		}
		getchar();
	    system("cls");
	}
	return 0;
}



void printBT(string sp, string sn, int v)
{
  string s;
	struct dane_z_pliku *temp = head;
  if(v < n)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, 2 * v + 2);

    s = s.substr(0,sp.length()-2);

    cout << s << sn << temp->numer << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, 2 * v + 1);
  }
}
