#include <iostream>
#include <vector>


typedef unsigned long long int uint64;

void evalPrime(std::vector<bool>& pt)
{
    pt[0] = false;
    pt[1] = false;
    const uint64 MXM = pt.size();
    const uint64 LIMIT = sqrt(MXM);

    for (uint64 i = 2; i < LIMIT; i++) {
        if (pt[i]) {
            for (uint64 j = i * i; j < MXM; j += i)
            {
                pt[j] = false;
            }
        }
    }
}

void makePrimFactors(const std::vector<bool>& pt, std::vector<int>& factors, uint64 number )
{
    for (int i = 2; i < pt.size(); i++ )
    {
        if(pt[i])
        {
            while (number % i == 0)
            {
                factors[i]++;
                number /= i;
            }
        }

    }
}

void printPrimeFactors(const std::vector<int>& factors, uint64 num)
{
    int goal = factors.size();
    std::cout << num << "=";

    for (uint64 i = 2 ; i < goal ; i++)
    {
        if (goal == 1)
            break;

        if (factors[i] > 0) {
            std::cout << i << "^" << factors[i] << " * ";
            goal /= pow(i, factors[i]);
        }
    }
    std::cout << "\b\b\b   \n";
}

int main()
{
    int n;
    std::vector<uint64>data;
    //소수 테이블

    data.push_back(1568);
    data.push_back(44863);
    data.push_back(5021863);
    data.push_back(525098);
    data.push_back(97);
    data.push_back(1568);


    int max = *std::max_element(data.begin(), data.end()); //제일 큰수 찾는 함수

    std::vector<bool> pt(max + 1);
    std::fill(pt.begin(), pt.end(), true);
    evalPrime(pt);

    for (auto d : data) {
        std::vector<int> factors(d + 1, 0);
        makePrimFactors(pt, factors, d);
        printPrimeFactors(factors, d);
    }


    return 0;
}