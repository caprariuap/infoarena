#include <iostream>

using namespace std;

int main()
{
        int number;
        int digits[10];
        int counter = 0;
        int nrOfDigits;

        cout << "n = "; cin >> number;

        while(number - counter >= 0)
        {
                number -= counter;
                digits[counter] = counter;
                counter++;
        }

        nrOfDigits = counter;
        counter--;
        if(number > 0)
        {
                int maxAddingAmount = 9 - digits[counter];

                while(number != 0)
                {
                        if(maxAddingAmount <= number)
                        {
                                digits[counter] += maxAddingAmount;
                                counter--;
                                number -= maxAddingAmount;
                        }
                        else
                        {
                                digits[counter] += number;
                                number = 0;
                        }
                }
        }

        for(int i = nrOfDigits - 1; i >= 0; i--)
                cout << digits[i];


        return 0;
}
