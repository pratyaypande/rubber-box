#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Enter the number of test cases: " << endl;
    cin >> t;
    int k[t];
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int a[n];
        int counter=1,maxC=0;
        for(int j=0;j<n;j++)
            cin >> a[j];   
        for(int j=0;j<n;j++)
        {
            if(j > 0)//needs edit
            {
                if(a[j] >= a[j-1])
                    counter++;
                else if((a[j] < a[j-1])||(j == n-1))
                {
                    if(a[j] >= a[j-1])
                        counter++;
                    else if((a[j >= a[j-1]])&&(counter >= maxC))
                        maxC = counter;
                    counter = 1;
                }
            }
            cout << "maxC = " << maxC << endl;
        }
        if(maxC == n)
            k[i] = 0;
        else
            k[i] = n-maxC;
    }
    for(int i=0;i<t;i++)
        cout << k[i] << endl;
    return 0;
}
