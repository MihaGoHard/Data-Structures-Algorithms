struct elem
{
  int key;
  int value;
};


void insertElemByIndex(std::vector<elem> &vector, int insertIndex, elem elem)
{
  auto iter = vector.cbegin();
  vector.insert(iter + insertIndex, elem);
} 


void deleteElemByIndex(std::vector<elem> &vector, int insertIndex)
{
  auto iter = vector.cbegin();
  vector.erase(iter + insertIndex);
}


int getch()
{
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}


char pressedButton()
{
  return char(getch());
}


void addDigitToNumberShowDigit(char buttonValue, int &inputNumber)
{
  int inputDigit = 0;
  inputDigit = atoi(&buttonValue);
  std::cout << inputDigit; 
  inputNumber = inputNumber * 10 + inputDigit;
}


bool checkArrSortedKeysUnic(std::vector<elem> elems)
{
  bool arrIsSorted = true;
  for (int i = 0; i < elems.size() - 1; i++)
  {
    if (elems[i + 1].key <= elems[i].key)
      arrIsSorted = false; 
  }  
  return arrIsSorted;
}