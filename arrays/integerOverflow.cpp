/*
The given code is a C++ program that demonstrates a function addOne and a main function.

The addOne function takes a vector of integers (originalNum) as input and returns a new vector of integers with 1 added to its value. The function follows the logic of adding one to the last digit of the input vector. If the last digit is less than 9, it increments the last digit by 1. If the last digit is 9, it continues to carry over the addition to the previous digits until a digit less than 9 is found.

Here is a step-by-step breakdown of the addOne function:

It initializes a variable getLastDigit with the last element of the originalNum vector.
It removes the last element from the originalNum vector using pop_back().
It initializes an empty vector temp to store the new number.
If the getLastDigit is less than 9, it increments getLastDigit by 1.
If the getLastDigit is 9 or greater, it enters a while loop to handle carrying over the addition.
It inserts a 0 at the beginning of the temp vector.
It updates getLastDigit with the new last digit from the originalNum vector.
It removes the last element from the originalNum vector using pop_back().
It increments getLastDigit by 1.
The loop continues until getLastDigit is less than 9.
It inserts getLastDigit at the beginning of the temp vector.
It inserts the remaining elements of the originalNum vector at the beginning of the temp vector.
It returns the temp vector.
The main function demonstrates the usage of the addOne function. It creates a vector arr with initial values {0, 9, 1, 9}. It then calls the addOne function passing arr as an argument and assigns the returned vector to arr. Finally, it prints the elements of the arr vector to the console.

When executed, this program will output the result of adding one to the given vector, which in this case would be {0, 9, 2, 0}.

*/

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

vector<int> addOne(vector<int> originalNum)
{
    int getLastDigit = originalNum.back();
    originalNum.pop_back();
    vector<int> temp;
    if (getLastDigit < 9)
    {
        getLastDigit++;
    }
    while (getLastDigit >= 9)
    {
        temp.insert(temp.begin(), 0);
        getLastDigit = originalNum.back();
        originalNum.pop_back();
        getLastDigit++;
    }
    temp.insert(temp.begin(), getLastDigit);
    temp.insert(temp.begin(), originalNum.begin(), originalNum.end());
    return temp;
}

int main()
{
    std::vector<int> arr = {0,9, 1, 9};
    int pivot = 5;
    arr = addOne(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
