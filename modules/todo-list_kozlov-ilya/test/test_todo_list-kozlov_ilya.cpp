    // Copyright 2017 Kozlov Ilya

#include <gtest/gtest.h>

#include <string>
#include <algorithm>

#include "include/todo_list_kozlov_ilya.h"

TEST(Kozlov_Ilya_TODOListTest, TODOListDefaultCanBeCreated) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(TODOList ListToTest);
}

TEST(Kozlov_Ilya_TODOListTest, TODOListCanBeCreated) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(TODOList ListToTest("ListToTest"));
}

TEST(Kozlov_Ilya_TODOListTest, NewTaskCanBeCreated) {
    // Arrange
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.NewTask());
}

TEST(Kozlov_Ilya_TODOListTest, NewTaskCanBeCreatedWithStringArg) {
    // Arrange
    TODOList ListToTest;
    const std::string testname = "To test the constructor";
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.NewTask(testname););
}

TEST(Kozlov_Ilya_TODOListTest, TaskCanBeDeletedInTODOList) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.DeleteTask(1));
}

TEST(Kozlov_Ilya_TODOListTest, TODOListCanBeCleared) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ClearList());
}

TEST(Kozlov_Ilya_TODOListTest, TaskCanBeRenamedInTODOList) {
    // Arrange
    const std::string testname = "To test the renaming";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.RenameTask(1, testname););
}

TEST(Kozlov_Ilya_TODOListTest, TODOListCanBeShown) {
    // Arrange
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ShowTODOList());
}

TEST(Kozlov_Ilya_TODOListTest, TODOListCanBeUnlimitedAndUnlimited) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.LimitTasksCount(1);
    ListToTest.UnlimitTasksCount();
    // Assert
    ASSERT_NO_FATAL_FAILURE ({
        ListToTest.LimitTasksCount(1);
        ListToTest.UnlimitTasksCount();
    });
}

TEST(Kozlov_Ilya_TODOListTest, TODOListCanBeSetDoneAndUndone) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE ({
        ListToTest.SetTaskDone(1);
        ListToTest.SetTaskUndone(1);
    });
}

TEST(Kozlov_Ilya_TODOListTest, TasksPosCanBeChangedInTODOList) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ChangeTasksPosition(1, 2));
}

TEST(Kozlov_Ilya_TODOListTest, ParamsCanBeGot) {
    // Arrange
    TODOList ListToTest;
    ListToTest.NewTask();
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE ({
        ListToTest.GetCurrentTasksValue();
        ListToTest.GetMaxTaskValue();
        ListToTest.GetTaskStatus(1);
        ListToTest.GetTaskName(1);
        ListToTest.GetTODOListName();
    });
}

TEST(Kozlov_Ilya_TODOListTest, TODOListParamConstrIsWorkingCorrectly) {
    // Arrange
    const std::string todolistname = "To test the working of constructor";
    // Act
    TODOList ListToTest(todolistname);
    // Assert
    ASSERT_EQ(todolistname, ListToTest.GetTODOListName());
}

TEST(Kozlov_Ilya_TODOListTest, ParamNewTaskIsWorkingCorrectly) {
    // Arrange
    const std::string tasktestname = "To test the New() method";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask(tasktestname);
    // Assert
    ASSERT_EQ(tasktestname, ListToTest.GetTaskName(1));
}

TEST(Kozlov_Ilya_TODOListTest, DeleteIsWorkingCorrectly) {
    // Arrange
    const std::string taskname1 = "Task1";
    const std::string taskname2 = "Task2";
    TODOList ListToTest;
    ListToTest.NewTask(taskname1);
    ListToTest.NewTask(taskname2);
    // Act
    ListToTest.DeleteTask(1);
    // Assert
    ASSERT_EQ(taskname2, ListToTest.GetTaskName(1));
}

TEST(Kozlov_Ilya_TODOListTest, ClearListIsWorkingCorrectly) {
    // Arrange
    const int expectedlen = 0;
    const int testlen = 42;
    TODOList ListToTest;
    // Act
    for (int i = 0; i < testlen; i++) {
        ListToTest.NewTask();
    }
    ListToTest.ClearList();
    // Assert
    ASSERT_EQ(expectedlen, ListToTest.GetCurrentTasksValue());
}

