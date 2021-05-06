#include <iostream>
#include <numeric>
#include <ctime>
#include <vector>
#include"fonctions.h"


using namespace std;

int main(int argc, char *argv[]){
	srand((int) time(0));
	int som=0;

//for(int cnt=0; cnt<1000; cnt++){
	int q = 3121, m = 7, n = 5;
	
/******KEYGEN*******/
	vector<int> s = initVect(n, q);
	vector<vector<int>> Mat = initMat(m, n, q);
	
	cout<<"A ="<<endl;
	for(int i = 0; i<m; i++){
		for(int k = 0; k<n; k++){
			cout<<Mat[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"s ="<<endl;
	for(int k = 0; k<n; k++){
		cout<<s[k]<<" ";
	}
	cout<<endl<<endl;
	
	vector<int> As = prodMat(Mat, s, m, n, q, 1);
	cout<<"As ="<<endl;
	for(int k = 0; k<m; k++){
		cout<<As[k]<<" ";
	}
	cout<<endl<<endl;
	
	vector<int> e = initVect(m, 5);

	cout<<"e ="<<endl;
	for(int k = 0; k<m; k++){
		cout<<e[k]<<" ";
	}
	cout<<endl<<endl;
	
	vector<int> b(m);
	for(int k = 0; k<m; k++){
		b[k]=((As[k]+e[k])%q);
	}
	cout<<"b ="<<endl;
	for(int k = 0; k<m; k++){
		cout<<b[k]<<" ";
	}
	cout<<endl<<endl;
	
/******CHIFFREMENT********/
	bool message = 0;
	
	vector<int> r = initVect(m, 2);
	cout<<"r ="<<endl;
	for(int k = 0; k<m; k++){
		cout<<r[k]<<" ";
	}
	cout<<endl<<endl;
	
	vector<int> c1 = prodMat(Mat, r, n, m, q, 0);
	cout<<"c1 ="<<endl;
	for(int k = 0; k<n; k++){
		cout<<c1[k]<<" ";
	}
	cout<<endl<<endl;
	
	int rb = prodScal(b, r, m, q);
	cout<<"rb = "<<rb<<endl;
	
	int c2=(q/2*message);
	c2=(c2+rb)%q;
	cout<<"c2 = "<<c2<<endl<<endl;
	
	
	/*********DECHIFFREMENT*********/
	cout<<"Le message est "<<dec(c1, s, c2, n, q)<<endl;
	//som+=(message==dec(c1, s, c2, n, q));

	//cout<<som;
	return 0;
}