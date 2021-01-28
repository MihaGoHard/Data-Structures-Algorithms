/*
  Задание №19.
    *После запуска ввести через пробел числа. Каждое нажатие пробела помещает число в стек. 
     Далее нажать Enter => cоздаётся первый элемент очереди. 
    
        input:  1 2 3 4 5 enter

        output: 1: 5 4 3 2 1

        номер элемента очереди => 1: стек с вершиной "5" => 5 4 3 2 1

    *при добавлении нового стека создаётся новый элемент очереди.

        prev state:   1: 5 4 3 2 1

        input:        9 8 7 6 5 enter

        output:       1: 5 4 3 2 1          
                      2: 5 6 7 8 9


    *обращение к какому-либо элементу очереди(стеку) осущесвляется через его индекс
*/

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "const_objects.h"
#include "utils.h"
#include "queue.h"
#include "stack.h"
#include "common_operations.h"
#include "queueMove.h"
#include "queueInsertRemove.h"
#include "stackInsertRemove.h"


void fillQueueByStacksEditQueue(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    bool noFirstMessage = false;

    showFirstMessage();
    fillStackAddToQueueTail(quPtr, stPtr);
    
    for (bool stopSearch = false; !stopSearch;)
    {
        if (!noFirstMessage)
        {   
            showMainNavMessage();
            noFirstMessage = true;
        }

        switch(pressedButton())
        {
            case ('c'):
            {     
                showQueueOfStacks(quPtr, stPtr); 
                showFillStackMessage();
                fillStackAddToQueueTail(quPtr, stPtr);
                noFirstMessage = false;
                break;
            }   
            case ('z'):
            {   
                checkQueMoveStackInQue(quPtr, stPtr);
                showQueueOfStacks(quPtr, stPtr);
                noFirstMessage = false;
                break;
            }
            case ('x'):
            {
                showFillNewStackMessage();
                fillStackAddToQueue(quPtr, stPtr);
                showQueueOfStacks(quPtr, stPtr);
                noFirstMessage = false;
                break;
            }
            case ('v'):
            {
                chooseStackDeleteItFromQue(quPtr, stPtr);
                checkEmtyQueueCreateNewQeueu(quPtr, stPtr);                
                noFirstMessage = false;
                break;
            }
            case ('b'):
            {
                showStackByIndex(quPtr, stPtr);
                noFirstMessage = false;
                break;
            }
            case ('s'):
            {
                changeAnyStack(quPtr, stPtr);
                checkEmtyQueueCreateNewQeueu(quPtr, stPtr);
                noFirstMessage = false;  
                break;   
            }
            case ('d'):
            {
                deleteQueueOfStacks(quPtr, stPtr);
                checkEmtyQueueCreateNewQeueu(quPtr, stPtr);
                noFirstMessage = false;
                break;
            }
            case ('q'):
            {
                stopSearch = true;
                break;
            }
        }
    }       
}

int main()
{
    queuePtr quPtr;
    stackPtr stPtr;
  
    fillQueueByStacksEditQueue(quPtr, stPtr);
    if (!checkEmptyQueueShowMessage)
    {
        deleteQueueOfStacks(quPtr, stPtr);
    }    
}