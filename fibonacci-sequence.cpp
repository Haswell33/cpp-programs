#include <cstdlib>
#include <iostream>

using namespace std;

main()
{
	double tab[100];
	int x=1;
	tab[0]=1;
	tab[1]=1;
	int n=2;
	
	//for
	for(n=2; n!=100; n++)
	{
		tab[n]=tab[n-1]+tab[n-2];	
	}

	//wypisywanie
	for(int n=0; n!=100; n++)
	{
		cout << x << ". " << tab[n] << endl;
		x++;
	}
	return 0;
}
