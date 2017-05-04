// Copyright 2017 Gvozdeva Viktoria
#include <gtest/gtest.h>

#include "include/queue.h"

TEST(Queue, cant_create_queue_of_int_elements_with_negative_size) {
    // Arrange
    // Act
    // Assert
    EXPECT_ANY_THROW(Queue<int> Q(-3));
}

TEST(Queue, can_create_queue_of_int_elements_with_positive_size) {
    // Arrange
    // Act
    // Assert
    EXPECT_NO_THROW(Queue<int> Q(6));
}

TEST(Queue, can_be_equated_two_queues) {
    // Arrange
    Queue<int> Q1(10);
    Queue<int> Q2(5);
    // Act
    for (int i = 0; i < 10; i++)
        Q1.Push(10);
    for (int j = 0; j < 5; j++)
        Q2.Push(9);
    Q1 = Q2;
    // Assert
    EXPECT_EQ(Q1 == Q2, true);
}

TEST(Queue, can_be_equated_by_itself) {
    // Arrange
    Queue<int> Q1(10);
    // Act
    Q1 = Q1;
    // Assert
    EXPECT_EQ(Q1 == Q1, true);
}

TEST(Queue, cant_add_elem_into_full_queue) {
    // Arrange
    Queue<int> Q(9);
    // Act
    for (int i = 0; i < 9; i++)
        Q.Push(10);
    // Assert
    EXPECT_ANY_THROW(Q.Push(11));
}

TEST(Queue, cant_take_elem_from_empty_queue) {
    // Arrange
    Queue<int> Q(9);
    // Act
    // Assert
    EXPECT_ANY_THROW(Q.Pop());
}

TEST(Queue, can_create_copy_of_Queue) {
    // Arrange
    Queue<int> Q(5);
    // Act
    // Assert
    ASSERT_NO_THROW(Queue<int> Q1(Q));
}

TEST(Queue, can_take_element_from_queue) {
    // Arrange
    Queue<int> Q(3);
    // Act
    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    // Assert
    int expRes = 1;
    EXPECT_EQ(Q.Pop(), expRes);
}

TEST(Queue, cant_push_element_in_deleted_queue) {
    // Arrange
    Queue<int> Q(10);
    // Act
    Q.~Queue();
    // Assert
    EXPECT_ANY_THROW(Q.Push(5));
}

TEST(Queue, cant_pop_element_from_deleted_queue) {
    // Arrange
    Queue<int> Q(10);
    // Act
    Q.~Queue();
    // Assert
    EXPECT_ANY_THROW(Q.Pop());
}

TEST(Queue, can_push_element_in_queue) {
    // Arrange
    Queue<int> Q(3);
    // Act
    // Assert
    EXPECT_NO_THROW(Q.Push(10));
}

TEST(Queue, check_is_full) {
    // Arrange
    Queue<int> Q(4);
    // Act
    for (int i = 0; i < 4; i++)
        Q.Push(i);
    // Assert
    EXPECT_EQ(Q.IsFull(), true);
}

TEST(Queue, check_is_empty) {
    // Arrange
    Queue<int> Q(10);
    // Act
    // Assert
    EXPECT_EQ(Q.IsEmpty(), true);
}

TEST(Queue, check_is_empty_after_push_and_pop) {
    // Arrange
    Queue<int> Q(3);
    // Act
    Q.Push(5);
    Q.Pop();
    // Assert
    EXPECT_EQ(Q.IsEmpty(), true);
}
