<a name="Hanoi-Scientific"></a>

<!-- PROJECT LOGO -->
<div align="center">
  <span>
    <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width=25 height=25/>
    <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/windows8/windows8-original.svg" width=25 height=25/>
    <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg" width=25 height=25/>
    <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cmake/cmake-original.svg" width=25 height=25/>
  </span>
  <br/>
  <img src="https://github.com/ArtemBystrovOfficial/Hanoi-Scientific/assets/92841151/0453a82e-80ee-4109-884b-5c8af5277048"/>
  <h2 align="center">Hanoi-Scientific</h2>

  <p align="center">
    Быстрая навигация
	  <br/>
    <a href="#about"><strong>О проекте</strong></a>
    <br />
    <a href="#name">Зависимости</a>
    ·
    <a href="#installing">Сборка</a>
    ·
    <a href="#license">Лицензия</a>
  </p>
</div>


<!-- ABOUT THE PROJECT -->
<a name="about"></a>
 ## О проекте

Проект посвящен обобщенной задаче о ханойской башне, о нахождения минимального количества перестановок для любого количества стержней и колец.
До сих пор в мире официально не было найдено универсального решения, и благодаря долгим изучением этой темы в разных областях математики и информатики, удалось
найти решение, которое позже будет выложено в научные источники. 

Конкретно данный репозиторий создан для симуляции сложной рекурсии, которая не отсекает правильные решения, и является одним из доказательств теории, ведь самостоятельно
перебирает все возможные варианты.

<a name="stack"></a>
### Зависимости и стек

- Boost 1.82.0 Lockfree
- Boost 1.82.0 Test
- C++17

<a name="installing"></a>
### Сборка и использование

Установите Boost https://www.boost.org/users/history/version_1_82_0.html
Используйте CMakeLists.txt для сборки
```cmake
  mkdir build
  cd build
  cmake ..
  cmake --build -j(n) .
```
```c++
#include "../include/hanoi.hpp"

int main() {
	auto b = hanoi::singleRun<5, 15, true>(); //параллельная реализация
}
```
```bash
[ RAW 7 4 7 3 0 0 1 4 7 0 2 3 2 2 1 0 1 4  ] -> побайтовое представление данных кадра
|---->| -> последний ход
------- -> текущие состаяние башен



  2 0
  3 1 4
------- | MOV: 7 ( 13 ) -> минимальное количество ходов
Efficiency coficent: -> работа оптимизаций
        AdvantageColumns        69
        LastStepNoneMoveble     81
        BasicShiftingRules      140
        AntiLoopDP      58
        EmptyMove       0
        BadGenerations  0
        SimetricMoves   0
Total frames: 33 -> количество обработанных кадров
Time execution: 0.162151s
```
