/*
  functions
    exchQueueStackPointers
    moveStackUp
    moveStackDown    
    getCurrQueueElement
    findQueIndex
    checkIndexShowMistace
    showStackByIndex
    moveStackInQueue
    checkQueMoveStackInQue
*/

void exchQueueStackPointers(struct queuePtr &quPtr, struct stackPtr &stPtr, int direction)
{
    if (direction == PREV)
    {
        stPtr.exchStPtr1 = quPtr.currQueuePtr -> pointerStackTop; 
        stPtr.exchStPtr2 = quPtr.currQueuePtr -> pointerPrevObj -> pointerStackTop;
        quPtr.currQueuePtr -> pointerPrevObj -> pointerStackTop = stPtr.exchStPtr1;
        quPtr.currQueuePtr -> pointerStackTop = stPtr.exchStPtr2;
    }
    if(direction == NEXT)
    {
        stPtr.exchStPtr1 = quPtr.currQueuePtr -> pointerStackTop; 
        stPtr.exchStPtr2 = quPtr.currQueuePtr -> pointerNextObj -> pointerStackTop;
        quPtr.currQueuePtr -> pointerNextObj -> pointerStackTop = stPtr.exchStPtr1;
        quPtr.currQueuePtr -> pointerStackTop = stPtr.exchStPtr2;
    }                  
}

void moveStackUp(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    exchQueueStackPointers(quPtr, stPtr, PREV);
    movePrevElemOfQueue(quPtr);   
}

void moveStackDown(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    exchQueueStackPointers(quPtr, stPtr, NEXT);
    moveNextElemOfQueue(quPtr);   
}


void getCurrQueueElement(struct queuePtr &quPtr, int stackIndex)
{
    quPtr.currQueuePtr = quPtr.headQueuePtr;
    for(bool indexFound = false; !indexFound;)
    {
        if(quPtr.currQueuePtr -> objValue == stackIndex)
        {
            indexFound = true;
        }
        else
        {
            moveNextElemOfQueue(quPtr);
        }   
    }
}

bool findQueIndex(struct queuePtr quPtr, int stackIndex)
{
    if (stackIndex <= quPtr.tailQueuePtr -> objValue && stackIndex > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void checkIndexShowMistace(struct queuePtr quPtr, int &stackIndex)
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

        if (buttonValue == enter)
        {
            if(!numberNotEmpty)
            {
                showMessage("введите индекс", true);
            }

            if (numberNotEmpty && !findQueIndex(quPtr, inputNumber))
            {
                showMessage("неверный индекс, повторите ввод", true);
            }

            if (numberNotEmpty && findQueIndex(quPtr, inputNumber))
            {
                stackIndex = inputNumber;
                numberNotEmpty = false;
                stopSearch = true;
            }

            inputNumber = 0;
        }
    }
}

void showStackByIndex(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    int stackIndex = 0;
    showMessage("\nВведите индекс стека, котрый хотите извлечь", true);
    showQueueOfStacks(quPtr, stPtr);
    checkIndexShowMistace(quPtr, stackIndex);
    getCurrQueueElement(quPtr, stackIndex);
    stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop;
    showMessage(": ", false);
    showStack(stPtr);
    setCurrStackPtrToNull(stPtr);
}

void moveStackInQueue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    showMessage("\nВведите номер стэка в очереди, позицию которого нужно изменить и нажмите `Enter`", true);
    showQueueOfStacks(quPtr, stPtr);
    char buttonValue;
    int stackIndex = 0;
    checkIndexShowMistace(quPtr, stackIndex);
    if (findQueIndex(quPtr, stackIndex))
    {
        showStackMoveMenu();
        showQueueOfStacks(quPtr, stPtr);
        getCurrQueueElement(quPtr, stackIndex);
        for (bool stopMove = false; !stopMove;)
        {
            switch(pressedButton())
            {
                case ('w'):
                {   
                    moveStackUp(quPtr, stPtr);
                    showQueueOfStacks(quPtr, stPtr);
                    showMessage("для возврата в гланое меню нажмите `q`", true);
                    break;
                }
                case ('s'):
                {
                    moveStackDown(quPtr, stPtr);
                    showQueueOfStacks(quPtr, stPtr);
                    showMessage("для возврата в гланое меню нажмите `q`", true);
                    break;
                }
                case ('q'):
                {
                    stopMove = true;
                }
            }    
        }
    }  
}


void checkQueMoveStackInQue(struct queuePtr quPtr, struct stackPtr stPtr)
{
    if (checkOnlyOneElemInQueue(quPtr))
    {
        showMessage("\nв очереди только один стек, дополните очередь", true);
    }
    else
    {
        moveStackInQueue(quPtr, stPtr);
    }    
}
