#include <random>
#include <vector>

std::vector<uint64_t> ZobristHash(int n) {
    std::random_device seed_gen;
    std::mt19937_64 engine(seed_gen());
    std::vector<uint64_t> base(n);
    for (int i = 0; i < n; i++) base[i] = engine();
    return base;
}
