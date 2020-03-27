/*
                              Условие задачи.

     Создать абстрактный класс Function с функциями вычисления значения по формуле
     y = f(x) в заданной точке, а так же функцией, выводящей информацию о виде
     функции на экран.
     Создать производные классы: Line(y = ax + b), Kub(y = ax^2 + bx + c),
     Hyperbola(y = a / x).
     Создать массив n функций и вывести полную информацию о значениях данных функций
     в точке x.
*/


                    /*  Код программы  */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <list>


#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

//ifstream in("/Users/nikita/Documents/Atom project/input.txt");
//ofstream out("/Users/nikita/Documents/Atom project/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

class Object {
public:
     virtual void print() = 0;
     virtual double func() = 0;
};
class Line : public Object {
protected:
     int x;
     int a,b;
public:
     Line() : x(0), a(0), b(0) {};
     Line(int x, int a, int b) : x(x), a(a), b(b) {};
     void print() {
          cout << "Уравнение линии: ";
          cout << "y = " << a << "x + " << b << endl;
     }
     double func() {
          return a*x + b;
     }

};
class Kub : public Line {
protected:
     int c;
public:
     Kub(): Line(), c(0) {};
     Kub(int x, int a, int b, int c) : Line(x,a,b), c(c) {};
     void print() {
          cout << "Уравнение параболы: ";
          cout << "y = " << a << "x^2 + " << b << "x + " << c << endl;
     }
     double func() {
          return a*x*x + b*x + c;
     }
};
class Hyperbola : public Object {
protected:
     int x;
     int a;
public:
     Hyperbola() : x(0), a(0) {};
     Hyperbola(int x, int a) : x(x), a(a) {};
     void print() {
          cout << "Уравнение гиперболы: ";
          cout << "y = " << a << "/x" << endl;
     }
     double func() {
          return double(a) / x;
     }
};

int main () {
     int n;
     cout << "Введите n: ";
     cin >> n;
     Object *arr[n];
     cout << "1 - Line" << endl;
     cout << "2 - Kub" << endl;
     cout << "3 - Huperbola" << endl;
     forn(i,n) {
          metka :cout << "Введите 1,2 или 3: " << endl;
          int z;
          cin >> z;
          if (z == 1) {
               int a,b,x;
               cout << "Введите x, a, b: ";
               cin >> x >> a >> b;
               arr[i] = new Line (x,a,b);
          }
          else {
               if (z == 2) {
                    int a,b,c,x;
                    cout << "Введите x, a, b, c: ";
                    cin >> x >> a >> b >> c;
                    arr[i] = new Kub(x,a,b,c);
               }
               else {
                    if (z == 3) {
                         int a,x;
                         cout << "Введите x, a: ";
                         cin >> x >> a;
                         arr[i] = new Hyperbola(x,a);
                    }
                    else {
                         cout << "Повторите попытку)" << endl;
                         goto metka;
                    }
               }
          }
     }
     forn(i,n) {
          arr[i] -> print();
          cout << "Функция y равна: ";
          cout << "y = " << arr[i] -> func() << endl;
     }


}
