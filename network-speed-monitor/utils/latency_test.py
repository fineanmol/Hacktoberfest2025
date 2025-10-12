import ping3
import statistics

def measure_latency(server_host="8.8.8.8", count=5):
    """Measure average latency and jitter to a given host."""
    latencies = []
    for _ in range(count):
        latency = ping3.ping(server_host, timeout=2)
        if latency:
            latencies.append(latency * 1000)  # seconds → ms
    if not latencies:
        return None, None
    avg_latency = round(sum(latencies) / len(latencies), 2)
    jitter = round(statistics.stdev(latencies), 2) if len(latencies) > 1 else 0
    return avg_latency, jitter
