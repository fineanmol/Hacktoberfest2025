# 🚀 Network Speed Monitor — Latency, Jitter & Health Score in Python

📝 **Description**  
This Python utility measures **download & upload speeds**, **ping**, **latency**, and **jitter**, calculates a **Network Health Score**, and logs results in **JSON format** for trend analysis and dashboard integration.

---

## ✨ Features
- ⬇️⬆️ **Download & Upload Speeds** using `speedtest-cli`  
- 🏓 **Ping, Latency & Jitter** using `ping3`  
- 📊 **Network Health Score** (0–100) based on speed, latency, and jitter  
- 🗂 **JSON Logging** for dashboard-ready structured data  
- ⚠️ **Optional Alerts** for poor network conditions  
- 🛠 **Modular Code** for maintainability and easy expansion  

---

## 🚀 How to Run

1. Install dependencies:

```bash
pip install -r requirements.txt
```

---
## 🧾 Output Example

🏓 Ping: 29.07 ms  |  📶 Latency: 5.0 ms  |  🔄 Jitter: 1.35 ms
⬇️ Download: 24.88 Mbps  |  ⬆️ Upload: 21.4 Mbps
📊 Network Health Score: 100/100
⚠️ Warning: Poor network detected!  # if applicable

<img width="931" height="139" alt="image" src="https://github.com/user-attachments/assets/e81b889e-c3c6-4522-a44c-1f28b9e01ff9" />

---
## 📂 Data Logging Example
{
  "timestamp": "2025-10-12 10:42:00",
  "download_mbps": 85.45,
  "upload_mbps": 21.67,
  "ping_ms": 14.23,
  "latency_ms": 13.8,
  "jitter_ms": 2.1,
  "network_score": 92
}


Stored in data/daily_summary.json
---

## 🎯 Purpose

This script is a practical and professional Python networking tool:
Helps beginners understand network performance, stability, and reliability
Can be extended to alerts, dashboards, and trend monitoring
Fully modular and portfolio-ready
