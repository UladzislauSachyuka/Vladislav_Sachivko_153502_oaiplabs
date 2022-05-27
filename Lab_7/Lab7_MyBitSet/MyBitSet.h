#ifndef MYBITSET_H
#define MYBITSET_H

#include <string>

template<size_t N>
class BitSet
{
public:
    unsigned char arr[(N + 7) / 8];

public:

    class reference
    {
        friend class BitSet;

        unsigned char &word;
        size_t bit;

        reference(unsigned char &word, size_t bit) : word(word), bit(bit) {}

    public:
        reference &operator=(bool x){
            x ? word |= (1 << bit) : word &= ~(1 << bit);
            return *this;
        }
        operator bool(){
            return (word & (1 << bit)) != 0;
        }
    };

    BitSet() {}

    bool operator[](size_t pos) const
    {
        return (arr[pos / 8] & (1 << (pos % 8))) != 0;
    }

    reference operator[](size_t pos)
    {
        return reference(arr[pos / 8], pos % 8);
    }

    bool all()
    {
        for(int i = 0; i < N; ++i)
        {
            if((arr[i / 8] & (1 << (i % 8))) == 0)
                return false;
        }
        return true;
    }

    bool any()
    {
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1 << (i % 8))) != 0){
                return true;
            }
        }
        return false;
    }

    bool none()
    {
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1 << (i % 8))) != 0){
                return false;
            }
        }
        return true;
    }

    size_t count()
    {
        size_t res = 0;
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1 << (i % 8))) != 0){
                ++res;
            }
        }
        return res;
    }

    BitSet &set()
    {
        for(int i = 0; i < N; ++i){
            arr[i / 8] |= (1 << (i % 8));
        }

        return *this;
    }
    BitSet &set(size_t pos)
    {
        arr[pos / 8] |= (1 << (pos % 8));
        return *this;
    }

    BitSet &reset()
    {
        for(int i = 0; i < N; ++i){
            arr[i / 8] &= ~(1 << (i % 8));
        }

        return *this;
    }

    BitSet &reset(size_t pos)
    {
        arr[pos / 8] &= ~(1 << (pos % 8));
        return *this;
    }

    BitSet &flip()
    {
        for(int i = 0; i < N; ++i){
            arr[i / 8] ^= (1 << (i % 8));
        }
        /*for (int i = 0; i < (N + 7) / 8; ++i)
            arr[i] = ~arr[i];*/
        return *this;
    }

    BitSet &flip(size_t pos)
    {
        arr[pos / 8] ^= (1 << (pos % 8));
        return *this;
    }

    bool test(size_t pos)
    {
        return (arr[pos / 8] & (1 << (pos % 8))) != 0;
    }


    std::string to_string()
    {
        std::string res;
        for(int i = 0; i < N; ++i){
            res += test(N - i - 1) ? '1' : '0';
        }
        return res;
    }

    unsigned long long to_ullong()
    {
        unsigned long long res = 0;

        for(int i = 0; i < (N + 7) / 8; ++i){
            res |= arr[i];
        }

        return res;
    }

    unsigned long to_ulong()
    {
        unsigned long res = 0;

        for(int i = 0; i < (N + 7) / 8; ++i){
            res |= arr[i];
        }

        return res;
    }

    size_t size()
    {
        return N;
    }

    friend BitSet operator~(const BitSet &bts)
    {
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = ~bts.arr[i];
        }
        return res;
    }

    friend BitSet operator&(const BitSet &lBts, const BitSet &rBts)
    {
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = lBts.arr[i] & rBts.arr[i];
        }
        return res;
    }

    friend BitSet operator|(const BitSet &lBts, const BitSet &rBts)
    {
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = lBts.arr[i] | rBts.arr[i];
        }
        return res;
    }
};










//template <size_t N>
//class MyBitSet
//{
//public:
//    unsigned char arr[(N + 7) / 8];

//public:
//    class reference
//    {
//        friend class MyBitSet;
//        unsigned char &word;
//        size_t bit;

//        reference(unsigned char &word, size_t bit) : word(word), bit(bit) {}

//    public:
//        reference &operator=(bool x)
//        {
//            x ? word |= (1 << bit) : word &= ~(1 << bit);
//        }

//    };

//    bool all()
//    {
//        for (int i = 0; i < N; ++i)
//        {
//            if ((arr[i / 8] & (1 << i % 8)) == 0)
//                return false;
//        }
//        return true;
//    }

//};


#endif // MYBITSET_H
