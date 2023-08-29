#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std;

std::shared_mutex guard;
std::mutex coutMutex;
vector<int> numbers = {};

int getNextValue() {
    
    static int i = 0;
    return i+=10;
}

void read(int index) {
    
    for(int i = 0; i < 10; i++) {
        std::shared_lock<std::shared_mutex> lock(guard);
        int value = numbers[index];
        lock.unlock();

        std::lock_guard<std::mutex> coutLock(coutMutex);
        cout << value << " ";
    }
}

void write() {
    
    for(int i = 0; i < 3; i++) {
        std::unique_lock<std::shared_mutex> lock(guard);
        int newValue = getNextValue();
        numbers.emplace_back(newValue);
    }
}

int main() {
    vector<thread> writers;
    for(int i = 0; i < 10; i++)
        writers.emplace_back(write);

    cout << "Writers produced: ";
    for(const auto & n : numbers)
        cout << n << " ";
    cout << endl;

    cout << "Readers consumed: ";
    vector<thread> readers;
    for(int i = 0; i < 10; i++)
        readers.emplace_back(read, i);

    for(auto && writer : writers)
        writer.join();
    for(auto && reader : readers)
        reader.join();

    cout << endl;
    return 0;
}