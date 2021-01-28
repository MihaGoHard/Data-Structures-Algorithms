const char stopQueueFilling = 'q';
const char continueProgram = ' ';
const char space = ' ';
const char enter = '\n';
const int PREV = 0;
const int NEXT = 11;

struct stackListObject
{
    int objIndex;
    int objValue;
    stackListObject *pointerPrevObj = nullptr;
};

struct queueListObject
{
    int objValue;
    queueListObject *pointerNextObj = nullptr;
    queueListObject *pointerPrevObj = nullptr;
    stackListObject *pointerStackTop = nullptr;
};

struct queuePtr
{
    queueListObject *headQueuePtr = nullptr;
    queueListObject *tailQueuePtr = nullptr;
    queueListObject *currQueuePtr = nullptr;
    queueListObject *newQueuePtr = nullptr;
};

struct stackPtr
{
    stackListObject *topStackPtr = nullptr;
    stackListObject *currStackPtr = nullptr;
    stackListObject *exchStPtr1 = nullptr;
    stackListObject *exchStPtr2 = nullptr;

};
