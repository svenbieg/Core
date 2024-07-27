//==============
// SharedLock.h
//==============

#pragma once


//=======
// Using
//=======

#include "SharedMutex.h"


//===========
// Namespace
//===========

namespace Concurrency {


//=============
// Shared-Lock
//=============

class SharedLock
{
public:
	// Con-/Destructors
	inline SharedLock(SharedMutex& Mutex): m_Mutex(&Mutex) {}
	inline ~SharedLock()
		{
		if(m_Mutex)
			m_Mutex->UnlockShared();
		}

	// Common
	inline VOID Lock() { m_Mutex->LockShared(); }
	inline VOID Release() { m_Mutex=nullptr; }
	inline VOID Unlock() { m_Mutex->UnlockShared(); }

private:
	// Common
	SharedMutex* m_Mutex;
};

}
