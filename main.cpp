#include <iostream>
#include <sstream>
#include <vector>

void printVector(const std::vector<int>& vec) {
    std::cout << "Current account values: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int calculateSum(std::string input) {
    std::stringstream ss(input);
    std::vector<int> accounts;

    std::string token;
    while (ss >> token) {
        if (token == "+") {
            if (accounts.size() < 2) {
                std::cerr << "Insufficient operands for addition.\n";
                return 0;
            }
            int num2 = accounts.back();
            accounts.pop_back();
            int num1 = accounts.back();
            accounts.pop_back();
            accounts.push_back(num1 + num2);
            printVector(accounts);
        } else if (token == "d") {
            if (accounts.empty()) {
                std::cerr << "No number to double.\n";
                return 0;
            }
            int num = accounts.back();
            accounts.push_back(num * 2);
            printVector(accounts);
        } else if (token == "c") {
            if (accounts.empty()) {
                std::cerr << "Vector is empty, cannot perform 'c' operation.\n";
                return 0;
            }
            accounts.pop_back();
            printVector(accounts);
        } else {
            try {
                int num = std::stoi(token);
                if (num < -333 || num > 333) {
                    std::cerr << "The number " << num << " is out of range.\n";
                    return 0;
                }
                accounts.push_back(num);
                printVector(accounts);
            } catch (...) {
                std::cerr << "Invalid input.\n";
                return 0;
            }
        }
    }

    int sum = 0;
    for (int num : accounts) {
        sum += num;
    }

    return sum;
}

int main() {
    std::string input;
    std::cout << "Enter a string of elements separated by spaces: ";
    std::getline(std::cin, input);

    int result = calculateSum(input);
    if (result != 0) {
        std::cout << "The sum of all saved accounts: " << result << std::endl;
    }

    return 0;
}
