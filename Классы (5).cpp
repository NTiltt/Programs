/*

                              Условие задачи.

     Создать класс Complex для работы с комплексными числами, содержащий следующие
     члены класса:
     1) Поля:
     -- double realPart -- Действительная часть,
     -- double imaginaryPart -- мнимая часть,
     2) функции, позволяющие:
     -- вывести на экран комплексное число,
     -- создать сопряженное число,
     -- сравнить два числа на равенство.
     Кроме того реализовать перегрузку операций сложения, умножения, вычитания
     и деления комплексных чисел.
*/


                         /* Код задачи */
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
#include <stack>


#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long double ld;
const ld EPS = 1e-7;

//ifstream in("/Users/nikita/Documents/Atom project/input.txt");
//ofstream out("/Users/nikita/Documents/Atom project/output.txt");

class Complex {
private:
     double realPart;
     double imaginaryPart;
public:
     Complex():realPart(0),imaginaryPart(0) {};
     Complex(double real, double imaginary):
     realPart(real), imaginaryPart(imaginary) {};
     void paired(double realPart, double imaginaryPart);  // Сопряженное число
     bool check(Complex x, Complex y);  // Проверка на равенство
     Complex operator + (Complex &); // Сложение двух чисел
     Complex operator - (Complex &); // Разность двух чисел
     Complex operator * (Complex &); // Произведение двух чисел
     Complex operator / (Complex &); // Частное двух чисел
     friend istream &operator >> (istream &, Complex &);
     friend ostream &operator << (ostream &, Complex &);
};
void Complex::paired(double realPart, double imaginaryPart) {
     imaginaryPart *= -1;
     Complex q(realPart,imaginaryPart);
     cout << q << endl;
}
bool Complex::check(Complex x,Complex y) {
     if (abs(x.realPart - y.realPart) < EPS && abs(x.imaginaryPart - y.imaginaryPart) < EPS) {
          return 1;
     }
     else {
          return 0;
     }
}
Complex Complex::operator + (Complex &x) {
     x.realPart = realPart + x.realPart;
     x.imaginaryPart = imaginaryPart + x.imaginaryPart;
     return x;

}
Complex Complex::operator - (Complex &x) {
     x.realPart = realPart - x.realPart;
     x.imaginaryPart = imaginaryPart - x.imaginaryPart;
     return x;
}
Complex Complex::operator *(Complex &x) {
     double i,j;
     i = realPart * x.realPart - imaginaryPart * x.imaginaryPart;
     j = realPart * x.imaginaryPart + x.realPart * imaginaryPart;
     x.realPart = i;
     x.imaginaryPart = j;
     return x;
}
Complex Complex::operator / (Complex &x) {
     double i,j;
     i = (realPart * x.realPart + imaginaryPart * x.imaginaryPart) / (x.realPart * x.realPart + x.imaginaryPart * x.imaginaryPart);
     j = (x.realPart * imaginaryPart - realPart * x.imaginaryPart) / (x.realPart * x.realPart + x.imaginaryPart * x.imaginaryPart);
     x.realPart = i;
     x.imaginaryPart = j;
     return x;
}
istream &operator >> (istream &fi, Complex &fp) {
     cout << "Введите действительную и мнимую части:" << endl;
     fi >> fp.realPart >> fp.imaginaryPart;
     return fi;
}
ostream &operator << (ostream &fo, Complex &fn) {
     if (fn.imaginaryPart < 0) {
          fo << fn.realPart << "-" << (fn.imaginaryPart) * (-1) << "i" << endl;
     }
     else {
          fo << fn.realPart << "+" << fn.imaginaryPart << "i" << endl;
     }
     return fo;
}
int main() {
     Complex c,q,k;
     cout << "Введите два комплексных числа:" << endl;
     cin >> c >> q;
     if (c.check(c,q)) {
          cout << "Эти числа равны." << endl;
     }
     else {
          cout << "Эти числа не равны." << endl;
     }
     k = c + q;
     cout << "Их сумма равна: " << k;
     k = c - q;
     cout << "Их разность равна: " << k;
     k = c * q;
     cout << "Их произведение равно: " << k;
     k = c / q;
     cout << "Их частное равно: " << k;
}
