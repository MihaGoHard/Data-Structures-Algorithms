struct compareChairFacultets
{
  std::string minChair;
  int minChairCompsNumber;

  std::string maxChair;
  int maxChairCompsNumber;

  std::string currChair;
  int currChairCompsNumber;

  std::string minFacultet;
  int minFacultCompsNumber;

  std::string maxFacultet;
  int maxFacultCompsNumber;

  std::string currFacultet;
  int currFacultCompsNumber;
};


struct lab 
{
  std::string labName;
  std::vector <int> comps;

  lab *pointeNextLab = nullptr;
};

struct chair
{
  std::string chairName;
  std::vector <int> comps;

  lab *labPointer = nullptr;
  chair *pointeNextChair = nullptr;
};

struct facultetStruct
{
  std::string facultetName;
  std::vector <int> comps;

  chair *chairPointer = nullptr;
  facultetStruct *pointeNextFacultet = nullptr;
};





