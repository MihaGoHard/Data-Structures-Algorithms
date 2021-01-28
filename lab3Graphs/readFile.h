void getCitiesFillCitiesVector(std::string line, graphsStruct &graphs)
{
  std::string cityName;
  for(int charIndex = 0; line[charIndex] != ':' && line[charIndex] != ';'; charIndex++)
  {
    if (line[charIndex] != ' ')
      cityName += line[charIndex];
  }
  cityPoint newCity;
  newCity.cityName = cityName;
  graphs.cities.push_back(newCity);
}

void getCitiesInitMatrix(std::ifstream &inputFile, graphsStruct &graphs)
{
  std::string line;
  while(getline(inputFile, line))
  {
    getCitiesFillCitiesVector(line, graphs); 
  }
  graphs.rows = graphs.columns = graphs.cities.size();
  graphs.weightMatrix.assign(graphs.rows, std::vector<int>(graphs.columns, 0));
}

void findCityIndex(int &columnIndex, std::string city, std::vector<cityPoint> cities)
{
  for (int i = 0; i < cities.size(); i++)
  {
    if(city == cities[i].cityName)
    {
      columnIndex = i;
    }  
  }
}

void parseLineAddWeightToMatrix(int rowIndex, std::string line, graphsStruct &graphs)
{
  int columnIndex = 0;
  int i = 0;
  std::string weight = "";
  std::string city = "";
  while (line[i] != ':')
    i++;
  for(; line[i] != ';'; i++)
  {
    if (line[i] == '-')
    {
      findCityIndex(columnIndex, city, graphs.cities);
      for(; line[i] != ' '; i++)
      {
        if (isdigit(line[i]))
        {
          weight += line[i]; 
        } 
      } 
      graphs.weightMatrix[rowIndex][columnIndex] = std::stoi(weight);
      graphs.weightMatrix[columnIndex][rowIndex] = std::stoi(weight);
      city = "";
      weight = "";
    } 
    else
    {
      if (line[i] != ':' && line[i] != ' ' && !isdigit(line[i]))
        city = city + line[i];
    }   
  } 
}

void getWeightFillMatrix(std::ifstream &inputFile, graphsStruct &graphs)
{
  inputFile.clear();
  inputFile.seekg(0);

  std::string line;
  for(int rowIndex = 0; getline(inputFile, line); rowIndex++)
  {
    parseLineAddWeightToMatrix(rowIndex, line, graphs); 
  }
}


void readFileBuildMatrix(std::ifstream &inputFile, graphsStruct &graphs)
{
  getCitiesInitMatrix(inputFile, graphs);

  getWeightFillMatrix(inputFile, graphs);
}


