# KISS
# Задача № 211

Алексеев Максим Б05-023

Задача решалась в предположении, что и текст, и строка влезет в оперативную память.

Идея решения:

Строим суффиксный автомат на тексте за O(n), где n - длина текста, в процессе предпосчёта насчитываем первое вхождение.
На запросы отвечаем за O(m), где m - длина запроса.

Инструкция по сборе:

mkdir build && cd build

cmake ..

make

После чего в папке build появится исполняемый файл KISS

Пример использования:

build/KISS input.txt

input: Good

return: 1

input: Task

return: 17

Также код можно использовать как библиотеку:

Надо подключить файл Solver.hpp, инициализировать класс Sover, в его конструктор передаётся название файла, для поиска первого вхождения надо вызвать у этого объекта функцию FirstEntry и передать туда искомую строчку.

