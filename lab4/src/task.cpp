#include "task.h"

// ============================================================
//  TODO: реализуйте ВСЕ методы Task по спецификации.
//
//  Конструктор:
//    - id           = переданный id
//    - projectId    = переданный projectId (0 = без проекта)
//    - title        = переданный title
//    - description  = ""
//    - status       = "Todo"
//    - priority     = "Medium"
//
//  Геттеры (GetId, GetProjectId, GetTitle, GetDescription,
//  GetStatus, GetPriority) — возвращают значения полей.
//  Методы помечены const — не меняют объект.
//
//  Сеттеры (SetProjectId, SetTitle, SetDescription,
//  SetStatus, SetPriority) — присваивают значения.
//  SetStatus принимает только "Todo" | "In Progress" | "Done".
//  SetPriority принимает только "Low" | "Medium" | "High".
//  При недопустимом значении поле НЕ меняется.
// ============================================================

Task::Task(int id, std::string title, int projectId)
    : id(id), projectId(projectId), title(title), description(""),
      status("Todo"), priority("Medium") {}

int Task::GetId() const { return id; }

int Task::GetProjectId() const { return projectId; }

std::string Task::GetTitle() const { return title; }

std::string Task::GetDescription() const { return description; }

std::string Task::GetStatus() const { return status; }

std::string Task::GetPriority() const { return priority; }

void Task::SetProjectId(int projectId) { this->projectId = projectId; }

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