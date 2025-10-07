import json
import os

DATA_FILE = "tasks.json"

def load_tasks():
    if not os.path.exists(DATA_FILE):
        return []
    try:
        with open(DATA_FILE, "r", encoding="utf-8") as f:
            return json.load(f)
    except (json.JSONDecodeError, OSError):
        return []

def save_tasks(tasks):
    with open(DATA_FILE, "w", encoding="utf-8") as f:
        json.dump(tasks, f, ensure_ascii=False, indent=2)

def list_tasks(tasks):
    if not tasks:
        print("No tasks.")
        return
    for i, t in enumerate(tasks, 1):
        status = "✔" if t["done"] else "✗"
        print(f"{i}. [{status}] {t['title']}")

def add_task(tasks, title):
    title = title.strip()
    if not title:
        print("Title cannot be empty.")
        return
    tasks.append({"title": title, "done": False})
    save_tasks(tasks)
    print("Added.")

def toggle_task(tasks, index):
    if index < 1 or index > len(tasks):
        print("Invalid task number.")
        return
    tasks[index - 1]["done"] = not tasks[index - 1]["done"]
    save_tasks(tasks)
    print("Updated.")

def delete_task(tasks, index):
    if index < 1 or index > len(tasks):
        print("Invalid task number.")
        return
    tasks.pop(index - 1)
    save_tasks(tasks)
    print("Deleted.")

def help_menu():
    print("Commands:")
    print("  list                Show tasks")
    print("  add <title>         Add a task")
    print("  done <num>          Toggle done/undone")
    print("  del <num>           Delete a task")
    print("  help                Show this help")
    print("  quit                Exit")

def main():
    tasks = load_tasks()
    print("Simple To-Do List")
    help_menu()
    while True:
        try:
            cmd = input("> ").strip()
        except (EOFError, KeyboardInterrupt):
            print("\nBye!")
            break

        if not cmd:
            continue

        parts = cmd.split(maxsplit=1)
        action = parts[0].lower()

        if action == "list":
            list_tasks(tasks)
        elif action == "add":
            if len(parts) == 1:
                print("Usage: add <title>")
            else:
                add_task(tasks, parts[1])
        elif action == "done":
            if len(parts) == 1 or not parts[1].isdigit():
                print("Usage: done <num>")
            else:
                toggle_task(tasks, int(parts[1]))
        elif action == "del":
            if len(parts) == 1 or not parts[1].isdigit():
                print("Usage: del <num>")
            else:
                delete_task(tasks, int(parts[1]))
        elif action == "help":
            help_menu()
        elif action == "quit":
            print("Bye!")
            break
        else:
            print("Unknown command. Type 'help'.")

if __name__ == "__main__":
    main()
