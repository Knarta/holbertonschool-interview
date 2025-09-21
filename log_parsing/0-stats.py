#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys
import re
import signal


def print_stats(total_size, status_counts):
    """
    Print the current statistics
    """
    print("File size: {}".format(total_size))
    valid_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    for code in sorted(valid_codes):
        if code in status_counts and status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def parse_line(line):
    """
    Parse a log line and extract status code and file size
    Returns (status_code, file_size) or (None, None) if invalid format
    """
    pattern = r'^(\S+) - \[([^\]]+)\] "GET /projects/260 HTTP/1\.1" ' + \
              r'(\d+) (\d+)$'
    match = re.match(pattern, line.strip())
    if match:
        status_code = match.group(3)
        file_size = int(match.group(4))
        return status_code, file_size

    return None, None


def main():
    """
    Main function to process stdin and compute metrics
    """
    total_size = 0
    status_counts = {}
    line_count = 0
    valid_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]

    def signal_handler(signum, frame):
        """Handle keyboard interrupt (CTRL+C)"""
        print_stats(total_size, status_counts)
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)

            if status_code is not None and file_size is not None:
                if status_code in valid_codes:
                    if status_code not in status_counts:
                        status_counts[status_code] = 0
                    status_counts[status_code] += 1

                total_size += file_size
                line_count += 1

                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
