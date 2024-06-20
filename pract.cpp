//добавление в нужную позицию 1 элемента
//git branch -M main
//git push -u origin main
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int numberElements=100;
vector <int> arrayOfIntegers(numberElements);
int numberOddElements = 0;
int numberElement;
int userChoice1;
int newElement;
void outputMenu()
{
    cout << "Меню: " << endl;
    cout << "Для повторного вывода меню на экран введите (1): " << endl;
    cout << "Для вывода условия задания на экран введите (2): " << endl;
    cout << "Для ввода кол-ва элемементов и заполнения массива введите (3): " << endl;
    cout << "Для вывода исходного массива введите (4): " << endl;
    cout << "Для ввода, замены, удаления элемента введите (5): " << endl;
    cout << "Для удаления всех чётных элементов в массиве введите (6): " << endl;
    cout << "Выход (7): " << endl;
}
void outputTask()
{
    cout << "<<Удалить из массива целых чисел все чётные значения.>>" << endl;
}

void enterSizeArrayAndFill()
{
    cout << "Введите желаемый размер массива: "; cin >> numberElements;
    while (numberElements <= 0)
    {
        cout << "Размер массива должен быть > 0. Введите размер заново: "; cin >> numberElements;
    }
    for (int i = 0; i < numberElements;)
    {
        cout << "Введите элемент: ";
        cin >> arrayOfIntegers[i];
        cout << "Ячейка " << ++i << " заполнена" << endl;
    }
}

void outputOriginalArray()
{
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < numberElements; i++)
    {
        cout << setw(2) << arrayOfIntegers[i];
    }
    cout << endl;
}

void outputNotOriginalArray()
{
    cout << "Полученный массив:" << endl;
    for (int i = 0; i < numberElements; i++)
    {
        cout << setw(2) << arrayOfIntegers[i];
    }
    cout << endl;
}

void insertElement()
{
    cout << "Вы хотите заменить элемент (0), добавить (1) или удалить (2)?: "; cin >> userChoice1;
    while (userChoice1 != 0 && userChoice1 != 1 && userChoice1 != 2)
    {
        cout << "Действия с таким выбором нет. Введите свой выбор заново: "; cin >> userChoice1;
    }
    if (userChoice1 == 0)
    {
        cout << "Какой номер элемента, который вы хотите заменить?: "; cin >> numberElement;
        while (numberElement<0 || numberElement>=numberElements)
        {
            cout << "Элемента с таким номером нет. Введите номер заново: "; cin >> numberElement;
        }
        cout << "Введите число:"; cin >> newElement;
        arrayOfIntegers[numberElement-1] = newElement;
        outputNotOriginalArray();
    }
    if (userChoice1 == 1)
    {
        cout << "Какой номер элемента, который вы хотите добавить?: "; cin >> numberElement;
        while (numberElement < 0 || numberElement-1 > numberElements)
        {
            cout << "Вы не можете добавлять элементы, номер которых больше " <<numberElements+1<<".Введите номер заново : "; cin >> numberElement;
        }
        numberElements += 1;
        for (int i = numberElements - 1; i >= numberElement; i--)
        {
            arrayOfIntegers[i] = arrayOfIntegers[i-1];
        }
        cout << "Введите число:"; cin >> newElement;
        arrayOfIntegers[numberElement-1] = newElement;
        outputNotOriginalArray();
    }
    if (userChoice1 == 2)
    {
        cout << "Какой номер элемента, который вы хотите удалить?: "; cin >> numberElement;
        while (numberElement < 0 || numberElement - 1 > numberElements)
        {
            cout << "Элемента с таким номером нет .Введите номер заново : "; cin >> numberElement;
        }
        for (int i = numberElement - 1; i < numberElements; i++)
        {
            arrayOfIntegers[i] = arrayOfIntegers[i + 1];
        }
        numberElements -= 1;
        outputNotOriginalArray();
    }
}

void deleteEvenElements()
{
    for (int i = 0; i < numberElements; i++)
    {
        if (arrayOfIntegers[i] % 2 != 0)
        {
            arrayOfIntegers[numberOddElements] = arrayOfIntegers[i];
            numberOddElements++;
        }
    }
    numberElements = numberOddElements;
    cout << "Все чётные элементы успешно удалены " << endl;
    int choice;
    cout << "Хотите посмотреть полученный массив. Да (0), Нет (1): "; cin >> choice;
    if (choice == 0)
    {
        if (numberElements == 0)
        {
            cout << "Исходный массив состоял только из чётных элементов. Они все были удалены ";
        }
        else outputNotOriginalArray();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    outputMenu();
    int userChoice;
    cout << "Введите команду: "; cin >> userChoice;
    do
    {
        switch (userChoice)
        {
        case 1:
            outputMenu();
            break;
        case 2:
            outputTask();
            break;
        case 3:
            enterSizeArrayAndFill();
            break;
        case 4:
            outputOriginalArray();
            break;
        case 5:
            insertElement();
            break;
        case 6:
            deleteEvenElements();
            break;
        case 7:
            exit(0);
        default:
            cout << "Команды с таким номером нет. Введите команду заново:"; cin >> userChoice;
        }
        cout << "Введите следующую команду: "; cin >> userChoice;
    } while (true);
}
