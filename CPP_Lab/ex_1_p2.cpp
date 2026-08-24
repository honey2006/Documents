// function overload

#include <iostream>
using namespace std;

void add(int x, int y)
{
    cout<<x+y<<endl;
}
void add(float x, float y)
{
    cout<<x+y<<endl;
}


int main()
{
    int a =5, b=6;
    float m=11.5, n=12.0;

    add(a,b);
    add(m,n);
    
    return 0;
}