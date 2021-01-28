/*
  Тема 2.5 "Поиск и сортировка данных"
  Задание №1.
    Массив elems заполняется элементами типа "elem" с полями "key" и "value". elem{key, value}  
    
    Обязательные условия: элемены в массиве отсортированы по ключу, ключ каждого элемента уникален.

    elems   elem1 = {1, 22}   elem2 = {5, 38}   elem3 = {10, 2}

    Ключ и значение каждого элемента вводятся через тире (key-value), элементы разделяются пробелом. Конец ввода массива "Enter".

    Пример заполнения массива elems элементами elem1 elem2 elem3:

    1-22пробел5-38пробел10-2enter

    1-22 5-38 20-2\n
      
                  elem1            elem2            elem3  
    elems = [key:1,value:22], [key:5,value:38], [key:20,value:2]
    
    операции с эелементами массива описаны в меню.
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <termios.h>
#include <unistd.h>


#include "commonFunctionsConst.h"
#include "search.h"
#include "showInfo.h"
#include "arrOperations.h"


int main ()
{                        
  std::vector<elem> elems = {};

  readDigitCreatNumFillArr(elems);

  for (bool stopSearch = false; !stopSearch;)
  {
    showElems(elems);
    showMainMenuNav();
    switch(pressedButton())
    {
      case ('i'):
        insertNewElem(elems);
        break;
      case ('s'):
        searchElemValueByKey(elems);
        break;
      case ('d'):
        deleteElemByKey(elems);
        break;  
      case ('q'):
        stopSearch = true;    
    }           
  }

  return 0;
}