#!/usr/bin/python3
"""Log parsing script that reads stdin and computes metrics."""

import sys

if __name__ == "__main__":
    total_size = 0
    status_counts = {}
    valid_codes = {"200", "301", "400", "401", "403", "404", "405", "500"}
    line_count = 0

    def print_stats():
        """Print accumulated statistics."""
        print("File size: {}".format(total_size))
        for code in sorted(status_counts.keys()):
            if status_counts[code] > 0:
                print("{}: {}".format(code, status_counts[code]))

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) < 7:
                    continue
                file_size = int(parts[-1])
                status_code = parts[-2]
                if status_code in valid_codes:
                    status_counts[status_code] = \
                        status_counts.get(status_code, 0) + 1
                total_size += file_size
                line_count += 1
                if line_count % 10 == 0:
                    print_stats()
            except (ValueError, IndexError):
                continue
    except KeyboardInterrupt:
        pass
    finally:
        print_stats()
