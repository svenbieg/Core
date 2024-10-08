//==============
// TimeHelper.h
//==============

#pragma once


//=======
// Using
//=======

#include "Concurrency/Scheduler.h"
#include "Devices/Timers/SystemTimer.h"


//========
// Common
//========

inline UINT GetTickCount()
{
return Devices::Timers::SystemTimer::Milliseconds();
}

inline UINT64 GetTickCount64()
{
return Devices::Timers::SystemTimer::Milliseconds64();
}

inline VOID Sleep(UINT Milliseconds)
{
using Scheduler=Concurrency::Scheduler;
Scheduler::SuspendCurrentTask(Milliseconds);
}

inline VOID SleepMicroseconds(UINT Microseconds)
{
using SystemTimer=Devices::Timers::SystemTimer;
UINT64 end=SystemTimer::Microseconds64()+Microseconds;
while(SystemTimer::Microseconds64()<=end);
}
