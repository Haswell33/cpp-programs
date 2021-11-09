#include <iostream>

using namespace std;

class Towar{
	private:
		string nazwa_towaru;
		int ilosc;
		double cena;
		bool czy_kupione;
		Towar *next;	
	Towar();
	~Towar();
	friend void dodaj(string nazwa_towaru, int ilosc, double cena);
	//friend void dodaj(string nazwa_towaru, int ilosc, double cena)
	//friend void wypisz();
};
Towar::Towar(){
    next = 0;
    czy_kupione = false;
}
class Lista{
	public:
		Towar *head;
		Lista();
		~Lista();
		
		//void dodaj(string nazwa_towaru, int ilosc, double cena);
		void wypisz();
};
Lista::Lista(){
	head = 0;
}
void dodaj(string nazwa_towaru, int ilosc, double cena){
	Towar *nowy_produkt = new Towar;

    nowy_produkt->nazwa_towaru = nazwa_towaru;
    nowy_produkt->ilosc = ilosc;
    nowy_produkt->cena = cena;
	
    if(head==0)
        head = nowy_produkt;
    else{
        Towar *temp = head;

        while(temp->next)
            temp = temp->next;
        temp->next = nowy_produkt;  
        nowy_produkt->next = 0;     
	}
}
void Lista::wypisz(){
    Towar *temp = head;
    int i = 1;
    while(temp){
        cout << i << ". " << "Nazwa towaru: " << temp->nazwa_towaru << endl << "Ilosc: " << temp->ilosc << endl << "Cena: " << temp->cena << endl << "Czy zostal zakupiony: ";
        if(temp->czy_kupione == false)
        	cout << "Nie";
		
		else cout << "Tak";
		temp = temp->next;
        i++;
        cout << endl;
    }
}

int main(){
	Lista *towar = new Lista;
	string m_nazwa_produktu;
	int m_ilosc_produktu;
	double m_cena;
	towar->dodaj("jajka", 3, 23.5);

	
	cout << "Nazwa produktu: ";
	cin >> m_nazwa_produktu;
	cout << "Ilosc produktu: ";
	cin >> m_ilosc_produktu;
	cout << "Cena produktu: ";
	cin >> m_cena;
    towar->dodaj(m_nazwa_produktu, m_ilosc_produktu, m_cena);
    towar->wypisz();
	
	return 0;	
}
