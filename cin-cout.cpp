#include <cstdlib>
#include <iostream>

using namespace std;

main()
{
	int suma=0;
	int b;
	int N;
	cout << "Podaj b: " << endl;
	cin >> b;
	cout << "Podaj N: " << endl;
	cin >> N;
	cout << b << endl;
	cout << N << endl;
	
	for(int L=1; L < N; L++)
	{	
		suma=suma+b;
	}
	cout << "Suma:" << suma << endl;
	return 0;
}
//zaimentuj algorytym obliczajacy sume N - kolejnych liczb naturlanych
//Pierwsza z liczb wprowadzona z klawiatury i równaa sie b;
