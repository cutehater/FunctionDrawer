#pragma once

#include <string>

class Function
{
public:
    Function();
    Function(const std::string& function_string);

    void SetFunction(const std::string& function_string);

    double GetValue(const double& x) const;

private:
    enum class SegmentType
    {
        AddictionOrSubstraction,
        MultiplicationOrDivision,
        Power,
        ComplexFunction,
        Base
    };

    double ParseSegment(const double& x, size_t left_bound, size_t right_bound) const;

    SegmentType GetSegmentType(size_t left_bound, size_t right_bound) const;

    double ParseAddSubstrOrMultDivSegment(const double& x, size_t left_bound, size_t right_bound, SegmentType segment_type) const;
    double ParsePowerSegment(const double& x, size_t left_bound, size_t right_bound) const;
    double ParseComplexFunctionSegment(const double& x, size_t left_bound, size_t right_bound) const;
    double ParseBaseSegment(const double& x, size_t left_bound, size_t right_bound) const;

    std::string function;
};
