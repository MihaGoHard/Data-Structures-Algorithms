int searchElemIndexByKey(std::vector<elem> elems, int key)
{
  int leftIndex = 0;
  int rightIndex = elems.size() - 1;
  int middleIndex = 0;
  int elemIndex = -1;
  for(bool stopSearch = false; !stopSearch; )
  {
    middleIndex = (leftIndex + rightIndex) / 2;
    
    if (key < elems[middleIndex].key)       
      rightIndex = middleIndex - 1;     
    else if (key > elems[middleIndex].key)  
      leftIndex = middleIndex + 1;    
    else
    { 
      elemIndex = middleIndex;
      stopSearch = true;                  
    }               

    if (leftIndex > rightIndex)           
      stopSearch = true;
  }
  return elemIndex;
}


void deleteElemByKey(std::vector<elem> &elems, int key)
{
  int elemIndex = searchElemIndexByKey(elems, key);
  if (elemIndex != -1)
    deleteElemByIndex(elems, elemIndex);
  else
    std::cout << std::endl << "нет эелемента с таким ключом"; 
}


void insertElem(std::vector<elem> &elems, elem elem)
{
  if (searchElemIndexByKey(elems, elem.key) == -1)
  {
    int leftIndex = 0;
    int rightIndex = elems.size() - 1;
    int middleIndex = 0;

    for(bool stopSearch = false; !stopSearch; )
    {
      middleIndex = (leftIndex + rightIndex) / 2;
      
      if (elem.key < elems[middleIndex].key)
        rightIndex = middleIndex - 1;
      else if (elem.key > elems[middleIndex].key)
        leftIndex = middleIndex + 1;              

      if (leftIndex > rightIndex)
      {
        if (rightIndex < 0)
          insertElemByIndex(elems, 0, elem);
        else
          insertElemByIndex(elems, rightIndex + 1, elem);               
        stopSearch = true;
      }  
    }
  }
  else
    std::cout << "\n!--элемент с таким ключом уже есть в массиве--!" << std::endl;
}
