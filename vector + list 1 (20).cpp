/*
                            Условие задачи.
    Заменить второй и предпоследний элементы на число различных цифр в их записях.

    Идея решения: Создать три вектора, в одном (f1) хранятся все цифры первого числа,
    во втором (s1) хранятся все цифры второго числа, в третьем (cnt) хранятся цифры обоих чисел.
    В третьем (cnt) векторе удалим все повторяющиеся числа.
    А потом просто пройдем по первому и второму вектору, если в векторах f1 или s1
    нет какого то числа из cnt, то увеличиваем ans++, в конце просто заменяем значения.
    Использую vector потому что необходимо просто заменить числа, находящиеся не по краям
    вектора.

*/



                            /* Код программы */

#include <iostream>
#include <algorithm>
#include <vector>
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



typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

bool find(vector<int> &v, int a) {
    for ( int i = 0; i < v.size(); i++) {
        if ( v[i] == a) {
            return true;
        }
    }
    return false;
}

int main() {
    //#ifdef _DEBUG
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    //#endif
    int n;
    cin >> n;
    vector <int> a(n);
    forn(i,n) {
        cin >> a[i];
    }
    int f = a[1];
    int s = a[n - 2];
    vector <int> cnt;
    vector <int> f1;
    vector <int> s1;
    while (f > 0) {
        cnt.pb(f % 10);
        f1.pb(f % 10);
        f /= 10;
    }
    while (s > 0) {
        cnt.pb(s % 10);
        s1.pb(s % 10);
        s /= 10;
    }
    forn(i,sz(cnt)) {
        for (int j = i + 1; j < sz(cnt);) {
            if (cnt[i] == cnt[j]) {
                cnt.erase(cnt.begin() + j);
            }
            else {
                j++;
            }
        }
    }
    int ans = 0;
    forn(i,sz(cnt)) {
        if (find(f1,cnt[i])) {
        }
        else {
            ans++;
        }
    }
    forn(i,sz(cnt)) {
        if (find(s1,cnt[i])) {
        }
        else {
            ans++;
        }
    }
    a[1] = ans;
    a[n - 2] = ans;
    forn(i,n) {
        cout << a[i] << " ";
    }
}


/*
                                        Тестовые примеры:

                1) Ввод:                                Вывод:
                5
                1 212444 3 2213 5                      1 2 3 2 5

                2) Ввод:                                Вывод:
                5
                1 41 3 4 5                              1 1 3 1 5

                3)Ввод:                                 Вывод:
                5
                1 123456 3 120456789 5                  1 5 3 5 5

                4) Ввод:                                Вывод:
                5
                1 123456 3 123456 5                     1 0 3 0 5

*/
