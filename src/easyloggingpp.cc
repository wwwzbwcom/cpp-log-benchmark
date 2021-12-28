
#include <benchmark/benchmark.h>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

static void BM_el_flush(benchmark::State &state)
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

static void BM_el(benchmark::State &state)
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
   el::Configurations conf;
   conf.setGlobally(el::ConfigurationType::ToFile, "1");
   conf.setGlobally(el::ConfigurationType::ToStandardOutput, "0");
   conf.setGlobally(el::ConfigurationType::Filename, "./log/easylogginpp.log");
   el::Loggers::reconfigureLogger("default", conf);

   ::benchmark::Initialize(&argc, argv);
   ::benchmark::RunSpecifiedBenchmarks();
}

BENCHMARK(BM_el_flush)
    ->Threads(1)
    ->Threads(2)
    ->Threads(4)
    ->Threads(8);

BENCHMARK(BM_el)
    ->Threads(1)
    ->Threads(2)
    ->Threads(4)
    ->Threads(8);
