import json
import os
from colorama import init, Fore, Style

init(autoreset=True)

DATA_FILE = "tasks.json"
BACKUP_FILE = "tasks_backup.json"


def load_tasks():
    """Load tasks from file, or create empty list if file not found/corrupted."""
    if not os.path.exists(DATA_FILE):
        return []
    try:
        with open(DATA_FILE, "r", encoding="utf-8") as f:
            return json.load(f)
    except (json.JSONDecodeError, OSError):
        print(Fore.YELLOW + "⚠ Corrupted data file detected. Creating a backup and resetting.")
        try:
            os.rename(DATA_FILE, BACKUP_FILE)
        except OSError:
            pass
        return []


def save_tasks(tasks):
    """Save tasks to JSON file safely."""
    try:
        with open(DATA_FILE, "w", encoding="utf-8") as f:
            json.dump(tasks, f, ensure_ascii=False, indent=2)
    except OSError as e:
        print(Fore.RED + f"❌ Error saving tasks: {e}")


def list_tasks(tasks):
    """List all tasks."""
    if not tasks:
        print(Fore.CYAN + "No tasks available.")
        return
    for i, t in enumerate(tasks, 1):
        status = Fore.GREEN + "✔" if t["done"] else Fore.RED + "✗"
        print(f"{Fore.WHITE}{i}. [{status}{Fore.WHITE}] {t['title']}")


def add_task(tasks, title):
    """Add a new task."""
    title = title.strip()
    if not title:
        print(Fore.RED + "❌ Title cannot be empty.")
        return
    tasks.append({"title": title, "done": False})
    save_tasks(tasks)
    print(Fore.GREEN + f"✅ Added: {title}")


def toggle_task(tasks, index):
    """Mark/unmark a task as done."""
    if not (1 <= index <= len(tasks)):
        print(Fore.RED + "❌ Invalid task number.")
        return
    task = tasks[index - 1]
    task["done"] = not task["done"]
    save_tasks(tasks)
    status = "done" if task["done"] else "not done"
    print(Fore.GREEN + f"🔄 Marked '{task['title']}' as {status}.")


def delete_task(tasks, index):
    """Delete a specific task."""
    if not (1 <= index <= len(tasks)):
        print(Fore.RED + "❌ Invalid task number.")
        return
    removed = tasks.pop(index - 1)
    save_tasks(tasks)
    print(Fore.GREEN + f"🗑 Deleted: {removed['title']}")


def clear_done(tasks):
    """Remove all completed tasks."""
    before = len(tasks)
    tasks = [t for t in tasks if not t["done"]]
    if len(tasks) == before:
        print(Fore.YELLOW + "No completed tasks to clear.")
    else:
        save_tasks(tasks)
        print(Fore.GREEN + f"🧹 Cleared {before - len(tasks)} completed task(s).")
    return tasks


def search_tasks(tasks, keyword):
    """Search for tasks containing a keyword."""
    keyword = keyword.lower().strip()
    if not keyword:
        print(Fore.RED + "❌ Please provide a search keyword.")
        return
    matches = [t for t in tasks if keyword in t["title"].lower()]
    if not matches:
        print(Fore.YELLOW + "No matching tasks found.")
    else:
        print(Fore.CYAN + f"🔍 Found {len(matches)} matching task(s):")
        for i, t in enumerate(matches, 1):
            status = "✔" if t["done"] else "✗"
            print(f"  {i}. [{status}] {t['title']}")


def help_menu():
    """Display available commands."""
    print(Fore.MAGENTA + Style.BRIGHT + "\nCommands:")
    print("  list                Show all tasks")
    print("  add <title>         Add a new task")
    print("  done <num>          Toggle done/undone")
    print("  del <num>           Delete a task")
    print("  clear               Remove all completed tasks")
    print("  search <keyword>    Search tasks by keyword")
    print("  help                Show this help menu")
    print("  quit                Exit\n")


def main():
    tasks = load_tasks()
    print(Fore.CYAN + "📝 Simple To-Do List")
    help_menu()

    while True:
        try:
            cmd = input(Fore.WHITE + "> ").strip()
        except (EOFError, KeyboardInterrupt):
            print("\n" + Fore.CYAN + "👋 Bye!")
            break

        if not cmd:
            continue

        parts = cmd.split(maxsplit=1)
        action = parts[0].lower()

        if action == "list":
            list_tasks(tasks)
        elif action == "add":
            add_task(tasks, parts[1] if len(parts) > 1 else "")
        elif action == "done":
            toggle_task(tasks, int(parts[1]) if len(parts) > 1 and parts[1].isdigit() else -1)
        elif action == "del":
            delete_task(tasks, int(parts[1]) if len(parts) > 1 and parts[1].isdigit() else -1)
        elif action == "clear":
            tasks = clear_done(tasks)
        elif action == "search":
            search_tasks(tasks, parts[1] if len(parts) > 1 else "")
        elif action == "help":
            help_menu()
        elif action in ("quit", "exit"):
            print(Fore.CYAN + "👋 Bye!")
            break
        else:
            print(Fore.RED + "❓ Unknown command. Type 'help' to see available options.")


if __name__ == "__main__":
    main()
