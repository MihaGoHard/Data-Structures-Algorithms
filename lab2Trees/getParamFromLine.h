int getPointsNum(std::string &line, int &i)
{
  int pointsNum = 0;
  for( ; line[i] == ' ' || line[i] == '.'; i++)
  {
    if (line[i] == '.')
    {
      pointsNum++;
    }  
  } 
  return pointsNum;     
}

std::string getInputStructName(std::string &line, int &i)
{
  std::string facultName = "";
  for( ; line[i] != ' ' && line[i] != ';' ; i++)
  {
    facultName += line[i];
  }
  return facultName;
}

std::vector<int> getCompsArr(std::string &line, int &i)
{
  std::vector<int> compNumbers = {};
  std::string strNum = "";
  while(line[i] != ';') 
  {
    if (isdigit(line[i]))
    {
      strNum += line[i];
    }

    if (isdigit(line[i]) && !isdigit(line[i + 1]))
    {
      int num = std::stoi(strNum);
      compNumbers.push_back(num);
      strNum = "";  
    }
    i++;    
  }
  return compNumbers;
}



