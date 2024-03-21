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
        void printListMock();
        void insertAtBeginningMock(NodePtr node);
        void removeNodeMock(const NodePtr node);
        Node createNodeMock(const Domain &domainObject);
        Domain loadDataMock(const std::map<std::string, std::string> &data);

    private:
        Stax *_staxObj;
    };
} // !namespace stax

#endif // !STAXTEST_HPP
