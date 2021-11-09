//Siedlaczek Karol I8X1N1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>

#define ilosc_elementow 400

using namespace std;

fstream R1, R2, R3, R4, R5; //tmp pliki do wyswietlania drzewa

struct AVL_tree
{
	AVL_tree *rodzic, *lewy, *prawy;
	int klucz, wspolczynnik_rownowagi;
};

fstream plik_wyjscie;

void RR(AVL_tree *&korzen, AVL_tree *A)
{
	AVL_tree *B = A->prawy;
	AVL_tree *wskaznik_wezla = A->rodzic;

	A->prawy = B->lewy;
	if(A->prawy)
		A->prawy->rodzic = A;
	
	B->lewy = A;
	B->rodzic = wskaznik_wezla;
	A->rodzic = B;
	
	if(wskaznik_wezla)
	{
		if(wskaznik_wezla->lewy == A) 
			wskaznik_wezla->lewy = B; 
		else 
			wskaznik_wezla->prawy = B;
	}
	else korzen = B;
	
	if(B->wspolczynnik_rownowagi == -1) 
		A->wspolczynnik_rownowagi = B->wspolczynnik_rownowagi = 0;
	else
	{
		A->wspolczynnik_rownowagi = -1; 
		B->wspolczynnik_rownowagi = 1;
	}
}

// Rotacja LL
void LL(AVL_tree *&korzen, AVL_tree *A)
{
	AVL_tree *B = A->lewy;
	AVL_tree *wskaznik_wezla = A->rodzic;
	
	A->lewy = B->prawy;
	if(A->lewy) 
		A->lewy->rodzic = A;
	
	B->prawy = A;
	B->rodzic = wskaznik_wezla;
	A->rodzic = B;
	
	if(wskaznik_wezla)
	{
		if(wskaznik_wezla->lewy == A)
			wskaznik_wezla->lewy = B;
		else 
			wskaznik_wezla->prawy = B;
	}
	else korzen = B;
	
	if(B->wspolczynnik_rownowagi == 1)
		A->wspolczynnik_rownowagi = B->wspolczynnik_rownowagi = 0;
	else
	{
		A->wspolczynnik_rownowagi = 1;
		B->wspolczynnik_rownowagi = -1;
	}
}

// Rotacja RL
void RL(AVL_tree *&korzen, AVL_tree *A)
{
	AVL_tree *B = A->prawy;
	AVL_tree *C = B->lewy;
	AVL_tree *wskaznik_wezla = A->rodzic;
	
	B->lewy = C->prawy;
	if(B->lewy) B->lewy->rodzic = B;
	
	A->prawy = C->lewy;
	if(A->prawy) A->prawy->rodzic = A;
	
	C->lewy = A;
	C->prawy = B;
	A->rodzic = B->rodzic = C;
	C->rodzic = wskaznik_wezla;
	
	if(wskaznik_wezla)
	{
		if(wskaznik_wezla->lewy == A) 
			wskaznik_wezla->lewy = C; 
		else 
			wskaznik_wezla->prawy = C;
	}
	else korzen = C;
	
	if(C->wspolczynnik_rownowagi == -1) 
		A->wspolczynnik_rownowagi = 1; 
	else 
		A->wspolczynnik_rownowagi = 0;
		
	if(C->wspolczynnik_rownowagi == 1) 
		B->wspolczynnik_rownowagi = -1; 
	else 
		B->wspolczynnik_rownowagi = 0;
	
	C->wspolczynnik_rownowagi = 0;
}

