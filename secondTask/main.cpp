#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cassert>

#define RESULT_COUNTER 5

std::mutex g_lock;

void incrementAndPrintResult(unsigned int& sharedCounter) 
{
    g_lock.lock();
    std::cout << "Incremented Data " << ++sharedCounter << std::endl;
    g_lock.unlock();
}

int main()
{
    unsigned int sharedCounter = 0;
    const int threadsAmount = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < threadsAmount; ++i) {
        threads.emplace_back(incrementAndPrintResult, std::ref(sharedCounter));
    }

    for (auto& th : threads) {
        th.join();
    }
    std::cout << "Counter after execution of all threads " << sharedCounter << std::endl;
    assert(sharedCounter == RESULT_COUNTER);
    std::cout << "Test was passed successfully" << std::endl;
}