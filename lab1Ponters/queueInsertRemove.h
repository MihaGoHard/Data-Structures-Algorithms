/*
  functions in module
    insertNewStackInQueue
    delStackFromQue
    chooseStackDeleteItFromQue
    fillStackAddToQueueTail
    fillStackAddToQueue
    checkEmtyQueueCreateNewQeueu
*/



void insertNewStackInQueue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    int stackIndex = 0;
    int direction = -1;
    showMessage("\nвведите номер стэка в очереди, относительно которого хотите вставить новый элемент и нажмите `Enter`", true);
    showQueueOfStacks(quPtr, stPtr);
    checkIndexShowMistace(quPtr, stackIndex);

    std::cout << "\n   для вставки перед элементом `"; 
    std::cout << stackIndex;
    std::cout << "` нажать 0, затем `enter`\n";

    std::cout << "\n   для вставки после элемента `"; 
    std::cout << stackIndex;
    std::cout << "` нажать 1, затем `enter`\n";


    std::cin >> direction;
    while(!checkZeroOrOne(direction)) 
    {
        showMessage("Введите 1 или 0 и нажмите `Enter`", true);
        std::cin >> direction;
    }

    getCurrQueueElement(quPtr, stackIndex);
    
    if (direction == 0)
    {
        insertNewElemToQueBefor(quPtr, stPtr);
    }

    if (direction == 1)
    {
        insertNewElemToQueAfter(quPtr, stPtr);
    }
    setCurrStackPtrToNull(stPtr);
}

void delStackFromQue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    if (checkOnlyOneElemInQueue(quPtr))
    {
        if(quPtr.currQueuePtr -> pointerStackTop != nullptr)
        {
            deleteStackOfCurrQueueElem(quPtr, stPtr);
        }   
        delete quPtr.currQueuePtr;
        setAllPointersToNull(quPtr, stPtr);
    }
    else if (quPtr.currQueuePtr == quPtr.headQueuePtr)
    {
        quPtr.tailQueuePtr -> pointerNextObj = quPtr.currQueuePtr -> pointerNextObj;
        quPtr.currQueuePtr -> pointerNextObj -> pointerPrevObj = quPtr.tailQueuePtr;
        quPtr.headQueuePtr = quPtr.currQueuePtr -> pointerNextObj;
        if(quPtr.currQueuePtr -> pointerStackTop != nullptr)
        {
            deleteStackOfCurrQueueElem(quPtr, stPtr);
        }
        delete quPtr.currQueuePtr;   
    }
    else if(quPtr.currQueuePtr == quPtr.tailQueuePtr)
    {
        quPtr.tailQueuePtr -> pointerPrevObj -> pointerNextObj = quPtr.headQueuePtr;
        quPtr.headQueuePtr -> pointerPrevObj = quPtr.tailQueuePtr -> pointerPrevObj;
        quPtr.tailQueuePtr = quPtr.tailQueuePtr -> pointerPrevObj;
        if(quPtr.currQueuePtr -> pointerStackTop != nullptr)
        {
            deleteStackOfCurrQueueElem(quPtr, stPtr);
        }
        delete quPtr.currQueuePtr;
    }
    else if (quPtr.currQueuePtr != quPtr.headQueuePtr)
    {
        quPtr.currQueuePtr -> pointerPrevObj -> pointerNextObj = quPtr.currQueuePtr -> pointerNextObj;
        quPtr.currQueuePtr -> pointerNextObj -> pointerPrevObj = quPtr.currQueuePtr -> pointerPrevObj;
        if(quPtr.currQueuePtr -> pointerStackTop != nullptr)
        {
            deleteStackOfCurrQueueElem(quPtr, stPtr);
        }
        delete quPtr.currQueuePtr;
    }
    quPtr.currQueuePtr = nullptr;
    if(!checkEmptyQueueShowMessage(quPtr))
    {
        reindexAllQueueElems(quPtr);
    }
}


void chooseStackDeleteItFromQue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    int stackIndex = 0;
    showMessage("\nВведите индекс стека, котрый хотите удалить", true);
    showQueueOfStacks(quPtr, stPtr);
    checkIndexShowMistace(quPtr, stackIndex);

    showMessage("\nудалён стек: ", false);

    getCurrQueueElement(quPtr, stackIndex);
    stPtr.currStackPtr = quPtr.currQueuePtr -> pointerStackTop;
    showStack(stPtr);
    delStackFromQue(quPtr, stPtr);
}

void fillStackAddToQueueTail(struct queuePtr &quPtr, struct stackPtr &stPtr)
{   
    readDigitCreatNumFillStack(quPtr, stPtr);
    checkQueHeadAddStackToQue(quPtr, stPtr);
    setCurrStackPtrToNull(stPtr);
    showQueueOfStacks(quPtr, stPtr);
}

void fillStackAddToQueue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    readDigitCreatNumFillStack(quPtr, stPtr);
    insertNewStackInQueue(quPtr, stPtr);
}

void checkEmtyQueueCreateNewQeueu(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    if(!checkEmptyQueueShowMessage(quPtr))
    {
        std::cout << "\n";
        showQueueOfStacks(quPtr, stPtr);
    }    
    else
    {
        showMessage("\nОчередь очищена", true);
        showFirstMessage();
        fillStackAddToQueueTail(quPtr, stPtr);
    }
}