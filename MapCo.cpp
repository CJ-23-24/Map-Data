///CJ Shay
///COSC_2436-001
/// 11/20/2026

#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

int main()
{
    unordered_map<int, int> numbers;

    int sizes[] = { 1000, 10000, 100000, 1000000 };

    for (int size : sizes)
    {
        numbers.clear();

        for (int i = 0; i < size; i++)
        {
            numbers[i] = i * 10;
        }

        auto start = chrono::high_resolution_clock::now();

        int total = 0;

        for (int i = 0; i < size; i++)
        {
            auto result = numbers.find(i);

            if (result != numbers.end())
            {
                total += result->second;
            }
        }

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Number of elements: " << size << endl;
        cout << "Lookup time: " << duration.count()
            << " microseconds" << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
