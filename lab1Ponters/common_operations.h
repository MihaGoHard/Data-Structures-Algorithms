/*
  functions in module
    showQueueOfStacks
    deleteQueueOfStacks
*/

void showQueueOfStacks(struct queuePtr quPtr, struct stackPtr stPtr)
{ 
    showMessage("\nОчередь стеков:", true);
    moveCurrQueueElemToHead(quPtr);
    bool stopQueueSearch = false;
    do
    {
        stopQueueSearch = checkTailQueueElem(quPtr);
        showNumberOfCurrQueueElem(quPtr);
        stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop; 
        showStack(stPtr);   
        moveNextElemOfQueue(quPtr);
    } 
    while (!stopQueueSearch); 
    std::cout << std::endl;
}

void deleteQueueOfStacks(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    if (quPtr.headQueuePtr != nullptr)
    {
        moveCurrQueueElemToHead(quPtr);
        bool stopQueueSearch = false;
        do
        {
            stopQueueSearch = checkTailQueueElem(quPtr);
            deleteStackOfCurrQueueElem(quPtr, stPtr);
            quPtr.newQueuePtr = quPtr.currQueuePtr -> pointerNextObj;
            delete quPtr.currQueuePtr;
            quPtr.currQueuePtr = nullptr;
            if (!stopQueueSearch)
            {
                quPtr.currQueuePtr = quPtr.newQueuePtr;
            }     
        } 
        while (!stopQueueSearch);
        setAllPointersToNull(quPtr, stPtr);
    }
    else
    {
        showMessage("empty queue or empry stack", true);
    }
}

