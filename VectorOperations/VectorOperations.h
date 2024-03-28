// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the VECTOROPERATIONS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// VECTOROPERATIONS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef VECTOROPERATIONS_EXPORTS
#define VECTOROPERATIONS_API __declspec(dllexport)
#else
#define VECTOROPERATIONS_API __declspec(dllimport)
#endif

#include <vector>

extern VECTOROPERATIONS_API std::vector<float> generateRandomVector(
    size_t n, float low = 0.0, float high = 1.0);

extern VECTOROPERATIONS_API std::vector<float> additionOfProduct(
    const std::vector<float>& a,
    const std::vector<float>& b,
    const std::vector<float>& c);
