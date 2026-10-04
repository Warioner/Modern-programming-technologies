#include "taskmanager.h"
#include <iostream>
// ============================================================
//  TODO: реализуйте ВСЕ методы TaskManager по спецификации.
//
//  ----- Базовые операции (были в лабораторной №3) -----
//
//  Конструктор:
//    nextTaskId    = 1
//    nextProjectId = 1
//    Репозитории пусты по умолчанию.
//
//  AddProject(name):
//    - создать Project(nextProjectId, name);
//    - увеличить nextProjectId на 1;
//    - добавить в projectRepository.
//
//  DeleteProject(index):
//    - если index вне диапазона — выйти;
//    - взять id проекта;
//    - УДАЛИТЬ ВСЕ ЗАДАЧИ ЭТОГО ПРОЕКТА (обход С КОНЦА,
//      иначе индексы сдвинутся после Remove);
//    - удалить проект из projectRepository.
//
//  GetProjects():
//    - вернуть projectRepository.GetAll().
//
//  AddTask(title, description, priority, status, projectId):
//    - создать Task(nextTaskId, title, projectId);
//    - увеличить nextTaskId на 1;
//    - установить description, priority, status;
//    - добавить в taskRepository.
//
//  UpdateTask(index, title, description, priority, status):
//    - если index вне диапазона — выйти;
//    - взять задачу по индексу;
//    - поменять title, description, priority, status
//      (id и projectId НЕ трогать!);
//    - положить обратно через taskRepository.Update.
//
//  DeleteTask(index):
//    - taskRepository.Remove(index).
//
//  GetTasks():
//    - вернуть taskRepository.GetAll().
//
//  ----- Новые операции (лабораторная №4) -----
//
//  MoveTaskToProject(taskIndex, projectId):
//    - если taskIndex вне диапазона — вернуть false;
//    - если projectId != 0 и такого проекта нет — вернуть false;
//    - взять задачу, вызвать SetProjectId(projectId);
//    - обновить через taskRepository.Update;
//    - вернуть true.
//    id задачи НЕ меняется.
//
//  CountTasksInProject(projectId):
//    - посчитать задачи, у которых GetProjectId() == projectId.
//
//  CountTasksInProjectByStatus(projectId, status):
//    - посчитать задачи проекта с указанным статусом.
//
//  CompletionPercent(projectId):
//    - если задач в проекте нет — вернуть 0.0;
//    - иначе 100.0 * (число задач со статусом "Done") / (всего задач).
// ============================================================

TaskManager::TaskManager() {
  nextTaskId = 1;
  nextProjectId = 1;
}

void TaskManager::AddTask(std::string title, std::string description,
                          std::string priority, std::string status,
                          int projectId) {
  Task new_task(nextTaskId, title);
  new_task.SetDescription(description);
  new_task.SetPriority(priority);
  new_task.SetStatus(status);
  new_task.SetProjectId(projectId);
  taskRepository.Add(new_task);
  nextTaskId++;
}

void TaskManager::UpdateTask(int index, std::string title,
                             std::string description, std::string priority,
                             std::string status) {
  Task new_task(index, title);
  new_task.SetDescription(description);
  new_task.SetPriority(priority);
  new_task.SetStatus(status);
  taskRepository.Update(index, new_task);
}
void TaskManager::DeleteTask(int index) {
  taskRepository.Remove(index);
  nextTaskId--;
}

std::vector<Task> TaskManager::GetTasks() { return taskRepository.GetAll(); }

void TaskManager::AddProject(std::string name) {
  Project new_project;
  new_project.setName(name);
  new_project.setId(nextProjectId);
  projectRepository.Add(new_project);
  nextProjectId++;
}

int TaskManager::getNextProjectId() { return this->nextProjectId; }

bool TaskManager::MoveTaskToProject(int taskIndex, int projectId) {

  Task task = this->GetTasks()[taskIndex];
  task.SetProjectId(projectId);
  taskRepository.Update(taskIndex, task);

  return true;
}

int TaskManager::CountTasksInProject(int projectId) {
  std::vector<Task> a = this->GetTasks();
  int count = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i].GetProjectId() == projectId) {
      count++;
    }
  }
  return count;
}

int TaskManager::CountTasksInProjectByStatus(int projectId,
                                             std::string status) {
  std::vector<Task> a = this->GetTasks();
  int count = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i].GetProjectId() == projectId && a[i].GetStatus() == status) {
      count++;
    }
  }
  return count;
}

double TaskManager::CompletionPercent(int projectId) {
  std::vector<Task> a = this->GetTasks();
  int countComplete = 0;
  int countAll = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i].GetProjectId() == projectId) {
      if (a[i].GetStatus() == "Done") {
        countComplete++;
      }
      countAll++;
    }
  }
  return countComplete * 100.0 / countAll;
}

void TaskManager::DeleteProject(int index) {
  projectRepository.Remove(index);
  nextProjectId--;
}
std::vector<Project> TaskManager::GetProjects() {
  return projectRepository.GetAll();
}