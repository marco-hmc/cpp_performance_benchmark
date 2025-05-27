#include <benchmark/benchmark.h>

#include "utils.h"

namespace {

    NO_OPTIMIZE int f(int x) { return x + 1; }

    NO_OPTIMIZE int g(int x) {
        static bool value = false;
        if (value) {
            return 0;
        }
        return x + 2;
    }

    void BM_SingleCall(benchmark::State& state) {
        for (auto _ : state) {
            int result = g(1);
            benchmark::DoNotOptimize(result);
        }
    }

    void BM_NestedCalls(benchmark::State& state) {
        int depth = state.range(0);
        for (auto _ : state) {
            int result = 1;
            for (int i = 0; i < depth; ++i) {
                result = g(result);
            }
            benchmark::DoNotOptimize(result);
        }
    }

}  // namespace

BENCHMARK(BM_SingleCall);
BENCHMARK(BM_NestedCalls)->Arg(10)->Arg(100)->Arg(1000);