# Sorting Algorithm Benchmark and Visualization

This project is a C++ sorting algorithm benchmark suite that compares several classic, experimental, and multithreaded sorting algorithms across different input patterns. The program generates structured CSV benchmark output, which can then be visualized using a Python graphing script.

The original version of this project was created as a CS 350 sorting analysis assignment. This revamped version modernizes the sorting implementations, adds new algorithms, validates sorted output, and produces graph-friendly benchmark data.

## Features

* Benchmarks multiple sorting algorithms
* Tests several input data patterns
* Runs repeated benchmark trials
* Validates that each algorithm sorted correctly
* Outputs results to a `.csv` file
* Includes metadata useful for analysis, such as input size, value range, seed, and runtime
* Includes a Python graphing script for runtime visualization
* Includes single-threaded and multithreaded sorting comparisons

## Sorting Algorithms Included

The project currently includes:

| Algorithm                  | Notes                                                                              |
| -------------------------- | ---------------------------------------------------------------------------------- |
| Heap Sort                  | In-place comparison sort using a max heap                                          |
| Counting Sort              | Integer sort using value counts; supports negative values through offset indexing  |
| Merge Sort                 | Stable comparison sort using a reusable temporary buffer                           |
| Parallel Merge Sort        | Multithreaded merge sort using asynchronous recursive sorting                      |
| Quick Sort Naive           | Uses the last element as pivot; intentionally included to show worst-case behavior |
| Quick Sort Median-of-Three | Improved quicksort using median-of-three pivot selection                           |
| Tree Sort Naive            | Uses an unbalanced binary search tree; demonstrates poor behavior on sorted data   |
| Tree Sort Multiset         | Uses `std::multiset`, typically backed by a balanced tree                          |
| Cube Sort                  | Educational block-based variant that sorts small blocks and merges them            |

## Input Types

Each algorithm is tested against multiple input distributions:

| Input Type           | Description                        |
| -------------------- | ---------------------------------- |
| `RandomManyDistinct` | Random values across a wide range  |
| `RandomFewDistinct`  | Random values with many duplicates |
| `SortedAscending`    | Already sorted data                |
| `ReverseSorted`      | Reverse-sorted data                |

These input patterns help demonstrate how algorithm performance changes depending on the shape of the data.

For example, naive Quick Sort and naive Tree Sort are expected to perform poorly on already-sorted or reverse-sorted data. This is intentional and useful for comparison.

## Output

The benchmark program writes results to:

```text
sorting_results.csv
```

Example CSV columns:

```text
algorithm,input_type,input_id,size,trial,seed,min_value,max_value,value_range,time_ns,time_ms,sorted,status,notes
```

Each row represents one benchmark run for one algorithm, input type, size, and trial.

The `sorted` field confirms whether the algorithm produced correctly ordered output.

The `status` field may contain:

| Status      | Meaning                                                 |
| ----------- | ------------------------------------------------------- |
| `completed` | Benchmark completed successfully                        |
| `failed`    | Algorithm completed but output was not sorted correctly |
| `skipped`   | Benchmark was intentionally skipped                     |

Some expensive worst-case runs may be skipped to prevent the benchmark from taking too long or causing stack-depth issues.

## Requirements

### C++ Build Requirements

* C++17-compatible compiler
* Windows 11 with Visual Studio 2022 recommended
* Or `g++` / `clang++` with C++17 support

### Python Requirements

The graphing script requires:

```bash
pip install pandas matplotlib
```

## Building on Windows with Visual Studio 2022

Install Visual Studio 2022 Community and select:

```text
Desktop development with C++
```

Open the project or create a new C++ console project and add the source files:

```text
Main.cpp
Timer.cpp
CountSort.cpp
HeapSort.cpp
MergeSort.cpp
QuickSortNaive.cpp
QuickSortMedian3.cpp
TreeSort.cpp
TreeSortMulti.cpp
CubeSort.cpp
ParallelMergeSort.cpp
Sorting.h
```

Use:

```text
Release
x64
```

Then run with:

```text
Ctrl + F5
```

The program should generate:

```text
sorting_results.csv
```

## Building from the Command Line

From the project directory, compile with:

```bash
g++ -std=c++17 -O2 -pthread -Wall -Wextra -pedantic Main.cpp Timer.cpp CountSort.cpp HeapSort.cpp MergeSort.cpp QuickSortNaive.cpp QuickSortMedian3.cpp TreeSort.cpp TreeSortMulti.cpp CubeSort.cpp ParallelMergeSort.cpp -o sorting_benchmark
```

Run the benchmark:

```bash
./sorting_benchmark
```

On Windows using MinGW or a similar environment, the executable may be:

```bash
sorting_benchmark.exe
```

## Generating Graphs

After running the C++ benchmark, run the Python graphing script:

```bash
python plot_sorting_results.py
```

The script reads:

```text
sorting_results.csv
```

And creates graph images in:

```text
graphs/
```

Generated graphs include:

* Runtime by input type
* Algorithm comparison at the largest tested size
* Merge Sort vs Parallel Merge Sort comparisons

## Benchmarking Notes

For accurate benchmark results:

* Build in `Release` mode
* Prefer `x64`
* Avoid running heavy background applications during benchmarks
* Run multiple trials and compare averages
* Treat small input sizes carefully because timing overhead can dominate the result
* Treat multithreaded results carefully because performance depends on available CPU cores

Debug builds are not recommended for performance comparisons because they can dramatically distort runtime results.

## Why Include Naive Algorithms?

Some algorithms in this project are intentionally not optimized.

For example:

* `QuickSortNaive` uses the last element as a pivot
* `TreeSortNaive` uses an unbalanced binary search tree

These are useful because they demonstrate how algorithm choice and input shape affect performance. The project is not only about finding the fastest sort. It is also about showing why certain implementations fail under specific conditions.

## Parallel Merge Sort

The project includes a multithreaded merge sort implementation to compare traditional single-threaded algorithms against a parallel approach.

Parallel Merge Sort can be faster on large inputs, but it may be slower on small inputs because thread creation and synchronization have overhead. This makes it especially useful for graphing and analysis.

## Cube Sort Note

The original README mentioned Cube Sort, but the source file was missing. This revamp includes an educational block-based Cube Sort variant.

This implementation:

1. Divides the array into fixed-size blocks
2. Sorts each block with insertion sort
3. Merges the sorted blocks until the full array is sorted

This is not intended to be a direct reproduction of the original parallel Cubesort research algorithm. It is included as a practical sequential sorting variant compatible with this benchmark project.

## Project Goals

This project demonstrates:

* C++ sorting algorithm implementation
* Algorithmic performance comparison
* Benchmark design
* CSV data generation
* Python-based visualization
* Effects of input distribution on algorithm behavior
* Basic multithreaded algorithm design

## Future Improvements

Possible future improvements include:

* Add command-line arguments for benchmark size and trial count
* Add a larger benchmark mode
* Add algorithm metrics such as comparisons, swaps, and writes
* Add Radix Sort for another integer-specific comparison
* Add Introsort as a real-world hybrid sorting algorithm
* Export interactive HTML graphs using Plotly
* Add CMake support
* Add automated correctness tests
* Add GitHub Actions build validation

## License

No license has been specified yet. Add a license file if this project is intended to be reused publicly.
