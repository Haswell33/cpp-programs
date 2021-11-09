//lab2_als kolejka priorytetowa

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>

using namespace std;
fstream plik;

struct zgloszenie //struktura jako baza danych
{
	string name; //dane zglaszajacego
	time_t czas; //czas wykonania zgloszenia
	string content; //tresc zgloszenia
	int priorytet; //crit, normal, low
	zgloszenie *next;
	zgloszenie();  //konstruktor
};

zgloszenie::zgloszenie()
{
	next = 0;
}

struct lista //struktura head
{
	zgloszenie *head; //wskaznik na  poczatek
	void dodaj_zgloszenie(string imie, time_t czas, string content, int priorytet);
	void wczytaj_zgloszenie(string imie, time_t czas, string content, int priorytet);	
	void stan_kolejki();
	void pobierz_zgloszenie();//tzn usun, wykonaj
	lista();	
};

lista::lista()
{
	head = 0;
}

void lista::dodaj_zgloszenie(string name, time_t czas, string content, int priorytet)
{
	zgloszenie *nowe = new zgloszenie; //tworzy nowy element w liscie	
	plik.open("kolejka_priorytetowa.txt", ios::app | ios::in);	
	if(plik.good()==false) 
	{
    	cout << "Nie mozna otworzyc pliku kolejka_priorytetowa.txt";
    	exit(1);
	}
	nowe->name = name;
	nowe->content = content;
	nowe->priorytet = priorytet;
	nowe->czas = czas;	
	plik << name << endl;
	plik << content << endl;
	plik << priorytet << endl;
	plik << ctime(&czas) << endl;
	
	if((head==0))
	{
		head = nowe;
	}
	else
	{	
		zgloszenie *tmp = head;
		
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = nowe;
		nowe->next = 0;	
	}
	plik.close();
}

void lista::wczytaj_zgloszenie(string name, time_t czas, string content, int priorytet)
{
	zgloszenie *nowe = new zgloszenie;
	nowe->name = name;
	nowe->content = content;
	nowe->priorytet = priorytet;
	nowe->czas = czas;	
	
	if(head==0) /*|| priorytet>priorytet)*/ //if pierwszy to teraz poczatek
	{
	//	nowe->next=head;	
		head = nowe;
	}
	else // else wedruje na koniec listy
	{
		/*if(head->priorytet < priorytet)
		{
			tmp->
		}*/
		zgloszenie *tmp = head;
		
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = nowe;
		nowe->next = 0;	
	}
}

void lista::stan_kolejki()//case 2
{
	plik.open("kolejka_priorytetowa.txt", ios::app | ios::in);
	if(plik.good()==false) 
	{
    	cout << "Nie mozna otworzyc pliku kolejka_priorytetowa.txt";
    	exit(1);
	}
	zgloszenie *tmp = head;
	while(tmp)
	{
		cout << endl 
			 << "OPIS ZGLOSZENIA " << endl 
			 << "Imie zglaszajacego: " << tmp->name << endl
			 << "Tresc zgloszenia: " << tmp->content << endl;		 
		if(tmp->priorytet==1)
			cout << "priorytet zgloszenia: Low" << endl;
		if(tmp->priorytet==2)
			cout << "priorytet zgloszenia: Normal" << endl;
		if(tmp->priorytet==3)
			cout << "priorytet zgloszenia: Critical" << endl;
		cout << "Czas zgloszenia: " << tmp->czas << endl;			 
		tmp = tmp->next;	
	}
	plik.close();
	cout << endl << "Nacisnij Enter, aby wrocic do menu wyboru";
}

void lista::pobierz_zgloszenie()//case 3
{
	ofstream plik_temp("plik_temp.txt");
	plik.open("kolejka_priorytetowa.txt", ios::in);
	string dane_z_kolejka_priorytetowa;
	int i=0;
	if(plik.good()==false) 
	{
    	cout << "Nie mozna otworzyc pliku kolejka_priorytetowa.txt";
    	exit(1);
	}
	
	while(getline(plik, dane_z_kolejka_priorytetowa))
	{
		i++;
		if(i>5)
			plik_temp << dane_z_kolejka_priorytetowa << endl;
	}
	plik_temp.close();
	plik.close();
	remove("kolejka_priorytetowa.txt");
	rename("plik_temp.txt", "kolejka_priorytetowa.txt");
	cout << "Zgloszenie z najwyzszym priorytetem zostalo obsluzone, nacisnij Enter, aby wrocic do menu wyboru";
			
    //zgloszenie *tmp = head;
	//head = tmp->next;
}

