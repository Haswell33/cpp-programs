/*Karol Siedlaczek I8X1N1 
ZAD 3.3
Napisz deklaracj� i definicj� klasy BankAccount, klasa powinna posiada�:
	prywatne pole typu string - nazwa posiadacza rachunku
	prywatne pole typu string � nazw� rachunku,
	prywatne pole typu string � numer rachunku,
	prywatne pole typu double � saldo rachunku,
	publiczny konstruktor inicjalizuj�cy atrybuty klasy, parametr inicjalizuj�cy saldo rachunku powinien posiada� warto�� domy�ln� r�wn� zero,
	publiczny konstruktor kopiuj�cy,
	publiczny destruktor zwalniaj�cy pami�� przydzielon� dynamicznie,
	publiczn� metod�, dodaj�c� do konta przekazan� kwot�,
	publiczn� metod�, podejmuj�c� z konta przekazan� kwot� oraz zwracaj�c� warto�� logiczn�, je�li przekazana kwota jest wi�ksza od salda rachunku, metoda powinna zwr�ci� logiczny fa�sz, w przeciwnym razie logiczn� prawd�,
	publiczn� metod� wy�wietlaj�c� wszystkie informacje o rachunku.

Dodatkowo napisz deklaracj� i definicj� klasy BankAccountVIP, kt�ra b�dzie dziedziczy� po klasie BankAccount oraz zawiera�:
	prywatne pole typu double � debet,
	publiczny konstruktor inicjalizuj�cy,
	publiczny konstruktor kopiuj�cy,
	publiczn� metod�, podejmuj�c� z konta przekazan� kwot� o podobnej funkcjonalno�ci jak ta z klasy bazowej z tym �e musi istnie� mo�liwo�� powstania debetu,
	publiczn� metod� wy�wietlaj�c� wszystkie informacje o rachunku VIP.
	Napisz funkcj� main testuj�c� wymienione klasy. */
#include <iostream>

using namespace std;

double kwota_odejmij = 0;

class BankAccount{
	private:
		string nazwa_posiadacza_rachunku, 
			   nazwa_rachunku, 
			   numer_rachunku;
		double saldo_rachunku;
	
	public:
		BankAccount(string k_nazwa_posiadacza_rachunku = "", string k_nazwa_rachunku = "", string k_numer_rachunku = ""){//konstruktor inicjalizujacy
			nazwa_posiadacza_rachunku = k_nazwa_posiadacza_rachunku;
			nazwa_rachunku = k_nazwa_rachunku;
			numer_rachunku = k_numer_rachunku;
			saldo_rachunku = 0;
		}
		
		BankAccount(const BankAccount &k_kopia_nazwa_posiadacza_rachunku, const BankAccount &k_kopia_nazwa_rachunku, const BankAccount &k_kopia_numer_rachunku, const BankAccount &k_kopia_saldo_rachunku){//konstruktor kopiujacy
			nazwa_posiadacza_rachunku = k_kopia_nazwa_posiadacza_rachunku.nazwa_posiadacza_rachunku;
			nazwa_rachunku = k_kopia_nazwa_rachunku.nazwa_rachunku;
			numer_rachunku = k_kopia_numer_rachunku.numer_rachunku;
			saldo_rachunku = k_kopia_saldo_rachunku.saldo_rachunku;
		}
		
		~BankAccount(){};

		void dodaj_saldo();
		virtual bool odejmij_saldo();
		void wyswietl_rachunek();
};

class BankAccountVIP:public BankAccount{
	private:
		double debet;
		
	public:
		BankAccountVIP(string k_nazwa_posiadacza_rachunku = "", string k_nazwa_rachunku = "", string k_numer_rachunku = "")
		:BankAccount(k_nazwa_posiadacza_rachunku, k_nazwa_rachunku, k_numer_rachunku){
			debet = 0;
		}
		
