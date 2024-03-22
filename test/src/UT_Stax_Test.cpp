
#include "staxTest.h"

using ::testing::AtLeast;
using namespace stax;

// Test inserting a node in an empty list.
TEST_F(StaxInsertAtBeginningTest, InsertAtBeginning_EmptyList)
{
    test_stax->insertAtBeginning(test_node);

    // Assert that the head points to the inserted node
    ASSERT_EQ(test_stax->head, test_node);
    ASSERT_EQ(test_node->prev, nullptr);
    ASSERT_EQ(test_node->next, nullptr);
}

// Test inserting a node in a non-empty list.
TEST(StaxInstertAtBeginningTest, InsertAtBeginning_nonEmptyList)
{
    MockNode *existing_node = new MockNode();
    test_stax->insertAtBeginning(existing_node);

    test_stax->insertAtBeginning(test_node);

    ASSERT_EQ(test_stax->head, test_node);

    ASSERT_EQ(existing_node->prev, test_node);
    ASSERT_EQ(test_node->next, existing_node);
    ASSERT_EQ(test_node->prev, nullptr);

    // Clean up
    delete existing_node;
}

// Test removing a node in the middle of the list
TEST_F(StaxRemoveNodeTest, RemoveNode_Middle)
{
    // Remove node2
    stax->removeNode(node2);

    ASSERT_EQ(node1->next, node3);
    ASSERT_EQ(node3->prev, node1);

    ASSERT_EQ(node2, nullptr);
}

// Test removing the head node
TEST_F(StaxRemoveNodeTest, RemoveNode_Head)
{
    stax->removeNode(node1);

    ASSERT_EQ(stax->head, node2);
    ASSERT_EQ(node2->prev, nullptr);

    ASSERT_EQ(node1, nullptr);
}

// Test removing the last node in the list
TEST_F(StaxRemoveNodeTest, RemoveNode_Last)
{
    stax->removeNode(node3);

    ASSERT_EQ(node1->next, node2);
    ASSERT_EQ(node2->prev, node1);

    ASSERT_EQ(node3, nullptr);
}

// Test loading data from an empty map
TEST_F(StaxLoadDataMockTest, LoadData_EmptyMap)
{
    std::map<std::string, std::string> empty_map;
    Domain result = stax_test->loadDataMock(empty_map);

    // Check if the returned Domain object has default values
    ASSERT_EQ(result.age, 0);
    ASSERT_EQ(result.name, "");
    ASSERT_EQ(result.registrar, "");
}

// Test loading data from a non-empty map
TEST_F(StaxLoadDataMockTest, LoadData_NonEmptyMap)
{
    std::map<std::string, std::string> data_map = {
        {"age", "25"},
        {"name", "example.com"},
        {"registrar", "GoDaddy"}};
    Domain result = stax_test->loadDataMock(data_map);

    // Check if the returned Domain object has correct values
    ASSERT_EQ(result.age, 25);
    ASSERT_EQ(result.name, "example.com");
    ASSERT_EQ(result.registrar, "GoDaddy");
}