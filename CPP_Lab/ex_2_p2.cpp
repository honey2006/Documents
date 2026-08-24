// first n term of a sequence

#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of terms and starting point"<<endl;
    int num, start;
    cin>>num>>start;

    cout<<"The requested sequence is:"<<endl;
    for (int i = start; i < num+start; i++)
    {
        cout<<i<<"\t";
    }

    cout<<"\nEnd of the sequence"<<endl;

    return 0;
}