		BankAccountVIP(const BankAccountVIP &k_kopia_nazwa_posiadacza_rachunku, const BankAccountVIP &k_kopia_nazwa_rachunku, const BankAccountVIP &k_kopia_numer_rachunku, const BankAccountVIP &k_kopia_saldo_rachunku, const BankAccountVIP &k_kopia_debet)
		:BankAccount(k_kopia_nazwa_posiadacza_rachunku, k_kopia_nazwa_rachunku, k_kopia_numer_rachunku, k_kopia_saldo_rachunku){//konstruktor kopiujacy
			debet = k_kopia_debet.debet;
		}
	
		~BankAccountVIP(){};
		
		//void dodaj_saldo();
		bool odejmij_saldo();
		virtual void wyswietl_rachunek();
};

void BankAccount::dodaj_saldo(){
	double kwota_dodaj;
	cout << "Podaj kwote do dodania: ";
	cin >> kwota_dodaj;
	saldo_rachunku = saldo_rachunku + kwota_dodaj;
}

bool BankAccount::odejmij_saldo(){
	cout << "Podaj kwote do odjecia: ";
	cin >> kwota_odejmij;
	if(kwota_odejmij > saldo_rachunku)
		return false;
	else{
		saldo_rachunku = saldo_rachunku - kwota_odejmij;
		return true;
	}		
}

void BankAccount::wyswietl_rachunek(){
	cout << "Informacje o rachunku:" << endl 
		 << "\tNazwa posiadacza: " << nazwa_posiadacza_rachunku << endl 
		 << "\tNazwa rachunku: " << nazwa_rachunku << endl
		 << "\tNumer rachunku: " << numer_rachunku << endl 
		 << "\tSaldo rachunku: " << saldo_rachunku << " PLN" << endl;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*void BankAccountVIP::dodaj_saldo(){
	double kwota_dodaj;
	cout << "Podaj kwote do dodania (VIP): ";
	cin >> kwota_dodaj;
	saldo_rachunku = saldo_rachunku + kwota_dodaj;
	if(saldo_rachunku >= 0)
		debet = 0;
}*/

bool BankAccountVIP::odejmij_saldo(){
	if(!BankAccount::odejmij_saldo()){ 
		debet = debet - kwota_odejmij; 
		return true;
	}
}
void BankAccountVIP::wyswietl_rachunek(){
	cout << "(VIP) ";
	BankAccount::wyswietl_rachunek();
	cout << "\tDebet: " << debet << " PLN" << endl;
}
int main(){
	string main_nazwa_posiadacza_rachunku, 
		   main_nazwa_rachunku, 
		   main_numer_rachunku;
		   
	BankAccount konto_1("Adam Kowalski", "Konto Student 360", "11 2222 3333 4444 5555 6666 7777");

	/*cout << "Podaj nazwe posiadacza rachunku: ";
	cin >> main_nazwa_posiadacza_rachunku;
	cout  << "Podaj nazwe rachunku: ";
	cin >> main_nazwa_rachunku;
	cout  << "Podaj nr rachunku: ";
	cin >> main_numer_rachunku;
	BankAccount konto_2(main_nazwa_posiadacza_rachunku, main_nazwa_rachunku, main_numer_rachunku);*/
	
	konto_1.dodaj_saldo();
	BankAccount konto_3 = konto_1;//uzycie konstruktora kopiujacego
	konto_1.odejmij_saldo();
	konto_1.wyswietl_rachunek();
	konto_3.wyswietl_rachunek();
	
	BankAccountVIP konto_1_VIP("Jan Nowak", "VIP konto", "0000 1111 2222 3333 4444 5555 6666");
	
	BankAccountVIP konto_2_VIP = konto_1_VIP;
	
	konto_1_VIP.odejmij_saldo();
	konto_1_VIP.wyswietl_rachunek();
	
	konto_2_VIP.wyswietl_rachunek();
	return 0;
}
