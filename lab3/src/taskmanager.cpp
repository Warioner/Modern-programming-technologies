#ifndef TASKMANAGER_CPP
#define TASKMANAGER_CPP

#include "taskmanager.h"

TaskManager::TaskManager() {
  nextTaskId = 1;
  nextProjectId = 1;
}

void TaskManager::AddTask(std::string title, std::string description,
                          std::string priority, std::string status) {
  Task new_task(nextTaskId, title);
  new_task.SetDescription(description);
  new_task.SetPriority(priority);
  new_task.SetStatus(status);
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
void TaskManager::DeleteProject(int index) {
  projectRepository.Remove(index);
  nextProjectId--;
}
std::vector<Project> TaskManager::GetProjects() {
  return projectRepository.GetAll();
}
#endif