/*
  functions in module
    showMessage
    <different Message functions>
    checkRightDirection
    getch
    pressedButton
    addDigitToNumberShowDigit
    checkZeroOrOne    
    setAllPointersToNull    
*/

void showMessage(std::string message, bool moveNextString)
{   
    if(moveNextString)
    {
        std::cout << message << std::endl;
    }
    else
    {
        std::cout << message;
    }   
}

void showFirstMessage()
{
    showMessage("Меню:", true);
    showMessage("   Для заполнения первого стека введите числа через пробел", true);
    showMessage("   Для создания первого элемента очереди, после ввода чисел нажмите `enter`", true);
}

void showIndexStackChoiceMenu()
{
    showMessage("\nМеню:", true);
    showMessage("   введите номер стэка в очереди, который хотите изменить и нажмите `Enter`", true);
}

void showChangeStackMenu()
{
    showMessage("Меню:", true);
    showMessage("   дополнение стека числами -`z`", true);
    showMessage("   удаление чисел из вершины стека - `x`", true);
}

void showAddStackCommands()
{
    showMessage("Команды:", true);
    showMessage("  добавление числа в вершину стека - ввести число, нажать `пробел`", true);
    showMessage("  подтвердить изменения - `enter`", true);
}

void showRemoveStackCommands()
{
    showMessage("Команды:", true);
    showMessage("  удаление вершины стека - `пробел`", true);
    showMessage("  подтвердить изменения - `enter`", true);
}

void showMainNavMessage()
{
    showMessage("Меню:", true);
    showMessage("   добавление в конец очереди нового стека - `c`", true);
    showMessage("   продвижение одного стека в очереди - `z`", true);
    showMessage("   добавления нового стека в любое место очереди - `x`", true);
    showMessage("   удаления стека из очереди - `v`", true);
    showMessage("   изменение одного стека - `s`", true);
    showMessage("   получение стека из очереди - `b`", true);
    showMessage("   удаление очереди - `d`, выход - `q`", true);
}

void showFillNewStackMessage()
{
    showMessage("Меню:",true);
    showMessage("   заполните новый стек числами через пробел и намжмите `enter`",true);
}


void showStackMoveMenu()
{
    showMessage("\nДля продвижения, выбранного стека, в начало очереди нажмите `W`", true);
    showMessage("Для продвижения, выбранного стека, в конец очереди нажмите`S`", true);
    showMessage("Чтобы вернуться назад нажмите `Q`", true);
}

void showFillStackMessage()
{
    showMessage("Меню:", true);
    showMessage("   заполните новый стек числами через пробел", true);
    showMessage("   для добавления стека в конец очереди нажмите `enter`", true);
}

bool checkRightDirection(int direction)
{
    if (direction == 1 || direction == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

char pressedButton()
{
    return char(getch());
}

void addDigitToNumberShowDigit(char buttonValue, int &inputNumber)
{
    int inputDigit = 0;
    inputDigit = atoi(&buttonValue);
    std::cout << inputDigit; 
    inputNumber = inputNumber * 10 + inputDigit;
}

bool checkZeroOrOne(int direction)
{
    if (direction == 0 || direction == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setAllPointersToNull(struct queuePtr &quPtr, struct stackPtr &stPtr)
{
    quPtr.newQueuePtr = quPtr.headQueuePtr = quPtr.tailQueuePtr = quPtr.currQueuePtr = nullptr;
    stPtr.currStackPtr = stPtr.topStackPtr = stPtr.exchStPtr1 = stPtr.exchStPtr2 = nullptr;
}














