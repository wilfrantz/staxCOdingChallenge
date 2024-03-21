#include "staxTest.h"

namespace stax
{

    void StaxTest::printListTest()
    {
        _staxObj->printList();
    }

    void StaxTest::removeNodeTest(const NodePtr node)
    {
        _staxObj->removeNode(node);
    }
    Node StaxTest::createNodeTest(const Domain &domainObject)
    {
        _staxObj->createNode(domainObject);
    }
    Domain StaxTest::loadDataTest(const std::map<std::string, std::string> &data)
    {
        _staxObj->loadData(data);
    }
} // !namespace stax