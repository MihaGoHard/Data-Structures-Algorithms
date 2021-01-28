void setMaxWeightInGraphs(graphsStruct &graphs)
{
  if (graphs.cities[graphs.secondCity].maxWeight != limit)
    graphs.maxWeight = graphs.cities[graphs.secondCity].maxWeight; 
}

void fillRoutVector(graphsStruct &graphs)
{
  if (graphs.cities[graphs.secondCity].maxWeight != limit)
  {
    graphs.route.push_back(graphs.secondCity);
    for (int i = graphs.secondCity; i != graphs.firstCity; )
    {
      i = graphs.cities[i].point;
      graphs.route.push_back(i);   
    }
  }  
}


void getMaxWeight(graphsStruct &graphs)
{
  graphs.cities[graphs.firstCity].maxWeight = 0;
  graphs.cities[graphs.firstCity].visited = true;
  graphs.cities[graphs.firstCity].startPointPtr = true;

  for (int j = 0; j < graphs.columns; j++)
  {
    if (graphs.weightMatrix[graphs.firstCity][j] > 0 && j != graphs.firstCity)
    {
      graphs.cities[j].maxWeight = graphs.weightMatrix[graphs.firstCity][j];
      graphs.cities[j].startPointPtr = true;
      graphs.cities[j].point = graphs.firstCity;
    }
  }  

  for (int i = 0; i < graphs.rows; i++)
  {
    for (int j = 0; j < graphs.columns; j++)
    {
      if (graphs.weightMatrix[i][j] != 0 && i != graphs.firstCity)
      { 
        if (graphs.cities[i].startPointPtr && !graphs.cities[j].startPointPtr)
        {
          graphs.cities[j].startPointPtr = true;
          graphs.cities[j].maxWeight = std::min(graphs.cities[i].maxWeight, graphs.weightMatrix[i][j]);
          graphs.cities[j].point = i;
        }

        if (!graphs.cities[i].startPointPtr && graphs.cities[j].startPointPtr)
        {
          graphs.cities[i].startPointPtr = true;
          graphs.cities[i].maxWeight = std::min(graphs.cities[j].maxWeight, graphs.weightMatrix[i][j]);
          graphs.cities[i].point = j;
        }

        if (graphs.cities[i].startPointPtr && graphs.cities[j].startPointPtr)
        {
          if (graphs.cities[i].maxWeight < std::min(graphs.cities[j].maxWeight, graphs.weightMatrix[i][j]))
          {
            graphs.cities[i].maxWeight = std::min(graphs.cities[j].maxWeight, graphs.weightMatrix[i][j]);
            graphs.cities[i].point = j;
          }

          if (graphs.cities[j].maxWeight < std::min(graphs.cities[i].maxWeight, graphs.weightMatrix[i][j]))
          {  
            graphs.cities[j].maxWeight = std::min(graphs.cities[i].maxWeight, graphs.weightMatrix[i][j]);  
            graphs.cities[j].point = i;
          }  
        }
      } 
    }
  }
  setMaxWeightInGraphs(graphs);
  fillRoutVector(graphs);
}