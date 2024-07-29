#pragma once

#include <optional>
#include <string>
#include <iostream>

struct Property
{
    std::optional<int> value;
    std::optional<std::string> name{"xiaoming"};
    std::string tag;
};

Property getProperty()
{
    Property p;
    return p;
}

// Summary:
// 1. The return value of getProperty() is a temporary object, which is not a lvalue.
// 2. The compiler may optimize the code, so it is hard to reproduce the issue.
void test_rvalue_reference()
{
    // this operation has a potential problem, because the return value of getProperty() is a temporary object, 
    // but this isssue is hard to reproduce, because the compiler may optimize it.
    const Property &p = getProperty();
    try
    {
        std::cout << p.name.value_or("") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}