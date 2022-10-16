# Упражнение 2

## [Входно-изходни потоци](https://en.cppreference.com/w/cpp/header/iostream)
```cpp
#include <iostream>
```

- Стандартен вход (клавиатура)
```cpp
int foo;
std::cin >> foo;
```

- Стандартен изход (терминал)
```cpp
std::cout << "Hello World!" << std::endl;
```

- Стандартен изход за грешки (терминал)
```cpp
std::cerr << "Oops: something went wrong!" << std::endl;
```


## [Променливи](https://en.cppreference.com/book/intro/variables)
```cpp
bool a = true, b = false;
int i = 42;
float g = 9.8;
const double PI = 3.14;
```


## [Аритметични операции](https://en.cppreference.com/w/cpp/language/operator_arithmetic): `+`, `-`, `*`, `/`, `%`

**N.B.** Ако `a` и `b` са цели числа, то `a / b` извършва **целочислено** делене.
```cpp
int a = 7, b = 2;
int c = a / b;
std::cout << c << std::endl; // Ще отпечата 3, не 3.5
```


## Побитови операции: `&`, `|`, `~`, `^`, `>>`, `<<`
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


## [Логически операции](https://en.cppreference.com/w/cpp/language/operator_logical): `&&`, `||`, `!`
```cpp
bool a = true, b = false;

bool not_a = !a;		// not a;
bool a_or_b = a || b;	// a or b;
bool a_and_b = a && b;	// a and b;
```


## Условни оператори: `if-else`, `switch`

#### [if-else](https://en.cppreference.com/w/cpp/language/if)
```cpp
if (a > b) {
	max = a;
} else {
	max = b;
}
```

#### [switch](https://en.cppreference.com/w/cpp/language/switch)
```cpp
switch (a > b) {
	case true:
		max = a;
		break;

	default:
		max = b;
}
```


## Цикли: `for`, `while`, `do-while`

#### [for](https://en.cppreference.com/w/cpp/language/for)
```cpp
int sum = 0;
for(int i = 0; i < 10; i ++) {
	sum += i;
}
```

#### [while](https://en.cppreference.com/w/cpp/language/while)
```cpp
int sum = 0;
int i = 0;
while (i < 10) {
	sum += i;
	i += 1;
}
```


## [Функцията `main`](https://en.cppreference.com/w/cpp/language/main_function)

```cpp
int main() {
	/* Insert code here ... */
	return 0;
}
```


## Задачи

1. Напишете програма, която прочита цяло число и отпечатва сбора от цифрите му.

2. Напишете програма, която прочита цяло число и отпечатва най-голямата му цифра.

3. Напишете програма, която прочита цяло число и отпечатва произведението на всички негови цифри, който се намират на четна позиция и се делят на 3.

4. Напишете програма, която прочита две цели числа `n` и `k` и отпечатва `n` на степен `k`. (Труден вариант: използвайте най-малкия възможен брой умножения, за да пресметнете степента).

5. Напишете програма, която прочита две цели числа `a` и `b` и отпечатва дали `b` се съдържа в `a`.
_Примери:_
  a    b
1234  12  -> true
1234  23  -> true
1234  34  -> true
1121 121  -> true
1121 111  -> false

## Домашно:

1. Напишете програма, която прочита цяло число и отпечатва дали десетичните му цифри са подредени в нарастващ ред.

_Примери:_
1234 -> true
1127 -> true
1244 -> true
1243 -> false
