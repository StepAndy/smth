#include "header.h"

//Перезапись массива в обратном порядке
void str_descending(string * buf,int n){
	string tmp;
	for(int i=0; i<n/2; i++){
		tmp = buf[i];
    	buf[i] = buf[n - i - 1];
    	buf[n - i - 1] = tmp;
	}	
}