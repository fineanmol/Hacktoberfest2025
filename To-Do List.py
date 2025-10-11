#Program for To-Do List Application
class ToDoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append(task)
        print(f'Task "{task}" added.')

    def view_tasks(self):
        if self.tasks:
            print('Tasks:')
            for i, task in enumerate(self.tasks, 1):
                print(f'{i}. {task}')
        else:
            print('No tasks in the list.')

    def mark_task_completed(self, task_number):
        if 1 <= task_number <= len(self.tasks):
            task = self.tasks[task_number - 1]
            print(f'Task "{task}" marked as completed.')
            self.tasks.pop(task_number - 1)
        else:
            print('Invalid task number.')

    def remove_task(self, task_number):
        if 1 <= task_number <= len(self.tasks):
            task = self.tasks[task_number - 1]
            print(f'Task "{task}" removed.')
            self.tasks.pop(task_number - 1)
        else:
            print('Invalid task number.')


def main():
    todo_list = ToDoList()

    while True:
        print('\nMenu:')
        print('1. Add Task')
        print('2. View Tasks')
        print('3. Mark Task as Completed')
        print('4. Remove Task')
        print('5. Quit')

        choice = input('Enter your choice: ')

        if choice == '1':
            task = input('Enter task: ')
            todo_list.add_task(task)
        elif choice == '2':
            todo_list.view_tasks()
        elif choice == '3':
            task_number = int(input('Enter task number to mark as completed: '))
            todo_list.mark_task_completed(task_number)
        elif choice == '4':
            task_number = int(input('Enter task number to remove: '))
            todo_list.remove_task(task_number)
        elif choice == '5':
            break
        else:
            print('Invalid choice. Please try again.')


if __name__ == '__main__':
    main()
