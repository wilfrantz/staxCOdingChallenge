#include "staxTest.h"

namespace stax
{

    void StaxTest::insertAtBeginningMock(NodePtr node)
    {
        _staxObj->insertAtBeginning(node);
    }

    void StaxTest::printListMock()
    {
        _staxObj->printList();
    }

    void StaxTest::removeNodeMock(const NodePtr node)
    {
        _staxObj->removeNode(node);
    }

    Node StaxTest::createNodeMock(const Domain &domainObject)
    {
        return _staxObj->createNode(domainObject);
    }

    Domain StaxTest::loadDataMock(const std::map<std::string, std::string> &data)
    {
        return _staxObj->loadData(data);
    }
} // !namespace stax