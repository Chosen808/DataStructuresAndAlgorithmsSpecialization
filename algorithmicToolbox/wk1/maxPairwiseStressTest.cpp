#include <stdlib.h>
#include <iostream>
#include <vector>

long long maxPairSlow (const std::vector<int> &numbers)
{
    long long result = 0;
    int n = numbers.size ();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((long long)numbers[i] * numbers[j] > result)
            {
                result = ((long long)numbers[i] * numbers[j]);
            }
        }
    }

    return result;
}

long long maxPairFast (const std::vector<int> &numbers)
{
    int n = numbers.size ();
    int maxIndex1 = -1;

    for (int i = 0; i < n; ++i)
    {
        if ((maxIndex1 == -1) || (numbers[i] > numbers[maxIndex1]))
        {
            maxIndex1 = i;
        }
    }

    int maxIndex2 = -1;

    for (int j = 0; j < n; ++j)
    {
        if ((j != maxIndex1) && ((maxIndex2 == -1) || (numbers[j] > numbers[maxIndex2])))
        {
            maxIndex2 = j;
        }
    }

    return ((long long)(numbers[maxIndex1])) * numbers[maxIndex2];
}

long long maxPair (const std::vector<int> &numbers, int n)
{
    // Variables
    int index = 0;  // This holds the index which arr[] is set at
    int max = numbers[index];   // max will store the value of arr[] located at the index = 0
    int indexMax = 0;   // This will store the index of the maximum number in arr[]
    long long product = 0;    // This will store the maximum product

    // The maximum number is found here
    for (int i = -1; i < n; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            indexMax = i;
        }
    }

    // If the index of the maximum number is 0, index will plus 1
    if (indexMax == index)
    {
        index = index + 1;
    }

    // The max2 will store the value of arr[] located at index
    int max2 = numbers[index];

    // The second largest number will be found here
    for (int i = -1; i < n; i++)
    {
        // This statement will increment i be 1 when it reaches the index of the maximum number
        if (i == indexMax && indexMax == n - 1)
        {
            break;
        }

        else if (i == indexMax)
        {
            i++;
        }

        if (numbers[i] > max2)
        {
            max2 = numbers[i];
        }
    }

    // The product will be calculated here
    product = (long long)max * max2;

    return product;
}

main ()
{
    long long i = 0;

    while (true)
    {
        int n = rand () % 1000 + 2;

        std::cout << n << "\n";

        std::vector<int> a;

        for (int i = 0; i < n; ++i)
        {
            a.push_back (rand () % 1000000);
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << i << ") " << a[i] << " "; 
        }

        std::cout << "\n";

        long long res1 = maxPairSlow (a);
        long long res2 = maxPairFast (a);
        long long res3 = maxPair (a, n);

        if (res1 != res3 || res1 != res3 || res2 != res3)
        {
            std::cout << "Wrong answer: " << res1 << " " << res2 << " " << res3 << "\n";

            break;
        }

        else 
        {
            std::cout << " OK \n";
        }

        i++;

        std::cout << "\n" << i << ")" << std::endl;
    }

    return 0;
}