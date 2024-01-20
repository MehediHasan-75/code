#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll priority(char c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}

void func(stack<char> &stk, char ch, string &postfix)
{
    if (stk.empty() || priority(stk.top()) < priority(ch))
    {
        stk.push(ch);
    }
    else
    {
        while (!stk.empty() && (priority(stk.top()) >= priority(ch)))
        {
            postfix.push_back(stk.top());
            stk.pop();
        }
        stk.push(ch);
    }
}

int main()
{
    ll n;
    ll count = 0;

    cin >> n;
    cin.ignore();
    cin.ignore();

    while (n--)
    {
        count++;
        if (count > 1)
            cout << endl;

        stack<char> stk;
        string postfix;
        string ch;

        ll idx = 0;

        while (true)
        {
            getline(cin, ch);
            if (ch.length() == 0 || !cin)
                break;

            if (isdigit(ch[0]))
            {
                postfix.push_back(ch[0]);
            }
            else if (ch[0] == ')')
            {
                while (stk.top() != '(')
                {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else if (ch[0] == '(')
            {
                stk.push('(');
            }
            else
            {
                func(stk, ch[0], postfix);
            }
        }

        while (!stk.empty())
        {
            postfix.push_back(stk.top());
            stk.pop();
        }

        cout << postfix << endl;
    }

    return 0;
}