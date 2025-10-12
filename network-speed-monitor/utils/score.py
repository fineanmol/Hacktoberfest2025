def calculate_score(download, upload, ping, jitter):
    """Compute a network health score out of 100."""
    score = 100
    if download < 10: score -= 30
    if upload < 2: score -= 20
    if ping > 100: score -= 20
    if jitter > 10: score -= 10
    return max(score, 0)
