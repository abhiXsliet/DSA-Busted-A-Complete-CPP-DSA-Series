#include<iostream>
using namespace std;

//OUTPUT QUESTION-1
void update1(int a)
{
    a = a/2;
}

//OUTPUT QUESTION-2
int update2(int a)
{
    a -= 5;
    return a;
}

//OUTPUT QUESTION-3
int update3(int a)
{
    int ans = a*a;
    return ans;
}

int main()
{
    int a = 10;
    update1(a);
    cout << a << endl;

    int b = 15;
    update2(b);
    cout << b << endl;

    int x = 14;
    x = update3(x);
    cout << x << endl;

    return 0;
}

