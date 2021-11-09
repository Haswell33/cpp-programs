/*Karol Siedlaczek I8X1N1 
ZAD 2.8
Napisz klas� Lista s�u��c� do przechowywania listy zakup�w. Poszczeg�lne pozycje listy maj� si� sk�ada� z element�w nazwy towaru, ilo�ci w jakiej planujemy go zakupi�, 
ceny oraz informacje czy uda�o si� go ju� kupi�. Lista powinna udost�pnia� nasepujace publiczne metody: 
	bezargumentowy konstruktor tworz�cy pust� list� 
	konstruktor kopiuj�cy 
	destruktor 
	dodaj 
	otrzymuj�c� w arugmentach nazw� towaru, ilo�� i cen� tego towaru jak� chcemy zakupi� i dodaj�ca te informacje do przechowywanej listy zakup�w
	wypisz() - wypisuj�ca ana standardowym wyj�ciu wszystkie elementy listy
	usun() - usuwaj�ca z listy towar podany w argumencie
	wyczysc() - usuwajaca wszystkie elementy listy */
#include <iostream>

using namespace std;

class Lista{
	private:
		string nazwa_towaru;
		int ilosc;
		double cena;
		bool czy_kupione;
		Lista *next;
		Lista *head;
		
	public:		
		Lista(){//konstrutkor bezarugmentowy (pusta lista)
		    next = NULL;
		    head = NULL;
		    czy_kupione = false;
		}
		Lista(const Lista &next_kopiowane, const Lista &head_kopiowane, const Lista &czy_kupione_kopiowane){//konstrktor kopiujacy
			next = next_kopiowane.next;
			head = head_kopiowane.head;
			
			//nazwa_towaru = nazwa_towaru_kopiowane.nazwa_towaru;
			//ilosc = ilosc_kopiowane.ilosc;
			//cena = cena_kopiowane.cena;
			//czy_kupione = czy_kupione_kopiowane.czy_kupione;
		}
		
		~Lista();//destruktor
		friend void dodaj(Lista *&head, string nazwa_towaru, int ilosc, double cena);
		friend void wypisz(Lista *&head);
		friend void usun(Lista *&head);
		friend void wyczysc(Lista *&head);
};

void dodaj(Lista *&head, string nazwa_towaru, int ilosc, double cena){
	Lista *nowy_produkt = new Lista;
    nowy_produkt->nazwa_towaru = nazwa_towaru;
    nowy_produkt->ilosc = ilosc;
    nowy_produkt->cena = cena;
	
    if(head == 0)
        head = nowy_produkt;
    else{
        Lista *temp = head;

        while(temp->next)
            temp = temp->next;
        temp->next = nowy_produkt;  
        nowy_produkt->next = 0;     
	}
}
void wypisz(Lista *&head){
    Lista *temp = head;
    int i = 1;
    
    while(temp){
        cout << i << ". " 
			 << "Nazwa towaru: " << temp->nazwa_towaru << endl 
			 << "\tIlosc: " << temp->ilosc  << " szt." << endl 
			 << "\tCena: " << temp->cena << " PLN" << endl 
			 << "\tCzy zostal zakupiony: ";
        if(temp->czy_kupione == false)
        	cout << "Nie" << endl;
		else cout << "Tak" << endl;
		temp = temp->next;
        i++;
    }
}

void usun(Lista *&head){
	int element_listy = 0;
    cout << "Ktory element listy chcesz usunac? (podaj nr)";
    cin >> element_listy;
    if(element_listy == 1){
        Lista *temp = head;
        head = temp->next;
    }

    if(element_listy >= 2){
        int j = 1;
        Lista *temp = head;

        while(temp){
            if((j+1) == element_listy) 
				break;

            temp = temp->next;
            j++;
        }
        
        if(temp->next->next == 0)
            temp->next = 0;
        else
            temp->next = temp->next->next;
    }
}

/*void wyczysc(Lista *&head){
	delete head;

}*/

int main(){
	Lista *X = NULL;
	string m_nazwa_produktu;
	int m_ilosc_produktu;
	double m_cena;
	dodaj(X, "jajka", 3, 4.99);
	
	cout << "Nazwa produktu: ";
	cin >> m_nazwa_produktu;
	cout << "Ilosc produktu: ";
	cin >> m_ilosc_produktu;
	cout << "Cena produktu: ";
	cin >> m_cena;
    dodaj(X, m_nazwa_produktu, m_ilosc_produktu, m_cena);
    wypisz(X);
    usun(X);
    //wyczysc(X);
    wypisz(X);

	return 0;	
}
