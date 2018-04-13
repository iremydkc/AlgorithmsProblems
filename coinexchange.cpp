/*
    this small program's goal is to solve money exchange problem.
    We have three input variable.How many unit number of coins you have, what
    is the set of coins and what is exchanged amount of money.

*/

#include <iostream>

using namespace std;

#define INF 999

void coinChange(int d[], int C[], int S[], int N, int A) {
	int i, p, min, coin;

	C[0] = 0;
	S[0] = 0;
	
	for(p = 1; p <= A; p++) {
		min = INF;
		for(i = 1; i <= N; i++) {
			if(d[i] <= p) {
				if(1 + C[p - d[i]] < min) {
					min = 1 + C[p - d[i]];
					coin = i;
				}
			}
		}
		C[p] = min;
		S[p] = coin;
	}
}

void coinSet(int s[], int S[], int n) {
	while(n > 0) {
		cout<< s[S[n]]<<" ";
		n = n - s[S[n]];
	}
	cout<<endl;
}

int main(void) {

	int k;
	cin>>k;
	k+=1; 

	int s[k];
	for(int i=1; i<k; i++) {
		cin>>s[i];
	}
	
	int n;
	cin>>n;
	
	int C[n+1];
	
	int S[n+1];

	coinChange(s, C, S, k, n);

	cout<<endl<<C[n]<<endl;
	
	coinSet(s, S, n);
		
	return 0;
}


