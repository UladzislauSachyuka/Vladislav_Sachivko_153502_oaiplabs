#ifndef PAIR_H
#define PAIR_H

#include <algorithm>

template <class T1, class T2>
struct Pair {
    T1 first;
    T2 second;

    constexpr Pair() : first(), second() {}

    Pair(const Pair& p) : first(p.first), second(p.second) {}

    Pair (Pair&& p) : first(move(p.first)), second(move(p.second)) {}

    constexpr Pair(const T1& f, const T2& s) : first(f), second(s) {}

    template <class Other1, class Other2>
    constexpr Pair(const Pair <Other1, Other2>& Right) : first(Right.first), second(Right.second) {}

    template <class Other1, class Other2>
    constexpr Pair(const Pair <Other1, Other2>&& Right) : first(move(Right.first)), second(move(Right.second)) {}

    template <class Other1, class Other2>
    constexpr Pair(Other1&& Val1, Other2&& Val2) : first(move(Val1)), second(move(Val2)) {}

    Pair& operator=(const Pair& p)
    {
        first = p.first;
        second = p.second;
    }

    template<class U1, class U2> Pair& operator=(const Pair<U1, U2>& p)
    {
        first = p.first;
        second = p.second;
    }

    Pair& operator=(Pair&& p) noexcept
    {
        first = move(p.first);
        second = move(p.second);
    }

    template<class U1, class U2> Pair& operator=(Pair<U1, U2>&& p)
    {
        first = move(p.first);
        second = move(p.second);
    }

    void swap(Pair& p) noexcept
    {
        std::swap(first, p.first);
        std::swap(second, p.second);
    }
};

#endif // PAIR_H
