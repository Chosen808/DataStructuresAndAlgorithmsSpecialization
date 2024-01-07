/**
 * MIT License
 *
 * Copyright (c) 2024 Jesus Christ
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice, its Author and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <iostream>

#define N 100

/**
 * @brief This function calculates the maximum product of 2 numbers in a list
 * @param int arr[] This is the array with the list of numbers 
 * @param int n     This is the size of the array
 * @return          The return is a long long, the maximum product
 */
long long maxPair (int arr[], int n)
{
    // Variables
    int index = 0;  // This holds the index which arr[] is set at
    int max = arr[index];   // max will store the value of arr[] located at the index = 0
    int indexMax = 0;   // This will store the index of the maximum number in arr[]
    long long product = 0;    // This will store the maximum product

    // The maximum number is found here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            indexMax = i;
        }
    }

    // If the index of the maximum number is 0, index will plus 1
    if (indexMax == index)
    {
        index = index + 1;
    }

    // The max2 will store the value of arr[] located at index
    int max2 = arr[index];

    // The second largest number will be found here
    for (int i = 0; i < n; i++)
    {
        // This statement will check if i and the index of the maximum number are the same and stop the loop
        if (i == indexMax && indexMax == n -1)
        {
            break;
        }

        // This statement will increment i be 1 when it reaches the index of the maximum number
        else if (i == indexMax)
        {
            i++;
        }

        if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }

    // The product will be calculated here
    product = (long long)max * max2;

    return product;
}

main ()
{
    // Variables
    int n = 0;  // This will store the size of the array
    int array[N];   // The array that will store the list
    int value = 0;  // This will be use to set the values for the array

    std::cout << "Please enter the size of the array: " << std::endl;
    std::cin >> n;

    std::cout << "\nPlease enter the numbers: " << std::endl;

    // Values for the array will be set here
    for (int i = 0; i < n; i++)
    {
        std::cin >> value;

        array[i] = value;
    }

    std::cout << "\nThese are the values entered: " << std::endl;

    // Value set in the array will be printed out here
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << std::endl;
    }

    std::cout << "\n";

    // This is the maximum product will be calculated and printed
    std::cout << "The maximum product is: " << maxPair (array, n) << std::endl;

    return 0;
}