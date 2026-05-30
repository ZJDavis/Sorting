from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt


RESULTS_FILE = Path("sorting_results.csv")
OUTPUT_DIR = Path("graphs")


def load_results() -> pd.DataFrame:
    if not RESULTS_FILE.exists():
        raise FileNotFoundError(f"Could not find {RESULTS_FILE}")

    df = pd.read_csv(RESULTS_FILE)

    completed = df[df["status"] == "completed"].copy()
    completed = completed[completed["sorted"] == True]

    if completed.empty:
        raise ValueError("No completed and correctly sorted benchmark rows found.")

    return completed


def plot_runtime_by_input_type(df: pd.DataFrame) -> None:
    OUTPUT_DIR.mkdir(exist_ok=True)

    grouped = (
        df.groupby(["algorithm", "input_type", "size"], as_index=False)
        .agg(avg_time_ms=("time_ms", "mean"))
    )

    for input_type in sorted(grouped["input_type"].unique()):
        subset = grouped[grouped["input_type"] == input_type]

        plt.figure(figsize=(12, 8))

        for algorithm in sorted(subset["algorithm"].unique()):
            algorithm_data = subset[subset["algorithm"] == algorithm]
            algorithm_data = algorithm_data.sort_values("size")

            plt.plot(
                algorithm_data["size"],
                algorithm_data["avg_time_ms"],
                marker="o",
                label=algorithm,
            )

        plt.title(f"Sorting Runtime - {input_type}")
        plt.xlabel("Input Size")
        plt.ylabel("Average Runtime (ms)")
        plt.xscale("log")
        plt.yscale("log")
        plt.grid(True, which="both", linestyle="--", linewidth=0.5)
        plt.legend()
        plt.tight_layout()

        output_path = OUTPUT_DIR / f"runtime_{input_type}.png"
        plt.savefig(output_path, dpi=150)
        plt.close()

        print(f"Wrote {output_path}")


def plot_algorithm_comparison_at_largest_size(df: pd.DataFrame) -> None:
    OUTPUT_DIR.mkdir(exist_ok=True)

    largest_size = df["size"].max()
    subset = df[df["size"] == largest_size]

    grouped = (
        subset.groupby(["algorithm", "input_type"], as_index=False)
        .agg(avg_time_ms=("time_ms", "mean"))
    )

    for input_type in sorted(grouped["input_type"].unique()):
        input_subset = grouped[grouped["input_type"] == input_type]
        input_subset = input_subset.sort_values("avg_time_ms")

        plt.figure(figsize=(12, 8))
        plt.bar(input_subset["algorithm"], input_subset["avg_time_ms"])

        plt.title(f"Average Runtime at Size {largest_size} - {input_type}")
        plt.xlabel("Algorithm")
        plt.ylabel("Average Runtime (ms)")
        plt.yscale("log")
        plt.xticks(rotation=45, ha="right")
        plt.tight_layout()

        output_path = OUTPUT_DIR / f"bar_{input_type}_{largest_size}.png"
        plt.savefig(output_path, dpi=150)
        plt.close()

        print(f"Wrote {output_path}")


def plot_parallel_vs_regular_merge(df: pd.DataFrame) -> None:
    OUTPUT_DIR.mkdir(exist_ok=True)

    subset = df[df["algorithm"].isin(["MergeSort", "ParallelMergeSort"])]

    if subset.empty:
        print("Skipping MergeSort vs ParallelMergeSort graph; no matching data found.")
        return

    grouped = (
        subset.groupby(["algorithm", "input_type", "size"], as_index=False)
        .agg(avg_time_ms=("time_ms", "mean"))
    )

    for input_type in sorted(grouped["input_type"].unique()):
        input_subset = grouped[grouped["input_type"] == input_type]

        plt.figure(figsize=(12, 8))

        for algorithm in ["MergeSort", "ParallelMergeSort"]:
            algorithm_data = input_subset[input_subset["algorithm"] == algorithm]
            algorithm_data = algorithm_data.sort_values("size")

            if algorithm_data.empty:
                continue

            plt.plot(
                algorithm_data["size"],
                algorithm_data["avg_time_ms"],
                marker="o",
                label=algorithm,
            )

        plt.title(f"Merge Sort vs Parallel Merge Sort - {input_type}")
        plt.xlabel("Input Size")
        plt.ylabel("Average Runtime (ms)")
        plt.xscale("log")
        plt.yscale("log")
        plt.grid(True, which="both", linestyle="--", linewidth=0.5)
        plt.legend()
        plt.tight_layout()

        output_path = OUTPUT_DIR / f"merge_vs_parallel_{input_type}.png"
        plt.savefig(output_path, dpi=150)
        plt.close()

        print(f"Wrote {output_path}")


def main() -> None:
    df = load_results()

    print("Loaded completed benchmark results:")
    print(df.head())

    plot_runtime_by_input_type(df)
    plot_algorithm_comparison_at_largest_size(df)
    plot_parallel_vs_regular_merge(df)

    print("Graph generation complete.")


if __name__ == "__main__":
    main()