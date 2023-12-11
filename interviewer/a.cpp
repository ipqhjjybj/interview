#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];
int abs(int x){
	if(x < 0){
		return -1 * x;
	}else{
		return x;
	}
}

int main(){
	while(scanf("%s", s) != EOF){
		int A = 0, D = 0, W = 0, S = 0;
		int nn = strlen(s);

		int rightans = nn / 4;

		for(int i = 0; i < nn; i++){
			if(s[i] == 'A'){
				A += 1;
			}else if(s[i] == 'D'){
				D += 1;
			}else if(s[i] == 'W'){
				W += 1;
			}else if(s[i] == 'S'){
				S += 1;
			}else{
				printf("error %c!\n", s[i]);
			}
		}
		int ans = abs(A - rightans) + abs(D - rightans) + abs(W - rightans) + abs(S - rightans);
		printf("%d\n", ans/2);
	}
}