// Rotacja LR
void LR(AVL_tree *&korzen, AVL_tree *A)
{
	AVL_tree *B = A->lewy;
	AVL_tree *C = B->prawy;
	AVL_tree *wskaznik_wezla = A->rodzic;
	
	B->prawy = C->lewy;
	if(B->prawy) B->prawy->rodzic = B;
	
	A->lewy = C->prawy;
	if(A->lewy) A->lewy->rodzic = A;
	
	C->prawy = A;
	C->lewy = B;
	A->rodzic = B->rodzic = C;
	C->rodzic = wskaznik_wezla;
	
	if(wskaznik_wezla)
	{
		if(wskaznik_wezla->lewy == A) 
			wskaznik_wezla->lewy = C; 
		else 
		wskaznik_wezla->prawy = C;
	}
	else korzen = C;
	
	if(C->wspolczynnik_rownowagi ==  1) 
		A->wspolczynnik_rownowagi = -1; 
	else 
		A->wspolczynnik_rownowagi = 0;
	
	if(C->wspolczynnik_rownowagi == -1) 
		B->wspolczynnik_rownowagi =  1; 
	else 
		B->wspolczynnik_rownowagi = 0;
	
	C->wspolczynnik_rownowagi = 0;
}

void dodaj_do_drzewa(AVL_tree *&korzen, int bufor)
{

	AVL_tree *wezel, *wskaznik_wezla, *x;
	bool wynik_roznicy;

	wezel = new AVL_tree;        // tworzymy dynamicznie nowy wêze³
	wezel->lewy = wezel->prawy = wezel->rodzic = NULL; //zerowanko
	wezel->klucz  = bufor;
	wezel->wspolczynnik_rownowagi = 0;
	
	  //----------------------------------------
	  // FAZA 1 - wstawienie wêz³a do drzewa AVL
  	//----------------------------------------

	wskaznik_wezla = korzen;              // rozpoczynamy od korzenia
	
	if(!wskaznik_wezla)
		korzen = wezel;       // jeœli drzewo jest puste, to wêze³ w umieszczamy w korzeniu
	else
	{                      // inaczej szukamy miejsce dla w
		while(true)
		if(bufor < wskaznik_wezla->klucz)     // porównujemy klucze
		{
			if(!wskaznik_wezla->lewy)     // jeœli p nie posiada lewego syna, to
			{
				wskaznik_wezla->lewy = wezel;   // lewym synem p staje siê wêze³ w
				break;         // wychodzimy z pêtli
			}
			wskaznik_wezla = wskaznik_wezla->lewy;     // inaczej przechodzimy do lewego syna
		}
		else
		{
			if(!wskaznik_wezla->prawy)    // jeœli p nie posiada prawego syna, to
			{
				wskaznik_wezla->prawy = wezel;  // prawym synem staje siê wêze³ w
				break;         // wychodzimy z pêtli
			}
			wskaznik_wezla = wskaznik_wezla->prawy;    // inaczej przechodzimy do prawego syna
		}
		
		wezel->rodzic = wskaznik_wezla;           // ojcem w jest p
		
		    //---------------------------------
		    // FAZA 2 - równowa¿enie drzewa AVL
		    //---------------------------------
		
		if(wskaznik_wezla->wspolczynnik_rownowagi) 
			wskaznik_wezla->wspolczynnik_rownowagi = 0; // UWAGA NR 1
		else
		{
			if(wskaznik_wezla->lewy == wezel)   // UWAGA NR 2
				wskaznik_wezla->wspolczynnik_rownowagi = 1;
			else
				wskaznik_wezla->wspolczynnik_rownowagi = -1;
			x = wskaznik_wezla->rodzic;        // bêdziemy szli w górê drzewa w kierunku korzenia
			                     // r i p wskazuj¹ ojca i syna na tej œcie¿ce
			wynik_roznicy = false;
			while(x)
			{
				if(x->wspolczynnik_rownowagi)
				{
					wynik_roznicy = true;     // ustalamy wynik pêtli
					break;        // przerywamy pêtlê
				};
				                    // inaczej modyfikujemy r.bf
				if(x->lewy == wskaznik_wezla) 
					x->wspolczynnik_rownowagi =  1;
				else             
					x->wspolczynnik_rownowagi = -1;
				wskaznik_wezla = x;          // przechodzimy w górê na wy¿szy poziom
				x = x->rodzic;
			}
			
			if(wynik_roznicy)             // jeœli r.bf = +/- 1, to musimy
			{                 // równowa¿yæ drzewo
				if(x->wspolczynnik_rownowagi == 1)
				{
					if(x->prawy == wskaznik_wezla) 
						x->wspolczynnik_rownowagi = 0;  // ga³êzie siê równowa¿¹
					else if(wskaznik_wezla->wspolczynnik_rownowagi == -1) 
						LR(korzen,x);
					else 
						LL(korzen,x);
				}
				else
				{              // r.bf = -1
					if(x->lewy == wskaznik_wezla) 
						x->wspolczynnik_rownowagi = 0;  // ga³êzie siê równowa¿¹
					else if(wskaznik_wezla->wspolczynnik_rownowagi == 1) 
						RL(korzen,x);
					else 
						RR(korzen,x);
				}
			}
		}
	}
}

