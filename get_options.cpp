#include "header.h"

//Получение и работа с опциями
int get_options(int argc, char *argv[],bool &contents_string,bool &ascending_mode){		//Последние два параметра - ссылочные (чтобы изменять оригинальные данные, а не их копии)	
	const char *options = "siad";														//"siad" - Допустимые опции,написанные без пробелов  										
	int opt_argument = 0;
	while((opt_argument = getopt(argc,argv,options))!=-1){
		switch(opt_argument){
			case 's':
				contents_string=1;
				break;
			case 'i':
				contents_string=0;
				break;
			case 'a':
				ascending_mode=1;
				break;
			case 'd':
				ascending_mode=0;
				break;
		}
	}
	return 0;	
}


