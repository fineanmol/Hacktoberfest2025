from utils.speed_test import get_speed
from utils.latency_test import measure_latency
from utils.score import calculate_score
from utils.logger import log_data
from datetime import datetime

def main():
    # 1️⃣ Measure download/upload/ping
    download, upload, ping = get_speed()

    # 2️⃣ Measure latency and jitter
    latency, jitter = measure_latency()

    # 3️⃣ Calculate network health score
    score = calculate_score(download, upload, ping, jitter)

    # 4️⃣ Print results
    print(f"🏓 Ping: {ping} ms  |  📶 Latency: {latency} ms  |  🔄 Jitter: {jitter} ms")
    print(f"⬇️ Download: {download} Mbps  |  ⬆️ Upload: {upload} Mbps")
    print(f"📊 Network Health Score: {score}/100")

    # 5️⃣ Optional alert
    if download < 5 or ping > 150:
        print("⚠️ Warning: Poor network detected!")

    # 6️⃣ Log results to JSON
    entry = {
        "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
        "download_mbps": download,
        "upload_mbps": upload,
        "ping_ms": ping,
        "latency_ms": latency,
        "jitter_ms": jitter,
        "network_score": score
    }
    log_data(entry)

if __name__ == "__main__":
    main()