TEST(Kozlov_Ilya_TODOListTest, TaskRenamingIsWorkingCorrectly) {
    // Arrange
    const std::string expectedname = "To test renaming's work";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    ListToTest.RenameTask(1, expectedname);
    // Assert
    ASSERT_EQ(expectedname, ListToTest.GetTaskName(1));
}

TEST(Kozlov_Ilya_TODOListTest, LimitingTaskCountIsWorkingCorrectly) {
    // Arrange
    const int expectedlen = 42;
    TODOList ListToTest;
    // Act
    ListToTest.LimitTasksCount(expectedlen);
    for (int i = 0; i < expectedlen * expectedlen; i++) {
        ListToTest.NewTask();
    }
    // Assert
    ASSERT_EQ(expectedlen, ListToTest.GetMaxTaskValue());
}


TEST(Kozlov_Ilya_TODOListTest, LimitingTaskCountToSmaller) {
    // Arrange
    const int oldlen = 10;
    TODOList ListToTest;
    // Act
    for (int i = 0; i < 10; i++) {
        ListToTest.NewTask();
    }
    ListToTest.LimitTasksCount(oldlen / 2);
    const int newlen = ListToTest.GetCurrentTasksValue();
    // Assert
    ASSERT_EQ(oldlen/2, newlen);
}

TEST(Kozlov_Ilya_TODOListTest, UnlimitingTaskCountIsWorkingCorrectly) {
    // Arrange
    const int limitedlen = 10;
    TODOList ListToTest;
    const std::size_t expectedlen = ListToTest.GetMaxTaskValue();
    // Act
    for (int i = 0; i < 10; i++) {
        ListToTest.NewTask();
    }
    ListToTest.LimitTasksCount(limitedlen / 2);
    ListToTest.UnlimitTasksCount();
    std::size_t newlen = ListToTest.GetMaxTaskValue();
    // Assert
    ASSERT_EQ(expectedlen, newlen);
}

TEST(Kozlov_Ilya_TODOListTest, ForbiddenParamsForMethods) {
    // Arrange
    const std::string tasknameparam = "To test the class";
    const int toolarge = 42;
    const int toolow = -42;
    TODOList ListToTest;
    ListToTest.NewTask();
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE({
        // deleting
        ListToTest.DeleteTask(toolarge);
        ListToTest.DeleteTask(toolow);
        // renaming
        ListToTest.RenameTask(toolarge, tasknameparam);
        ListToTest.RenameTask(toolow, tasknameparam);
        // limiting
        ListToTest.LimitTasksCount(toolarge);
        ListToTest.LimitTasksCount(toolow);
        // setting done
        ListToTest.SetTaskDone(toolarge);
        ListToTest.SetTaskDone(toolow);
        // setting undone
        ListToTest.SetTaskUndone(toolarge);
        ListToTest.SetTaskUndone(toolow);
        // changing position
        ListToTest.ChangeTasksPosition(toolarge, toolow);
        ListToTest.ChangeTasksPosition(toolow, toolarge);
        ListToTest.ChangeTasksPosition(toolarge, toolarge);
        ListToTest.ChangeTasksPosition(toolow, toolow);
    });
}

TEST(Kozlov_Ilya_TODOListTest, ChangeTaskPosIsWorkingCorrectly) {
    // Arrange
    const std::string taskpos1 = "TaskPos1";
    const std::string taskpos2 = "TaskPos2";
    TODOList ListToTest;
    ListToTest.NewTask(taskpos1);
    ListToTest.NewTask(taskpos2);
    // Act
    ListToTest.ChangeTasksPosition(1, 2);
    // Assert
    ASSERT_EQ(taskpos2, ListToTest.GetTaskName(1));
}

TEST(Kozlov_Ilya_TODOListTest, ThrowForWrongParamsForGetName) {
    // Arrange
    const int wrong = 42;
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_ANY_THROW(ListToTest.GetTaskName(wrong));
}

TEST(Kozlov_Ilya_TODOListTest, ThrowForWrongParamsForGetStatus) {
    // Arrange
    const int wrong = 42;
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_ANY_THROW(ListToTest.GetTaskStatus(wrong));
}
