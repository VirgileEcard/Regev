#include "fonctions.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> initVect(int n, int q){
	vector<int>s(n);
	for(int k = 0; k<n; k++){
		s[k]=(rand()%q);
	}
	
	return s;
}

vector<vector<int>> initMat(int m, int n, int q){
	vector<vector<int>> Mat(m, vector<int> (m, 0));
	
	for(int i = 0; i<m; i++){
		for(int k = 0; k<n; k++){
			Mat[i][k]=(rand()%q);
		}
	}
	return Mat;
}

vector<int> prodMat(vector<vector<int>>Mat, vector<int> s, int m, int n, int q, bool prem){
	vector<int>As(m);
	for(int i = 0; i<m; i++){
		int ps=0;
		for(int k = 0; k<n; k++){
			if(prem){ps+=((Mat[i][k]*s[k])%q);}
			else {ps+=((Mat[k][i]*s[k])%q);}
		}
		As[i]=ps%q;
	}
	
	return As;
}

int prodScal (vector<int> b, vector<int> r, int m, int q){
	int ps=0;
	for(int k = 0; k<m; k++){
		ps+=((b[k]*r[k])%q);
	}
	return ps%q;

}

bool dec(vector<int> c1, vector<int> s, int c2, int n, int q){
	int res=prodScal(c1, s, n, q);
	
	/*cout<<res<<endl;*/
	
	res = c2-res;
	if(res<0) res+=q;
	
	/*cout<<res<<endl;*/
	
	return (res>(q/4));
}