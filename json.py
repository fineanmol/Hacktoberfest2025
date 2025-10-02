import json

def save_json(data, filename):
    """Save data to a JSON file."""
    with open(filename, 'w') as f:
        json.dump(data, f, indent=2)

def load_json(filename):
    """Load data from a JSON file."""
    try:
        with open(filename, 'r') as f:
            return json.load(f)
    except FileNotFoundError:
        return {}

# Example
save_json({"name": "Neko", "tasks": []}, "config.json")
data = load_json("config.json")
print(data)  # {'name': 'Neko', 'tasks': []}
