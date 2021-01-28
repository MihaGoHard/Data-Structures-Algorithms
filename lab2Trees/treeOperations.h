void checkRootAndPointsAddFacultToTree(bool &treeRoot, facultetStruct *&currFacultet, facultetStruct *&root, int pointsNum, std::string inputStructName, std::vector<int> inputCompsArr)
{
  if (treeRoot && pointsNum == 1)
  {
    treeRoot = false;
    currFacultet -> facultetName = inputStructName;
    currFacultet -> comps = inputCompsArr;
    currFacultet -> chairPointer = nullptr;
    currFacultet -> pointeNextFacultet = nullptr;
    root -> pointeNextFacultet = currFacultet;
  }
  else if (pointsNum == 1)
  {
    currFacultet -> pointeNextFacultet = new facultetStruct;
    currFacultet -> pointeNextFacultet -> facultetName = inputStructName;
    currFacultet -> pointeNextFacultet -> comps = inputCompsArr;
    currFacultet = currFacultet -> pointeNextFacultet;
  }
}

void checkPointsAddChairsToTree(facultetStruct *&currFacultet, chair *&currChair, int pointsNum, std::string inputStructName, std::vector<int> inputCompsArr)
{
  if (pointsNum == 2) 
  {
    if (currFacultet -> chairPointer == nullptr)
    {
      currChair = new chair;
      currChair -> pointeNextChair = nullptr;
      currChair -> labPointer = nullptr;
      currChair -> chairName = inputStructName;
      currChair -> comps = inputCompsArr;
      currFacultet -> chairPointer = currChair;
    } 
    else 
    {
      currChair -> pointeNextChair = new chair;
      currChair -> pointeNextChair -> labPointer = nullptr;
      currChair -> pointeNextChair -> pointeNextChair = nullptr;
      currChair -> pointeNextChair -> chairName = inputStructName;
      currChair -> pointeNextChair -> comps = inputCompsArr;
      currChair = currChair -> pointeNextChair;
    }
  }
}

void checkPointsAddLabsToTree(chair *&currChair, lab *&currLab, int pointsNum, std::string inputStructName, std::vector<int> inputCompsArr)
{
  if (pointsNum == 3)
  {
    if (currChair -> labPointer == nullptr)
    {
      currLab = new lab;
      currLab -> pointeNextLab = nullptr;
      currLab -> labName = inputStructName;
      currLab -> comps = inputCompsArr;
      currChair -> labPointer = currLab;
    }
    else
    {
      currLab -> pointeNextLab = new lab;
      currLab -> pointeNextLab -> labName = inputStructName;
      currLab -> pointeNextLab -> comps = inputCompsArr;
      currLab -> pointeNextLab -> pointeNextLab = nullptr;
      currLab = currLab -> pointeNextLab;
    }
  }  
}

void readFileFillTree(facultetStruct *&currFacultet, facultetStruct  *&root, chair *&currChair, lab *&currLab, std::ifstream &inputFile)
{
  std::string line;
  bool treeRoot = true;
  while(getline(inputFile, line))
  {
    int i = 0;
  
    int pointsNum = getPointsNum(line, i);
    std::string inputStructName = getInputStructName(line, i);
    std::vector<int> inputCompsArr = getCompsArr(line, i);
    unsigned int numOfComps = inputCompsArr.size();  

    checkRootAndPointsAddFacultToTree(treeRoot, currFacultet, root, pointsNum, inputStructName, inputCompsArr);

    checkPointsAddChairsToTree(currFacultet, currChair, pointsNum, inputStructName, inputCompsArr);

    checkPointsAddLabsToTree(currChair, currLab, pointsNum, inputStructName, inputCompsArr);
  }
  currFacultet = root;
}
