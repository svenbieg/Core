//=========
// Mutex.h
//=========

#pragma once


//===========
// Namespace
//===========

namespace Concurrency {


//======================
// Forward-Declarations
//======================

class Task;


//=======
// Mutex
//=======

class Mutex
{
public:
	// Con-/Destructors
	inline Mutex(): m_Owner(nullptr) {}

	// Common
	VOID Lock();
	VOID Lock(BOOL Exclusive);
	BOOL TryLock();
	BOOL TryLock(BOOL Exclusive);
	VOID Unlock();

protected:
	// Common
	Task* m_Owner;
};

}
