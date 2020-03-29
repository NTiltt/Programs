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

class Triangle {
private:
    int a,b,c;
public:
    Triangle (): a(1), b(1), c(1) {};
    Triangle (int a, int b, int c): a(a), b(b), c(c) {};
    void print() {
        cout << "Сторона a: " << a << endl;
        cout << "Сторона b: " << b << endl;
        cout << "Сторона c: " << c << endl;
    }
    int per() {
        return a + b + c;
    }
    double area() {
        double p = double(a + b + c ) / 2;
        return sqrt(p*(p - a)*(p - b)*(p - c));
    }
    void get(int a, int b, int c) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    bool check() {
        if (a + b > c && a + c > b && b + c > a) {
            return true;
        }
        else {
            return false;
        }
    }
    Triangle operator ++ () {
        this -> a = this -> a + 1;
        this -> b = this -> b + 1;
        this -> c = this -> c + 1;
        return *this;
    }
    Triangle operator -- () {
        this -> a = this -> a - 1;
        this -> b = this -> b - 1;
        this -> c = this -> c - 1;
        return *this;
    }
    Triangle operator * (int c) {
        this -> a = this -> a * c;
        this -> b = this -> b * c;
        this -> c = this -> c * c;
        return *this;
    }
};

int main() {
    Triangle q;
    int a,b,c;
    cout << "Введите стороны треугольника: " << endl;
    metka: cin >> a >> b >> c;
    Triangle w(a,b,c);
    if (w.check()) {
        cout << "Ваш треугольник: " << endl;
        w.print();
        cout << "Периметр треугольника равен: " << w.per() << endl;
        cout << "Площадь треугольника равна: " << w.area() << endl;
        cout << "Увеличим все стороны треугольника на 1" << endl;
        ++w;
        w.print();
        cout << "Уменьшим все стороны на 1" << endl;
        --w;
        w.print();
        cout << "Введите число x: ";
        int x;
        cin >> x;
        cout << "Увеличим все стороны на число " << x << ":" << endl;
        w*x;
        w.print();
        cout << "Установим новые длины сторон треугольнику, введите три числа: ";
        int s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        w.get(s1,s2,s3);
        cout << "Новые треугольник готов: " << endl;
        w.print();
    }
    else {
        cout << "Ваш треугольник не существует, попробуйте еще раз:)" << endl;
        goto metka;
    }



}
