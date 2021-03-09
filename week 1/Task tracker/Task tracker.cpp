#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

// Перечислимый тип для статуса задачи

/*

enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
*/



TasksInfo operator+(TasksInfo& one, TasksInfo& two){
	TasksInfo result;
	result[TaskStatus::NEW] = one[TaskStatus::NEW] + two[TaskStatus::NEW];
	result[TaskStatus::IN_PROGRESS] = one[TaskStatus::IN_PROGRESS] + two[TaskStatus::IN_PROGRESS];
	result[TaskStatus::TESTING] = one[TaskStatus::TESTING] + two[TaskStatus::TESTING];
	result[TaskStatus::DONE] = one[TaskStatus::DONE] + two[TaskStatus::DONE];
	return result;
}


void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

/*
void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}
*/

void cleanup(TasksInfo& tsk, bool untouch){
	TasksInfo tmp;
	for (auto& it:tsk){
		if (it.second != 0) tmp[it.first] = it.second;
	}
	tsk = tmp;
	if (untouch) tsk.erase(TaskStatus::DONE);
}

//always empty
TasksInfo empt1;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика

	const TasksInfo& GetPersonTasksInfo(const string& person) const{
	  if (dev_task.count(person) == 0){
		  return empt1;
	  }
	  else{
//		  const TasksInfo ret = dev_task.at(person);
//		  TasksInfo tmp = dev_task.at(person);
//		  cleanup(tmp, 0);
		  return {dev_task.at(person)};
	  }
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
  if (person == ""){}
  else if (dev_task.count(person) == 0){
//	  dev_task[person] = ++TaskStatus::NEW;
	  dev_task[person] = {{TaskStatus::NEW, 1}};
  }
  else {
	  dev_task[person][TaskStatus::NEW]++;
  }
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count){
	  TasksInfo update, untouched = dev_task[person];

	  //delete all done's, since func should not return that
//	  dev_task.at(person).erase(TaskStatus::DONE);

	  //no such guy
	  if (dev_task.count(person) == 0){
		  cleanup(update, 0);
		  cleanup(untouched, 1);
		  return make_pair(update, untouched);
	  }
	  int everything = dev_task[person][TaskStatus::NEW] +
			  dev_task[person][TaskStatus::IN_PROGRESS] +
					  dev_task[person][TaskStatus::TESTING];
	  //too many tasks
	  if (everything < task_count){
		  task_count = everything;
//	  	  update[TaskStatus::NEW] += 555555;
//		  return make_pair(update, untouched);
	  }

	  //guy has no tasks
	  else if (everything == 0 || task_count == 0){
//	  	  update[TaskStatus::NEW] += 444444;
		  return make_pair(update, update);
	  }

	  untouched = dev_task.at(person);
	  for (auto& it:dev_task.at(person)){
		  switch(it.first){
			  case(TaskStatus::NEW): {
				  //little number of tasks to be executed
				  if (task_count < it.second){
					  update[TaskStatus::IN_PROGRESS] += task_count;
					  untouched[TaskStatus::NEW] -= task_count;
					  task_count = 0;
				  }
					  else{
				  update[TaskStatus::IN_PROGRESS] += it.second;
				  untouched[TaskStatus::NEW] = 0;
				  task_count -= it.second;
			  }
				  break;
			  }
			  case(TaskStatus::IN_PROGRESS): {
				  if (task_count == 0){}
				  else if (task_count < it.second){
						  update[TaskStatus::TESTING] += task_count;
						  untouched[TaskStatus::IN_PROGRESS] = it.second - task_count;
						  task_count = 0;
				  }
				  else {
					  update[TaskStatus::TESTING] += it.second;
					  untouched[TaskStatus::IN_PROGRESS] = 0;
					  task_count -= it.second;
				  }
				  break;
			  }
			  case(TaskStatus::TESTING): {
				  if (task_count == 0){}
				  else{
					  update[TaskStatus::DONE] += task_count;
					  //not doin anything with done for update
					  untouched[TaskStatus::TESTING] -= task_count;
					  task_count = 0;
				  }
				  break;
			  }
			  case(TaskStatus::DONE): {

				  break;
			  }
		  }
	  }

	  dev_task.at(person) = update + untouched;
	  cleanup(update, 0);
	  cleanup(untouched, 1);
	  cleanup(dev_task.at(person), 0);
	  return make_pair(update, untouched);

  }


private:
  map<string, TasksInfo> dev_task;
};



int main() {
/*
	TasksInfo v = {{TaskStatus::NEW, 1}, {TaskStatus::IN_PROGRESS, 2}, {TaskStatus::TESTING, 3},
			{TaskStatus::DONE, 4}
	};
	PrintTasksInfo(v);
*/

	  TeamTasks tasks;
	  tasks.AddNewTask("Ilia");
	  for (int i = 0; i < 3; ++i) {
	    tasks.AddNewTask("Ivan");
	  }
	  cout << "Ilia's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	  cout << "Ivan's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	  TasksInfo updated_tasks, untouched_tasks;

	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Ivan", 2);
	  cout << "Updated Ivan's tasks: ";
	  PrintTasksInfo(updated_tasks);
	  cout << "Untouched Ivan's tasks: ";
	  PrintTasksInfo(untouched_tasks);

	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Ivan", 2);
	  cout << "Updated Ivan's tasks: ";
	  PrintTasksInfo(updated_tasks);
	  cout << "Untouched Ivan's tasks: ";
	  PrintTasksInfo(untouched_tasks);

  return 0;
}



