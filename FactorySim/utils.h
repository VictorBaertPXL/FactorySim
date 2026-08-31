// vraag 25: template function
// vraag 3: useful and correct class/function

#ifndef UTILS_H
#define UTILS_H

template<typename T>   // vraag 25: template
T clampValue(T value, T min, T max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

#endif
