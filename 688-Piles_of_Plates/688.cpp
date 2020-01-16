#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

/*
class Functor {
public:
    void Init(uint64_t rows, uint64_t cols) {
        m_cachedResults.resize(rows, vector<uint64_t>(cols, 0));
        m_cachedResults[0][0] = 1;
        m_cachedResults[1][0] = 2;
        m_cachedResults[2][0] = 3;
        m_cachedResults[2][1] = 1;
        for (uint64_t rowIndex = 3; rowIndex < rows; ++rowIndex) {
            m_cachedResults[rowIndex][0] = rowIndex + 1;
            m_cachedResults[rowIndex][1] = rowIndex >> 1;
            for (uint64_t colIndex = 2; colIndex < cols; ++colIndex) {
                for (uint64_t k = 1; m_cachedResults[rowIndex - k][colIndex - 1] > k; ++k)
                {
                    m_cachedResults[rowIndex][colIndex] = k;
                }
                if (m_cachedResults[rowIndex][colIndex] == 0) { break; }
            }
        }
    }

    uint64_t f(uint64_t n, uint64_t k) {
        return m_cachedResults[n - 1][k - 1];
    }

    uint64_t F(uint64_t n) {
        uint64_t ret = 0;
        for (uint64_t k = 1; f(n, k) > 0; ++k) {
            ret += f(n, k);
        }
        return ret;
    }

    uint64_t S(uint64_t N) {
        uint64_t ret = 0;
        for (uint64_t n = 1; n <= N; ++n) {
            ret += F(n);
        }
        return ret;
    }

private:
    vector<vector<uint64_t>> m_cachedResults;
};
*/


class Functor2 {
public:
    uint64_t R(uint64_t N) {
        uint64_t ret = 0;
        uint64_t col = 1;
        uint64_t startRow = 1;
        while (startRow <= N) {
            uint64_t rowCount = N - startRow + 1;
            uint64_t m = rowCount / col;
            uint64_t colMod = ((1 + m) % 1000000007) * (rowCount % col % 1000000007) % 1000000007;
            if ((m & 0x1) == 0) {
                colMod += (((m / 2) % 1000000007) * ((1 + m) % 1000000007) % 1000000007) * (col % 1000000007) % 1000000007;
            } else {
                colMod += ((m % 1000000007) * ((1 + m) / 2 % 1000000007) % 1000000007) * (col % 1000000007) % 1000000007;
            }
            ret += colMod % 1000000007;
            ret %= 1000000007;

            //cout << "col = " << col << ", ret = " << ret << endl;

            ++col;
            startRow += col;
        }
        return ret;
    }
};


int main() {
/*
    Functor functor;
    functor.Init(100, 100);

    // Test Cases
    cout << "f(10,3) = " << functor.f(10, 3) << endl;
    cout << "f(10,5) = " << functor.f(10, 5) << endl;
    cout << "F(100) = " << functor.F(100) << endl;
    cout << "S(100) = " << functor.S(100) << endl;

    for (uint64_t n = 1; n <= 100; ++n) {
        for (uint64_t k = 1; functor.f(n, k) > 0; ++k) {
            cout << functor.f(n, k) << ' ';
        }
        cout << std::endl;
    }
*/

    Functor2 functor2;

    //cout << "S(1) % 1000000007 = " << functor2.R(1) << endl;
    //cout << "S(2) % 1000000007 = " << functor2.R(2) << endl;
    cout << "S(100) % 1000000007 = " << functor2.R(10000000000000000) << endl;

    return 0;
}
