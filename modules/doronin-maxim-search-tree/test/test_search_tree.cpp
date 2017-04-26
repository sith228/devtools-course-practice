// Copyright 2017 Doronin Maxim

#include <gtest/gtest.h>

#include "include/SearchTree.h"

class Doronin_Maxim_SearchTree_Test : public ::testing::Test {
 protected:
    SearchTree *tree;

    void SetUp() {
        tree = new SearchTree();

        tree->insert(11.0);

        tree->insert(7.0);
        tree->insert(3.0);
        tree->insert(10.0);
        tree->insert(2.0);
        tree->insert(5.0);
        tree->insert(8.0);
        tree->insert(1.0);
        tree->insert(4.0);
        tree->insert(6.0);
        tree->insert(9.0);

        tree->insert(15.0);
        tree->insert(13.0);
        tree->insert(16.0);
        tree->insert(12.0);
        tree->insert(14.0);
        tree->insert(17.0);
    }
};

TEST_F(Doronin_Maxim_SearchTree_Test, can_create_tree) {
    SearchTree *stree;

    ASSERT_NO_THROW(stree = new SearchTree());
}

TEST_F(Doronin_Maxim_SearchTree_Test, can_insert_element_in_empty_tree) {
    SearchTree *stree = new SearchTree();
    double key = 111.111;

    ASSERT_NO_THROW(stree->insert(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test, can_insert_element_in_not_emplty_tree) {
    // SetUP() in Doronin_Maxim_SearchTree_Test
    double key = 111.111;

    ASSERT_NO_THROW(tree->insert(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test, throws_when_try_insert_not_unique_elem) {
    // SetUP() in Doronin_Maxim_SearchTree_Test
    double key = 7.0;

    ASSERT_ANY_THROW(tree->insert(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test, inserted_element_is_correct_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test
    double key = 7.5;
    double expectedParentKey = 8.0;

    tree->insert(key);
    const Node* node = tree->search(key);
    const Node* expectedParent = tree->search(expectedParentKey);

    EXPECT_EQ(node, expectedParent->left);
}

TEST_F(Doronin_Maxim_SearchTree_Test, inserted_element_has_correct_parent) {
    // SetUP() in Doronin_Maxim_SearchTree_Test
    double key = 7.5;
    double expectedParentKey = 8.0;

    tree->insert(key);
    const Node* node = tree->search(key);
    const Node* expectedParent = tree->search(expectedParentKey);

    EXPECT_EQ(node->parent, expectedParent);
}


TEST_F(Doronin_Maxim_SearchTree_Test, can_search_inserted_element) {
    SearchTree *stree = new SearchTree();
    double key = 111.111;

    stree->insert(key);
    const Node* node = stree->search(key);

    EXPECT_EQ(node->key, key);
}
