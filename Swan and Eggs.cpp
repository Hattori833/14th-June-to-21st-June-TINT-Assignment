#include <iostream>
#include <vector>
using namespace std;

bool isValid(int age_in_weeks)
{
    return (age_in_weeks > 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    int range,inp;
    cin>>range;

    if(range < 0)
    {
        cout<<"\nError";
        exit(1);
    }

    while(range--)
    {
        cin>>inp;
        v.push_back(inp);
    }

    int total_no_of_eggs = 0;
    for(int x : v)
    {
        if( !isValid(x) )
        {
            cout<<"\nError";
            exit(1);
        }

        if(x >= 52)
        {
            total_no_of_eggs = total_no_of_eggs + 16;
        }
        else
        {
            int rem_weeks = 4 - (52-x);
            if(rem_weeks >= 0)
                total_no_of_eggs = total_no_of_eggs + (rem_weeks * 4);
        }        
    }

    cout<<total_no_of_eggs;

    return 0;
}