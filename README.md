# Курсовой проект "Большие простые числа"

Программное решение для факторизации и проверки на простоту больших чисел. 

## Используемые библиотеки:

* [Boost multiprecision 1.85.0](https://github.com/boostorg/multiprecision.git) для представления больших чисел
* [Google C++ Testing Framework](https://github.com/google/googletest) для тестирования
* [magic_enum](https://github.com/Neargye/magic_enum) для работы с Enum (в примерах использования)

Библиотеки подтягиваются в CMakeLists.txt

## Требования
Используется C++17, компилятор должен быть совместим с ним.

## Сборка проекта через CMake

```
mkdir build
cd build
cmake ..
cmake --build
```

## Пример использования библиотеки
Библиотека находится в ``namespace Proj``.
В корне проекта находится файл ``main.cpp``, в котором содержатся примеры работы с библиотекой.
