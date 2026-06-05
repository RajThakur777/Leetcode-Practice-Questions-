class Solution {
public:
    using ll = long long;

    string s;
    int n;

    ll dpCnt[16][10][10];
    ll dpWave[16][10][10];

    pair<ll, ll> solve(int pos,int prevPrev,int prev,bool tight,bool leadingZero) {
        if (pos == n) {
            return {1, 0};
        }

        if (!tight && !leadingZero &&
            prevPrev >= 0 && prev >= 0 &&
            dpCnt[pos][prevPrev][prev] != -1) {

            return {
                dpCnt[pos][prevPrev][prev],
                dpWave[pos][prevPrev][prev]
            };
        }

        ll totalCnt = 0;
        ll totalWave = 0;

        int limit = tight ? (s[pos] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {

            bool newLeadingZero = leadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev;

            if (newLeadingZero) {
                newPrev = -1;
            } else {
                newPrev = digit;
            }

            auto [cnt, wave] = solve(
                pos + 1,
                newPrevPrev,
                newPrev,
                tight && (digit == limit),
                newLeadingZero
            );

            // Check whether 'prev' becomes a peak/valley
            if (!newLeadingZero &&
                prevPrev >= 0 &&
                prev >= 0) {

                bool peak =
                    (prevPrev < prev && prev > digit);

                bool valley =
                    (prevPrev > prev && prev < digit);

                if (peak || valley) {
                    totalWave += cnt;
                }
            }

            totalCnt += cnt;
            totalWave += wave;
        }

        if (!tight && !leadingZero &&
            prevPrev >= 0 && prev >= 0) {

            dpCnt[pos][prevPrev][prev] = totalCnt;
            dpWave[pos][prevPrev][prev] = totalWave;
        }

        return {totalCnt, totalWave};
    }

    ll calc(long long x) {

        if (x < 100) {
            return 0;
        }

        s = to_string(x);
        n = s.size();

        memset(dpCnt, -1, sizeof(dpCnt));
        memset(dpWave, -1, sizeof(dpWave));

        auto [cnt, wave] =
            solve(0, -1, -1, true, true);

        return wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};