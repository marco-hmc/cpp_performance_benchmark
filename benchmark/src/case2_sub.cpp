#include <benchmark/benchmark.h>

void BM_Subtraction(benchmark::State& state) {
    for (auto _ : state) {
        int x = 3 - 1;
        benchmark::DoNotOptimize(x);
    }
}

BENCHMARK(BM_Subtraction);
