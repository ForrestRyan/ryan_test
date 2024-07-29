#include "include/header.h"
#include "include/test_rvalue_reference.h"
#include "include/test_variable_condition_mutex.h"
#include "include/test_unique_shared_lock.h"

int main()
{
    test_rvalue_reference();
    test_unique_shared_lock();
    test_variable_condition_mutex();

    std::cout << "over!" << std::endl;

    return 0;
}