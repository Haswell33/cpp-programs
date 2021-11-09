/*Karol Siedlaczek I8X1N1
LAB 3.4
Zmodyfikuj program 3.3 tak, aby z klasy BankAccount zrobiæ klasê wirtualn¹, oraz utworzyæ now¹ klasê BankAccountNormal dziedzicz¹c¹ po niej, a w klasie BankAccountVIP dodaæ:
	pole typu double - Max_limit, (nieprzekraczalny limit)
	pole typu double - procent (do obliczenia zad³u¿enia debet)
	napisaæ metody wirtualne tych klas.
	napisaæ settery do ww. pól.*/
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

		virtual void dodaj_saldo();
		virtual bool odejmij_saldo();
		virtual void wyswietl_rachunek();
		
		void setter_nazwa_posiadacza_rachunku();
		void setter_nazwa_rachunku();
		void setter_numer_rachunku();
		void setter_saldo_rachunku();
};

class BankAccountVIP:public BankAccount{
	private:
		double debet,
		       max_limit, //max limit, ale czego, debetu?
		       procent;
			
	public:
		BankAccountVIP(string k_nazwa_posiadacza_rachunku = "", string k_nazwa_rachunku = "", string k_numer_rachunku = "")
		:BankAccount(k_nazwa_posiadacza_rachunku, k_nazwa_rachunku, k_numer_rachunku){
			debet = 0;
			max_limit = -100;
		}
		
		BankAccountVIP(const BankAccountVIP &k_kopia_nazwa_posiadacza_rachunku, const BankAccountVIP &k_kopia_nazwa_rachunku, const BankAccountVIP &k_kopia_numer_rachunku, const BankAccountVIP &k_kopia_saldo_rachunku, const BankAccountVIP &k_kopia_debet)
		:BankAccount(k_kopia_nazwa_posiadacza_rachunku, k_kopia_nazwa_rachunku, k_kopia_numer_rachunku, k_kopia_saldo_rachunku){//konstruktor kopiujacy
			debet = k_kopia_debet.debet;
		}
	
		~BankAccountVIP(){};
		
		//void dodaj_saldo();
		virtual bool odejmij_saldo();
		virtual void wyswietl_rachunek();
		
		void setter_debet();
		void setter_max_limit();
		void setter_procent();
};

class BankAccountNormal:public BankAccount{
	private:
		
	public:
		BankAccountNormal(string k_nazwa_posiadacza_rachunku = "", string k_nazwa_rachunku = "", string k_numer_rachunku = "")
		:BankAccount(k_nazwa_posiadacza_rachunku, k_nazwa_rachunku, k_numer_rachunku){
		}
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

void BankAccount::setter_nazwa_posiadacza_rachunku(){
	string zmienna;
	cout << ": ";
	cin >> zmienna;
	nazwa_posiadacza_rachunku = zmienna;
}

void BankAccount::setter_nazwa_rachunku(){
	string zmienna;
	cout << ": ";
	cin >> zmienna;
	nazwa_rachunku = zmienna;
}

void BankAccount::setter_numer_rachunku(){
	string zmienna;
	cout << ": ";
	cin >> zmienna;
	numer_rachunku = zmienna;
}

void BankAccount::setter_saldo_rachunku(){
	double zmienna = 0;
	cout << ": ";
	cin >> zmienna;
	saldo_rachunku = zmienna;
}

/*%%%%%%%%%%%%%%%%%%%%funkcje VIP%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

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
		if((debet - kwota_odejmij) >= max_limit){
			debet = debet - kwota_odejmij; 
			return true;
		}
		else cout << "Kwota wykracza poza maksymalny limit debetu" << endl;
	}
}
void BankAccountVIP::wyswietl_rachunek(){
	procent = (debet/max_limit) * 100;
	if(procent < 0)
		procent = procent * -1;
	cout << "(VIP) ";
	BankAccount::wyswietl_rachunek();
	cout << "\tDebet: " << debet << " PLN" << endl
	     << "\tProcent debetu: " << procent << "%" << endl;
}

void BankAccountVIP::setter_debet(){
	double zmienna = 0;
	cout << ": ";
	cin >> zmienna;
	debet = zmienna;
}

void BankAccountVIP::setter_max_limit(){
	double zmienna = 0;
	cout << ": ";
	cin >> zmienna;
	max_limit = zmienna;
}

void BankAccountVIP::setter_procent(){
	double zmienna;
	cout << ": ";
	cin >> zmienna;
	procent = zmienna;
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
	
	BankAccountVIP konto_1_VIP("Jan Nowak", "VIP Konto", "0000 1111 2222 3333 4444 5555 6666");
	
	BankAccountVIP konto_2_VIP = konto_1_VIP;
	
	konto_1_VIP.odejmij_saldo();
	konto_1_VIP.wyswietl_rachunek();
	
	konto_2_VIP.wyswietl_rachunek();
	konto_2_VIP.setter_nazwa_posiadacza_rachunku();
	konto_2_VIP.wyswietl_rachunek();
	return 0;
}
