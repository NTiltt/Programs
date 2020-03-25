/*

                              Условие задачи.

     Создать класс для работы с двумерным массивом целых чисел. Разработать
     следующие члены класса:
     1) поле int [][] intArray;
     2) Функции позволяющие:
     -- ввести элементы массива с клавиатуры,
     -- вывести элементы массива на экран,
     -- вычислить сумму элементов i-го столбца,
     -- вычислить количество нулевых элементов в массиве,
     -- установить значение всех элементов главной диагонали массива, равное скаляру.
     Кроме того, необходимо реализовать перегрузку:
     -- операции ++(--), которая позволяет одновременно увеличить(уменьшить) значение
     всех элементов массива на единицу;
     -- операции +, которая позволяет сложить два массива соответствующих размерностей.
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

//ifstream in("/Users/nikita/Documents/Atom project/input.txt");
//ofstream out("/Users/nikita/Documents/Atom project/output.txt");

class Array {
private:
     int **mas;
     int n,m;
public:
     Array() {}
     Array(int n, int m) {
          mas = new int *[n];
          forn(i,n) {
               mas[i] = new int [m];
          }
          this -> n = n;
          this -> m = m;
     }
     void solve(int n, int m);          //Ввести элементы массива с клавиатуры
     int sum(int j);                    //Вычислить сумму элементов j-го столбца
     void get(int x);                   //Установить значение элементов на главной диагонали равному x
     void print(int n, int m);         //Вывести элементы массива на экран
     int cnt(int n, int m);            // Вычислить количество нулевых элементов в массиве
     Array operator ++ ();             // Одновременно увеличиваем все значения массива на 1
     Array operator -- ();             // Одновременно уменьшаем все значения массива на 1
     Array operator + (const Array);    // Складываем два массива одинакого размера
};
void Array::solve(int n,int m) {
     forn(i,n) {
          forn(j,m) {
               cin >> mas[i][j];
          }
     }
}
int Array::sum(int j) {
     int sum = 0;
     forn(i,n) {
          sum += mas[i][j];
     }
     return sum;
}
void Array::get(int x) {
     forn(i,n) {
          forn(j,m) {
               if (i == j) {
                    mas[i][j] = x;
               }
          }
     }
}
void Array::print(int n,int m) {
     forn(i,n) {
          forn(j,m) {
               cout << mas[i][j] << " ";
          }
          cout << endl;
     }
}
int Array::cnt(int n, int m) {
     int cnt1 = 0;
     forn(i,n) {
          forn(j,m) {
               if (mas[i][j] == 0) {
                    cnt1++;
               }
          }
     }
     return cnt1;
}
Array Array::operator ++ () {
     forn(i,n) {
          forn(j,m) {
               mas[i][j]++;
          }
     }
     return *this;
}
Array Array::operator -- () {
     forn(i,n) {
          forn(j,m) {
               mas[i][j]--;
          }
     }
     return *this;
}
Array Array::operator + (const Array arr) {
     Array result(n,m);
     forn(i,n) {
          forn(j,m) {
               result.mas[i][j] = this -> mas[i][j] + arr.mas[i][j];
          }
     }
     return result;

}
int main () {
     Array mas(100,100);
     Array mas1(100,100);
     Array mas3;
     int n,m;
     cout << "Введите размеры матрицы:" << endl;
     cin >> n >> m;
     cout << "Введите первую матрицу:" << endl;
     mas.solve(n,m);
     cout << "Введите номер столбца, сумму которого хотите посчитать:" <<  endl;
     int x;
     cin >> x;
     cout << "Сумма равна: ";
     cout << mas.sum(x);
     cout << endl;
     cout << "Количество нулевых элементов в матрице равно: ";
     cout << mas.cnt(n,m) << endl;
     cout << "Введите значение, которое хотите увидеть на главной диагонали: "<< endl;
     int q;
     cin >> q;
     mas.get(q);
     mas.print(n,m);
     cout << endl;
     cout << "Увеличим значение всей матрицы на 1:" << endl;
     ++mas;
     mas.print(n,m);
     cout << endl;
     cout << "Уменьшим значение всей матрицы на 1: " << endl;
     --mas;
     mas.print(n,m);
     cout << endl;
     cout << "Введите вторую матрицу:" << endl;
     mas1.solve(n,m);
     cout << "Сумма двух матриц равна: " << endl;
     mas3 = mas + mas1;
     mas3.print(n,m);
     cout << endl;
}
