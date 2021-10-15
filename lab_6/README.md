# Лабораторная работа 6

## Задание 1

Модифицировать программы, составленные в **Л.Р. №№3,4**, используя переменные
семафорного типа. Измерять время работы программы для тех же значений параметров, что были
использованы при выполнении **Л.Р. №3**.

## Задание 2

Модифицировать программы, составленные в **Л.Р. №№3,4**, используя методы
барьерной синхронизации. Измерять время работы программы для тех же значений параметров, что были
использованы при выполнении **Л.Р. №3**.

## Как запустить

```
make; \
./bin/main 100
```

тут 100 - длина массивов (`N`)

## Результат работы

```
$ ./bin/main 100
N: 10; Paralled: 1; Product: 159667200; Elapsed time (ms): 0.1369
N: 10; Paralled: 0; Product: 159667200; Elapsed time (ms): 0.0015
With lock; N: 10; Paralled: 1; Product: 159667200; Elapsed time (ms): 0.0037
With lock; N: 10; Paralled: 0; Product: 159667200; Elapsed time (ms): 0.0013
With barrier; N: 10; Paralled: 1; Product: 159667200; Elapsed time (ms): 0.0030
With barrier; N: 10; Paralled: 0; Product: 159667200; Elapsed time (ms): 0.0012
```

```
$ ./bin/main 1000
N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.1572
N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0044
With lock; N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.1362
With lock; N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0157
With barrier; N: 1000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0068
With barrier; N: 1000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0071
```

```
$ ./bin/main 10000
N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 0.1558
N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0327
With lock; N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 1.4424
With lock; N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.1911
With barrier; N: 10000; Paralled: 1; Product:        0; Elapsed time (ms): 0.0548
With barrier; N: 10000; Paralled: 0; Product:        0; Elapsed time (ms): 0.0691
```

```
$ ./bin/main 100000
N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 0.2765
N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 0.3284
With lock; N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 18.1322
With lock; N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 1.9778
With barrier; N: 100000; Paralled: 1; Product:        0; Elapsed time (ms): 0.6604
With barrier; N: 100000; Paralled: 0; Product:        0; Elapsed time (ms): 0.8454
```

```
$ ./bin/main 1000000
N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 0.8881
N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 4.8713
With lock; N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 174.1061
With lock; N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 23.5832
With barrier; N: 1000000; Paralled: 1; Product:        0; Elapsed time (ms): 30.3266
With barrier; N: 1000000; Paralled: 0; Product:        0; Elapsed time (ms): 7.7148
```

```
$ ./bin/main 10000000
N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 10.4505
N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 40.2896
With lock; N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 1532.3101
With lock; N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 160.9275
With barrier; N: 10000000; Paralled: 1; Product:        0; Elapsed time (ms): 66.3096
With barrier; N: 10000000; Paralled: 0; Product:        0; Elapsed time (ms): 49.8434
```

Почти везде произошло переполнение переменной `prod`, но это нам не особо важно.

Время исполнения последовательного кода такое же, как в **Л.Р. №3**.

Результаты работы правильные (проверяется на маленьких `N`)

Видим, что код с барьерной синхронизацией работает быстрее кода с семафорными переменными, но при этом медленее, чем простой последовательный код.
И это логично, в целом, ведь оба этих метода требуют бОльшего количества операций.

Подобные механизмы стоило бы использовать в ситуациях когда нам важна последовательность операций.
Умножение же ассоциативно и коммутативно, поэтому в них нет особого смысла.
