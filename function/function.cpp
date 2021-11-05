#include "function.h"

#include <cctype>
#include <vector>
#include <math.h>
#include <stdexcept>

Function::Function()
{

}

Function::Function(const std::string& function_string)
{
    SetFunction(function_string);
}

void Function::SetFunction(const std::string& function_string)
{   
    for (const char& c : function_string)
    {
        if (!isalnum(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != ' ' && c != '(' && c != ')')
        {
            throw std::invalid_argument("unrecognized symbol: " + std::string(1, c));
        }

        if (c != ' ')
        {
            function.push_back(c);
        }
    }
}

double Function::GetValue(const double& x) const 
{
    if (function.empty())
    {
        throw std::invalid_argument("empty function");
    }
    else
    {
        return ParseSegment(x, 0, function.size() - 1);
    }
}

double Function::ParseSegment(const double& x, size_t left_bound, size_t right_bound) const
{   
    for (; left_bound <= right_bound && function[left_bound] == '(' && function[right_bound] == ')'; ++left_bound, --right_bound);

    if (left_bound > right_bound)
    {
        throw std::invalid_argument("invalid function format");
    }

    SegmentType segment_type = GetSegmentType(left_bound, right_bound);

    if (segment_type == SegmentType::AddictionOrSubstraction)
    {
        return ParseAddSubstrOrMultDivSegment(x, left_bound, right_bound, SegmentType::AddictionOrSubstraction);
    }
    else if (segment_type == SegmentType::MultiplicationOrDivision)
    {
        return ParseAddSubstrOrMultDivSegment(x, left_bound, right_bound, SegmentType::MultiplicationOrDivision);
    }
    else if (segment_type == SegmentType::Power)
    {
        return ParsePowerSegment(x, left_bound, right_bound);
    }
    else if (segment_type == SegmentType::ComplexFunction)
    {
        return ParseComplexFunctionSegment(x, left_bound, right_bound);
    }
    else
    {
        return ParseBaseSegment(x, left_bound, right_bound);
    }
}

Function::SegmentType Function::GetSegmentType(size_t left_bound, size_t right_bound) const {
    bool has_addiction_or_substraction = false;
    bool has_multiplication_or_division = false;
    bool has_power = false;
    bool has_complex_function = false;

    int64_t open_brackets = 0;

    for (size_t i = left_bound; i <= right_bound; ++i)
    {
        if (function[i] == '(')
        {
            ++open_brackets;
        }
        else if (function[i] == ')')
        {
            --open_brackets;

            if (open_brackets < 0)
            {
                throw std::invalid_argument("invalid function format");
            }
        }
        else if (open_brackets == 0)
        {
            if (function[i] == '+' || function[i] == '-')
            {
                has_addiction_or_substraction = true;
            }
            else if (function[i] == '*' || function[i] == '/')
            {
                has_multiplication_or_division = true;
            }
            else if (function[i] == '^')
            {
                has_power = true;
            }
            else if (function[i] != 'x' && !isdigit(function[i]))
            {
                has_complex_function = true;
            }
        }
    }

    if (has_addiction_or_substraction)
    {
        return SegmentType::AddictionOrSubstraction;
    }
    else if (has_multiplication_or_division)
    {
        return SegmentType::MultiplicationOrDivision;
    }
    else if (has_power)
    {
        return SegmentType::Power;
    }
    else if (has_complex_function)
    {
        return SegmentType::ComplexFunction;
    }
    else
    {
        return SegmentType::Base;
    }
}


double Function::ParseAddSubstrOrMultDivSegment(const double &x, size_t left_bound, size_t right_bound, SegmentType segment_type) const
{
    int64_t open_brackets = 0;

    size_t segment_begin = left_bound;

    std::vector<double> subsegments_results;
    std::vector<char> signs;

    for (size_t i = left_bound; i <= right_bound; ++i)
    {
        if (function[i] == '(')
        {
            ++open_brackets;
        }
        else if (function[i] == ')')
        {
            --open_brackets;
        }
        else if (open_brackets == 0 && (((function[i] == '+' || function[i] == '-') && segment_type == SegmentType::AddictionOrSubstraction) ||
                 ((function[i] == '*' || function[i] == '/') && segment_type == SegmentType::MultiplicationOrDivision)))
        {
            if (segment_begin == i)
            {
                throw std::invalid_argument("invalid function format");
            }
            else
            {
                subsegments_results.push_back(ParseSegment(x, segment_begin, i - 1));
                signs.push_back(function[i]);

                segment_begin = i + 1;
            }

        }
    }

    if (segment_begin == right_bound + 1)
    {
        throw std::invalid_argument("invalid function format");
    }

    subsegments_results.push_back(ParseSegment(x, segment_begin, right_bound));

    double answer = subsegments_results[0];

    for (size_t i = 0; i < signs.size(); ++i)
    {
        if (signs[i] == '+')
        {
            answer += subsegments_results[i + 1];
        }
        else if (signs[i] == '-')
        {
            answer -= subsegments_results[i + 1];
        }
        else if (signs[i] == '*')
        {
            answer *= subsegments_results[i + 1];
        }
        else
        {
            answer /= subsegments_results[i + 1];

            if (isnan(answer) || isinf(answer))
            {
                throw std::out_of_range("");
            }
        }
    }

    return answer;
}

double Function::ParsePowerSegment(const double &x, size_t left_bound, size_t right_bound) const
{
    if (function[left_bound] == '^' || function[right_bound] == '^')
    {
        throw std::invalid_argument("invalid function format");
    }

    int64_t open_brackets = 0;

    size_t power_sign_pos;

    for (size_t i = right_bound; i >= left_bound; --i)
    {
        if (function[i] == ')')
        {
            ++open_brackets;
        }
        else if (function[i] == '(')
        {
            --open_brackets;
        }
        else if (open_brackets == 0 && function[i] == '^')
        {
            power_sign_pos = i;
            break;
        }
    }

    double answer = std::pow(ParseSegment(x, left_bound, power_sign_pos - 1), ParseSegment(x, power_sign_pos + 1, right_bound));

    if (isnan(answer) || isinf(answer))
    {
        throw std::out_of_range("");
    }
    else
    {
        return answer;
    }
}

double Function::ParseComplexFunctionSegment(const double &x, size_t left_bound, size_t right_bound) const
{
    if (function[right_bound] != ')')
    {
        throw std::invalid_argument("invalid function format");
    }

    size_t open_bracket_pos;

    for (size_t i = left_bound; i <= right_bound; ++i)
    {
        if (function[i] == '(')
        {
            open_bracket_pos = i;
            break;
        }
    }

    std::string function_name = function.substr(left_bound, open_bracket_pos - left_bound);

    double value = ParseSegment(x, open_bracket_pos + 1, right_bound - 1);
    double answer;

    if (function_name == "sin")
    {
        answer = std::sin(value);
    }
    else if (function_name == "cos")
    {
        answer = std::cos(value);
    }
    else if (function_name == "tan")
    {
        answer = std::tan(value);
    }
    else if (function_name == "asin")
    {
        answer = std::asin(value);
    }
    else if (function_name == "acos")
    {
        answer = std::acos(value);
    }
    else if (function_name == "atan")
    {
        answer = std::atan(value);
    }
    else if (function_name == "sqrt")
    {
        answer = std::sqrt(value);
    }
    else if (function_name == "log")
    {
        answer = std::log(value);
    }
    else if (function_name == "log10")
    {
        answer = std::log10(value);
    }
    else if (function_name == "log2")
    {
        answer = std::log2(value);
    }
    else if (function_name == "abs")
    {
        answer = std::abs(value);
    }
    else {
        throw std::invalid_argument("invalid function format");
    }

    if (isnan(answer) || isinf(answer))
    {
        throw std::out_of_range("");
    }
    else
    {
        return answer;
    }
}

double Function::ParseBaseSegment(const double &x, size_t left_bound, size_t right_bound) const
{
    if (left_bound == right_bound && function[left_bound] == 'x')
    {
        return x;
    }
    else
    {
        double answer = 0;

        for (size_t i = left_bound; i <= right_bound; ++i)
        {
            if (!isdigit(function[i]))
            {
                throw std::invalid_argument("invalid function format");
            }
            else
            {
                answer = answer * 10 + static_cast<double>(function[i] - '0');
            }
        }

        return answer;
    }
}
