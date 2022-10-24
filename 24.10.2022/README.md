# Упражнение 3

### Въпроси: Какъв е резултата от изпълнението на следните фрагменти код?

```cpp
int x = -7;
unsigned int y = x;
std::cout << x << std::endl;
std::cout << y << std::endl;
```

```cpp
int c = 5;
if (c = 7) {
	int d = (c += 7) + (++ c);
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}
```

```cpp
int main() {
	std::cout << "foo" << std::endl;
}
```

```cpp
void main() {
	std::cout << "foo" << std::endl;
}
```


### [`const`](https://www.geeksforgeeks.org/const-keyword-in-cpp/) или как да си го направим _малко_ по-трудно да се застреляме в крака.
```cpp
int foo = 5;
foo += 7;            // ok - foo is now 12

const int bar = 5;

if (bar = 7) { ... } // compile time error: bar is const!

bar += 7;            // compile time error: bar is const!
int baz = bar + 7;   // ok - baz = 12
```


## [Функции](https://en.cppreference.com/w/cpp/language/functions)
```cpp
bool isEven(const int n) {
	return n % 2 == 0;
}

int factorial(const int n) {
	int res = 1;
	for (int i = 1; i <= n; i ++) {
		res *= i;
	}
	return res;
}

int sumArith(const int a, const int b, const int step) {
	int res = 0;
	for (int x = a; x < b; x += step) {
		res += x;
	}
	return res;
}

double pow(const double x, const int n) {
	if (n < 0) {
		return 1 / pow(x, n);
	} else {
		return n == 0 ? 1 : x * pow(x, n - 1);
	}
}
```


## Задачи

1. Напишете функция, която приема две дати и връща дали първата от тях е преди втората.


2. Напишете функция, която приема положително цяло число и връща дали то е просто.


3. Напишете прорама, която прочита положително цяло число $k$ и отпечатва всички Мерсенови прости числа с $k$ или по-малко цифри. Наричаме едно просто число [Мерсеново просто](https://en.wikipedia.org/wiki/Mersenne_prime) ако е от вида $2^p - 1, p \in \mathbb{N}$.


4. Палиндроми: Напишете функция, която приема положително цяло число и връща дали то е палиндром.


5. [Редица на Колац](https://en.wikipedia.org/wiki/Collatz_conjecture): Напишете програма, която прочита положително цяло число $x$ и отпечатва всички членове на редицата на Колац, започваща от $x$ (разделенени с интервали). Редицата на Колац се дефинира като:
* ако $x_n = 1$:        край на редицата
* ако $x_n$ е четно:    $x_{n+1} = x_n / 2$
* ako $x_n$ е нечетно:  $x_{n+1} = 3 * x_n + 1$


6. [Вавилонски метод за корен квадратен](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method): напишете функция, която приема положителни числа $x$ и $\epsilon$ и пресмята $\sqrt{x}$ посредством следната редица от приближения:
* $x_0 = x$
* $x_{n+1} = 1/2 * (x_n + x / x_n)$, докато $|x_{n+1} - x_n| \ge \epsilon$


## Домашно:

1. Напишете програма, която прочита две дати (във формат dd mm yyyy) и връща броя на дните от първата до втората.
