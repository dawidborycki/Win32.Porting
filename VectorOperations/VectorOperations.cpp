#include "pch.h"
#include "framework.h"
#include "VectorOperations.h"
#include <random>

std::vector<float> generateRandomVector(size_t n, float low, float high) {
    std::vector<float> result(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(low, high);

    for (size_t i = 0; i < n; ++i) {
        result[i] = distr(gen);
    }

    return result;
}

std::vector<float> additionOfProduct(
    const std::vector<float>& a,
    const std::vector<float>& b,
    const std::vector<float>& c) {

    // Ensure all vectors have the same size
    if (a.size() != b.size() || a.size() != c.size()) {
        throw std::runtime_error("All vectors must be of the same size.");
    }

    // Initialize result vector of the same size as input vectors
    std::vector<float> result(a.size()); 

    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] * b[i] + c[i];
    }

    return result; 
}