#include "Choice.hpp"
#include "Functions.hpp"
#include <iostream>
#include <Windows.h>
#include "Functions.h"



int Choice()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 10;
    float array[size]{};

    int choice;
    int sortChoice;

    while (true) {
        system("cls");

        std::cout << "Программа для работы с массивом" << "\n";
        std::cout << "Выберите способ ввода массива:" << "\n";
        std::cout << "1. Ввести вручную" << "\n";
        std::cout << "2. Заполнить автоматически" << "\n";
        std::cout << "0. Выйти из программы" << "\n";
        std::cin >> choice;

        if (choice == 1) {
            manualInput(array, size);
        }
        else if (choice == 2) {
            autoInput(array, size);
        }
        else if (choice == 0) {
            break;
        }
        else {
            std::cout << "Некорректный выбор. Попробуйте снова." << "\n";
            continue;
        }

        system("cls");

        std::cout << "������:" << std::endl;
        printArray(array, size);

        std::cout << "Выберите способ сортировки:\n1) По убыванию\n2) По возрастанию\n3) Не изменять массив\n";
        std::cin >> sortChoice;

        switch (sortChoice) {
        case 1:
            bubbleSortDescending(array, size);
            printArray(array, size);
            break;
        case 2:
            bubbleSortAscending(array, size);
            printArray(array, size);
            break;
        case 3:
            std::cout << "Массив остается без изменений." << "\n";
            printArray(array, size);
            break;
        default:
            std::cout << "Некорректный выбор сортировки." << "\n";
            break;
        }

        system("pause");
    }

    return 0;
}