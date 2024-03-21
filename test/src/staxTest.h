#ifndef STAXTEST_HPP
#define STAXTEST_HPP

#include "stax.h"

namespace stax
{
    // Type aliases for pointers
    using NodePtr = Node *;
    using DomainPtr = Domain *;

    class StaxTest
    {
    public:
        void printListTest();
        void removeNodeTest(const NodePtr node);
        Node createNodeTest(const Domain &domainObject);
        Domain loadDataTest(const std::map<std::string, std::string> &data);

    private:
        Stax *_staxObj;
    };

}

#endif // !STAXTEST_HPP
