/*
  Тема 2.3 Деревья. 
  Задание 11.

  На вход подаётся файл типа:

  . РТФ  234 5433 245 ;                факультет (РТФ) с компьютерами[234 5433 245]                                      
  .. кафедра_ртф1  343 223 556 ;
    ... лаборатория1  45 33 55 ;  
    ... лаборатория2  34 23 ;
  .. кафедра_ртф2 876  234 543 ;       кафедра (кафедра_ртф2) факультета (РТФ) с компьютерами[876 234 543]
    ... лаборатория1  321 543 ;
    ... лаборатория2  98 76 32 ;
  . УИП  32 43 ;
    .. кафедра_уип1  87 65 54 43 ;
      ... лаборатория1  99 75 47 5 ;
      ... лаборатория2  32 12 43 7 ; 
    .. кафедра_уип2  98 76 53 991 8 ;
      ... лаборатория1  121 4332 342 ;
      ... лаборатория2  13 32 123 433 ;  лаборатория (лаборатория2) кафедры(кафедра_уип2) факультета(УИП) с компьютерами[13 32 123 433]


  *называния факультетов/кафедр/лабораторий пишутся слитно

  *одна точка указывает на факультет, две - на кафедру, три - на лабораторию

  *после точки(точек) через пробел указывается название факультета/кафедры/лаборатории соответсвенно  

  *далее через пробел указываются номера компьютеров

  *в конце строки обязательна ';'

  Команды:

     получение информации: нажать 'w', затем 'enter'

     выход: нажать 'q', затем 'enter'

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

#include "const_objects.h"
#include "getParamFromLine.h"
#include "treeOperations.h"
#include "compare.h" 
#include "scanTree.h"
#include "cleanTree.h" 

void scanInstTreeShowResult(facultetStruct *&currFacultet, chair *&currChair, lab *&currLab)
{
  compareChairFacultets compare {" ", 0, " ", 0, " ", 0, " ", 0, " ", 0, " ", 0};
    
  scanFacultetsChairsLabs(currFacultet, currChair, currLab, compare);

  showResult(compare);
}

int main()
{
  for(char ch; ch != 'q';)
  {
    ch = getchar();
    if (ch == 'w')
    {
      std::ifstream inputFile("./input2.txt"); // окрываем файл для чтения
      if (inputFile.is_open())
      {
        facultetStruct *currFacultet, *root; 

        chair *currChair = nullptr;

        lab *currLab = nullptr;

        currFacultet = new facultetStruct;

        root = new facultetStruct;

        readFileFillTree(currFacultet, root, currChair, currLab, inputFile);
            
        scanInstTreeShowResult(currFacultet, currChair, currLab);

        deleteTree(currFacultet, root, currChair, currLab);
      }
      inputFile.close();     // закрываем файл
    }  
  }   
  return 0;
}

      