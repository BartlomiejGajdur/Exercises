#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename IteratorIT, typename UnaryPredicate>
long long parallel_count_if(IteratorIT first, IteratorIT last, UnaryPredicate p)
{   
    auto length = std::distance(first, last);
    auto hardwareCount = std::thread::hardware_concurrency();
    auto hardwareNeeded = hardwareCount != 0 ? hardwareCount : 2;

    auto chunk = length / hardwareNeeded; // Divide into chunks

    std::vector<std::thread> threads;
    std::vector<long long> counter(hardwareNeeded);

    for (size_t i = 0; i < hardwareNeeded - 1; ++i)
    {   
        threads.emplace_back([&](IteratorIT begin, IteratorIT end, UnaryPredicate pred, long long& sum)
        {
            sum = std::count_if(begin, end, pred);
        },
        first + i * chunk,
        first + (i + 1) * chunk,
        p,
        std::ref(counter[i]));
    }

    // Poprawiono zakres dla ostatniego wątku
    counter[hardwareNeeded - 1] = std::count_if(first + (hardwareNeeded - 1) * chunk, last, p);

    for (auto&& th : threads)
    {
        th.join();
    }

    return std::accumulate(counter.begin(), counter.end(), 0LL); // Dodano LL do literału 0
}