# Лабораторная работа 5

## Задание 1

Модифицировать программы, составленные в **Л.Р. №№3,4**, распределив
вычислительную нагрузку по секциям (как минимум двумя способами). Измерять время работы программы для тех же значений параметров, что были использованы при выполнении **Л.Р. №3**.

## Как запустить

```
make; \
./bin/main 100
```

тут 100 - длина массивов (`N`)

## Результат работы

```
$ ./bin/main 100
Sections: 0; N: 100; Paralled: 1; Product:        0; Elapsed time (ms): 0.1556
Sections: 0; N: 100; Paralled: 0; Product:        0; Elapsed time (ms): 0.0031
Sections: 2; N: 100; Paralled: 1; Product:        0; Elapsed time (ms): 0.0037
Sections: 2; N: 100; Paralled: 0; Product:        0; Elapsed time (ms): 0.0012
Sections: 4; N: 100; Paralled: 1; Product:        0; Elapsed time (ms): 0.0016
Sections: 4; N: 100; Paralled: 0; Product:        0; Elapsed time (ms): 0.0013
```

```
$ ./bin/main 1000
Sections: 0; N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.3050
Sections: 0; N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0051
Sections: 2; N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0054
Sections: 2; N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0043
Sections: 4; N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0024
Sections: 4; N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0048
```

```
$ ./bin/main 10000
Sections: 0; N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 0.4297
Sections: 0; N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0396
Sections: 2; N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0271
Sections: 2; N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0341
Sections: 4; N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0141
Sections: 4; N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0369
```

```
$ ./bin/main 100000
Sections: 0; N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 9.8408
Sections: 0; N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 0.5192
Sections: 2; N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 0.3153
Sections: 2; N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 0.4457
Sections: 4; N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 0.1989
Sections: 4; N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 0.4930
```

```
$ ./bin/main 1000000
Sections: 0; N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 37.0087
Sections: 0; N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 5.2074
Sections: 2; N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 3.1007
Sections: 2; N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 4.4398
Sections: 4; N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 1.8750
Sections: 4; N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 5.0873
```

```
$ ./bin/main 10000000
Sections: 0; N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 442.2037
Sections: 0; N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 42.6539
Sections: 2; N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 31.0706
Sections: 2; N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 37.3716
Sections: 4; N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 22.8008
Sections: 4; N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 39.4020

```

Почти везде произошло переполнение переменной `prod`, но это нам не особо важно.

Время исполнения последовательного кода такое же, как в **Л.Р. №3, 4**.

Разбил код на секции двумя способами (на 2 секции и на 4).

Видим, что быстрее всего работает код с 4 секциями, медленее всего - стандартная реализация совсем их объявления.
