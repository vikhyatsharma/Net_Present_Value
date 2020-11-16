#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{

    double NPV,initial,cashflow[100],dcf[100],year,discount_rate;
    double discount_factor[100],temp,d,total,Net_Profit;
    int i;

    NPV = 0.0;
    Net_Profit = 0.0;

    cout << "Enter Discount Rate:";
    cin >> discount_rate;
    cout << "Enter Year:";
    cin >> year;
    cout << "Enter Initial Investment:";
    cin >> initial;
    cout << "Enter Year wise cashflow" << endl;

    for(i=1;i <= year;i++)
    {
        cout << "Year\t" << i << "\t" << ":";
        cin >> cashflow[i];
    }

    for(i=1;i <= year;i++)
    {
        temp = discount_rate/100;
        d = temp + 1 ;
        discount_factor[i] = 1/(pow(d,i));
        dcf[i] = cashflow[i] * discount_factor[i];

    }

    for(i=1;i <= year;i++)
    {

        NPV = NPV + dcf[i];
        total = total + cashflow[i];
    }

        Net_Profit = total - initial;
        NPV = NPV - initial;
        cout << endl;

    for(i=1;i <= year;i++)
    {
        cout << discount_factor[i] << "\t" << dcf[i] << endl;
    }

    cout << endl;
    cout << "NPV=" << NPV << endl;
    cout << "Net Profit=" << Net_Profit << endl;
    return 0;

}