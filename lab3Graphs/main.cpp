/*
  Тема 2.4 Графы. 
  Задание 19.

  На вход подаётся файл типа:

  B:  M-7  E-5  A-3 ;  описаны дуги, идущие из пункта В (B-M макс груз-7) (B-Е макс груз-5) (B-А макс груз-3)  
  E:  A-10 B-5 ;
  A:  B-3  E-10 ; 
  M:  B-7  C-12 ;      описаны дуги (M-В макс груз-7) (B-С макс груз-12)
  C:  M-12 ;
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> 

#include "constObjects.h"
#include "readFile.h"
#include "showInfoGetUserData.h"
#include "algorithm.h"
   


int main()
{
  for(char ch; ch != 'q';)
  {
    graphsStruct graphs;
    std::ifstream inputFile("./input.txt"); // окрываем файл для чтения
    if (inputFile.is_open())
    {
      readFileBuildMatrix(inputFile, graphs);
    }
    inputFile.close();     // закрываем файл

    showCities(graphs);

    getCitiesForCompare(graphs);   

    getMaxWeight(graphs);   
 
    showResult(graphs);

    std::cin >> ch;
  }
  return 0;
}

      