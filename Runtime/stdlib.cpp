//============
// stdlib.cpp
//============

#include "pch.h"


//=======
// Using
//=======

#include <stdarg.h>
#include <stdio.h>
#include "heap.h"


//========
// cstdio
//========

_reent* _impure_ptr=nullptr;

extern "C" INT fputc(INT c, FILE* file)
{
return fwrite(&c, 1, 1, file);
}

extern "C" INT fputs(LPCSTR str, FILE* file)
{
INT len=0;
while(str[len])
	{
	size_t written=fwrite(&str[len], 1, 1, file);
	if(!written)
		break;
	len++;
	}
return len;
}

extern "C" size_t fwrite(VOID const* buf, size_t size, size_t count, FILE* file)
{
return 0;
}

extern "C" int sprintf(LPSTR str, LPCSTR format, ...)
{
return 0;
}

extern "C" size_t write(FILE* file, void const* buf, size_t size)
{
return fwrite(buf, 1, size, file);
}


//=========
// cstdlib
//=========

heap_handle_t g_heap=nullptr;

extern "C" LPCSTR getenv(LPCSTR name)
{
return nullptr;
}

extern "C" VOID* malloc(SIZE_T size)
{
return heap_alloc(g_heap, size);
}

extern "C" VOID free(VOID* buf)
{
heap_free(g_heap, buf);
}

extern "C" VOID* realloc(VOID* buf, SIZE_T size)
{
return heap_realloc(g_heap, buf, size);
}


//=========
// cstring
//=========

extern "C" INT memcmp(VOID const* buf1, VOID const* buf2, SIZE_T size)
{
LPCSTR buf1_ptr=(LPCSTR)buf1;
LPCSTR buf2_ptr=(LPCSTR)buf2;
for(SIZE_T u=0; u<size; u++)
	{
	if(buf1_ptr[u]>buf2_ptr[u])
		return 1;
	if(buf1_ptr[u]<buf2_ptr[u])
		return -1;
	}
return 0;
}

extern "C" VOID* memcpy(VOID* dst, VOID const* src, SIZE_T size)
{
LPSTR dst_buf=(LPSTR)dst;
LPCSTR src_buf=(LPCSTR)src;
for(SIZE_T u=0; u<size; u++)
	dst_buf[u]=src_buf[u];
return dst;
}

extern "C" VOID* memset(VOID* dst, INT value, SIZE_T size)
{
LPSTR dst_buf=(LPSTR)dst;
for(SIZE_T u=0; u<size; u++)
	dst_buf[u]=(CHAR)value;
return dst;
}

extern "C" LPCSTR strchr(LPCSTR str, INT c)
{
if(!str)
	return nullptr;
while(str[0]!=c)
	str++;
return str;
}

extern "C" INT strcmp(LPCSTR str1, LPCSTR str2)
{
if(!str1)
	{
	if(!str2)
		return 0;
	return -1;
	}
if(!str2)
	return 1;
for(UINT pos=0; pos>=0; pos++)
	{
	if(str1[pos]>str2[pos])
		return 1;
	if(str1[pos]<str2[pos])
		return -1;
	if(!str1[pos])
		break;
	}
return 0;
}

extern "C" INT strlen(LPCSTR str)
{
if(!str)
	return 0;
UINT len=0;
for(; str[len]; len++);
return len;
}

extern "C" INT strncmp(LPCSTR str1, LPCSTR str2, UINT len)
{
if(!str1)
	{
	if(!str2)
		return 0;
	return -1;
	}
if(!str2)
	return 1;
for(UINT pos=0; pos<len; pos++)
	{
	if(str1[pos]>str2[pos])
		return 1;
	if(str1[pos]<str2[pos])
		return -1;
	if(!str1[pos])
		break;
	}
return 0;
}

extern "C" UINT strtoul(LPCSTR str, LPCSTR end, INT base)
{
UINT len=0;
if(end>str)
	len=(UINT)(end-str);
UINT value=0;
StringScanUInt(str, &value, base, len);
return value;
}


//========
// cxxabi
//========

extern "C" void __cxa_atexit()
{}


//========
// stdlib
//========

extern "C" [[noreturn]] VOID abort()
{
Abort();
}

extern "C" [[noreturn]] VOID __assert_func(LPCSTR file, INT line, LPCSTR func, LPCSTR expr)
{
Abort(file, line, func, expr);
}
