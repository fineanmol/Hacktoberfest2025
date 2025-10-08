import json
import os

DATA_FILE = "tasks.json"
import shlex

def require_int(args, usage):
    if not args or not args[0].isdigit():
        print(usage)
        return None
    return int(args[0])

def cmd_list(tasks, args):
    list_tasks(tasks)

def cmd_add(tasks, args):
    if not args:
        print("Usage: add <title>")
        return
    add_task(tasks, " ".join(args))  # allow spaces in title

def cmd_done(tasks, args):
    n = require_int(args, "Usage: done <num>")
    if n is not None:
        toggle_task(tasks, n)

def cmd_del(tasks, args):
    n = require_int(args, "Usage: del <num>")
    if n is not None:
        delete_task(tasks, n)

def cmd_help(tasks, args):
    help_menu()

def cmd_quit(tasks, args):
    print("Bye!")
    return False  # signal to exit loop

DISPATCH = {
    "list": cmd_list,
    "add": cmd_add,
    "done": cmd_done,
    "del":  cmd_del,
    "help": cmd_help,
    "quit": cmd_quit,
}

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

        parts = shlex.split(input("> ").strip())
        if not parts:
            continue
        action, *args = parts
        handler = DISPATCH.get(action)
        if not handler:
            print("Unknown command. Type 'help'.")
            continue
        keep_running = handler(tasks, args)
        if keep_running is False:
            break

if __name__ == "__main__":
    main()
