Q1.write a c++ program for perform Thread Concepts operations using function pointer, lambda function.

#include <iostream>
#include <thread>
using namespace std;

void task1(int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Thread using function pointer\n";
    }
}

class TaskObj {
public:
    void operator()(int n)
    {
        for (int i = 0; i < n; i++)
            cout << "Thread using function object\n";
    }
};

class Example {
public:
    void memberTask()
    {
        cout << "Thread using non-static member function\n";
    }

    static void staticTask()
    {
        cout << "Thread using static member function\n";
    }
};

int main()
{
    cout << "Threads running independently\n";

    thread t1(task1, 3);
    thread t2(TaskObj(), 3);

    auto lambdaTask = [](int n) {
        for (int i = 0; i < n; i++)
            cout << "Thread using lambda\n";
    };

    thread t3(lambdaTask, 3);

    Example ex;

    thread t4(&Example::memberTask, &ex);
    thread t5(&Example::staticTask);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "All threads completed\n";

    for (int i = 0; i < 5; i++) {
        cout << "Main thread extra operations: " << i + 1 << "\n";
    }

    thread t6([] {
        for (int i = 0; i < 3; i++)
            cout << "Thread t6 performing task\n";
    });

    t6.join();

    for (int i = 0; i < 5; i++) {
        cout << "More main thread operations: " << i + 1 << "\n";
    }

    return 0;
}

Output:

Threads running independently
Thread using function object
Thread using non-static member function
Thread using lambda
Thread using lambda
Thread using lambda
Thread using function object
Thread using function object
Thread using function pointer
Thread using function pointer
Thread using function pointer
Thread using static member function
All threads completed
Main thread extra operations: 1
Main thread extra operations: 2
Main thread extra operations: 3
Main thread extra operations: 4
Main thread extra operations: 5
Thread t6 performing task
Thread t6 performing task
Thread t6 performing task
More main thread operations: 1
More main thread operations: 2
More main thread operations: 3
More main thread operations: 4
More main thread operations: 5