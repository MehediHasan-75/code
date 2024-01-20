#include "testlib.h"
#include <iostream>

using namespace std;

int a[26], b[26];

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int k = atoi(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int l = atoi(argv[4]);
    println(k);
    string s, t;
    t = rnd.next(format("[a-x]{%d,%d}", m - 2 * l, m - 2 * l));
    for (int i = 0; i < l; i++)
        t += "y";
    for (int i = 0; i < l; i++)
        t += "z";
    for (int i = 0; i < m; i++)
        b[t[i] - 'a']++;
    for (int i = 0; i < k; i++)
    {
        int x = max(0, l + 1 - a[24]);
        int y = max(0, l + 1 - a[25]);
        int q = rnd.next(0, x + y);
        if (q < x)
            s += "y";
        else if (q < y)
            s += "z";
        else
            s += rnd.next(format("[a-x]{%d,%d}", 1, 1));
        a[s[i] - 'a']++;
    }
    for (int i = 0; i + k < n; i++)
    {
        a[s[i] - 'a']--;
        if (a[24] <= l && a[25] <= l)
        {
            if (a[24] < l)
                s += "z";
            else if (a[25] < l)
                s += "y";
            else
            {
                int q = rnd.next(0, 1);
                if (q)
                    s += "z";
                else
                    s += "y";
            }
        }
        else
        {
            s += rnd.next(format("[a-x]{%d,%d}", 1, 1));
        }
        a[s[i + k] - 'a']++;
    }
    println(s);
    println(t);
    return 0;
}
