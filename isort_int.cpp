#include "header.h"

//Сортирую массив чисел 
void isort_int(int * buf,int n){
	int k,j;
	for(int i=1; i<n; i++){				
		k = buf[i]; //
		j = i-1;
		while(j>=0 && buf[j]>k){
			buf[j+1]=buf[j];
			j--;
		}
		buf[j+1]=k;
	}
}