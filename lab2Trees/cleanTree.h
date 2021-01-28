void cleanLabs(chair *&currChair, lab *&currLab)
{
  lab *labToDelete = nullptr;
  bool firstLabFound = false;
  do
  {
    if (!firstLabFound)
    {
      currLab = currChair -> labPointer;
      firstLabFound = true;
    }
    else
    {
      labToDelete = currLab;
      currLab = currLab -> pointeNextLab;
      delete labToDelete;
    }
    //std::cout << "    " << currLab -> labName << std::endl;
  } while (currLab -> pointeNextLab != nullptr);
  currChair -> labPointer = nullptr;
  currLab = nullptr;
  labToDelete = nullptr;
}

void cleanChairsLabs(facultetStruct *&currFacultet, chair *&currChair, lab *&currLab)
{
  chair *chairToDelete = nullptr;
  bool firstChairFound = false;
  do
  {
    if (!firstChairFound)
    {
      currChair = currFacultet -> chairPointer;
      firstChairFound = true;
    }
    else
    {
      chairToDelete = currChair;
      currChair = currChair -> pointeNextChair;
      delete chairToDelete; 
    }
    //std::cout << "  " << currChair -> chairName << std::endl;
    if (currChair -> labPointer != nullptr)
    {
      cleanLabs(currChair, currLab);
    }
  } while (currChair -> pointeNextChair != nullptr);
  currFacultet -> chairPointer = nullptr;
  currChair = nullptr;
  chairToDelete = nullptr;
}

void cleanFacultetsChairsLabs(facultetStruct *&currFacultet, chair *&currChair, lab *&currLab)
{
  facultetStruct *facultetToDelete;
  while (currFacultet -> pointeNextFacultet != nullptr)
  {
    facultetToDelete = currFacultet;
    currFacultet = currFacultet -> pointeNextFacultet;
    //std::cout << currFacultet -> facultetName << std::endl;
    delete facultetToDelete;
    if (currFacultet -> chairPointer != nullptr)
    {
      cleanChairsLabs(currFacultet, currChair, currLab);
    }
  }
  facultetToDelete = nullptr;
  currFacultet = nullptr;
}

void deleteTree(facultetStruct *&currFacultet, facultetStruct *&root, chair *&currChair, lab *&currLab)
{
  currFacultet = root;
  cleanFacultetsChairsLabs(currFacultet, currChair, currLab);
  root = nullptr; 
}