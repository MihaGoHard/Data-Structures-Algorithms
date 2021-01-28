/* 
functions in module
    checkQueHeadAddStackToQue
    moveCurrQueueElemToHead
    moveCurrQueueElemToTail
    checkNullNextElem
    checkTailQueueElem
    checkNullNextElem
    moveNextElemOfQueue
    movePrevElemOfQueue
    deleteCurrQueueElem
    deleteCurrQueueElem
    showNumberOfCurrQueueElem
    checkEmptyQueueShowMessage
    changeIndexesInQueueAfterCurrElem
    reindexAllQueueElems
    insertNewElemToQueBefor
    insertNewElemToQueAfter
*/
void checkQueHeadAddStackToQue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    if (quPtr.headQueuePtr == nullptr) 
    {
        quPtr.headQueuePtr = new queueListObject;
        quPtr.headQueuePtr -> objValue = 1;
        quPtr.headQueuePtr -> pointerNextObj = nullptr;
        quPtr.headQueuePtr -> pointerPrevObj = nullptr;
        quPtr.headQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.tailQueuePtr = quPtr.headQueuePtr;
        quPtr.currQueuePtr = quPtr.headQueuePtr;
    }
    else
    {
        quPtr.newQueuePtr = new queueListObject;
        quPtr.newQueuePtr -> pointerNextObj = quPtr.headQueuePtr;
        quPtr.newQueuePtr -> pointerPrevObj = quPtr.currQueuePtr;
        quPtr.newQueuePtr -> objValue = quPtr.tailQueuePtr -> objValue + 1;
        quPtr.tailQueuePtr = quPtr.newQueuePtr;
        quPtr.headQueuePtr -> pointerPrevObj = quPtr.tailQueuePtr;
        quPtr.newQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.currQueuePtr -> pointerNextObj = quPtr.newQueuePtr;
        quPtr.currQueuePtr = quPtr.newQueuePtr;
    }
}

void moveCurrQueueElemToHead(struct queuePtr &quPtr)
{
    quPtr.currQueuePtr = quPtr.headQueuePtr;
}

void moveCurrQueueElemToTail(struct queuePtr &quPtr)
{
    quPtr.currQueuePtr = quPtr.tailQueuePtr;
}


bool checkTailQueueElem(struct queuePtr quPtr)
{
    if (quPtr.currQueuePtr == quPtr.tailQueuePtr)
    {
        return true;
    }    
    else
    {
        return false;
    }  
}

bool checkNullNextElem(struct queuePtr quPtr)
{
    if (quPtr.currQueuePtr -> pointerNextObj == nullptr)
    {
        return true;
    }    
    else
    {
        return false;
    }  
}

void moveNextElemOfQueue(struct queuePtr &quPtr)
{
    quPtr.newQueuePtr = quPtr.currQueuePtr -> pointerNextObj;
    quPtr.currQueuePtr = quPtr.newQueuePtr;
}

void movePrevElemOfQueue(struct queuePtr &quPtr)
{
    quPtr.newQueuePtr = quPtr.currQueuePtr -> pointerPrevObj;
    quPtr.currQueuePtr = quPtr.newQueuePtr;
}

void deleteCurrQueueElem(struct queuePtr &quPtr)
{
    quPtr.newQueuePtr = quPtr.currQueuePtr;
    quPtr.currQueuePtr = quPtr.newQueuePtr -> pointerNextObj;
    delete quPtr.newQueuePtr;
}

void showNumberOfCurrQueueElem(struct queuePtr quPtr)
{
    std::cout << quPtr.currQueuePtr -> objValue << ": ";
}