AVL_tree *usun_z_drzewa(AVL_tree *&korzen, AVL_tree *x)
{
	AVL_tree  *t,*y,*z;
	bool zagniezdzenie;
	
	if(x->lewy && x->prawy)
	{
		//y    = usun_z_drzewa(korzen,predAVL(x));
		zagniezdzenie = false;
	}
	else
	{
		if(x->lewy)
		{
			y = x->lewy;
			x->lewy = NULL;
		}
		else
		{
			y = x->prawy;
			x->prawy = NULL;
		}
		x->wspolczynnik_rownowagi = 0;
		zagniezdzenie  = true;
	}
	
	if(y)
	{
		y->rodzic    = x->rodzic;
		y->lewy  = x->lewy;
		
		if(y->lewy)  
			y->lewy->rodzic  = y;
		y->prawy = x->prawy; 
		
		if(y->prawy)  
			y->prawy->rodzic = y;
		y->wspolczynnik_rownowagi = x->wspolczynnik_rownowagi;
	}
	
	if(x->rodzic)
	{
		if(x->rodzic->lewy == x) 
			x->rodzic->lewy = y; 
		else 
			x->rodzic->prawy = y;
	}
	else 
		korzen = y;
	
	if(zagniezdzenie)
	{
		z = y;
		y = x->rodzic;
		while(y)
		{
			if(!y->wspolczynnik_rownowagi)
			{              // Przypadek nr 1
				if(y->lewy == z)
					y->wspolczynnik_rownowagi = -1;
				else 
					y->wspolczynnik_rownowagi = 1;
				break;
			}
			else
			{
				if(((y->wspolczynnik_rownowagi == 1) && (y->lewy == z)) || ((y->wspolczynnik_rownowagi == -1) && (y->prawy == z)))
				{           // Przypadek nr 2
					y->wspolczynnik_rownowagi = 0;
					z = y; y = y->rodzic;
				}
				else
				{
					if(y->lewy == z)
						t = y->prawy; 
					else 
						t = y->lewy;
					if(!t->wspolczynnik_rownowagi)
					{         // Przypadek 3A
						if(y->wspolczynnik_rownowagi == 1)
							LL(korzen,y);
						else 
							RR(korzen,y);
						break;
					}	
					else if(y->wspolczynnik_rownowagi == t->wspolczynnik_rownowagi)
					{         // Przypadek 3B
						if(y->wspolczynnik_rownowagi == 1) 
							LL(korzen,y); 
						else 
							RR(korzen,y);
						z = t; y = t->rodzic;
					}
					else
					{         // Przypadek 3C
						if(y->wspolczynnik_rownowagi == 1)
							LR(korzen,y); 
						else
							RL(korzen,y);
						z = y->rodzic;
						y = z->rodzic;
					}
				}
			}
		}
	}  
	return x;	
}

