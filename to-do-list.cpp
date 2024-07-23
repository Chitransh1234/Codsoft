#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &description)
    {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(int taskNumber)
    {
        if (taskNumber < 1 || taskNumber > tasks.size())
        {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[taskNumber - 1].completed = true;
        cout << "Task " << taskNumber << " marked as completed." << endl;
    }

    void removeTask(int taskNumber)
    {
        if (taskNumber < 1 || taskNumber > tasks.size())
        {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
};

void showMenu()
{
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    ToDoList toDoList;
    int choice;
    string description;
    int taskNumber;

    while (true)
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            toDoList.addTask(description);
            break;
        case 2:
            toDoList.viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            toDoList.markTaskAsCompleted(taskNumber);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            toDoList.removeTask(taskNumber);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
