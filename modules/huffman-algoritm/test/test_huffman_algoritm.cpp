// Copyright 2017 Bevzuk Semen

#include <gtest/gtest.h>

#include "include/huffman.h"

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Empty_Node) {
    EXPECT_NO_THROW(Node node);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Compare_Two_Nodes) {
    Node node_1;
    Node node_2;
    node_1.count = 2;
    node_2.count = 2;
    node_1.symbol = 'a';
    node_2.symbol = 'a';
    bool result;

    if (node_1 == node_2)
        result = true;
    else
        result = false;
   
    EXPECT_EQ(result, true);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Node) {
    Node node('a', 1);
    Node expected_node;
    expected_node.count = 1;
    expected_node.symbol = 'a';

    EXPECT_EQ(node, expected_node);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Node_whith_branchs) {
    Node node_left('l', 1);
    Node node_right('r', 1);

    Node root(&node_left, &node_right);

    EXPECT_EQ(*(root.left), node_left);
    EXPECT_EQ(*(root.right), node_right);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Sort_List_Nodes_counts) {
    std::list<Node*> tree;
    Node *node_1 = new Node('a', 1);
    Node *node_2 = new Node('b', 2);
    tree.push_back(node_2);
    tree.push_back(node_1);


    tree.sort(SortNode);
    Node *result_node_1 = tree.front();
    tree.pop_front();
    Node *result_node_2 = tree.front();
    tree.pop_front();

    ASSERT_LT(result_node_1->count, result_node_2->count);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Encode_String) {
    std::string input_string = "aaabbc";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;
    std::string result_code = "000111110";

    std::string out_code = ha.Encode(input_string, &code_table);

    EXPECT_EQ(out_code, result_code);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Decode_Code) {
    std::string input_code = "000111110";
    std::map<char, std::vector<bool> > code_table;
    std::vector<bool> vec_1;
    vec_1.push_back(0);
    std::vector<bool> vec_2;
    vec_2.push_back(1);
    vec_2.push_back(1);
    std::vector<bool> vec_3;
    vec_3.push_back(1);
    vec_3.push_back(0);
    code_table['a'] = vec_1;
    code_table['b'] = vec_2;
    code_table['c'] = vec_3;
    Huffman ha;
    std::string result_string = "aaabbc";

    std::string out_string = ha.Decode(input_code, code_table);

    EXPECT_EQ(out_string, result_string);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Encode_and_Decode) {
    std::map<char, std::vector<bool> > code_table;
    std::string input_string = "aaabbc";
    std::string result_string = input_string;
    Huffman ha;
    
    std::string out_code = ha.Encode(input_string, &code_table);
    std::string out_string = ha.Decode(out_code, code_table);

    EXPECT_EQ(out_string, result_string);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_String_Encode) {
    std::string input_string = "";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;

    EXPECT_ANY_THROW(ha.Encode(input_string, &code_table));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Null_Pointer_In_Table_Encode) {
    std::string input_string = "aaabbc";
    Huffman ha;

    EXPECT_ANY_THROW(ha.Encode(input_string, NULL));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_Code_Decode) {
    std::string input_code = "";
    std::map<char, std::vector<bool> > code_table;
    std::vector<bool> vec_1;
    vec_1.push_back(0);
    code_table['a'] = vec_1;
    Huffman ha;

    EXPECT_ANY_THROW(ha.Decode(input_code, code_table));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_Table_Decode) {
    std::string input_code = "000011";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;

    EXPECT_ANY_THROW(ha.Decode(input_code, code_table));
}