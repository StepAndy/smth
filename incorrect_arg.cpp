#include "header.h"

//Проверяю введенные аргументы на соответствие требованиям
int incorrect_arg(int argc,char *argv[]){										
	if(argc==2 && strcmp(argv[1],"-h")==0){													//1)Если помимо имени программы передан только один аргумент, 
		printf("\t[HELP:]\n");																//этим аргументом может быть только опция для вызова справки [-h]
		printf("First two arguments must be Input and Output file respectively.\n");
		printf("You can use only one option for content and one for sorting mode at a time.\n");
		printf("Options:\n");
		printf("-s = content of string\n");
		printf("-i = content of integer\n");
		printf("-a = ascending order\n");
		printf("-d = descending order\n");
		printf("To view help, use [-h]\n");
		return	1;
	}
	else if(argc!=5){												//2)Если аргументов недостаточное количество
		printf("Error - incorrect number of arguments!\n");
		printf("To view help, use [-h]\n");
		return 1;
	}
	else if(argc==5){												//3)Если количесвто аргументов правильное,но  
		int content=0, mode=0;										//нарушена логика работы программы с опциями:
		for(int i=0; i<argc; i++){
			if(strcmp(argv[i], "-s")==0 || strcmp(argv[i], "-i")==0)	
				content++;												//Подсчет количества используемых опций для содержимого
			if(strcmp(argv[i], "-a")==0 || strcmp(argv[i], "-d")==0)	
				mode++;													//Подсчет количества используемых опций для режима сортировки
		}
		if(content>1 && mode>1){									//3.1)Если одновременно выбраны все 4 опции					
			printf("Using all options at once is forbidden. To view help, use [-h]\n");
			return	1;
		} 
		else if(content>1 || mode>1){								//3.2)Если одновременно выбраны взаимоисключающие варианты
			printf("Please,select only one of the two options.\n");
			return	1;
		} 
			
	}
	return 0;	
}