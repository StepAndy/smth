#include <fstream>
#include <stdio.h>
#include <unistd.h> 
#include <cctype>
#include <cstring>
#include "header.h"
#define N 100 		
using namespace std;

int input_file_error(ifstream &in){
	if (!in.is_open()){
		printf("Wrong name of Input file. Try again with the correct one.\n");
		return 1;
	}
	return 0;
}

int in_to_buf(int &count, bool contents_string,ifstream &in,string *buf_str,int *buf_int){
	int i=0;
	while(!in.eof()){
		int j=0;
		if(contents_string){
			//Пока не закончился файл, заполняю буфер его содержимым
			getline(in,buf_str[i]); 	
			//До конца строки проверяю на отсутствие пробелов, иначе сообщаю об ошибке в содержимом
			while(buf_str[i][j]){ 		
				if(buf_str[i][j]==' '){											
					printf("Incorrect file content! File must not have spaces.\n");							
					return 0;
				}
				j++;	
			}
			i++;				
		} 
		else{
			in >> buf_int[i++];																												
			//Если вместо чисел другое содержимое, объявить об ошибке
			if(!isdigit(buf_int[i])){	
				printf("Incorrect file content! The content must consist of numbers only.\n");
				return 0;
			}
		} 
		count++;									
	}
	return 1;
}

void buf_to_file(int &count,bool contents_string,string *buf_str,int *buf_int,ofstream &out){
	int i=0;
	while(i<count){
		if(contents_string) 
			out << buf_str[i++] << "\n";
		else 
			out << buf_int[i++] << "\n";
	}
}

int main(int argc, char *argv[])
{
	ifstream in(argv[argc-4]);
	string buf_str[N];
	int    buf_int[N];
	int i=0, count=0;	
	bool contents_string,ascending_mode; 
	
	//Выход, если аргументы переданы некорректно
	if(incorrect_arg(argc,argv)) 
		return 1;															
	//Если все верно, то работать в соответствии с полученными аргументами 	
	else get_options(argc,argv,contents_string,ascending_mode);				
	
	//Выход, если нет указанного входного файла
	if(input_file_error(in)) return 1;	
	//Копировать в буфер из входного файла. Выйти, если возникло исключение
	if(!in_to_buf(count,contents_string,in,buf_str,buf_int)) return 1;		
	in.close();
	
	if(contents_string)	
		//Сортирую буфер в зависимости от содержимого соответствующей функцией
		isort_str(buf_str,count);											
	else 
		isort_int(buf_int,count);

	//Если сортировка по убыванию -  массив перезаписывается в обратном порядке 	
	if(!ascending_mode){																						
		int j=0;															
		if(contents_string) 
			str_descending(buf_str,count);
		else 
			int_descending(buf_int,count);		
	}
	
	ofstream out(argv[argc-1]);	
	//Передаю из буфера содержимое в выходной файл
	buf_to_file(count,contents_string,buf_str,buf_int,out);					
	out.close();
	return 0;
}

