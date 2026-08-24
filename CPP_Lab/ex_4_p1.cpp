#include <iostream>
using namespace std;

#include <vector>
int main()
{
    int n;
    cout<<"Enter the limit of the array"<<endl;
    cin>>n;

    vector<int> arr;

    cout<<"Enter the elments of the array"<<endl;

    int p; cin>>p; arr.push_back(p);
    int min= arr.front(),max= arr.front();

    for (int i=1; i<n; i++)
    {
        int p; cin>>p; arr.push_back(p);
        if (p>max) max = p;
        if (p<min) min = p;
    }

    cout<<"The minimum and the maxium is:\t"<<min<<"\t"<<max<<endl;

    return 0;
}