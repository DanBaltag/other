#include <iostream>
using namespace std;

class Arie{
	protected:
		double S;
	public:
		virtual double get_arie() = 0;
};
class Patrat:public Arie{
	protected:
		double l;
	public:
		Patrat(){
			Arie::S = 1;
		}
		Patrat(double l){
			Arie::S = l*l;
		}
		double get_arie(){
			return Arie::S;
		}
};
class Dreptunghi:public Arie{
	public:
		Dreptunghi(){
			Arie::S = 1;
		}
		Dreptunghi(double l1, double l2){
			Arie::S = l1*l2;
		}
		double get_arie(){
			return Arie::S;
		}
};

Arie* tip(){
	int c;
	Arie* aux;
	cout<<"alegeti tipul clasei:\n1:Patrat\n2:Dreptunghi\n";cin>>c;
	switch(c){
		case 1:
			double l;
			cout<<"dati latura "; cin>>l;
			if (l) return (aux = new Patrat(l));
			else return (aux = new Patrat);
		case 2:
			double l1, l2;
			cout<<"dati latura 1 "; cin>>l1;
			cout<<"dati latura 2 "; cin>>l2;
			if (l1>0 && l2>0) return (aux = new Dreptunghi(l1,l2));
			else return (aux = new Patrat);
		default:
			break;
	}
}

void afis(int n, Arie* a[]){
	for (int i=0;i<n;i++)
		cout<<i<<":"<<a[i]->get_arie()<<endl;
	cout<<endl;
}

double maxim(Arie *a, Arie *b){
	if (a->get_arie() > b->get_arie())
		return a->get_arie();
	else return b->get_arie();
}

double minim(Arie *a, Arie *b){
	if (a->get_arie() < b->get_arie())
		return a->get_arie();
	else return b->get_arie();
}

void comp(int n, Arie* a[]){
	cout<<"alegeti elementele pentru a fi comparate:\n";
	afis(n,a);
	int c, e1, e2; cin>>e1; cin>>e2;
	cout<<"alegeti operatia de comparare:\n1:maxim\n2:minim\n";cin>>c;
	switch(c){
		case 1: cout<<maxim(a[e1],a[e2]); break;
		case 2: cout<<minim(a[e1],a[e2]); break;
		default:break;
	}
}

int main(){
	int n;
	cout<<"dati nr elemente:";cin>>n;
	Arie *a[n];
	for (int i=0;i<n;i++){
		a[i] = tip();
	}
	for (int i=0;i<n;i++){
		cout<<a[i]->get_arie()<<endl;
	}
	//comp(n,a);
} 
