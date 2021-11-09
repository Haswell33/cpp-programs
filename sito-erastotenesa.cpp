#include <iostream>
#include <fstream>
#include <cstdlib>
//liczby pierwsze

using namespace std;

typedef struct lista_pierwsze
{
	int data;
	struct lista_pierwsze *next;	
}l_p;

l_p* create_list(int n)
{
	l_p *nowy, *head = NULL;
	for(int i=n; i>1; i--)
	{
		nowy = (l_p*)malloc(sizeof(l_p));
		nowy->data = i;
		nowy->next = head;
		head = nowy;
	}
	return head;
}

void sito_eratostensa(l_p *head)
{
	l_p *x = head, *y, *z;
	int i;
	while(x)
	{
		
		i = x->data;
		//cout << data%i << endl;
		y = x;
		z = x->next;
		
		while(z)
		{
			if(!(z -> data%i))
			{
				y->next = z->next;
				free(z);
				z = y->next;	
			}
			else
			{
				y = z;
				z = y->next;
			}
		}	
		x = x->next;	
	}	
}

void save_to_file(l_p* head, int n)
{
	fstream file;
	file.open("pierwsze.txt", ios::out);
	file << "Liczby pierwsze z zakresu (2..." << n << "): " << endl;
	if(head==NULL)
	{
		return;
	}
	while(head)
	{
		file << head->data << endl;
		head = head->next;
	}	
	if(file.good() == true)
	{
		file.close();
	}	
}

int main()
{
	int n=0;
	l_p *head=NULL;
	cout << "Okres gorny zbioru: ";
	while(!(cin >> n)) 
	{
	    cout << "Dana liczba musi byc w systemie dziesietnym oraz wieksza od 1: ";
	    cin.clear(); 
	    cin.sync(); 
	}
	head = create_list(n);
	sito_eratostensa(head);
	save_to_file(head, n);
	return 0;
}
