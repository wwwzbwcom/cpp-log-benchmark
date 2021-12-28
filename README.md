# CPP Log Benchmark

C++ Log Benchmark, Also a good example for using these libraries:

- glog
- g3log
- spdlog
- easyloggingpp

## Build

```
bazel build //src:all --copt=-O3 --copt=-fPIC
```


## Result


### glog

```bash
2021-12-28T11:06:52+08:00
Running ./bazel-bin/src/glog
Run on (16 X 3193.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 16384 KiB (x2)
Load Average: 1.11, 0.91, 0.74
***WARNING*** Library was built as DEBUG. Timings may be affected.
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
BM_glog/threads:1             1023 ns         1023 ns       620720
BM_glog/threads:2             1072 ns         1822 ns       355786
BM_glog/threads:4             1547 ns         3983 ns       162020
BM_glog/threads:8             1698 ns         7562 ns        73736
BM_glog_flush/threads:1       2180 ns         2180 ns       329233
BM_glog_flush/threads:2       3061 ns         4309 ns       121706
BM_glog_flush/threads:4       4865 ns        12200 ns        42672
BM_glog_flush/threads:8       5625 ns        25833 ns        21448
```

### g3log

> G3log don't provide manual flush

```bash
2021-12-28T11:06:07+08:00
Running ./bazel-bin/src/g3log
Run on (16 X 3193.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 16384 KiB (x2)
Load Average: 1.93, 0.98, 0.75
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_g3log/threads:1       1271 ns         1264 ns       454411
BM_g3log/threads:2        697 ns         1270 ns       581948
BM_g3log/threads:4        490 ns         1531 ns       399124
BM_g3log/threads:8        823 ns         3430 ns       202248
g3log g3FileSink shutdown at: 11:06:14 193585
Log file at: [./log/bazel-binsrcg3log.g3log.20211228-110607.log]
```


### Spdlog

```bash
2021-12-28T11:06:26+08:00
Running ./bazel-bin/src/spdlog
Run on (16 X 3193.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 16384 KiB (x2)
Load Average: 1.69, 0.99, 0.76
***WARNING*** Library was built as DEBUG. Timings may be affected.
--------------------------------------------------------------------
Benchmark                          Time             CPU   Iterations
--------------------------------------------------------------------
BM_spdlog/threads:1              154 ns          154 ns      4271937
BM_spdlog/threads:2              337 ns          551 ns      1336454
BM_spdlog/threads:4              487 ns         1212 ns       592168
BM_spdlog/threads:8              563 ns         2069 ns       289264
BM_spdlog_flush/threads:1       1283 ns         1283 ns       491953
BM_spdlog_flush/threads:2       2504 ns         4355 ns       160320
BM_spdlog_flush/threads:4       4154 ns        10417 ns        90168
BM_spdlog_flush/threads:8       4415 ns        21095 ns        32624
```

### easyloggingpp


```bash
2021-12-28T11:07:20+08:00
Running ./bazel-bin/src/easyloggingpp
Run on (16 X 3193.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 16384 KiB (x2)
Load Average: 0.73, 0.84, 0.72
***WARNING*** Library was built as DEBUG. Timings may be affected.
----------------------------------------------------------------
Benchmark                      Time             CPU   Iterations
----------------------------------------------------------------
BM_el_flush/threads:1       2581 ns         2581 ns       269841
BM_el_flush/threads:2       7431 ns        13237 ns        50700
BM_el_flush/threads:4       8848 ns        17703 ns        37992
BM_el_flush/threads:8       8945 ns        18623 ns        38256
BM_el/threads:1             2601 ns         2602 ns       248963
BM_el/threads:2             7408 ns        13301 ns        51788
BM_el/threads:4             9019 ns        18139 ns        36860
BM_el/threads:8             9385 ns        19408 ns        37648
```