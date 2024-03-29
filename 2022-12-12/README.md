### [Побитови операции](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/): `&`, `|`, `~`, `^`, `>>`, `<<`
```cpp
//  a = 8,      b = 7,      c = 5
int a = 0b1000, b = 0b0111, c = 0b0101;

int d = a & b;
int e = a | b;
int f = ~c;

int g = b ^ c;
int h = b >> 1;
int i = c << 3;
```


### Полезни връзки:
- [Имплементация на събиране](https://www.geeksforgeeks.org/full-adder-in-digital-logic/) посредством [логичеки елементи](https://bg.wikipedia.org/wiki/%D0%9B%D0%BE%D0%B3%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8_%D0%B5%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82)
- https://graphics.stanford.edu/~seander/bithacks.html: страница с много _"побитови-хакове"_ за имплементация на различни интересни/полезни функции.


## Задачи:

1. Имплементирайте следните функции:
   1. `bitSet`, която задава стойността на бита на дадена позиция на единица.
   2. `bitClear`, която задава стойността на бита на дадена позиция на нула.
   3. `bitFlip`, която обръща стойността на бита на дадена позиция.
   4. `bitGet`, която връща стойността на бита на дадена позиция.
   5. `bitMask`, която връща число, чийто първи $n$-бита са единици.

2. Напишете функция, която проверява дали дадено положително число е степен на двойката.

3. Дефинирайте функция, която приема символен низ и връща дали той е панграма (т.е. дали съдържа всяка буква от азбуката поне веднъж).

4. Дефинирайте функцията `strlen_UTF8`, която пресмята дължината на [UTF-8](https://en.wikipedia.org/wiki/UTF-8)-кодиран символен низ.

5. [Домашно] Имплементирайте следните функции:
   1. `countSetBits`, която връща броя на _"сетнатите"_ (т.е. равни на 1 битове в дадено число.
   2. `countTrailingZeros`, която връща броя на нулите след последния сетнат бит на дадено число.
   3. `countLeadingZeros`, която връща броя на нулите преди първия сетнат бит на дадено число.
