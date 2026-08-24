#include <iostream>
using namespace std;
int is_prime(int n)
{
    for (int i = 2; i<=n/2; i++)
    {
        if (n%i == 0) return 0;
    }
    return 1;
}
int main()
{
    int num;
    cout<<"Enter a number"<<endl;
    cin>>num;

    if (num<2)
    {
        cout<<"No prime numbers upto "<<num<<endl;
        return 0;
    }

    cout<<"Prime numbers upto "<<num<<" :"<<endl;
    cout<<"2\t";
    // TODO: 2 is odd
    for (int i=3; i<=num; i++){
        if (is_prime(i)) cout<<i<<"\t";
    }
    cout<<"\nEnd of the list"<<endl;
    return 0;
}