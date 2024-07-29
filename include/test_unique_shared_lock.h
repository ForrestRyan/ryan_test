#pragma once

#include <shared_mutex>
#include <mutex>
#include <iostream> // std::cout
#include <string>

using namespace std;
std::shared_mutex m_mutex;

// Summary:
// 1. unique_lock is NOT reentrant, shared_lock is reentrant
// 2. unique_lock and shared_lock can NOT be used in the same scope/thread
void test_unique_shared_lock()
{
#if 0 // both share_lock is reentrant, this option is fine
    const std::shared_lock shared_lock1(m_mutex);
    cout << "test shared_lock1" << endl;

    const std::shared_lock shared_lock2(m_mutex);
    cout << "test shared_lock2" << endl;

#endif

#if 0 // both unique_lock will be deadlock(Resource deadlock avoided)
    const std::unique_lock unique_lock1(m_mutex);
    cout << "test unique_lock1" << endl;

    const std::unique_lock unique_lock2(m_mutex);
    cout << "test unique_lock2" << endl;
#endif

#if 0 // this option will hangle there
    const std::shared_lock shared_lock1(m_mutex);
    cout << "test shared_lock1" << endl;

    {
        const std::unique_lock unique_lock1(m_mutex);
        cout << "test unique_lock1" << endl;
    }
#endif

#if 1 // this option is fine
    {
        const std::shared_lock shared_lock1(m_mutex);
        cout << "test shared_lock1" << endl;
    }

    const std::unique_lock unique_lock1(m_mutex);
    cout << "test unique_lock1" << endl;

#endif

#if 0 // this option is fine
    {
        const std::unique_lock unique_lock1(m_mutex);
        cout << "test unique_lock1" << endl;
    }

    const std::shared_lock shared_lock1(m_mutex);
    cout << "test shared_lock1" << endl;
#endif

#if 0 // first to call unique_lock, then to call shared_lock, will be deadlock (Resource deadlock avoided)
    const std::unique_lock unique_lock1(m_mutex);
    cout << "test unique_lock1" << endl;

    const std::shared_lock shared_lock1(m_mutex);
    cout << "test shared_lock1" << endl;
#endif
}