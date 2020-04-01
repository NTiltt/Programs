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
#include "stack.cpp"
#include "queue.cpp"


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

struct point {
     int x, y, z;
     void print();
};
void point::print() {
     cout << x << " " << y << " " << z << endl;
}
double len(point a, point b) {
     return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}


int main() {
     point circle, a[10];
     double r;
     cin >> r;
     int n;
     cin >> n;
     for (int i = 0; i < n; i++) {
          cin >> a[i].x >> a[i].y >> a[i].z;
     }
     point ans;
     int k = INT_MIN;
     for (int OX = -100; OX < 100; OX++) {
          circle.x = OX;
          for (int OY = -100; OY < 100; OY++) {
               circle.y = OY;
               for (int OZ = -100; OZ < 100; OZ++) {
                    circle.z = OZ;
                    int cnt = 0;
                    for (int i = 0; i < n; i++) {
                         if (len(circle,a[i]) <= r) {
                              cnt++;
                         }
                    }
                    if (cnt > k) {
                         ans.x = OX;
                         ans.y = OY;
                         ans.z = OZ;
                         k = cnt;
                    }
               }
          }
     }
     ans.print();
}
