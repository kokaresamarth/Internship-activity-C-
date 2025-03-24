Q4.write a c++ program for perform Un ordered map operations using Exception handling techniques.

#include <iostream>
#include <unordered_map>
using namespace std;

class BaseTask {
protected:
    unordered_map<string, int> data;

public:
    BaseTask() {
        data["value1"] = 0;
        data["value2"] = 0;
    }

    BaseTask(int x, int y) {
        if (x < 0 || y < 0) {
            throw invalid_argument("Negative values are not allowed.");
        }
        data["value1"] = x;
        data["value2"] = y;
    }

    virtual void displayTaskInfo() {
        cout << "Base task initialized with values: "
             << data["value1"] << ", " << data["value2"] << "\n";
    }

    void updateValue(const string& key, int value) {
        data[key] = value;
        cout << "Updated " << key << " to " << value << "\n";
    }

    int getValue(const string& key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        } else {
            throw invalid_argument("Key not found.");
        }
    }

    virtual ~BaseTask() {}
};

class DerivedTask : public BaseTask {
public:
    DerivedTask(int x, int y) : BaseTask(x, y) {}

    void processSum() {
        int sum = data["value1"] + data["value2"];
        cout << "Sum: " << sum << "\n";
    }

    void processProduct() {
        int product = data["value1"] * data["value2"];
        cout << "Product: " << product << "\n";
    }

    void displayTaskInfo() override {
        cout << "Derived task operations started." << endl;
        cout << "Values: " << data["value1"] << " and " << data["value2"] << "\n";
    }

    void displayAllData() {
        cout << "All data in DerivedTask:" << endl;
        for (const auto& pair : data) {
            cout << pair.first << ": " << pair.second << "\n";
        }
    }
};

int main() {
    try {
        DerivedTask task(10, 20);
        task.displayTaskInfo();

        cout << "Processing task operations:" << endl;
        task.processSum();
        task.processProduct();

        task.updateValue("value3", 30);
        task.updateValue("value4", 40);

        cout << "Fetching individual values:" << endl;
        cout << "Value3: " << task.getValue("value3") << "\n";
        cout << "Value4: " << task.getValue("value4") << "\n";

        task.displayAllData();

        unordered_map<string, int> additionalData = {
            {"extra1", 50},
            {"extra2", 60},
            {"extra3", 70}
        };

        cout << "Additional data processing:" << endl;
        for (const auto& pair : additionalData) {
            cout << pair.first << ": " << pair.second << "\n";
        }

        cout << "Main execution completed." << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}

Output:

Derived task operations started.
Values: 10 and 20
Processing task operations:
Sum: 30
Product: 200
Updated value3 to 30
Updated value4 to 40
Fetching individual values:
Value3: 30
Value4: 40
All data in DerivedTask:
value1: 10
value2: 20
value3: 30
value4: 40
Additional data processing:
extra1: 50
extra2: 60
extra3: 70
Main execution completed.