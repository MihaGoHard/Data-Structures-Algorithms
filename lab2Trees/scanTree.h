void scanLabs(facultetStruct *currFacultet, chair *&currChair, lab *&currLab, compareChairFacultets &compare)
{
  compare.currChairCompsNumber = currChair -> comps.size(); 
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
      currLab = currLab -> pointeNextLab;    
    }

    compare.currChair = currChair -> chairName;
    compare.currChairCompsNumber = compare.currChairCompsNumber + currLab -> comps.size();      

    compareChair(compare);

  } while (currLab -> pointeNextLab != nullptr);
}

void scanChairsLabs(facultetStruct *&currFacultet, chair *&currChair, lab *&currLab, compareChairFacultets &compare)
{
  bool firstChairFound = false;
  compare.currFacultCompsNumber = currFacultet -> comps.size();
  do
  {
    if (!firstChairFound)
    {
      currChair = currFacultet -> chairPointer;
      firstChairFound = true;
    }
    else
    {
      currChair = currChair -> pointeNextChair; 
    }
    //std::cout << "  " << currChair -> chairName << std::endl;
    if (currChair -> labPointer != nullptr)
    {
      scanLabs(currFacultet, currChair, currLab, compare);
    }
    compare.currFacultet = currFacultet -> facultetName;
    compare.currFacultCompsNumber = compare.currFacultCompsNumber + compare.currChairCompsNumber;
  } while (currChair -> pointeNextChair != nullptr);
  compareFacultets(compare);
}

void scanFacultetsChairsLabs(facultetStruct *&currFacultet, chair *&currChair, lab *&currLab, compareChairFacultets &compare)
{
  while (currFacultet -> pointeNextFacultet != nullptr)
  {
    currFacultet = currFacultet -> pointeNextFacultet;
    //std::cout << currFacultet -> facultetName << std::endl;
    if (currFacultet -> chairPointer != nullptr)
    {
      scanChairsLabs(currFacultet, currChair, currLab, compare);
    }
  }
}