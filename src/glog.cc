#include <glog/logging.h>
#include <benchmark/benchmark.h>

static void BM_glog(benchmark::State &state)
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

static void BM_glog_flush(benchmark::State &state)
{
    for (auto _ : state)
    {
        LOG(INFO) << "0123456789"
                  << "0123456789"
                  << "0123456789"
                  << "0123456789"
                  << "0123456789";
        
        google::FlushLogFiles(0);
    }

}

int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}

BENCHMARK(BM_glog)->Threads(1)->Threads(2)->Threads(4)->Threads(8);

BENCHMARK(BM_glog_flush)->Threads(1)->Threads(2)->Threads(4)->Threads(8);
