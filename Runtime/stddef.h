//==========
// stddef.h
//==========

#pragma once


//=======
// Types
//=======

typedef unsigned long long int size_t;
typedef size_t SIZE_T;

typedef unsigned long long int FILE_SIZE;


//========
// Macros
//========

#define NULL 0

#define offsetof(type, member) __builtin_offsetof(type, member)
