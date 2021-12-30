#pragma once
#include <array>
#include <cassert>
#include <string>
#include <vector>

struct Dice {
    std::array<int, 6> surface;

    Dice(int TOP = 1, int FRONT = 2) {
        assert(1 <= TOP and TOP <= 6);
        assert(1 <= FRONT and FRONT <= 6);
        assert(TOP + FRONT != 7);
        surface[0] = TOP;
        surface[1] = FRONT;
        surface[2] = dice[TOP - 1][FRONT - 1];
        surface[3] = 7 - surface[2];
        surface[4] = 7 - surface[1];
        surface[5] = 7 - surface[0];
    }

    Dice(const std::vector<int>& v) {
        assert(v.size() == 6);
        for (size_t i = 0; i < 6; i++) surface[i] = v[i];
    }

    const int& top() const { return surface[0]; }
    const int& front() const { return surface[1]; }
    const int& right() const { return surface[2]; }
    const int& left() const { return surface[3]; }
    const int& back() const { return surface[4]; }
    const int& bottom() const { return surface[5]; }
    const int& operator[](int k) const { return surface[k]; }

    int& top() { return surface[0]; }
    int& front() { return surface[1]; }
    int& right() { return surface[2]; }
    int& left() { return surface[3]; }
    int& back() { return surface[4]; }
    int& bottom() { return surface[5]; }
    int& operator[](int k) { return surface[k]; }

    bool operator==(const Dice& d) const { return surface == d.surface; }
    bool operator!=(const Dice& d) const { return surface != d.surface; }
    bool operator<(const Dice& d) const { return surface < d.surface; }

    int roll(int k) {  // x++, x--, y++, y--, turn right, turn left
        assert(0 <= k and k < 6);
        int tmp = surface[code[k][0]];
        for (int i = 0; i < 3; i++) surface[code[k][i]] = surface[code[k][i + 1]];
        surface[code[k][3]] = tmp;
        return surface[0];
    }

    int rollc(char c) {
        for (int k = 0; k < 6; k++) {
            if (direction[k] != c) continue;
            return roll(k);
        }
        assert(false);
    }

    int hash() const {
        int res = 0;
        for (size_t i = 0; i < 6; i++) {
            assert(1 <= surface[i] and surface[i] <= 6);
            (res *= 6) += surface[i] - 1;
        }
        return res;
    }

    std::vector<Dice> make_all() {
        std::vector<Dice> res;
        for (int i = 0; i < 6; i++) {
            Dice d(*this);
            if (i == 1) d.roll(2);
            if (i == 2) d.roll(3);
            if (i == 3) d.roll(3), d.roll(3);
            if (i == 4) d.roll(5);
            if (i == 5) d.roll(4);
            for (int j = 0; j < 4; j++) {
                res.emplace_back(d);
                d.roll(0);
            }
        }
        return res;
    }

    Dice identifier() {
        auto dices = make_all();
        return *min_element(dices.begin(), dices.end());
    }

private:
    const int dice[6][6] = {{0, 3, 5, 2, 4, 0}, {4, 0, 1, 6, 0, 3}, {2, 6, 0, 0, 1, 5},
                            {5, 1, 0, 0, 6, 2}, {3, 0, 6, 1, 0, 4}, {0, 4, 2, 5, 3, 0}};
    const int code[6][4] = {{0, 3, 5, 2}, {0, 2, 5, 3}, {0, 1, 5, 4}, {0, 4, 5, 1}, {1, 2, 4, 3}, {1, 3, 4, 2}};
    const char direction[6] = {'E', 'W', 'N', 'S', 'R', 'L'};
};
