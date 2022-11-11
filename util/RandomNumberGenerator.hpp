#pragma once
#include <chrono>
#include <random>

struct RandomNumberGenerator {
    std::mt19937 mt;
    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    uint32_t operator()(uint32_t a, uint32_t b) {
        std::uniform_int_distribution<uint32_t> dist(a, b - 1);
        return dist(mt);
    }
    uint32_t operator()(uint32_t b) { return (*this)(0, b); }
};

struct RandomNumberGenerator64 {
    std::mt19937_64 mt;
    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    uint64_t operator()(uint64_t a, uint64_t b) {
        std::uniform_int_distribution<uint64_t> dist(a, b - 1);
        return dist(mt);
    }
    uint64_t operator()(uint64_t b) { return (*this)(0, b); }
};
