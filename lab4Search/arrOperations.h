void readDigitCreatNumFillArr(std::vector<elem> &elems)
{
  int inputNumber = 0;
  char buttonValue = ' ';
  bool numberNotEmpty = false;
  elem newElem = {0, 0};
  std::cout << "введите эелементы в соотношении ключ-значение" <<std::endl;
  for (bool stopSearch = false; !stopSearch;)
  {
    buttonValue = pressedButton();
    if (isdigit(buttonValue))
    {
      addDigitToNumberShowDigit(buttonValue, inputNumber);
      numberNotEmpty = true;
    }

    switch (buttonValue)
    {
      case '-':    
        newElem.key = inputNumber;
        inputNumber = 0;
        std::cout << "-";
        break;
    
      case ' ':
        newElem.value = inputNumber;
        inputNumber = 0;    
        elems.push_back(newElem);
        std::cout << " ";
        break;

      case '\n':
        newElem.value = inputNumber;
        elems.push_back(newElem);

        if (checkArrSortedKeysUnic(elems))
          stopSearch = true;
        else 
        {
          std::cout << "\n!--элементы должны быть отсортированны по ключу, ключ каждого элемента должен быть уникальным--!" << std::endl;
          std::cout << "введите эелементы в соотношении ключ-значение" <<std::endl;
          elems = {};
          newElem = {0, 0};
          inputNumber = 0;
          numberNotEmpty = false;
          buttonValue = ' ';
        }            
        break;
    }
  }
  std::cout << std::endl;    
}


void deleteElemByKey(std::vector<elem> &elems)
{
  int inputNumber = 0;
  char buttonValue = ' ';
  bool numberNotEmpty = false;

  if (elems.size() != 0)
  {
    showElems(elems);
    showDeleteMenuNav();
  }    
  for (bool stopSearch = false; !stopSearch;)
  {
    switch (elems.size())
    {
      case 0:
        std::cout << std::endl << "!--массив очищен--!" << std::endl << std::endl;
        readDigitCreatNumFillArr(elems);
        stopSearch = true;
        break;
      default:
      {
        buttonValue = pressedButton();
        if (isdigit(buttonValue))
        {
          addDigitToNumberShowDigit(buttonValue, inputNumber);
          numberNotEmpty = true;
        }

        switch (buttonValue)
        {
          case '\n':    
            deleteElemByKey(elems, inputNumber);
            if (elems.size() != 0)
            {
              showElems(elems);
              showDeleteMenuNav();
            }    
            inputNumber = 0;
            break;

          case 'q':
            stopSearch = true;
            break;
        }
      }        
    }              
  }
}


void searchElemValueByKey(std::vector<elem> &elems)
{
  int inputNumber = 0;
  char buttonValue = ' ';
  bool numberNotEmpty = false;

  showElems(elems);
  showSearchElemNav();
    
  for (bool stopSearch = false; !stopSearch;)
  {
    buttonValue = pressedButton();
    if (isdigit(buttonValue))
    {
      addDigitToNumberShowDigit(buttonValue, inputNumber);
      numberNotEmpty = true;
    }

    switch (buttonValue)
    {
      case '\n':
        {
          int elemIndex = searchElemIndexByKey(elems, inputNumber);
          if (elemIndex != -1)
          {
            int elemValue = getElemValueByIndex(elems, elemIndex);
            std::cout << std::endl << "value: " << elemValue << std::endl;
          }
          else
            std::cout << std::endl << "нет эелемента с таким ключом";

          showElems(elems);    
          showSearchElemNav();
          inputNumber = 0;
        }
        break;

      case 'q':
        stopSearch = true;
        break;
    }        
  }
}


void insertNewElem(std::vector<elem> &elems)
{
  int inputNumber = 0;
  char buttonValue = ' ';
  bool numberNotEmpty = false;
  elem newElem = {0, 0};
  showElems(elems);
  showInsertElemNav();
  for (bool stopSearch = false; !stopSearch;)
  {
    buttonValue = pressedButton();
    if (isdigit(buttonValue))
    {
      addDigitToNumberShowDigit(buttonValue, inputNumber);
      numberNotEmpty = true;
    }

    switch (buttonValue)
    {    
      case '-':    
        newElem.key = inputNumber;
        inputNumber = 0;
        std::cout << "-";
        break;

      case '\n':
        newElem.value = inputNumber;
        insertElem(elems, newElem);
        showElems(elems);
        showInsertElemNav();
        inputNumber = 0;
        break;

      case 'q':
        stopSearch = true;
        break;
    }        
  }    
} 