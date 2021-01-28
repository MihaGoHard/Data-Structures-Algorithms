/*
  functions in module
    checkStackTopAddStackElem
    checkNullPrevStackPtr
    setCurrStackPtrToNull
    deleteStackOfCurrQueueElem
    showStack
    readDigitCreatNumFillStack
    deleteTopOfStack
    getCurrStackElemByIndex
    insertNumToStackBefor
    insertNumToStackAfter
*/  


void checkStackTopAddStackElem(struct stackPtr &stPtr, int inputNum)
{
    stPtr.topStackPtr = new stackListObject;
    stPtr.topStackPtr -> objValue = inputNum;
    if (stPtr.currStackPtr == nullptr)
    {
        stPtr.topStackPtr -> pointerPrevObj = nullptr;
    }
    else
    {
        stPtr.topStackPtr -> pointerPrevObj = stPtr.currStackPtr;
    }
    stPtr.currStackPtr = stPtr.topStackPtr;
}




bool checkNullPrevStackPtr(struct stackPtr &stPtr)
{
    if (stPtr.currStackPtr -> pointerPrevObj == nullptr)
    {
        return true;
    }    
    else
    {
        return false;
    }  
}

void setCurrStackPtrToNull(struct stackPtr &stPtr)
{
    stPtr.currStackPtr = nullptr;
}

void deleteStackOfCurrQueueElem(struct queuePtr &quPtr, struct stackPtr &stPtr)
{

    stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop;
    bool stopStackSearch = false;
    do
    {
        stopStackSearch = checkNullPrevStackPtr(stPtr);
        stPtr.topStackPtr = stPtr.currStackPtr;
        stPtr.currStackPtr = stPtr.topStackPtr -> pointerPrevObj;
        delete stPtr.topStackPtr;
        stPtr.topStackPtr = nullptr;
    } 
    while(!stopStackSearch);
}    


void showStack(struct stackPtr stPtr)
{ 
    bool stopStackSearch = false;
    do
    {
        stopStackSearch = checkNullPrevStackPtr(stPtr);
        std::cout << stPtr.currStackPtr -> objValue << " ";   
        stPtr.currStackPtr = stPtr.currStackPtr -> pointerPrevObj; 
    } 
    while(!stopStackSearch);
    std::cout << std::endl;
}

void readDigitCreatNumFillStack(struct queuePtr quPtr, struct stackPtr &stPtr)
{
    int inputNumber = 0;
    char buttonValue = ' ';
    bool numberNotEmpty = false;
    for (bool stopSearch = false; !stopSearch;)
    {
        buttonValue = pressedButton();
        if (isdigit(buttonValue))
        {
            addDigitToNumberShowDigit(buttonValue, inputNumber);
            numberNotEmpty = true;
        }

        if (buttonValue == space)
        {    
            if (numberNotEmpty)
            {
                checkStackTopAddStackElem(stPtr, inputNumber);
                showMessage(" добавлено в стек: ", false);
                numberNotEmpty = false;
                inputNumber = 0;
                showStack(stPtr);
            }
            else
            {
                showMessage("введите число", true);
            }
                
        }
        if (buttonValue == enter)
        {
            if (stPtr.topStackPtr != nullptr)
            {
                stopSearch = true;
                showMessage("\nновый стек: ", false);
                showStack(stPtr);
            }    
            else
            {
                showMessage("для продолжения заполните стек", true);
            }
        }
    }
    stPtr.currStackPtr = stPtr.topStackPtr;
}

void deleteTopOfStack(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    for (bool stopSearch = false; !stopSearch;)
    {
        switch(pressedButton())
        {
            case(space):
            {     
                if (stPtr.currStackPtr -> pointerPrevObj == nullptr)
                {
                    delete stPtr.currStackPtr;
                    stPtr.currStackPtr = stPtr.topStackPtr = nullptr;
                    quPtr.currQueuePtr -> pointerStackTop = nullptr;
                    stopSearch = true;
                }
                else
                {   
                    stPtr.topStackPtr = stPtr.currStackPtr -> pointerPrevObj;
                    delete stPtr.currStackPtr;
                    stPtr.currStackPtr = stPtr.topStackPtr;
                    showStack(stPtr);
                }    
                break;                    
            }
            case(enter):
            {
                if (stPtr.topStackPtr != nullptr)
                {
                    stopSearch = true;
                }    
                else
                {
                    showMessage("для продолжения заполните стек", true);
                }  
                break;
            }
        }
    }
}

void getCurrStackElemByIndex(struct queuePtr &quPtr, struct stackPtr &stPtr, int index)
{
    stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop;
    for(bool numberFound = false;!numberFound && !checkNullPrevStackPtr(stPtr);)
    {
    
        if(stPtr.currStackPtr -> objIndex == index)
        {
            numberFound = true;
        }
        else
        {
            stPtr.exchStPtr1 = stPtr.currStackPtr;
            stPtr.currStackPtr = stPtr.currStackPtr -> pointerPrevObj;
        }   
    }
}


void insertNumToStackBefor(struct queuePtr &quPtr, struct stackPtr &stPtr, int number)
{
    if(stPtr.currStackPtr == stPtr.topStackPtr)
    {
        stPtr.topStackPtr = new stackListObject;
        stPtr.topStackPtr -> objValue = number;
        stPtr.topStackPtr -> pointerPrevObj = stPtr.currStackPtr;
        quPtr.currQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        stPtr.currStackPtr = stPtr.topStackPtr;
    }
    else
    {
        stPtr.exchStPtr2 = new stackListObject;
        stPtr.exchStPtr2 -> objValue = number;
        stPtr.exchStPtr2 -> pointerPrevObj = stPtr.currStackPtr;
        stPtr.exchStPtr1 -> pointerPrevObj = stPtr.exchStPtr2;
        stPtr.currStackPtr = stPtr.exchStPtr2;
        stPtr.exchStPtr1 = stPtr.exchStPtr2 = nullptr;
    }   
}

void insertNumToStackAfter(struct queuePtr &quPtr, struct stackPtr &stPtr, int number)
{
    stPtr.exchStPtr2 = new stackListObject;
    stPtr.exchStPtr2 -> objValue = number;
    if(stPtr.currStackPtr -> pointerPrevObj == nullptr)
    {
        stPtr.exchStPtr2 -> pointerPrevObj = nullptr;
    }    
    else
    {
        stPtr.exchStPtr2 -> pointerPrevObj = stPtr.currStackPtr -> pointerPrevObj;
    }
    stPtr.currStackPtr -> pointerPrevObj = stPtr.exchStPtr2;
    stPtr.currStackPtr = stPtr.exchStPtr2;
    stPtr.exchStPtr2 = nullptr;
}







