#!/bin/bash
# save as memory_avg.sh

runs=10
cmd="$*"
total_memory=0

echo "Running '$cmd' $runs times..."

for i in $(seq 1 $runs); do
  output=$(/usr/bin/time -l bash -c "$cmd" 2>&1)
  
  # Extract the number after "maximum resident set size"
  mem=$(echo "$output" | grep "maximum resident set size" | awk '{print $1}')
  
  if [[ -n "$mem" && "$mem" =~ ^[0-9]+$ ]]; then
    total_memory=$((total_memory + mem))
    echo "Run $i: $mem bytes"
  else
    echo "Run $i: Failed to get memory usage"
    echo "Debug: maximum resident set size line:"
    echo "$output" | grep -A 1 "maximum resident set size"
    runs=$((runs - 1))
  fi
done

if [ $runs -gt 0 ]; then
  avg=$((total_memory / runs))
  avg_kb=$(echo "scale=2; $avg/1024" | bc)
  avg_mb=$(echo "scale=2; $avg/1024/1024" | bc)
  
  echo "----------------------------------------"
  echo "Average memory usage over $runs runs:"
  echo "$avg bytes ($avg_kb KB, $avg_mb MB)"
fi
