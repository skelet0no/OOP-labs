#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"

class Array {//предназначен для хранения массива указателей на объекты типа Figure
public:
    Array();// Конструктор по умолчанию
    Array(int size);// Конструктор с заданным размером
    virtual ~Array();// Деструктор

    void del_figure(int i);// Удаление фигуры по индексу
    void add(int i, Figure* figure); //Добавляет фигуру (Figure* figure) по указанному индексу i.
    double total_area();// Вычисление общей площади
    Figure* operator[](int i) const;// Оператор доступа по индексу(Перегруженный оператор [], который позволяет получать доступ к фигуре по индексу i. Возвращает указатель на фигуру (Figure*).)

private:
    Figure** _figures;// Массив указателей на фигуры
    int _size;// Размер массива
};

#endif //ARRAY_H
