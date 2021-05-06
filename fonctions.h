#ifndef __FONCTIONS_H
#define __FONCTIONS_H


#include <vector>
using namespace std;


vector<vector<int>> initMat(int m, int n, int q);

vector<int> initVect(int n, int q);

vector<int> prodMat(vector<vector<int>>Mat, vector<int> s, int m, int n, int q, bool prem);

int prodScal (vector<int> b, vector<int> r, int m, int q);

bool dec(vector<int> c1, vector<int> s, int c2, int n, int q);

#endif