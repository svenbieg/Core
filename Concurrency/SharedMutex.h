//===============
// SharedMutex.h
//===============

#pragma once


//=======
// Using
//=======

#include "Mutex.h"


//===========
// Namespace
//===========

namespace Concurrency {


//==============
// Shared-Mutex
//==============

class SharedMutex: public Mutex
{
public:
	// Con-/Destructors
	SharedMutex() {}

	// Common
	VOID LockShared();
	VOID UnlockShared();
};

}
