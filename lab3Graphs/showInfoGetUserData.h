void showCities(graphsStruct &graphs)
{
  std::cout << "\n";
  std::cout << "\n\n" << "Список городов" << ": ";
  for (int i = 0; i < graphs.cities.size(); i++)
  {
      std::cout << graphs.cities[i].cityName << "  ";
  }
  std::cout << "\n\n" << "введите через пробел названия двух городов и нажмите `enter`" << "\n\n";
}

bool checkNewCityInCities(std::string city, std::vector<cityPoint> cities)
{
  bool cityInCities = false;
  for (int i = 0; i < cities.size(); i++)
  {
    if(city == cities[i].cityName)
    {
      cityInCities = true;
    }  
  }
  return cityInCities;
}

void getCitiesForCompare(graphsStruct &graphs)
{
  std::string firstCity = "";
  std::string secondCity = "";
  while (!checkNewCityInCities(firstCity, graphs.cities) || !checkNewCityInCities(secondCity, graphs.cities))
  {
    std::cin >> firstCity;
    std::cin >> secondCity;
    if (!checkNewCityInCities(firstCity, graphs.cities) || !checkNewCityInCities(secondCity, graphs.cities))
      std::cout << "неверный город, повторите ввод" << std::endl << std::endl;
  }  

  findCityIndex(graphs.firstCity, firstCity, graphs.cities);
  findCityIndex(graphs.secondCity, secondCity, graphs.cities);
  graphs.cities[graphs.firstCity].maxWeight = 0;
}

void showWeightMatrix(graphsStruct &graphs)
{
  for (int i = 0; i < graphs.rows; i++)
  {
      for (int j = 0; j < graphs.columns; j++)
      {
          std::cout << graphs.weightMatrix[i][j] << " ";
      }
      std::cout << std::endl;
  }
}

void showResult(graphsStruct &graphs) {
  std::string firstCityName = graphs.cities[graphs.firstCity].cityName;
  std::string secondCityName = graphs.cities[graphs.secondCity].cityName;
  
  if (graphs.maxWeight != 0)
  {
    std::cout << "Между городами " << firstCityName << " и " << secondCityName << " " << "можно провести максимальный груз, равный ";
    std::cout << graphs.maxWeight << std::endl;
    std::cout << "по маршруту: ";

    for (int i = graphs.route.size() - 1; i >= 0 ; i--)
    {
      std::cout << graphs.cities[graphs.route[i]].cityName << " "; 
    }
    std::cout << std::endl;
  }
  else
  { 
    std::cout << "Между городами " << firstCityName << " и " << secondCityName << " отсутствует дорога" << std::endl;
    std::cout << "масса груза: " << graphs.maxWeight <<  std::endl;
  }
  
  std::cout << "\nпродолжить - любая клавиша, затем `enter`\nвыход - `q`, затем `enter` \n" << std::endl;
}