void wprowadz_dane_do_zgloszenia(string zmienna_name, time_t zmienna_czas, string zmienna_content, int zmienna_priorytet, lista *baza)//case 1
{
    cout << endl << "Dane zglaszajacego: ";
	getline(cin, zmienna_name);			
	cout << "Tresc zgloszenia: ";
	getline(cin, zmienna_content); 
	cout << "Okresl piorytet zgloszenia za pomoca odpowiedniego numeru: " << endl 
		 << "\t1. Low" << endl 
		 << "\t2. Normal" << endl 
		 << "\t3. Critical" << endl 
		 << ": ";
	cin >> zmienna_priorytet;
	cin.ignore();
	ctime(&zmienna_czas);
	baza->dodaj_zgloszenie(zmienna_name, zmienna_czas, zmienna_content, zmienna_priorytet);
	cout << "Nacisnij Enter, aby wrocic do menu wyboru";
}

void stan_zgloszen()//NIEUZYWANA
{
	cout << endl;
    string output;  	
	int i=0;
    plik.open("kolejka_priorytetowa.txt", ios::in);
    if(plik.good()==false) 
	{
    	cout << "Nie mozna otworzyc pliku kolejka_priorytetowa.txt";
    	exit(1);
	}
	while (!plik.eof()) 
	{
		i++;
		getline(plik,output);
		if(i==1)
			cout << endl << "Imie zglaszajacego: " << output;
		if(i==2)
			cout << endl << "Tresc zgloszenia: " << output;	
		if((i==3) && (output == "1"))
			cout << endl <<"Priorytet zgloszenia: Low";
		if((i==3) && (output == "2"))
			cout << endl << "Priorytet zgloszenia: Normal";
		if((i==3) && (output == "3"))
			cout << endl << "Priorytet zgloszenia: Critical";	
		if(i==4)
			cout << endl << "Czas zgloszenia: " << output;
		if(i==5)
		{
			i=0;
			cout << endl;	
		}			
	}
	plik.close();
	cout << endl << "Nacisnij Enter, aby wrocic do menu wyboru";
}


void wczytaj_zgloszenie(string zmienna_name, time_t zmienna_czas, string zmienna_content, int zmienna_priorytet, lista *baza)//przed switchem
{
	string temp_tekst01, temp_tekst02, kosz_na_pusta_linie;
	plik.open("kolejka_priorytetowa.txt", ios::in);
	if(plik.good()==false) 
	{
    	cout << "Nie mozna otworzyc pliku kolejka_priorytetowa.txt";
    	exit(1);
	}
	while(!plik.eof())//wczytaj dane z pliku do bufora pamieci operacyjnej
	{
		getline(plik, zmienna_name);
		getline(plik, zmienna_content); 	
		getline(plik, temp_tekst01);
		zmienna_priorytet = atoi(temp_tekst01.c_str());		
		getline(plik, temp_tekst02);
		//zmienna_czas = atoi(temp_tekst02.c_str());
		//ctime(&zmienna_czas);
		
		getline(plik, kosz_na_pusta_linie);
		kosz_na_pusta_linie.clear();
		baza->wczytaj_zgloszenie(zmienna_name, zmienna_czas, zmienna_content, zmienna_priorytet);
	}
	plik.close();	
}

int main()
{	
	char wybor;
	string zmienna_name, zmienna_content;
	time_t zmienna_czas;
	int zmienna_priorytet;
	lista *baza = new lista;
	wczytaj_zgloszenie(zmienna_name, zmienna_czas, zmienna_content, zmienna_priorytet, baza);
	
	for(;;)
	{
		cout << "1. Dodaj zgloszenie" << endl
			 << "2. Wyswietl stan kolejki" << endl
			 << "3. Pobierz zgloszenie z kolejki" << endl
			 << "4. Zakoncz dzialanie aplikacji" << endl
			 << endl
			 << "Wybor: ";
		wybor=getch();
		
		switch(wybor)
		{
			case '1':
            {
            	wprowadz_dane_do_zgloszenia(zmienna_name, zmienna_czas, zmienna_content, zmienna_priorytet, baza);
                break;
            }
			case '2':
            {
            	baza->stan_kolejki();
                break;
            }
			case '3':
            {
                baza->pobierz_zgloszenie();
                break;
            }
			case '4':
            {
            	cout << "Koniec programu.";
                exit(0);
            }
            case '5'://sprawdza file, nie aktualizuje
            {
            	stan_zgloszen();
            	break;
			}
			default: cout << "Nie ma takiej opcji w menu";
		}
		getchar();
        system("cls"); 
	}
	return 0;
}
