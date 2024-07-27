//=================
// SharedMutex.cpp
//=================

#include "pch.h"


//=======
// Using
//=======

#include "Devices/System/Cpu.h"
#include "Scheduler.h"
#include "SharedMutex.h"

using namespace Devices::System;


//===========
// Namespace
//===========

namespace Concurrency {


//========
// Common
//========

void SharedMutex::LockShared()
{
SpinLock lock(Scheduler::s_CriticalSection);
UINT core=Cpu::GetId();
auto task=Scheduler::s_CurrentTask[core];
if(!task)
	return;
task->SetFlag(TaskFlags::Sharing);
if(!m_Owner)
	{
	m_Owner=task;
	return;
	}
if(m_Owner->GetFlag(TaskFlags::Sharing))
	{
	Scheduler::AddParallelTask(m_Owner, task);
	return;
	}
Scheduler::SuspendCurrentTask(m_Owner, 0);
lock.Yield();
m_Owner->m_Waiting=nullptr;
m_Owner=task;
}

void SharedMutex::UnlockShared()
{
SpinLock lock(Scheduler::s_CriticalSection);
UINT core=Cpu::GetId();
auto current=Scheduler::s_CurrentTask[core];
if(!current)
	return;
current->ClearFlag(TaskFlags::Sharing);
auto parallel=Scheduler::RemoveParallelTask(m_Owner, current);
if(parallel)
	{
	m_Owner=parallel;
	return;
	}
auto waiting=m_Owner->m_Waiting;
if(!waiting)
	{
	m_Owner=nullptr;
	return;
	}
Scheduler::ResumeTask(waiting);
}

}
