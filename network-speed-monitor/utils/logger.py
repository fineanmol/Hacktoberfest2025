import os
import json
from datetime import datetime

DATA_FILE = "data/daily_summary.json"

def log_data(entry):
    """Append a new record to daily_summary.json safely."""
    os.makedirs("data", exist_ok=True)
    
    # Check if file exists and is non-empty
    if os.path.exists(DATA_FILE) and os.path.getsize(DATA_FILE) > 0:
        with open(DATA_FILE, "r") as f:
            try:
                data = json.load(f)
            except json.JSONDecodeError:
                data = []
    else:
        data = []

    data.append(entry)

    with open(DATA_FILE, "w") as f:
        json.dump(data, f, indent=4)
