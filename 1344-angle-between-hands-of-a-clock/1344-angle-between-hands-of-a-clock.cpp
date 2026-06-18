class Solution {
public:
    double angleClock(int hours, int minutes) {
        double mnt = minutes * 6.0;
        double hour = (hours % 12) * 30.0 + minutes * 0.5;

        double diff = abs(hour - mnt);
        return min(diff, 360.0 - diff);
    }
};