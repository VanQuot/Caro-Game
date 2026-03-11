#ifndef _UTILS_H_
#define _UTILS_H_
#include <string>
#include <algorithm>
#include <cwctype>
#include <initializer_list>

namespace Utils 
{
    template <typename T, typename U = T>
    inline bool keyMatchPattern(
        const T& key,
        const std::initializer_list<U>& patterns
    )
    {
        for (const auto& pattern : patterns) 
        {
            if (pattern == key)
                return true;
        }
        return false;
    }

    inline bool keyMeanUp(const std::wstring& key)
    {
        return keyMatchPattern(key, {L"W", L"w", L"UP"});
    }

    inline bool keyMeanDown(const std::wstring& key)
    {
        return keyMatchPattern(key, {L"S", L"s", L"DOWN"});
    }

    inline bool keyMeanLeft(const std::wstring& key)
    {
        return keyMatchPattern(key, {L"A", L"a", L"LEFT"});
    }

    inline bool keyMeanRight(const std::wstring& key)
    {
        return keyMatchPattern(key, {L"D", L"d", L"RIGHT"});
    }

    template <typename T>
    inline T modCycle(T current, T max)
    {
        current += max;
        return max ? current % max : 0;
    }

    template <typename T>
    inline void ltrim(T& str)
    {
        str.erase(
            str.begin(),
            std::find_if(
                str.begin(),
                str.end(),
                [](wchar_t ch) { return !std::iswspace(ch); }
            )
        );
    }

    template <typename T>
    inline void rtrim(T& str)
    {
        str.erase(
            std::find_if(
                str.rbegin(),
                str.rend(),
                [](wchar_t ch) { return !std::iswspace(ch); }
            ).base(),
            str.end()
        );
    }

    template <typename T>
    inline void trim(T& str)
    {
        ltrim(str);
        rtrim(str);
    }

    template <typename T = std::wstring, typename _Elem = wchar_t>
    inline std::pair<T, T> LineSplitter(
        const T& line,
        _Elem delim = L'='
    )
    {
        size_t pos = line.find_first_of(delim);

        if (pos == T::npos)
            return {line, T()};

        return {line.substr(0, pos), line.substr(pos + 1)};
    }

}
#endif // !_UTILS_H_