void compareChair(compareChairFacultets &compare)
{
  if (compare.minChairCompsNumber == 0 && compare.minChair == " " && compare.currChairCompsNumber != 0)
  {
    compare.minChairCompsNumber = compare.currChairCompsNumber;
    compare.minChair = compare.currChair;
  }

  if (compare.currChairCompsNumber < compare.minChairCompsNumber && compare.currChairCompsNumber != 0)
  {
    compare.minChairCompsNumber = compare.currChairCompsNumber;
    compare.minChair = compare.currChair;
  }
  
  if (compare.currChairCompsNumber == compare.minChairCompsNumber && compare.currChairCompsNumber != 0)
  {
    size_t pos = compare.minChair.find(compare.currChair);  // проверка на вхождение строки
    if (pos == std::string::npos)
    {  
      compare.minChair = compare.minChair + " " + compare.currChair;
    }  
  }

  if (compare.maxChairCompsNumber == 0 && compare.minChair == " " && compare.currChairCompsNumber != 0)
  {
    compare.maxChairCompsNumber = compare.currChairCompsNumber;
    compare.maxChair = compare.currChair;
  }

  if (compare.currChairCompsNumber > compare.maxChairCompsNumber)
  {
    compare.maxChairCompsNumber = compare.currChairCompsNumber;
    compare.maxChair = compare.currChair;
  }

  if (compare.currChairCompsNumber == compare.maxChairCompsNumber && compare.currChairCompsNumber != 0)
  {
    size_t pos = compare.maxChair.find(compare.currChair);
    if (pos == std::string::npos)
    {  
      compare.maxChair = compare.maxChair + " " + compare.currChair;
    }  
  }
}

void compareFacultets(compareChairFacultets &compare)
{
  if (compare.minFacultCompsNumber == 0 && compare.minFacultet == " " && compare.currFacultCompsNumber != 0)
  {
    compare.minFacultCompsNumber = compare.currFacultCompsNumber;
    compare.minFacultet = compare.currFacultet;
  }

  if (compare.currFacultCompsNumber < compare.minFacultCompsNumber && compare.currFacultCompsNumber != 0)
  {
    compare.minFacultCompsNumber = compare.currFacultCompsNumber;
    compare.minFacultet = compare.currFacultet;
  }
  
  if (compare.currFacultCompsNumber == compare.minFacultCompsNumber && compare.currFacultCompsNumber != 0)
  {
    size_t pos = compare.minFacultet.find(compare.currFacultet);  // проверка на вхождение строки
    if (pos == std::string::npos)
    {  
      compare.minFacultet = compare.minFacultet + " " + compare.currFacultet;
    }  
  }

  if (compare.maxFacultCompsNumber == 0 && compare.maxFacultet == " " && compare.currFacultCompsNumber != 0)
  {
    compare.maxFacultCompsNumber = compare.currFacultCompsNumber;
    compare.maxFacultet = compare.currFacultet;
  }

  if (compare.currFacultCompsNumber > compare.maxFacultCompsNumber)
  {
    compare.maxFacultCompsNumber = compare.currFacultCompsNumber;
    compare.maxFacultet = compare.currFacultet;
  }

  if (compare.currFacultCompsNumber == compare.maxFacultCompsNumber && compare.currFacultCompsNumber != 0)
  {
    size_t pos = compare.maxFacultet.find(compare.currFacultet);
    if (pos == std::string::npos)
    {  
      compare.maxFacultet = compare.maxFacultet + " " + compare.currFacultet;
    }  
  }
}

void showResult(compareChairFacultets compare)
{
  std::cout << std::endl << "=================================================================" << std::endl;
  std::cout << "кафедра(ы) с минимальным колличеством компьютеров: " << compare.minChair << std::endl;
  std::cout << "кафедра(ы) с максимальным колличеством компьютеров: " << compare.maxChair << std::endl << std::endl;

  std::cout << "факультет(ы) с минимальным колличеством компьютеров: " << compare.minFacultet << std::endl;
  std::cout << "факультет(ы) с максимальным колличеством компьютеров: " << compare.maxFacultet << std::endl;
  std::cout << "=================================================================" << std::endl << std::endl;
}