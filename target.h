#ifndef TARGET_H
#define TARGET_H
#include <string>

struct Target
{
    std::string type;
    std::string name;
    std::string src;
    std::string libs;
    std::string include;
    std::string pkg;
};

#endif // TARGET_H
