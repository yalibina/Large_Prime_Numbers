# Курсовой проект "Большие простые числа"

Программное решение для факторизации и проверки на простоту больших чисел. 

## Используемые библиотеки:

* [Boost multiprecision 1.84.0](https://github.com/boostorg/multiprecision.git) для представления больших чисел
* [Google C++ Testing Framework](https://github.com/google/googletest) для тестирования
* Стандартная библиотека C++ для некоторых структур данных и генератора mt19937
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

## Функционал библиотеки

Используется alias ``using large_int = boost::multiprecision::cpp_int``.

``enum class TestStatus { Prime, StrongProbablyPrime, ProbablyPrime, Composite }``

1. В папке ``factorization`` находятся методы для факторизации:
   * ``trial_division_to_max`` - перебор делителей до заданного максимального, возвращается разложение на простые
   * ``fermat_factorization`` - метод факторизации Ферма, возвращается найденный делитель 
   * ``pollard_rho`` - Ро-алгоритм Полларда, возвращается найденный делитель или -1, если за указанное число итераций не было найдено делителя
   * ``pollard_p1`` - p-1 - алгоритм Полларда, возвращается найденный делитель или -1, если за указанное число итераций не было найдено делителя
2. В папке ``rsa`` находятся классы для симуляции работы криптосистемы RSA (продемонстрированно в ``main.cpp``)
3. В папке ``test_primality`` находятся методы проверки на простоту, возвращается значение из перечисления ``TestStatus``:
   * ``test_fermat_base`` - тест Ферма на псевдопростоту по заданному основанию
   * ``test_lucas_lehmer`` - тест Люка-Лемера для чисел Мерсенна по заданной экспоненте
   * ``test_lucas_spsp`` - тест Люка на сильную псевдопростоту
   * ``test_miller_rabin`` - тест Миллера-Рабина на сильную псевдопростоту, задаётся максимальное кол-во итераций
   * ``test_trial_division_to_max`` - перебор делителей до заданного максимального
4. В папке ``utilities`` находятся вспомогательные методы:
   * ``fast_pow``, ``fast_pow_mod`` - алгоритмы быстрого возведения в степень или в степень по модулю
   * ``calc_gcd`` - алгоритм Евклида, возвращает НОД двух чисел
   * ``knuth_gcd`` - расширенный алгоритм Евклида, возвращает структуру ``Gcd {m, n, gcd}``, $gcd = gcd(a,b) = m * a + n * b$
   * ``int_sqrt`` - возвращает наименьшее целое число, большее квадратного корня из числа
   * ``reduce_by_k`` - выделяет максимальную степень числа $k$ из множителей заданного числа.
   * ``generate_prime`` - генерирует сильно возможно простое число с заданным количеством бит.

## Пример использования библиотеки
Библиотека находится в ``namespace Proj``.
В корне проекта находится файл ``main.cpp``, в котором содержатся примеры работы с библиотекой.
