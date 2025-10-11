import time
import datetime
import platform
import os

# Time between reminders (in seconds) — 30 minutes = 1800 seconds
REMINDER_INTERVAL = 1800  

MESSAGES = [
    "💧 Time to drink some water!",
    "👀 Look away from the screen for 20 seconds to relax your eyes.",
    "🧍‍♀️ Stand up and stretch your legs!",
    "☕ Take a short break — you’ve earned it!"
]

def notify(message: str):
    """Display a system notification or terminal message."""
    print(f"[{datetime.datetime.now().strftime('%H:%M:%S')}] {message}")

    # Use native notifications if available
    if platform.system() == "Darwin":  # macOS
        os.system(f"osascript -e 'display notification \"{message}\" with title \"Break Reminder\"'")
    elif platform.system() == "Linux":
        os.system(f"notify-send 'Break Reminder' '{message}'")
    elif platform.system() == "Windows":
        # Windows toast notification via powershell
        os.system(f'powershell -Command "New-BurntToastNotification -Text \'{message}\'"')

def main():
    print("🔔 Break Reminder is running... (Press Ctrl+C to stop)")
    while True:
        for msg in MESSAGES:
            notify(msg)
            time.sleep(REMINDER_INTERVAL)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n🛑 Break Reminder stopped. Take care of yourself!")
