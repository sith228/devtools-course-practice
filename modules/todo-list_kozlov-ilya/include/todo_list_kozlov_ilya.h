// Copyright 2017 Kozlov Ilya

#ifndef MODULES_TODO_LIST_KOZLOV_ILYA_INCLUDE_TODO_LIST_KOZLOV_ILYA_H_
#define MODULES_TODO_LIST_KOZLOV_ILYA_INCLUDE_TODO_LIST_KOZLOV_ILYA_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

enum TaskStatus { UNDONE_TASK, DONE_TASK };

class TODOList {
 private:
    class TODOTask {
     private:
        std::string task_name = "New Task";
        TaskStatus task_status = DONE_TASK;

     public:
        TODOTask();
        explicit TODOTask(const std::string _users_task_name);

        void Rename(const std::string _new_task_name);
        void SetDone();
        void SetUndone();
        std::string GetTaskName();
        TaskStatus GetTaskStatus();
    };
    std::size_t max_tasks_value = data_list.max_size();
    std::vector<TODOTask> data_list;
    std::string todo_list_name = "";

 public:
    TODOList();
    explicit TODOList(const std::string _users_todo_list_name);

    void NewTask();
    void NewTask(const std::string _new_task_name);
    void DeleteTask(const std::size_t _task_index);
    void ClearList();
    void RenameTask(const std::size_t _task_index,
                    const std::string _new_task_name);
    void ShowTODOList();
    void LimitTasksCount(const std::size_t _new_limit);
    void UnlimitTasksCount();
    void SetTaskDone(const std::size_t _task_index);
    void SetTaskUndone(const std::size_t _task_index);
    void ChangeTasksPosition(const std::size_t _current_postiton,
                             const std::size_t _new_position);
    const std::size_t GetMaxTaskValue();
    const std::size_t GetCurrentTasksValue();
    std::string GetTaskName(const std::size_t _task_index);
    TaskStatus GetTaskStatus(const std::size_t _task_index);
    std::string GetTODOListName();
};
#endif  // MODULES_TODO_LIST_KOZLOV_ILYA_INCLUDE_TODO_LIST_KOZLOV_ILYA_H_
