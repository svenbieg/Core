//=============
// Scheduler.h
//=============

#pragma once


//=======
// Using
//=======

#include "Settings.h"
#include "SpinLock.h"
#include "Task.h"


//===========
// Namespace
//===========

namespace Concurrency {


//===========
// Scheduler
//===========

class Scheduler
{
public:
	// Friends
	friend class Mutex;
	friend class SharedMutex;
	friend class Signal;

	// Common
	static VOID AddTask(Handle<Task> Task);
	static VOID Begin();
	static VOID ExitTask();
	static Handle<Task> GetCurrentTask();
	static VOID Initialize();

private:
	// Common
	static Task* AddParallelTask(Task* Current, Task* Parallel);
	static Handle<Task> GetWaitingTask();
	static VOID HandleTaskSwitch(VOID* Parameter);
	static VOID IdleTask();
	static VOID MainTask();
	static VOID OnSystemTimerTick();
	static Task* RemoveParallelTask(Task* Current, Task* Remove);
	static VOID ResumeTask(Task* Task);
	static Task* SuspendCurrentTask(Task* Owner, UINT MilliSeconds);
	static Task* SuspendTask(Task* Owner, Task* Suspend, UINT MilliSeconds);
	static UINT s_CurrentCore;
	static Handle<Task> s_CurrentTask[CPU_COUNT];
	static Handle<Task> s_IdleTask[CPU_COUNT];
	static CriticalSection s_CriticalSection;
	static Handle<Task> s_WaitingTask;
};

}
