#include <iostream>
#include "../VectorOperations/VectorOperations.h"
#include <chrono>

template<typename Func, typename... Args>
long long measureExecutionTime(Func func, int trialCount, Args... args) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < trialCount; ++i) {
        func(args...); // Invoke the function with the provided arguments
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return duration.count(); // Return the execution time in milliseconds
}

int main()
{
    const int trialCount = 5000;
    const int vector_length = 10000;

    std::vector<float> vector1 = generateRandomVector(vector_length);
    std::vector<float> vector2 = generateRandomVector(vector_length);
    std::vector<float> offset = generateRandomVector(vector_length);

    long long executionTime = measureExecutionTime(additionOfProduct,
        trialCount, vector1, vector2, offset);

    std::cout << "Platform: ";
#if defined(_M_ARM64)
    std::cout << "arm64, ";
#elif defined(_M_X64) || defined(__amd64__)
    std::cout << "x64, ";
#else
    std::cout << "x86, ";
#endif

    std::cout << "ExecutionTime: " << executionTime << " ms\n";
}