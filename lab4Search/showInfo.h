void showElems(std::vector<elem> &elems)
{
  std::cout << std::endl << std::endl;
  for(int i = 0; i < elems.size(); i++)
    std::cout << "[key:" << elems[i].key << ",value:" << elems[i].value << "], ";

  std::cout << std::endl;
}


int getElemValueByIndex(std::vector<elem> &elems, int elemIndex)
{
  return elems[elemIndex].value;
}


void showMainMenuNav()
{
  std::cout << "*поиск значения элемента по ключу -S" << std::endl;
  std::cout << "*удаление элемента по ключу -D" << std::endl;
  std::cout << "*вставка элемента -I" << std::endl;
  std::cout << "*выход -Q" << std::endl;
}


void showDeleteMenuNav()
{
  std::cout << "**введите ключ, нажмите enter для удаления" << std::endl;
  std::cout << "**выход в главное меню -Q" << std::endl;
}


void showSearchElemNav()
{
  std::cout << "**введите ключ, нажмите enter" << std::endl;
  std::cout << "**выход в главное меню -Q" << std::endl;
}


void showInsertElemNav()
{
  std::cout << "**введите новый эелемент в соотношении ключ-значение" <<std::endl;
  std::cout << "**выход в главное меню -Q" << std::endl;
}