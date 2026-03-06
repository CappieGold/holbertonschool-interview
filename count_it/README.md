# Count it!

## Description

A recursive Python function that queries the **Reddit API**, parses the titles of all **hot articles** for a given subreddit, and prints a sorted count of specified keywords.

## Prototype

```python
def count_words(subreddit, word_list)
```

## Rules

- Results are **case-insensitive** (`JavA` and `java` are the same keyword).
- If `word_list` contains duplicates, their counts are summed together.
- Only **exact word matches** count — `java.` or `java!` do not count as `java`.
- Output is sorted by **count descending**, then **alphabetically ascending** for ties.
- Keywords with zero matches are not printed.
- Invalid subreddits print nothing (redirects are not followed).
- The function must be **recursive** (pagination via Reddit's `after` token).

## Usage

```bash
python3 0-main.py <subreddit> '<space-separated keywords>'
```

### Examples

```bash
$ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4

$ python3 0-main.py programming 'JavA java'
java: 54

$ python3 0-main.py not_a_valid_subreddit 'python java'
$
```

> **Note:** Counts will vary since Reddit hot articles change constantly.

## Files

| File | Description |
|------|-------------|
| `0-count.py` | Recursive function `count_words` |
| `0-main.py` | Main entry point for testing |
