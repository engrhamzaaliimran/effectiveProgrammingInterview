/*
The given code is a C++ program that demonstrates a function processedVector and a main function.

The processedVector function takes two parameters: a constant reference to a vector of integers (arrInt) and an integer pivot. It returns a new vector of integers temp that is processed based on the given pivot.

Here is a step-by-step breakdown of the processedVector function:

It initializes an empty vector temp to store the processed elements.
It prints the element at the pivot index from the arrInt vector to the console.
It iterates over the arrInt vector using a for loop.
If the element at index i in arrInt is less than the element at the pivot index, it is pushed into the temp vector.
It iterates over the arrInt vector again using a for loop.
If the element at index i in arrInt is equal to the element at the pivot index, it is pushed into the temp vector.
It iterates over the arrInt vector once more using a for loop.
If the element at index i in arrInt is greater than the element at the pivot index, it is pushed into the temp vector.
It prints a newline to the console.
It returns the temp vector.
The main function demonstrates the usage of the processedVector function. It creates a vector arr with initial values {1, -1, 24, 14, 2, 1, 0, 0, 14, 4, 2} and assigns the pivot index 5. It then calls the processedVector function passing arr and pivot as arguments, and assigns the returned vector to arr. Finally, it prints the elements of the arr vector to the console.

When executed, this program will output the processed vector based on the given pivot. The temp vector will contain elements less than the pivot, followed by elements equal to the pivot, and then elements greater than the pivot. The exact output will depend on the values in the arr vector and the chosen pivot index.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<int> processedVector(const std::vector<int> &arrInt, int pivot)
{
    std::vector<int> temp;
    //pivot--; // Adjust pivot index
    cout << "Element at the pivot = " <<arrInt[pivot] << endl;
    // Insert elements less than pivot
    for (int i = 0; i < arrInt.size(); i++)
    {
        if (arrInt[i] < arrInt[pivot])
            temp.push_back(arrInt[i]);
    }

    for (int i = 0; i < arrInt.size(); i++)
    {
        if (arrInt[i] == arrInt[pivot])
            temp.push_back(arrInt[i]);
    }

    // Insert elements greater than pivot
    for (int i = 0; i < arrInt.size(); i++)
    {
        if (arrInt[i] > arrInt[pivot])
            temp.push_back(arrInt[i]);
    }

    std::cout << std::endl;
    return temp;
}

int main()
{
    std::vector<int> arr = {1, -1, 24, 14, 2, 1,0,0, 14, 4, 2};
    int pivot = 5;
    arr = processedVector(arr, pivot);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
