Pull Request: Add Network Speed Monitor Python Program

📝 Description
This pull request adds a new Python utility script — Network Speed Monitor — that measures internet download/upload speeds, ping, latency, and jitter using the speedtest-cli and ping3 modules.
It also calculates a Network Health Score and logs daily summaries in a structured JSON file for visualization.

✨ Features

Uses speedtest-cli to measure download & upload speeds accurately.

Measures ping, latency, and jitter for network stability insights.

Calculates a Network Health Score out of 100 based on speed, ping, and jitter.

Logs results in JSON format for dashboards or trend analysis.

Optional alert system for low speeds or high latency.

Modular code structure for maintainability and easy expansion.

🚀 How to Run

Install required packages:

pip install -r requirements.txt


Run the program:

python main.py


🧾 Output Example

🏓 Ping: 14.2 ms  |  📶 Latency: 13.8 ms  |  🔄 Jitter: 2.1 ms
⬇️ Download: 85.45 Mbps  |  ⬆️ Upload: 21.67 Mbps
📊 Network Health Score: 92/100
⚠️ Warning: Poor network detected!  # if applicable


📂 Data Logging Example

{
  "timestamp": "2025-10-12 10:42:00",
  "download_mbps": 85.45,
  "upload_mbps": 21.67,
  "ping_ms": 14.23,
  "latency_ms": 13.8,
  "jitter_ms": 2.1,
  "network_score": 92
}


##🎯 Purpose
This script is a meaningful and practical addition to the repository’s Python examples — it helps both beginners and advanced users understand network performance, stability, and reliability.
It’s also ready for dashboard integration, trend monitoring, and alerting — making it a complete, professional-grade network monitoring tool.
