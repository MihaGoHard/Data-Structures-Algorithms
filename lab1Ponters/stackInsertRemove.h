/*
  changeAnyStack  
*/

void changeAnyStack(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    if (!checkEmptyQueueShowMessage(quPtr))
    {
        showIndexStackChoiceMenu();
        showQueueOfStacks(quPtr, stPtr);
        for (bool stopSearch = false; !stopSearch;)
        {
            int stackIndex = -1;
            checkIndexShowMistace(quPtr, stackIndex);
            getCurrQueueElement(quPtr, stackIndex);
            stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop;
            showMessage("\nСтек: ", false);
            showStack(stPtr);
            showChangeStackMenu();

            switch(pressedButton())
            {
                case ('z'):
                {
                    showAddStackCommands();
                    readDigitCreatNumFillStack(quPtr, stPtr);
                    quPtr.currQueuePtr -> pointerStackTop = stPtr.topStackPtr;
                    showQueueOfStacks(quPtr, stPtr);
                    setCurrStackPtrToNull(stPtr);
                    stopSearch = true;  
                    break;      
                }
                case ('x'):
                {
                    showRemoveStackCommands();
                    deleteTopOfStack(quPtr, stPtr);
                    if(stPtr.topStackPtr == nullptr) 
                    {
                        delStackFromQue(quPtr, stPtr);
                    }
                    else
                    {
                        quPtr.currQueuePtr -> pointerStackTop = stPtr.topStackPtr;    
                    }

                    if(quPtr.currQueuePtr != nullptr)
                    {
                        showQueueOfStacks(quPtr, stPtr);
                    }
                    setCurrStackPtrToNull(stPtr);
                    stopSearch = true;  
                    break;      
                } 
            }
        }
    }   
}