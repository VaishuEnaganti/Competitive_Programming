#include <vector>
#include <iostream>

using namespace std;

// Declarations at the top
int getmax(const vector<int>& A, int N);
int getsum(const vector<int>& A, int N);
int getrequiredworkers(const vector<int>& A, int N, int mlp);
int partition(const vector<int>& A, int N, int K);
int workpartioning(int N, int K);
