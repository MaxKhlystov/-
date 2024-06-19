#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void outputMenu()
{
    cout << "Меню: " << endl;
    cout << "Для повторного вывода меню на экран введите (0): " << endl;
    cout << "Для вывода условия задания на экран введите (1): " << endl;
    cout << "Для ввода кол-ва элемементов массива введите (2): " << endl;
    cout << "Для заполнения массива введите (3): " << endl;
    cout << "Для вывода исходного массива введите (4): " << endl;
    cout << "Для удаления всех чётных элементов в массиве введите (5): " << endl;
    cout << "Для вывода полученного массива введите (6): " << endl;
    cout << "Выход (7): " << endl;
}
void outputTask()
{
    cout << "<<Удалить из массива целых чисел все чётные значения.>>" << endl;
}

int main()
{
    int numberElements = 10;
    vector <int> arrayOfIntegers(numberElements);
    int numberOddElements = 0;
    setlocale(LC_ALL, "Russian");
    outputMenu();
    int userChoice;
    cout << "Введите команду: "; cin >> userChoice;
    do
    {
        switch (userChoice)
        {
        case 0:
            outputMenu();
            break;
        case 1:
            outputTask();
            break;
        case 2:
            cout << "Введите желаемый размер массива:"; cin >> numberElements;
            break;
        case 3:
            for (int i = 0; i < numberElements;)
            {
                cout << "Введите элемент: ";
                cin >> arrayOfIntegers[i];
                cout << "Ячейка " << ++i << " заполнена" << endl;
            }
            break;
        case 4:
            cout << "Исходный массив:" << endl;
            for (int i = 0; i < numberElements; i++)
            {
                cout << setw(2) << arrayOfIntegers[i];
            }
            cout << endl;
            break;
        case 5:
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
            break;
        case 6:
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
            break;
        case 7:
            exit(0);
        default:
            cout << "Команды с таким номером нет. Введите команду заново:"; cin >> userChoice;
        }
        cout << "Введите следующую команду: "; cin >> userChoice;
    } while (true);
}
