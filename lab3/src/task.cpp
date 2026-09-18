#ifndef TASK_CPP
#define TASK_CPP

#include "task.h"

Task::Task(int id, std::string title)
    : id(id), title(title), description(""), status("Todo"),
      priority("Medium") {}

int Task::GetId() { return id; }
std::string Task::GetTitle() { return title; }
std::string Task::GetDescription() { return description; }
std::string Task::GetStatus() { return status; }
std::string Task::GetPriority() { return priority; }

void Task::SetTitle(std::string title) { this->title = title; }

void Task::SetDescription(std::string description) {
  this->description = description;
}

void Task::SetStatus(std::string status) {
  if (status == "Todo" || status == "In Progress" || status == "Done") {
    this->status = status;
  }
}

void Task::SetPriority(std::string priority) {
  if (status == "Low" || status == "Medium" || status == "High") {
    this->priority = priority;
  }
}

#endif