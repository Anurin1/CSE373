#include <iostream>;
#include <unordered_map>;

using namespace std;

int getCycleLength(int num, unordered_map<int, int>& cache);

int main()
{
    int minInput, maxInput;
    cin >> minInput >> maxInput;

    unordered_map<int, int> cache({{ 1, 1 }});
    int maxLength = 1;

    for (int num = minInput; num <= maxInput; num++)
    {
        int cycleLength = getCycleLength(num, cache);

        if (cycleLength > maxLength)
        {
            maxLength = cycleLength;
        }
    }

    cout << minInput << " " << maxInput << " " << maxLength;
    return 0;
}

int getCycleLength(int num, unordered_map<int, int>& cache)
{
    if (cache.find(num) != cache.end()) 
    {
        return cache[num];
    }

    int nextNum = num % 2 == 0 ? num / 2 : 3 * num + 1;
    int length = 1 + getCycleLength(nextNum, cache);

    cache.insert({ num, length });
    return length;
}