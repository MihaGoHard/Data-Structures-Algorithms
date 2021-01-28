const int limit = 2000;

struct cityPoint
{
  std::string cityName;
  int maxWeight = limit;
  bool startPointPtr = false;
  bool visited = false;
  int point = -1; 
};
  

struct graphsStruct
{
  int rows = 0;
  int columns = 0;

  int firstCity = -1;
  int secondCity = -1;
  
  std::vector <cityPoint> cities;
  
  std::vector <std::vector<int>> weightMatrix; 

  std::vector <int> route;

  int maxWeight = 0;
};