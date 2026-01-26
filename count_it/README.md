# Count It

Recursive function that queries the Reddit API to count keyword occurrences in hot article titles from a subreddit.

## Features

- Recursively fetches all hot posts from a subreddit
- Case-insensitive word matching
- Counts word occurrences (not titles)
- Results sorted by count (descending), then alphabetically
- Words delimited by spaces (punctuation excluded)

## Usage

```python
count_words(subreddit, word_list)
```

## Requirements

- Python 3.x
- `requests` library

## Example

```bash
python3 0-main.py programming 'react python java javascript'
```

Output:
```
java: 27
javascript: 20
python: 17
react: 17
```

## Notes

- Duplicate words in word_list are summed together
- Words with no matches are skipped
- Invalid subreddits print nothing