AVL_tree *znajdz_element(AVL_tree *wskaznik_wezla, int z)
{
  while(wskaznik_wezla && wskaznik_wezla->klucz != z)
    //wskaznik_wezla = (z < wskaznik_wezla->klucz) ? wskaznik_wezla->klucz: wskaznik_wezla->prawy;

  return wskaznik_wezla;
}

void wypisz_drzewo(AVL_tree *x, int z)
{
	if(x)
	{
		z++;	
		wypisz_drzewo(x->prawy, z);
		if(z==1)
			R1 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";			
		if(z==2)
			R2 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";			
		if(z==3)
			R3 << x->klucz << ":" << x->wspolczynnik_rownowagi << " "; 	
		if(z==4)
			R4 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";		
		if(z==5)
			R5 << x->klucz << ":" << x->wspolczynnik_rownowagi << " "; 			
		wypisz_drzewo(x->lewy, z);	
	}
}

output(string output)
{
		
}

int main()//powtarza sie 13
{
	AVL_tree *korzen = NULL;
	char wybor;
	int ilosc_wezlow=0, wezel_do_usuniecia_dodania=0;
	long int tablica_wezlow[ilosc_elementow], tablica_wezlow2[ilosc_elementow];
	bool wynik, czy_istnieje_w_tablicy;
	string output;
	fstream plik_wejscie, plik_wyjscie1, plik_wyjscie2;
	plik_wejscie.open("pliczek.txt", ios::in);
	wynik=plik_wejscie.good();
	if(!plik_wejscie.good())
	{
        cout << "Blad otwierania pliku wejsciowego!";
        exit(0);
    }
	
    while(!plik_wejscie.eof())//zapisze dane z pliku do tablicy
    {
    	plik_wejscie >> tablica_wezlow[ilosc_wezlow];
    	ilosc_wezlow++;	
	}

	//for(int i=0; i<ilosc_wezlow; i++)
	for(int i=0; i<ilosc_wezlow; i++)
	{
		for(int j=i+1; j<ilosc_wezlow; j++)
		{
			if(tablica_wezlow[i]==tablica_wezlow[j]) 
				tablica_wezlow[j]=0;
		}	
	}
	cout << "Odczytana zawartosc tablicy: " << endl;
	for(int i = 0; i<ilosc_wezlow; i++) //z tablicy stworz drzewo AVL
	{
		if(tablica_wezlow[i]!=0)
		{
			cout << i << ". " << tablica_wezlow[i] << " " << endl;
	    	dodaj_do_drzewa(korzen, tablica_wezlow[i]);	
		}	    
	}
	cout << endl;
	for(;;)
	{
		cout << "1. Dodaj nowy wezel do drzewa" << endl
			 << "2. Usun wezel z drzewa" << endl
			 << "3. Wyswietl stan drzewa" << endl
			 << "4. Zakoncz dzialanie programu" << endl
			 << "Wybor: ";			 
		wybor=getch();
		
	    switch(wybor)
		{
			case '1'://dodaj wezel
			{
				wezel_do_usuniecia_dodania = 0;
				czy_istnieje_w_tablicy=false;
				cout << "Podaj wartosc wezla ktory chcesz dodac: ";
				cin >> wezel_do_usuniecia_dodania;
				
				//cout << ilosc_wezlow << tablica_wezlow[ilosc_wezlow] << endl;
				 
				for(int i = 0; i<ilosc_wezlow; i++)
				{
					if(wezel_do_usuniecia_dodania==tablica_wezlow[i])
						czy_istnieje_w_tablicy=true;	
				}
				
				if(czy_istnieje_w_tablicy==true)
				{
					cout << "Podana wartosc zawiera sie w tablicy, dlatego nie mozna jej dodac";
					getchar();
					break;
				}
				else
				{
					cout << "Podana wartosc nie zawiera sie w tablicy - mozna ja dodac";
					dodaj_do_drzewa(korzen, wezel_do_usuniecia_dodania);
					tablica_wezlow[ilosc_wezlow] = wezel_do_usuniecia_dodania;
					ilosc_wezlow++;
					break;
				}
			}
			
			case '2'://usun wezel
			{
				wezel_do_usuniecia_dodania = 0;
				czy_istnieje_w_tablicy=false;
				cout << "Podaj wartosc wezla ktory chcesz usunac: ";
				cin >> wezel_do_usuniecia_dodania;
				
				for(int i = 0; i<ilosc_wezlow; i++)
				{
					if(wezel_do_usuniecia_dodania==tablica_wezlow[i])
						czy_istnieje_w_tablicy=true;	
				}
				
				if(czy_istnieje_w_tablicy==true)
				{
					cout << "Podana wartosc zawiera sie w tablicy";
					//znajdz_element(korzen,tablica_wezlow[i]);
					//usun_z_drzewa(korzen, znajdz_element(korzen,tablica_wezlow[i]))
					break;
				}
				else
				{
					cout << "Podana wartosc nie zawiera sie w tablicy";
					getchar();
					break;
				}
			}
			
			case '3'://wypisz drzewo
			{
				R1.open("R1.txt", ios::out);
				R2.open("R2.txt", ios::out);
				R3.open("R3.txt", ios::out);
				R4.open("R4.txt", ios::out);
				R5.open("R5.txt", ios::out);
				cout << "\nStan drzewa(od prawej do lewej): " << endl;
				int z = 0;
				wypisz_drzewo(korzen, z);
				R1.close();
				R2.close();
				R3.close();
				R4.close();
				R5.close();
				
				R1.open("R1.txt", ios::in);
				R2.open("R2.txt", ios::in);
				R3.open("R3.txt", ios::in);
				R4.open("R4.txt", ios::in);
				R5.open("R5.txt", ios::in);
				getline(R1, output);
				cout << "Poziom 1: " << output << endl;
				getline(R2, output);
				cout << "Poziom 2: " << output << endl;
				getline(R3, output);
				cout << "Poziom 3: " << output << endl;	
				getline(R4, output);
				cout << "Poziom 4: " << output << endl;
				getline(R5, output);
				cout << "Poziom 5: " << output << endl;
				R1.close();
				R2.close();
				R3.close();
				R4.close();
				R5.close();
				remove("R1.txt");
				remove("R2.txt");
				remove("R3.txt");
				remove("R4.txt");
				remove("R5.txt");
				
				
				break;
			}
			
			case '4'://zamknij i zapisz
			{	
				plik_wyjscie1.open("tree_save.txt", ios::out);
				plik_wyjscie2.open("tree_wyj.txt", ios::out);
				for(int i = 0; i<ilosc_wezlow; i++) //zapisz wartosci do wyjscia3
				{
				    plik_wyjscie1 << tablica_wezlow[i] << endl;
				}
				
				R1.open("R1.txt", ios::out);
				R2.open("R2.txt", ios::out);
				R3.open("R3.txt", ios::out);
				R4.open("R4.txt", ios::out);
				R5.open("R5.txt", ios::out);
				int z = 0;
				wypisz_drzewo(korzen, z);
				R1.close();
				R2.close();
				R3.close();
				R4.close();
				R5.close();
				
				R1.open("R1.txt", ios::in);
				R2.open("R2.txt", ios::in);
				R3.open("R3.txt", ios::in);
				R4.open("R4.txt", ios::in);
				R5.open("R5.txt", ios::in);
				
				
				//tutaj zrobic getlina
				plik_wyjscie2 << R1 << endl;
				plik_wyjscie2 << R2 << endl;
				plik_wyjscie2 << R3 << endl;
				plik_wyjscie2 << R4 << endl;
				plik_wyjscie2 << R5 << endl;
	
				R1.close();
				R2.close();
				R3.close();
				R4.close();
				R5.close();
				remove("R1.txt");
				remove("R2.txt");
				remove("R3.txt");
				remove("R4.txt");
				remove("R5.txt");
				cout << "Koniec programu. Wartosci zostaly zapisane w pliku tree_wyj_wartosci.txt, natomiast stan drzewa w tree_wyj_avl.txt" << endl;
				plik_wyjscie1.close();
				plik_wyjscie2.close();
			
                exit(0);
			}
			case '5': //testowy
			{	
				cout << endl;
				for(int i = 0; i<ilosc_wezlow; i++) //z tablicy stworz drzewo AVL
				{
					if(tablica_wezlow[i]!=0)
					{
						cout << i << ". " << tablica_wezlow[i] << " " << endl;
					}	    
				}
				getche();
				break;
				
			}
			default: cout << "Nie ma takiej opcji w menu";
		}
		getchar();
	    system("cls");
	}
	plik_wyjscie.close();
	return 0;	
}
//for(int i=0; i<ilosc_wezlow; i++)//z danych z tablicy stworz drzewo AVL
	 // {
	    //cout << Tk[i] << " ";
	    //dodaj_drzewo(korzen,tablica_wezlow[i]);
	 // }
	//tablica_wezlow[0]=tablica_wezlow[0];
	/*cout << endl;
	int ilosc_wezlow_bez_powtorzen=1;
	for(int i=0; i<ilosc_wezlow; i++)
	{
		x=0;
		for(int j=0; j<ilosc_wezlow_bez_powtorzen; j++)
		{
			if(tablica_wezlow[i]==tablica_wezlow_bez_powtorzen[j])
			{
				x=1;	
			}
			if(x==0)
			{
				tablica_wezlow_bez_powtorzen[ilosc_wezlow_bez_powtorzen]=tablica_wezlow[i];
				ilosc_wezlow_bez_powtorzen++;
			}	
		}
		cout << "2." << ilosc_wezlow_bez_powtorzen << ": " << tablica_wezlow_bez_powtorzen[ilosc_wezlow_bez_powtorzen] << endl;
	}*/

