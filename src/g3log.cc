#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>
#include <benchmark/benchmark.h>

static void BM_g3log(benchmark::State &state)
{
    for (auto _ : state)
    {
        LOG(INFO) << "0123456789"
                  << "0123456789"
                  << "0123456789"
                  << "0123456789"
                  << "0123456789";
    }
}

int main(int argc, char **argv)
{
    auto worker = g3::LogWorker::createLogWorker();
    auto defaultHandler = worker->addDefaultLogger(argv[0], "./log");

    // logger is initialized
    g3::initializeLogging(worker.get());

    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}

BENCHMARK(BM_g3log)->Threads(1)->Threads(2)->Threads(4)->Threads(8);
