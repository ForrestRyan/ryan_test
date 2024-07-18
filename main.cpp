#include "include/header.h"
#include <optional>
#include <shared_mutex>
#include <mutex>

using namespace std;
std::shared_mutex m_managerMutex;

struct Property {
    std::optional<int> value;
    std::optional<std::string> name{"xiaoming"};
    std::string tag;
};

Property getProperty() {
    Property p;
    return p;
}

void test_shared_mutex()
{
    // const std::shared_lock lock1(m_managerMutex);
    // cout << "test shared_lock1" << endl;

    {
        const std::shared_lock lock2(m_managerMutex);
        cout << "test shared_lock2" << endl;
    }

    {
        const std::unique_lock lock(m_managerMutex);
        cout << "test unique_lock" << endl;
    }

    // const std::unique_lock lock2(m_managerMutex);
    // cout << "test unique_lock" << endl;
}

int main()
{
    const Property &p = getProperty();
    test_shared_mutex();

    try
    {
        std::cout << p.name.value_or("") << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "over!" << std::endl;

    return 0;
}