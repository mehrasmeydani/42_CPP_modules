#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

RUNS="${RUNS:-100}"
LENGTHS_INPUT="${LENGTHS:-5 8 10 12 16 20 24 28 32 40}"
read -r -a LENGTHS <<< "$LENGTHS_INPUT"

# Ford-Johnson worst-case comparisons:
# F(n) = sum_{k=1..n} ceil(log2(3k/4))
# Computed with integer arithmetic only.
ford_johnson_max() {
	local n="$1"
	local sum=0
	local k=1
	while (( k <= n )); do
		local e=0
		local lhs=4
		local rhs=$((3 * k))
		while (( lhs < rhs )); do
			lhs=$((lhs * 2))
			e=$((e + 1))
		done
		sum=$((sum + e))
		k=$((k + 1))
	done
	echo "$sum"
}

make >/dev/null

total_fail=0

for n in "${LENGTHS[@]}"; do
	if (( n < 1 )); then
		echo "[SKIP] n=$n (must be >= 1)"
		continue
	fi

	max_cmp="$(ford_johnson_max "$n")"
	pass=0
	fail=0
	worst=0
	first_fail=""

	for ((run = 1; run <= RUNS; run++)); do
		nums=()

		if (( run == 1 )); then
			# Deterministic descending
			for ((v = n; v >= 1; v--)); do
				nums+=("$v")
			done
		elif (( run == 2 )); then
			# Deterministic ascending
			for ((v = 1; v <= n; v++)); do
				nums+=("$v")
			done
		elif (( run == 3 )); then
			# Deterministic zig-zag
			low=1
			high="$n"
			while (( low <= high )); do
				nums+=("$high")
				if (( low != high )); then
					nums+=("$low")
				fi
				low=$((low + 1))
				high=$((high - 1))
			done
		else
			# Random unique values
			mapfile -t nums < <(shuf -i 1-"$((n * 20))" -n "$n")
		fi

		out="$(./PmergeMe "${nums[@]}" | tail -n 1 | tr -d '\r')"
		if [[ ! "$out" =~ ^[0-9]+$ ]]; then
			fail=$((fail + 1))
			total_fail=$((total_fail + 1))
			if [[ -z "$first_fail" ]]; then
				first_fail="run=$run invalid-output='$out'"
			fi
			continue
		fi

		cmp="$out"
		if (( cmp > worst )); then
			worst="$cmp"
		fi

		if (( cmp <= max_cmp )); then
			pass=$((pass + 1))
		else
			fail=$((fail + 1))
			total_fail=$((total_fail + 1))
			if [[ -z "$first_fail" ]]; then
				first_fail="run=$run comparisons=$cmp max=$max_cmp input=${nums[*]}"
			fi
		fi
	done

	echo "n=$n max=$max_cmp pass=$pass fail=$fail worst_seen=$worst"
	if [[ -n "$first_fail" ]]; then
		echo "  first_failure: $first_fail"
	fi
done

if (( total_fail > 0 )); then
	echo "RESULT: FAIL ($total_fail failing runs)"
	exit 1
fi

echo "RESULT: PASS"