bool checkOnlyOneElemInQueue(struct queuePtr quPtr)
{
    if (quPtr.headQueuePtr -> pointerNextObj == nullptr || quPtr.headQueuePtr == quPtr.tailQueuePtr)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

bool checkEmptyQueueShowMessage(struct queuePtr quPtr)
{
    if (quPtr.headQueuePtr == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void changeIndexesInQueueAfterCurrElem(struct queuePtr &quPtr)
{
    bool tailFound = false;
    while (!tailFound)
    {
        quPtr.currQueuePtr = quPtr.currQueuePtr -> pointerNextObj;
        quPtr.currQueuePtr -> objValue++;        
        if (quPtr.currQueuePtr == quPtr.tailQueuePtr)
        {
            tailFound = true;
        }
    }
}

void reindexAllQueueElems(struct queuePtr &quPtr)
{
    quPtr.headQueuePtr -> objValue = 1;
    quPtr.currQueuePtr = quPtr.headQueuePtr; 
    for (bool tailFound = false; !tailFound;)
    {
        quPtr.currQueuePtr = quPtr.currQueuePtr -> pointerNextObj;
        if(quPtr.currQueuePtr != quPtr.headQueuePtr)
        {
            quPtr.currQueuePtr -> objValue = quPtr.currQueuePtr-> pointerPrevObj -> objValue + 1;
        }
        if (quPtr.currQueuePtr == quPtr.tailQueuePtr)
        {
            tailFound = true;
        }
    }
}

void insertNewElemToQueBefor(struct queuePtr &quPtr, struct stackPtr &stPtr)
{

    if (quPtr.currQueuePtr == quPtr.headQueuePtr)
    {
        quPtr.currQueuePtr = new queueListObject;
        quPtr.currQueuePtr -> objValue = 1;
        quPtr.currQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.currQueuePtr -> pointerPrevObj = quPtr.tailQueuePtr;
        quPtr.currQueuePtr -> pointerNextObj = quPtr.headQueuePtr;
        quPtr.headQueuePtr -> pointerPrevObj = quPtr.currQueuePtr;
        quPtr.tailQueuePtr -> pointerPrevObj = quPtr.currQueuePtr;
        quPtr.headQueuePtr = quPtr.currQueuePtr;  
        changeIndexesInQueueAfterCurrElem(quPtr);
    }

    else if (quPtr.currQueuePtr != quPtr.headQueuePtr)
    {    
        quPtr.newQueuePtr = new queueListObject;
        quPtr.newQueuePtr -> pointerPrevObj = quPtr.currQueuePtr -> pointerPrevObj;
        quPtr.newQueuePtr -> pointerNextObj = quPtr.currQueuePtr;
        quPtr.newQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.newQueuePtr -> objValue = quPtr.newQueuePtr -> pointerPrevObj -> objValue + 1;
        quPtr.currQueuePtr -> pointerPrevObj -> pointerNextObj = quPtr.newQueuePtr;
        quPtr.currQueuePtr -> pointerPrevObj = quPtr.newQueuePtr;
        quPtr.currQueuePtr = quPtr.newQueuePtr;
        changeIndexesInQueueAfterCurrElem(quPtr);
    }
}

void insertNewElemToQueAfter(struct queuePtr &quPtr, struct stackPtr &stPtr)
{

    if (quPtr.currQueuePtr == quPtr.tailQueuePtr)
    {
        quPtr.currQueuePtr = new queueListObject;
        quPtr.currQueuePtr -> objValue = quPtr.tailQueuePtr -> objValue + 1;
        quPtr.currQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.currQueuePtr -> pointerPrevObj = quPtr.tailQueuePtr;
        quPtr.currQueuePtr -> pointerNextObj = quPtr.headQueuePtr;
        quPtr.headQueuePtr -> pointerPrevObj = quPtr.currQueuePtr;
        quPtr.tailQueuePtr -> pointerNextObj = quPtr.currQueuePtr;
        quPtr.tailQueuePtr = quPtr.currQueuePtr;  
    }
    else 
    {    
        quPtr.newQueuePtr = new queueListObject;
        quPtr.newQueuePtr -> objValue = quPtr.currQueuePtr -> objValue + 1;
        quPtr.newQueuePtr -> pointerStackTop = stPtr.topStackPtr;
        quPtr.newQueuePtr -> pointerPrevObj = quPtr.currQueuePtr;
        quPtr.newQueuePtr -> pointerNextObj = quPtr.currQueuePtr -> pointerNextObj;
        quPtr.currQueuePtr -> pointerNextObj -> pointerPrevObj = quPtr.newQueuePtr;
        quPtr.currQueuePtr -> pointerNextObj = quPtr.newQueuePtr;
        quPtr.currQueuePtr = quPtr.newQueuePtr;
        changeIndexesInQueueAfterCurrElem(quPtr);
    }
}
 









