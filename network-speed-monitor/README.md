# 🚀 Network Speed Monitor

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
## 🧾 Output Example
🏓 Ping: 29.07 ms  |  📶 Latency: 5.0 ms  |  🔄 Jitter: 1.35 ms
⬇️ Download: 24.88 Mbps  |  ⬆️ Upload: 21.4 Mbps
📊 Network Health Score: 100/100
⚠️ Warning: Poor network detected!  # if applicable
