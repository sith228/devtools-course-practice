// Copyright 2017 Doronin Maxim

#include <gtest/gtest.h>

#include "include/SearchTree.h"

class Doronin_Maxim_SearchTree_Test_F : public ::testing::Test {
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

    void TearDown() {
        delete tree;
    }
};

TEST(Doronin_Maxim_SearchTree_Test, can_create_tree) {
    ASSERT_NO_THROW(new SearchTree());
}

TEST(Doronin_Maxim_SearchTree_Test, can_delete_empty_tree) {
    SearchTree *tree = new SearchTree();

    ASSERT_NO_THROW(delete tree);
}

TEST(Doronin_Maxim_SearchTree_Test, can_delete_not_empty_tree) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;

    tree->insert(key);

    ASSERT_NO_THROW(delete tree);
}

TEST(Doronin_Maxim_SearchTree_Test, can_insert_element_in_empty_tree) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;

    ASSERT_NO_THROW(tree->insert(key));
    delete tree;
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, can_insert_element_in_not_empty_tree) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 111.111;

    ASSERT_NO_THROW(tree->insert(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, throws_when_try_insert_nounique_elem) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 7.0;

    ASSERT_ANY_THROW(tree->insert(key));
}

TEST(Doronin_Maxim_SearchTree_Test, can_search_element) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;

    tree->insert(key);
    ASSERT_NO_THROW(tree->search(key));
    delete tree;
}

TEST(Doronin_Maxim_SearchTree_Test, can_search_inserted_element) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;

    tree->insert(key);
    const Node* node = tree->search(key);

    EXPECT_EQ(node->key, key);
    delete tree;
}

TEST(Doronin_Maxim_SearchTree_Test, throws_when_try_search_in_empty_tree) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;

    ASSERT_ANY_THROW(tree->search(key));
    delete tree;
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, search_returns_0_when_element_missed) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 111.111;

    const Node* node = tree->search(key);

    EXPECT_EQ(node, (Node*)0);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, inserted_element_is_correct_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 7.5;
    double expectedParentKey = 8.0;

    tree->insert(key);
    const Node* node = tree->search(key);
    const Node* expectedParent = tree->search(expectedParentKey);

    EXPECT_EQ(node, expectedParent->left);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, inserted_element_has_correct_parent) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 7.5;
    double expectedParentKey = 8.0;

    tree->insert(key);
    const Node* node = tree->search(key);
    const Node* expectedParent = tree->search(expectedParentKey);

    EXPECT_EQ(node->parent, expectedParent);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, can_findMin) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    ASSERT_NO_THROW(tree->findMin());
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, can_findMax) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    ASSERT_NO_THROW(tree->findMax());
}

TEST(Doronin_Maxim_SearchTree_Test, throw_when_try_findMin_in_empty_tree) {
    SearchTree *tree = new SearchTree();

    ASSERT_ANY_THROW(tree->findMin());
    delete tree;
}

TEST(Doronin_Maxim_SearchTree_Test, throw_when_try_findMax_in_empty_tree) {
    SearchTree *tree = new SearchTree();

    ASSERT_ANY_THROW(tree->findMin());
    delete tree;
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, throw_when_try_findMin_in_0_subtree) {
    ASSERT_ANY_THROW(tree->findMin(0));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, throw_when_try_findMax_in_0_subtree) {
    ASSERT_ANY_THROW(tree->findMax(0));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMin_in_whole_tree_correct) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double minKey = 1.0;

    EXPECT_EQ(tree->findMin()->key, minKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMax_in_whole_tree_correct) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double maxKey = 17.0;

    EXPECT_EQ(tree->findMax()->key, maxKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMin_in_subtree_correct) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double minKeyInSubTree = 12.0;
    double subRootKey = 15.0;

    const Node* subRoot = tree->search(subRootKey);

    EXPECT_EQ(tree->findMin(subRoot)->key, minKeyInSubTree);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMax_in_subtree_correct) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double maxKeyInSubTree = 10.0;
    double subRootKey = 7.0;

    const Node* subRoot = tree->search(subRootKey);

    EXPECT_EQ(tree->findMax(subRoot)->key, maxKeyInSubTree);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMin_works_correct_when_no_left) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double minKeyInSubTree = 8.0;
    double subRootKey = 8.0;

    const Node* subRoot = tree->search(subRootKey);

    EXPECT_EQ(tree->findMin(subRoot)->key, minKeyInSubTree);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findMax_works_correct_when_no_right) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double maxKeyInSubTree = 2.0;
    double subRootKey = 2.0;

    const Node* subRoot = tree->search(subRootKey);

    EXPECT_EQ(tree->findMax(subRoot)->key, maxKeyInSubTree);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findPrev_throws_when_key_is_missed) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 111.111;

    ASSERT_ANY_THROW(tree->findPrev(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findNext_throws_when_key_is_missed) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 111.111;

    ASSERT_ANY_THROW(tree->findNext(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findPrev_works_correctly_when_left) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 7.0;
    double expectPrevKey = 6.0;

    EXPECT_EQ(tree->findPrev(key)->key, expectPrevKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findNext_works_correctly_when_right) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 7.0;
    double expectNextKey = 8.0;

    EXPECT_EQ(tree->findNext(key)->key, expectNextKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findPrev_works_correctly_when_noleft) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 8.0;
    double expectPrevKey = 7.0;

    EXPECT_EQ(tree->findPrev(key)->key, expectPrevKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findNext_works_correctly_when_noright) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 10.0;
    double expectNextKey = 11.0;

    EXPECT_EQ(tree->findNext(key)->key, expectNextKey);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findPrev_return_0_when_no_prev) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 1.0;

    EXPECT_EQ((Node*)0, tree->findPrev(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, findNext_return_0_when_no_next) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 17.0;

    EXPECT_EQ((Node*)0, tree->findNext(key));
}

TEST(Doronin_Maxim_SearchTree_Test, findPrev_throws_when_tree_is_empty) {
    SearchTree *tree = new SearchTree();
    double key = 0.0;

    ASSERT_ANY_THROW(tree->findPrev(key));
    delete tree;
}

TEST(Doronin_Maxim_SearchTree_Test, findNext_throws_when_tree_is_empty) {
    SearchTree *tree = new SearchTree();
    double key = 0.0;

    ASSERT_ANY_THROW(tree->findNext(key));
    delete tree;
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_throws_when_try_erase_not_actual_elem) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 111.111;

    ASSERT_ANY_THROW(tree->erase(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, can_erase_actual_element) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double key = 15.0;

    ASSERT_NO_THROW(tree->erase(key));
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, erase_left_leaf_correct_for_parent) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 4.0;
    double parentKey = 5.0;
    const Node* parent = tree->search(parentKey);

    tree->erase(eraseKey);

    EXPECT_EQ((Node*)0, parent->left);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, no_left_leaf_after_erasing) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 4.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, erase_right_leaf_correct_for_parent) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 6.0;
    double parentKey = 5.0;
    const Node* parent = tree->search(parentKey);

    tree->erase(eraseKey);

    EXPECT_EQ((Node*)0, parent->right);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, no_right_leaf_after_erasing) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 6.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}


TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_parent_when_only_right_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 8.0;
    double parentKey = 10.0;
    double rightChildKey = 9.0;
    const Node* parent = tree->search(parentKey);
    const Node* rightChild = tree->search(rightChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(rightChild, parent->left);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_child_when_only_right_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 8.0;
    double parentKey = 10.0;
    double rightChildKey = 9.0;
    const Node* parent = tree->search(parentKey);
    const Node* rightChild = tree->search(rightChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(rightChild->parent, parent);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    no_element_after_erasing_when_only_right_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 8.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_parent_when_only_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 10.0;
    double parentKey = 7.0;
    double leftChildKey = 8.0;
    const Node* parent = tree->search(parentKey);
    const Node* leftChild = tree->search(leftChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(leftChild, parent->right);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_child_when_only_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 10.0;
    double parentKey = 7.0;
    double leftChildKey = 8.0;
    const Node* parent = tree->search(parentKey);
    const Node* leftChild = tree->search(leftChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(leftChild->parent, parent);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    no_element_after_erasing_when_only_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 10.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_parent_when_only_left_child_and_its_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 2.0;
    double parentKey = 3.0;
    double leftChildKey = 1.0;
    const Node* parent = tree->search(parentKey);
    const Node* leftChild = tree->search(leftChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(leftChild, parent->left);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_child_when_only_left_child_and_its_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 2.0;
    double parentKey = 3.0;
    double leftChildKey = 1.0;
    const Node* parent = tree->search(parentKey);
    const Node* leftChild = tree->search(leftChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(leftChild->parent, parent);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    no_element_after_erasing_when_only_left_child_and_its_left_child) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 2.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_children_when_both_children) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 7.0;
    double nextKey = 8.0;
    double leftChildKey = 3.0;
    double rightChildKey = 10.0;
    double parentKey = 11.0;
    const Node* parent = tree->search(parentKey);
    const Node* leftChild = tree->search(leftChildKey);
    const Node* rightChild = tree->search(rightChildKey);

    tree->erase(eraseKey);
    const Node* node = tree->search(nextKey);

    EXPECT_EQ(node->parent, parent);
    EXPECT_EQ(node->left, leftChild);
    EXPECT_EQ(node->right, rightChild);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    erase_correct_for_next_when_both_children) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 7.0;
    double nextParentKey = 10.0;
    double nextLeftChildKey = 9.0;
    const Node* nextParent = tree->search(nextParentKey);
    const Node* nextLeftChild = tree->search(nextLeftChildKey);

    tree->erase(eraseKey);

    EXPECT_EQ(nextLeftChild->parent, nextParent);
    EXPECT_EQ(nextParent->left, nextLeftChild);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F,
    no_element_after_erasing_when_both_children) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F
    double eraseKey = 7.0;

    tree->erase(eraseKey);
    const Node* node = tree->search(eraseKey);

    EXPECT_EQ((Node*)0, node);
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, isEmpty_returns_false_when_not_empty) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    EXPECT_FALSE(tree->isEmpty());
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, isEmpty_returns_true_when_empty) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    tree->clear();

    EXPECT_TRUE(tree->isEmpty());
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, size_returns_not_0_when_not_empty) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    EXPECT_NE(0, tree->size());
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, size_returns_0_when_empty) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    tree->clear();

    EXPECT_EQ(0, tree->size());
}

TEST_F(Doronin_Maxim_SearchTree_Test_F, size_returns_actual_size) {
    // SetUP() in Doronin_Maxim_SearchTree_Test_F

    EXPECT_EQ(17, tree->size());
}
