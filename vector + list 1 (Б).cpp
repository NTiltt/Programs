/*
                              Условия задачи.
          Вставить после первого и перед последним элементы, получающиеся из
          исходных перестановкой цифр в обратном порядке.
          Использую двунаправленный список, так как с помощью функций для них можно
          легко выполнить задачу.
*/



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

ifstream in("/Users/nikita/Documents/Atom project/input.txt");
ofstream out("/Users/nikita/Documents/Atom project/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

template <class X> class DoubleList {
     struct Element {
          X inf;
          Element *next;
          Element *prev;
          Element (X x) : inf(x), next(0), prev(0) {};
     };
     Element *head;
     Element *tail;
     int size;
     Element *find(int ind) {
          Element *cur = head;
          for (int i = 1; i < ind; i++) {
               cur = cur -> next;
          }
          return cur;
     }
public:
     DoubleList(): head(0), tail(0), size(0) {};
     bool empty() {
          return head == 0;
     }
     int len() {
          return size;
     }
     int get(int ind) {
          Element *r = find(ind);
          X i = r -> inf;
          return i;
     }
     void insertleft(int ind, X data) {
          Element *newPtr = new Element(data);
          size = len() + 1;
          Element *cur = find(ind);
          if (cur == NULL) {
               head = newPtr;
               tail = newPtr;
          }
          else {
               newPtr -> next = cur;
               newPtr -> prev = cur -> prev;
               cur -> prev = newPtr;
               if (cur == head) {
                    head = newPtr;
               }
               else {
                    newPtr -> prev -> next = newPtr;
               }
          }
     }
     void insertright(int ind, X data) {
          Element *newPtr = new Element(data);
          size = len() + 1;
          Element *cur = find(ind);
          if (cur == NULL) {
               head = newPtr;
               tail = newPtr;
          }
          else {
               newPtr -> next = cur -> next;
               newPtr -> prev = cur;
               cur -> next = newPtr;
               if (cur == tail) {
                    tail = newPtr;
               }
               else {
                    newPtr -> next -> prev = cur;
               }
          }
     }
     void remove(int ind) {
          Element *cur = find(ind);
          --size;
          if (size == 0) {
               head = NULL;
               tail = NULL;
          }
          else {
               if (cur == head) {
                    head = head -> next;
                    head -> prev = NULL;
               }
               else {
                    if (cur == tail) {
                         tail = tail -> prev;
                         tail -> next = NULL;
                    }
                    else {
                         cur -> prev -> next = cur -> next;
                         cur -> next -> prev = cur -> prev;
                    }
               }
          }
          cur -> next = NULL;
          cur -> prev = NULL;
          delete cur;
     }
     void printlr() {
          for (Element *cur = head; cur != NULL; cur = cur -> next) {
               cout << cur -> inf << " ";
          }
          cout << endl;
     }
     void printrl() {
          for (Element * cur = tail; cur != NULL; cur = cur -> prev) {
               cout << cur -> inf << " ";
          }
          cout << endl;
     }

};


int main() {
     int n;
     cin >> n;
     DoubleList <int> l;
     forn(i,n) {
          int x;
          cin >> x;
          l.insertright(l.len(),x);
     }
     int a,b;
     cout << "Введите два числа: ";
     cin >> a >> b;
     string s;
     while (a > 0) {
          char c = (a % 10) + '0';
          s += c;
          a /= 10;
     }
     string s1;
     while (b > 0) {
          char c = (b % 10) + '0';
          s1 += c;
          b /= 10;
     }
     int a1 = atol(s.c_str());
     int b1 = atol(s1.c_str());
     if (n == 1) {
          l.insertright(1,a1);
          l.insertleft(l.len(),b1);
     }
     else {
          l.insertleft(l.len(),b1);
          l.insertright(1,a1);
     }
     l.printlr();

}



/*
                              Тестовые примеры.

          1) Ввод:                                Вывод:
          5
          1 2 3 4 5                               1 321 2 3 4 213 5
          123 312

          2) Ввод:                                Вывод:
          2
          1 1                                     1 987654321 0 1
          123456789 0

          3) Ввод:                                Вывод:
          1
          1                                       1 89 89
          980 980
*/
