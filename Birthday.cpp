#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Date
{
    public:
        int dd,mm,yyyy;
        Date(int dd,int mm,int yyyy)
        {
            this->dd = dd;
            this->mm = mm;
            this->yyyy = yyyy;
        }
};

// To store number of days in all months from January to Dec.
const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// To count number of Leap years from 00/00/0000 to dd/mm/yyyy
// Where Date d = dd/mm/yyyy
int countLeapYears(Date d)
{
    int y = d.yyyy;
 
    // Check if the current year needs to be  considered for the count of leap years or not
    if (d.mm <= 2)
        y--;

    // An year is a leap year if it is a multiple of 4,multiple of 400 and not a multiple of 100.
    
    return (y / 4) - (y / 100) + (y / 400);

}

// dt1 = Birth Date
// dt2 = Current date
// This function returns the number of days b/w dt1 and dt2
int noOfDaysBetweenTwoDates(Date dt1, Date dt2)
{
    // n1 = Number of days from 00/00/0000 to dd1/mm1/yyyy1
    /* n1 = (No. of days in yyy1 years) + (No. of days in month mm1) + (No. of days in dd1)
            + (No. of Leap Years from 00/00/0000 to  dd1/mm1/yyyy1)*/
    long int n1 = (dt1.yyyy * 365) + dt1.dd;
 
    // Add days for months in given date
    for (int i = 0; i < dt1.mm - 1; i++)
        n1 += month_days[i];
 
    n1 += countLeapYears(dt1);

    // n2 = Number of days from 00/00/0000 to dd2/mm2/yyyy2
    /* n2 = (No. of days in yyy2 years) + (No. of days in month mm2) + (No. of days in dd2)
            + (No. of Leap Years from 00/00/0000 to  dd2/mm2/yyyy2)*/
    long int n2 = (dt2.yyyy * 365) + dt2.dd;
 
    // Add days for months in given date
    for (int i = 0; i < dt2.mm - 1; i++)
        n2 += month_days[i];
 
    n2 += countLeapYears(dt2);    
 
    // return difference between n2 and n1.
    // Hence we get number of days between Birth Date and Current date
    return (n2 - n1);
}

bool isPrime(int n)
{
    int i;

    if(n == 1)
        return false;

    for(i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int range=2;
    int mm1, dd1, yyyy1;
    int mm2, dd2, yyyy2;

    cin>>dd1>>mm1>>yyyy1;
    cin>>dd2>>mm2>>yyyy2;

    Date birth_date(dd1, mm1, yyyy1);
    Date curr_date(dd2, mm2, yyyy2);

    int num_of_days = noOfDaysBetweenTwoDates(birth_date, curr_date);
    int num_of_weeks = num_of_days / 7;
	
	cout<<"\nNumber of days between Current Date and Birth Date = "<<num_of_days;
    cout<<"\nNumber of weeks between Current Date and Birth Date = "<<num_of_weeks;


    int prime_factor_sum = 0, non_prime_factor_sum = 0;
    int a,b;
    vector<int> prime_factors;
    vector<int> non_prime_factors;
    
    for(int i=2;i*i<=num_of_weeks;i++)
    {

        if(num_of_weeks%i == 0)
        {
            if(num_of_weeks/i == i)
            {
                a = i;
                isPrime(a) ? prime_factors.push_back(a) : non_prime_factors.push_back(a);
            }
            else
            {
                a = i;
                b = num_of_weeks/i;

                isPrime(a) ? prime_factors.push_back(a) : non_prime_factors.push_back(a);
                isPrime(b) ? prime_factors.push_back(b) : non_prime_factors.push_back(b);

            }
        }
    }
	
    cout<<"\nPrime Factors of "<<num_of_weeks<<" = ";
    for(int x : prime_factors)
    {
        prime_factor_sum = prime_factor_sum + x;
        cout<<x<<",";
    }
    	
    

    cout<<"\nNon Prime Factors of "<<num_of_weeks<<" = ";
    for(int x : non_prime_factors)
    {
        non_prime_factor_sum = non_prime_factor_sum + x;
        cout<<x<<",";
    }
    	
    	
    cout<<"\nPrime Factor sum = "<<prime_factor_sum;
    cout<<"\nNon Prime Factor sum = "<<non_prime_factor_sum;

    if(prime_factor_sum > non_prime_factor_sum)
        cout<<"\nGrant"<<endl;
    else
        cout<<"\nNot a Grant"<<endl;

    return 0;
}