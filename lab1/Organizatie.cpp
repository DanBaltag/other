#include <iostream>

#include <fstream>
using namespace std;

class Organizatie{
	private:
		string denumirea, adresa, numele_directorului;
		int nr_angajati;
	public:
		void citire(){
			cout<<"denumirea:";cin>>denumirea;
			cout<<"adresa:";cin>>adresa;
			cout<<"numele_directorului:";cin>>numele_directorului;
			cout<<"nr_angajati:";cin>>nr_angajati;
		}
		void afisare(){
			cout<<endl;
			cout<<"denumirea: "<<denumirea<<endl;
			cout<<"adresa: "<<adresa<<endl;
			cout<<"numele_directorului: "<<numele_directorului<<endl;
			cout<<"nr_angajati: "<<nr_angajati<<endl;
			cout<<endl;
		}
		int get_angajati(){
			return nr_angajati;
		}
		string get_denumirea(){
			return denumirea;
		}
		string get_adresa(){
			return adresa;
		}
		void scrie_fisier(){
			ofstream f("Organizatie.txt", ofstream::out | ofstream::app);
			f<<denumirea<<"\n";
			f<<adresa<<"\n";
			f<<numele_directorului<<"\n";
			f<<nr_angajati<<"\n";
			f.close();
		}
		void citeste_fisier(int n){
			ifstream f("Organizatie.txt");
			string mat[4*n];
			if (!f.is_open()){
					cerr<<"eroare la deschiderea fisierului\n";
					return;
			}
			for(int i=0;i<n*4;i++)
				f >> mat[i];
			for(int i=n*4-4;i<n*4;i++)
				cout<<mat[i]<<endl;
			f.close();
		}
};

void sort(int n, Organizatie tab[]){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(tab[i].get_angajati()<tab[j].get_angajati()){
				Organizatie aux = tab[i];
				tab[i] = tab[j];
				tab[j] = aux;
			}
}

void afis_custom(int n, Organizatie tab[]){
	for(int i=0;i<n;i++)
		if(tab[i].get_denumirea() != "")
			tab[i].afisare();
}

void adaugare(int* n, Organizatie tab[]){
	if(*n >= 10) return;
	*n+=1;
	int i;
	for(i=*n-1;i>0;i--)
		tab[i] = tab[i-1];
	tab[i].citire();
}

void mod(int n, Organizatie tab[]){
	string x;
	cout<<"dati adresa:";cin>>x;
	for(int i=0;i<n;i++)
		if(tab[i].get_adresa() == x)
			tab[i].citire();
}

void s_fisier(int n, Organizatie tab[]){
	for(int i=0;i<n;i++)
		tab[i].scrie_fisier();
}
void c_fisier(int n,Organizatie tab[]){
	tab[0].citeste_fisier(n);
}

void c1(int *n, Organizatie t[]){
	cout<<"nr elemente:";cin>>*n;
	for(int i;i<*n;i++)
		t[i].citire();
}

void c2(int n, Organizatie t[]){
	for(int i;i<n;i++)
		t[i].afisare();
}

int main(){
	int c, n;
	Organizatie t[10];
	do{
		cout<<"1:citirea elementelor\n2:afisarea elementelor\n3:sortarea elementelor\n4:afisarea elementelor pentru care se stie denumirea\n5:adaugarea pe I pozitie a unui element nou\n6:modificarea elementelor pentru o adresa data\n7:scrierea in fisier\n8:afisarea ultimului element din fisier\n"; cin>>c;
		switch(c){
			case 1: c1(&n,t); break;
			case 2: c2(n,t); break;
			case 3: sort(n,t); break;
			case 4: afis_custom(n,t); break;
			case 5: adaugare(&n,t); break;
			case 6: mod(n,t); break;
			case 7: s_fisier(n,t); break;
			case 8: c_fisier(n,t); break;
		}
	}while(c>0&&c<8);
}
