#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

int reverseNumber(int num)
{
	int reversed_num = 0;
	while(num != 0)
	{
		int dig = num % 10;
		reversed_num = (reversed_num*10)+dig;
		num = num / 10;
	}
	
	return reversed_num;
}

bool isDominant(int num)
{
    int p=0,q=0;
    int dig;
    int count = 0;
    
	//cout<<"\n\nNumber = "<<num;
	
	int reversed_num = reverseNumber(num);
	
    while(reversed_num != 0)
    {
        dig = reversed_num % 10;
        
        count = count + 1;
        
        if( (count%2 == 0) && (dig != 0) )
        {
    		//cout<<"\nCount = "<<count;
    		//cout<<"\ndigit = "<<dig;
        	if(p == 0)
        		p = 1;
        		
            p = p*dig;
        }

        if( (count%2) && (dig != 0) )
        {
        	//cout<<"\nCount = "<<count;
    		//cout<<"\ndigit = "<<dig;
        	if(q == 0)
        		q = 1;
        		
            q = q*dig;
        }
        
        reversed_num = reversed_num / 10;
    }
	
	//cout<<"\np = "<<p;
	//cout<<"\nq = "<<q;
    if(p >= q)
        return true;

    return false;
}
void printDominantMagical(int k)
{
    if(isDominant(k))
        cout<<"Dominant"<<" ";
    else
        cout<<"Magical"<<" ";
        
}

// If no of digits > 10 ==> Returns true.
// Otherwise returns false
bool checkNoOfDigits(long int num)
{
    int dig;
    int count = 0;
    //cout<<"\n\nNumber = "<<num;
    
    while(num != 0)
    {
        dig = num % 10;
        count = count + 1;
        num = num / 10;
    }
	
	//cout<<"\n\nCount = "<<count;
    if(count >= 10)
        return true;
    else
    	return false;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    vector<long int> v;
    int range;
    cin>>range;

    if(range < 0)
    {
        cout<<"\nError - range cant be -ve ";
        exit(1);
    }

    long int inp;

    while(range--)
    {
        cin>>inp;
        v.push_back(inp);
    }

    for(int i=0;i<v.size();i++)
    {
    	if(v[i] <= 0)
    	{
    		cout<<"Error"<<" ";
    		continue;
    	}
    	
    	if( checkNoOfDigits(v[i]) )
    	{
        	cout<<"Error(No of digits cant be greater than 10)"<<" ";
        	continue;
    	}
    	
        if( isDominant(v[i]) )
        {
            cout<<"Dominant"<<" ";
        }
        
        else
        {
            cout<<"Magical"<<" ";
        }
    }

}