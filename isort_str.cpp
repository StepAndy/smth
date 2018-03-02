#include "header.h"

//Сортирую массив строк
void isort_str(string * buf,int n){			
	string k;
	int j;
	for(int i=1; i<n; i++){			
		k = buf[i];
		j = i-1;
		while(j>=0 && buf[j].compare(k)>0){
			buf[j+1]=buf[j];
			j--;
		}
		buf[j+1]=k;
	}
}