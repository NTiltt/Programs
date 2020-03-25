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
class Queue {
     struct Element {
          X inf;
          Element *next;
          Element (X x): inf(x), next(0) {}
     };
     Element *head, *tail;
public:
     Queue(): head(0), tail(0) {}
     bool empty() {
          return head == 0;
     }
     X get() {
          if (empty()) {
               return -1;
          }
          else {
               Element *t = head;
               X i =  t -> inf;
               head =  t -> next;
               if (head == NULL) {
                    tail = NULL;
               }
               delete t;
               return i;
          }
     }
     void put(X data) {
          Element *t = tail;
          tail = new Element(data);
          if (!head) {
               head = tail;
          }
          else {
               t -> next = tail;
          }
     }
};

int main() {
     Queue <int> q;
     Queue <int> ans;
     int x;
     while (in >> x) {
          q.put(x);
     }
     q.put(0);
     q.put(0);
     int cnt = 0;
     int next = q.get();
     int next1 = q.get();
     while (!q.empty()) {
          if (next == next1) {
               cnt++;
               next1 = q.get();
          }
          else {
               ans.put(next);
               next = next1;
               next1 = q.get();
          }
     }
     out << cnt << endl;
     while (!ans.empty()) {
          out << ans.get() << " ";
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