/*void wypisz_drzewo2(string sp, string sn, AVL_tree * v)
{
	string element_drzewa;

	if(x)
	{
		element_drzewa = sp;
		if(sn == cr) 
			element_drzewa[element_drzewa.length() - 2] = ' ';
			
		wypisz_drzewo(s + cp, cr, x->prawy);
		element_drzewa = element_drzewa.substr(0,sp.length()-2);
		cout << element_drzewa << sn << x->klucz << ":" << x->wspolczynnik_rownowagi << endl;
		element_drzewa = sp;
		
		if(sn == cl) 
			element_drzewa[element_drzewa.length() - 2] = ' ';
		wypisz_drzewo(element_drzewa + cp, cl, x->lewy);
		dl;
	}
}*/







//WYPOISZ DRZEWO STARE
/*
if(x)
	{
		z++;	
		wypisz_drzewo(x->prawy, z);
		
		if(z==1)
		{
			cout << "R" << z << ": " << x->klucz << ":" << x->wspolczynnik_rownowagi << " " << endl;
			R1 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";
		}
					
		if(z==2)
		{
			cout << "R" << z << ": " << x->klucz << ":" << x->wspolczynnik_rownowagi << " " << endl;
			R2 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";	
		}
				
		if(z==3)
		{
			cout << "R" << z << ": " << x->klucz << ":" << x->wspolczynnik_rownowagi << " " << endl;
			R3 << x->klucz << ":" << x->wspolczynnik_rownowagi << " "; 
		}
			
		if(z==4)
		{
			cout << "R" << z << ": " << x->klucz << ":" << x->wspolczynnik_rownowagi << " " << endl;
			R4 << x->klucz << ":" << x->wspolczynnik_rownowagi << " ";
			
		}
				
		if(z==5)
		{
			cout << "R" << z << ": " << x->klucz << ":" << x->wspolczynnik_rownowagi << "\t" << endl;
			R5 << x->klucz << ":" << x->wspolczynnik_rownowagi << " "; 	
		}		*/
