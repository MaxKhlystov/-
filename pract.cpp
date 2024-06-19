#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int numberElements = 1;
vector <int> arrayOfIntegers(numberElements);
int numberOddElements = 0;
void outputMenu()
{
    cout << "Меню: " << endl;
    cout << "Для повторного вывода меню на экран введите (1): " << endl;
    cout << "Для вывода условия задания на экран введите (2): " << endl;
    cout << "Для ввода кол-ва элемементов и заполнения массива введите (3): " << endl;
    cout << "Для вывода исходного массива введите (4): " << endl;
    cout << "Для удаления всех чётных элементов в массиве введите (5): " << endl;
    cout << "Для вывода полученного массива введите (6): " << endl;
    cout << "Выход (7): " << endl;
}
void outputTask()
{
    cout << "<<Удалить из массива целых чисел все чётные значения.>>" << endl;
}

void enterSizeArrayAndFill()
{
    cout << "Введите желаемый размер массива:"; cin >> numberElements;
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
}

void outputReceivedArray()
{
    if (numberElements == 0)
    {
        cout << "Исходный массив состоял только из чётных элементов. Они все были удалены ";
    }
    else
        cout << "Полученный массив:" << endl;
    for (int i = 0; i < numberElements; i++)
    {
        cout << setw(2) << arrayOfIntegers[i];
    }
    cout << endl;
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
            deleteEvenElements();
            break;
        case 6:
            outputReceivedArray();
            break;
        case 7:
            exit(0);
        default:
            cout << "Команды с таким номером нет. Введите команду заново:"; cin >> userChoice;
        }
        cout << "Введите следующую команду: "; cin >> userChoice;
    } while (true);
}
