#include <iostream>

using namespace std;

int main()
{
        long int tablica[100], duplikaty[100];
        int n,e=0;
        cout << "Ile liczb? ";
        cin >> n;
        int ile=0;
        for(int i=0; i<n; i++)
        {
                cout << "Podaj liczbe numer " << i+1 << ": ";
                cin >> e;
                tablica[i]=e;
        }
        cout << endl << "Tablica przed usunieciem duplikatow: ";
        for(int j=0; j<n; j++)
        {
                cout << tablica[j] << ",";
        }
        cout << endl;
        for(int k=0; k<n; k++)
        {
                for(int l=k; l<n; l++)
                {
                        if((tablica[k]==tablica[l]) && (l<=n) && (k!=l))
                        {
                                if(tablica[k]==tablica[l]) 
                                {
                                        duplikaty[k]=0;
                                }
                        }
                }
        }
        cout << endl << "Tablica po usunieciu duplikatow: ";
        for(int o=0; o<n; o++)
        {
                if(duplikaty[o]!=0)
                cout << tablica[o] << ",";
        }
        cout << endl;
        system("pause");
        return 0;
}
