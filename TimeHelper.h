//==============
// TimeHelper.h
//==============

#pragma once


//=======
// Using
//=======

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
// TODO
using SystemTimer=Devices::Timers::SystemTimer;
UINT64 end=SystemTimer::Milliseconds64()+Milliseconds;
while(SystemTimer::Milliseconds64()<=end);
}

inline VOID SleepMicroseconds(UINT Microseconds)
{
using SystemTimer=Devices::Timers::SystemTimer;
UINT64 end=SystemTimer::Microseconds64()+Microseconds;
while(SystemTimer::Microseconds64()<=end);
}
