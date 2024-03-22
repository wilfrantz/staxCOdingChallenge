#ifndef STAXTEST_HPP
#define STAXTEST_HPP

#include "stax.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace stax
{
    using NodePtr = Node *;
    using DomainPtr = Domain *;

    class StaxTest : public ::testing::Test
    {
    public:
        void StaxTest::insertAtBeginningMock(NodePtr node)
        {
            _staxObj->insertAtBeginning(node);
        }

        void StaxTest::removeNodeMock(const NodePtr node)
        {
            _staxObj->removeNode(node);
        }

        Domain StaxTest::loadDataMock(const std::map<std::string, std::string> &data)
        {
            return _staxObj->loadData(data);
        }

    protected:
        // Test data and objects
        MockNode *test_node;
        Stax *test_stax;

        // Initialize test data and objects
        void SetUp() override
        {
            test_node = new MockNode();
            test_node->prev = nullptr;
            test_node->data.age = 25;
            test_node->data.name = "example.com";
            test_node->data.registrar = "GoDaddy";
            test_stax = new Stax();
        }

        // Clean up test data and objects
        void TearDown() override
        {
            delete test_node;
            delete test_stax;
        }
    };
} // !namespace stax

#endif // !STAXTEST_HPP
