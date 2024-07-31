#include <iostream>
#include <vector>
#include <string>

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1/2/3/4): ";
}

void addTask(std::vector<std::string>& tasks) {
    std::string task;
    std::cin.ignore();  // Clear input buffer
    std::cout << "Enter the task: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }
    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << '\n';
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }
    viewTasks(tasks);
    size_t index;
    std::cout << "Enter the task number to delete: ";
    std::cin >> index;
    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task deleted successfully!\n";
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
