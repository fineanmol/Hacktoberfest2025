import json
import os

DATA_FILE = "students.json"

# -- Data Handling --

def load_data():
    """Load student data from JSON file."""
    if not os.path.exists(DATA_FILE):
        return {}
    with open(DATA_FILE, "r") as f:
        return json.load(f)

def save_data(data):
    """Save student data to JSON file."""
    with open(DATA_FILE, "w") as f:
        json.dump(data, f, indent=4)

# -- Core Functionalities --

def add_student(data):
    roll = input("Enter Roll Number: ")
    if roll in data:
        print("Student already exists!")
        return

    name = input("Enter Student Name: ")
    marks = {}
    for subject in ["Math", "Science", "English", "History", "Computer"]:
        marks[subject] = int(input(f"Enter marks for {subject}: "))

    avg = sum(marks.values()) / len(marks)
    grade = calculate_grade(avg)

    data[roll] = {"name": name, "marks": marks, "average": avg, "grade": grade}
    save_data(data)
    print(f"\n✅ Student {name} added successfully!\n")

def calculate_grade(average):
    if average >= 90:
        return "A+"
    elif average >= 80:
        return "A"
    elif average >= 70:
        return "B"
    elif average >= 60:
        return "C"
    else:
        return "F"

def view_all_students(data):
    if not data:
        print("\n⚠️ No student records found!\n")
        return
    print("\n📘 All Student Records:\n")
    for roll, info in data.items():
        print(f"Roll No: {roll}")
        print(f"Name: {info['name']}")
        print(f"Average: {info['average']:.2f}")
        print(f"Grade: {info['grade']}")
        print("-" * 30)

def search_student(data):
    roll = input("Enter Roll Number to Search: ")
    if roll not in data:
        print("❌ Student not found!")
        return

    info = data[roll]
    print(f"\n🎓 Student Details for Roll No: {roll}")
    print(f"Name: {info['name']}")
    for sub, mark in info["marks"].items():
        print(f"{sub}: {mark}")
    print(f"Average: {info['average']:.2f}")
    print(f"Grade: {info['grade']}\n")

def delete_student(data):
    roll = input("Enter Roll Number to Delete: ")
    if roll in data:
        del data[roll]
        save_data(data)
        print("✅ Student record deleted successfully!")
    else:
        print("❌ Student not found!")

# - Main Menu -

def main():
    data = load_data()

    while True:
        print("""
= STUDENT GRADE MANAGEMENT SYSTEM =
1. Add New Student
2. View All Students
3. Search Student
4. Delete Student
5. Exit

        """)
        choice = input("Enter your choice: ")

        if choice == "1":
            add_student(data)
        elif choice == "2":
            view_all_students(data)
        elif choice == "3":
            search_student(data)
        elif choice == "4":
            delete_student(data)
        elif choice == "5":
            print("👋 Exiting... Have a nice day!")
            break
        else:
            print("⚠️ Invalid choice, please try again!")

if __name__ == "__main__":
    main()
