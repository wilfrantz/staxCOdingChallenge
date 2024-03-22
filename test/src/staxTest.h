#ifndef STAXTEST_HPP
#define STAXTEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../src/stax.h"

namespace stax
{
    using NodePtr = Node *;
    using DomainPtr = Domain *;

    class StaxTest : public ::testing::Test
    {
    public:
        void insertAtBeginningMock(NodePtr node)
        {
            _staxObj->insertAtBeginning(node);
        }

        void removeNodeMock(const NodePtr node)
        {
            _staxObj->removeNode(node);
        }

        Domain loadDataMock(const std::map<std::string, std::string> &data)
        {
            return _staxObj->loadData(data);
        }

    protected:
        NodePtr test_node;
        Stax *_staxObj;

        // Initialize test data and objects
        void SetUp() override
        {
            test_node = new Node();
            test_node->prev = nullptr;
            test_node->data.age = 25;
            test_node->data.name = "example.com";
            test_node->data.registrar = "GoDaddy";
            _staxObj = new Stax();
        }

        // Clean up test data and objects
        void TearDown() override
        {
            delete test_node;
            delete _staxObj;
        }
    };
} // !namespace stax

#endif // !STAXTEST_HPP
