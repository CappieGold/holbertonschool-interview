#!/usr/bin/python3
"""Module to count keywords in hot articles of a subreddit."""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Recursively query Reddit API, parse hot article titles,
    and print sorted count of given keywords.

    Args:
        subreddit: the subreddit to search
        word_list: list of keywords to count
        after: pagination token for Reddit API
        counts: dictionary accumulating keyword counts
    """
    if counts is None:
        counts = {}
        for word in word_list:
            w = word.lower()
            counts[w] = counts.get(w, 0)

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:count_it:v1.0 (by /u/holberton)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False
        )
    except Exception:
        return

    if response.status_code != 200:
        return

    try:
        data = response.json().get("data", {})
    except Exception:
        return

    children = data.get("children", [])
    for child in children:
        title = child.get("data", {}).get("title", "")
        words = title.lower().split()
        for word in counts:
            for w in words:
                if w == word:
                    counts[word] += 1

    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    sorted_counts = sorted(
        counts.items(), key=lambda item: (-item[1], item[0])
    )
    for word, count in sorted_counts:
        if count > 0:
            print("{}: {}".format(word, count))
