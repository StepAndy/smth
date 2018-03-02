#include <fstream>
#include <stdio.h>
#include <unistd.h> 
#include <cctype>
#include <cstring>
#include <string.h>
using namespace std;

int get_options(int argc, char *argv[],bool &contents_string,bool &ascending_mode); //Получение и работа с опциями

int incorrect_arg(int argc,char *argv[]); //Проверяю введенные аргументы на соответствие требованиям

void isort_str(string * buf,int n); //Сортирую массив строк

void isort_int(int * buf,int n); //Сортирую массив чисел 

void str_descending(string * buf,int n); //Перезапись массива строк в обратном порядке

void int_descending(int * buf,int n); //Перезапись массива чисел в обратном порядке

