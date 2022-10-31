# Упражнение 3


### Въпроси:

* Какъв е резултата от изпълнението на следните фрагменти код?

```cpp
int c = 5, d = 7;

if (c < d) {
	int c = 10;
	d = c;
}

std::cout << "c = " << c << ", d = " << d << std::endl;
```

```cpp
const double x = 1.5e7*3+1;
std::cout << x << std::endl;
std::cout << std::setprecision(10) << x << std::endl;
```

```cpp
const double x = 1.e16;;
const double y = x + 1;
std::cout << std::boolalpha << (x == y) << std::endl;
```

```cpp
int c = 5, d = 7, e = 2;
int f = ++e = c + d;

std::cout << "e = " << e << ", f = " << f << std::endl;
```

```cpp
int c = 5, d = 7, e = 2;
int f = ++(e = c + d);

std::cout << "e = " << e << ", f = " << f << std::endl;
```

* [_Maximal Munch_ Rule](https://en.wikipedia.org/wiki/Maximal_munch)
```cpp
int c = 5, d = 7, e = c+++d;
std::cout << "c = " << c << ", d = " << d << ", e = " << e << std::endl;
```

* Какво връщат следните функции?
```cpp
int foo(int n) {
	int i = 1;
	while (n > 0) {
		i *= n % 10;
		n /= 10;
	}
	return i;
}

int bar(int n) {
	int i = 1;
	for (; n > 0; n /= 10) {
		i *= n % 10;
	}
	return i;
}

int bar(int n) {
	int i = 1;
	for (; n > 0; i ++, n /= 10);
	return i;
}
```


### [`<cmath>`](https://en.cppreference.com/w/cpp/header/cmath): колекция от полезни математически функции наследени от _С_.

## Задачи
1. Напишете функция, която пресмята разстоянието между две точки в равнината.

2. Напишете функция, която пресмята разстоянието от точка до окръжност (център + радиус).

3. Напишете функция, която пресмята скаларното произведенение на два двуизмерни вектора.

4. Напишете функция, която пресмята ъгъла между два двуизмерни вектора.

5. Напишете функция, която пресмята лицето на тригълник по три точки.

6. Напишете програма, която прочита $x_{min}$, $x_{max}$ и $N$ и пресмята интеграла на $f(x) = x^2e^{-x}\sin(x)$ върху интервала $[x_{min}, x_{max}]$ посредством следното приближение $\int_{x_{min}}^{x_{max}} f(x)dx \approx \sum_{i=0}^{N-1} f(x_i)\Delta{x}$, където $\Delta{x} = (x_{max} - x_{min}) / N$ и $x_i = x_{min} + i \Delta{x}$.

7. Напишете функция, която връща дали едно число е съвършено. Наричаме _съвършено_ всяко положително число, което е равно на сбора на делителите си.

