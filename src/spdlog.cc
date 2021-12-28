#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <benchmark/benchmark.h>

static void BM_spdlog_flush(benchmark::State &state)
{
    auto logger = spdlog::get("default");
    for (auto _ : state)
    {
        spdlog::info("%s%s%s%s%s", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789");
        logger->flush();
    }
}

static void BM_spdlog(benchmark::State &state)
{
    for (auto _ : state)
    {
        spdlog::info("%s%s%s%s%s", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789");
    }
}

int main(int argc, char **argv)
{
    auto logger = spdlog::basic_logger_mt("default", "log/spdlog-log.txt");
    spdlog::set_default_logger(logger);

    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}

BENCHMARK(BM_spdlog)->Threads(1)->Threads(2)->Threads(4)->Threads(8);

BENCHMARK(BM_spdlog_flush)->Threads(1)->Threads(2)->Threads(4)->Threads(8);
