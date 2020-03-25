/*
                         Условие задачи.
     Создать список чисел. Подсчитать количество пар соседних элементов, которые
     совпадают между собой. Оставить по одному из таких элементов, т.е. исключить
     все повторяющиеся, идущие подряд элементы.
*/

                    /*    Код задачи.   */

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
#include <queue>
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

ifstream in("/Users/nikita/Documents/Atom project/input.txt");
ofstream out("/Users/nikita/Documents/Atom project/output.txt");

template <class X>
class Stack {
     struct Element {
          X inf;
          Element *next;
          Element(X x, Element *p):inf(x), next(p) {}
     };
     Element *head;
public:
     Stack(): head(0) {}
     bool empty() {
          return head == 0;
     }
     X pop() {
          if (empty()) {
               return 0;
          }
          Element *r = head;
          X i = r -> inf;
          head = r -> next;
          delete r;
          return i;
     }
     void add(X data) {
          head = new Element(data, head);
     }
     X top() {
          if (empty()) {
               return 0;
          }
          else {
               return head -> inf;
          }
     }
};

int main() {
     Stack <int> s;
     Stack <int> ans;
     int x;
     while (in >> x) {
          s.add(x);
     }
     int cnt = 0;
     while (!s.empty()) {
          int tek = s.pop();
          if (tek == s.top()) {
               cnt++;
               continue;
          }
          else {
               ans.add(tek);
          }
     }
     out << cnt << endl;
     while (!ans.empty()) {
          out << ans.pop() << " ";
     }
}

/*
                         Тестовые примеры:

          1) Ввод:                           Вывод:
                                            8
          1 1 1 1 1 1 1 1 1                 1

          2)Ввод:                            Вывод:
                                            5
          1 1 1 2 2 3 1 4 4 5 6 7 8 8       1 2 3 1 4 5 6 7 8

          3)Ввод:                            Вывод:
                                             7
          1 2 3 4 4 5 5 5 5 5 5 5            1 2 3 4 5



*/
