#include <iostream>
#include <vector>

long long maxPair (const std::vector<int> &numbers)
{
    long long result{0};
    int n = numbers.size ();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] * numbers[j] > result)
            {
                result = (long long)numbers[i] * numbers[j];
            }
        }
    }

    return result;
}


main ()
{
    int n{0};

    std::cout << "Please enter the size of the array: " << std::endl;
    std::cin >> n;

    std::vector<int> numbers(n);

    std::cout << "\nPlease enter the numbers for the array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    std::cout << "\nThe maximum product is: " << maxPair (numbers) << std::endl;

    return 0;
}