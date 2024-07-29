#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;                   // 全局互斥锁
std::condition_variable cv;       // 全局条件变量
std::queue<int> buffer;           // 共享队列
const int capacity = 5;           // 队列容量
const size_t MAX_QUEUE_SIZE = 12; // 生产者生产数量
void callbackProducer()
{
    for (int i = 1; i <= MAX_QUEUE_SIZE; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return buffer.size() < capacity; }); // 等待队列不满

        buffer.push(i); // 向队列添加元素
        std::cout << "--> Produced: " << i << std::endl;

        lock.unlock();
        cv.notify_one(); // 通知消费者
    }
}

void callbackConsumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return !buffer.empty(); }); // 等待队列非空

        int value = buffer.front();
        buffer.pop(); // 从队列取出元素
        std::cout << "Consumed: " << value << std::endl;

        lock.unlock();
        cv.notify_one(); // 通知生产者

        if (value == MAX_QUEUE_SIZE)
        {
            break; // 假设我们只消费到MAX_QUEUE_SIZE,然后退出循环
        }
    }
}

void test_variable_condition_mutex()
{
    std::thread t1(callbackProducer);
    std::thread t2(callbackConsumer);

    t1.join();
    t2.join();
}
