//===========
// Mutex.cpp
//===========

#include "pch.h"


//=======
// Using
//=======

#include "Devices/System/Cpu.h"
#include "Devices/System/Interrupts.h"
#include "Mutex.h"
#include "Scheduler.h"
#include "Task.h"

using namespace Devices::System;


//===========
// Namespace
//===========

namespace Concurrency {


//========
// Common
//========

VOID Mutex::Lock()
{
SpinLock lock(Scheduler::s_CriticalSection);
UINT core=Cpu::GetId();
auto task=Scheduler::s_CurrentTask[core];
if(!m_Owner)
	{
	m_Owner=task;
	return;
	}
Scheduler::SuspendCurrentTask(m_Owner, 0);
m_Owner->m_Waiting=nullptr;
m_Owner=task;
}

VOID Mutex::Lock(BOOL exclusive)
{
if(!exclusive)
	return Lock();
SpinLock lock(Scheduler::s_CriticalSection);
UINT core=Cpu::GetId();
auto task=Scheduler::s_CurrentTask[core];
if(!task)
	return;
task->SetFlag(TaskFlags::Exclusive);
if(!m_Owner)
	{
	m_Owner=task;
	Interrupts::Disable();
	return;
	}
Scheduler::SuspendCurrentTask(m_Owner, 0);
m_Owner->m_Waiting=nullptr;
m_Owner=task;
}

BOOL Mutex::TryLock()
{
SpinLock lock(Scheduler::s_CriticalSection);
if(m_Owner)
	return false;
UINT core=Cpu::GetId();
m_Owner=Scheduler::s_CurrentTask[core];
return true;
}

BOOL Mutex::TryLock(BOOL exclusive)
{
if(!exclusive)
	return TryLock();
SpinLock lock(Scheduler::s_CriticalSection);
if(m_Owner)
	return false;
UINT core=Cpu::GetId();
m_Owner=Scheduler::s_CurrentTask[core];
if(m_Owner)
	{
	m_Owner->SetFlag(TaskFlags::Exclusive);
	Interrupts::Disable();
	}
return true;
}

VOID Mutex::Unlock()
{
SpinLock lock(Scheduler::s_CriticalSection);
if(!m_Owner)
	return;
if(m_Owner->GetFlag(TaskFlags::Exclusive))
	{
	Interrupts::Enable();
	m_Owner->ClearFlag(TaskFlags::Exclusive);
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
