#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int amount;
    cin>>amount;

    if( (amount<0) || (amount>25000) )
    {
        cout<<"Error";
        exit(1);
    }

    vector<int> notes_coins = { 2000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    vector<int> notes_coins_freq(10);

    int no_of_denominations = notes_coins.size();

    // Greedy Approach.
    for(int i=0;i<no_of_denominations;i++)
    {
        if(amount >= notes_coins[i])
        {
            notes_coins_freq[i] = amount/notes_coins[i];
            amount = amount - (notes_coins[i] * notes_coins_freq[i]);
        }
    }

    for(int i=0;i<no_of_denominations;i++)
    {
        cout<<notes_coins_freq[i]<<" ";
    }

    return 0;
}