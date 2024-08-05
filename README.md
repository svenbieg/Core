<h1>Core</h1>

<p>
This kernel provides basic functionality for multi-tasking C++ applications.<br />
The scheduler is working without any prioritization, while the
<a href="https://github.com/svenbieg/Heap">memory-manager</a> supports constant low time allocation.<br />
</p>
<br />

<img src="https://github.com/user-attachments/assets/a62770eb-6f1a-4035-a30c-d2c6846475e8" /><br />
<br />

<p>
I have implemented all synchronization-primitives that are important.<br />
There is a CriticalSection with a SpinLock, keeping other cores in a loop while scheduling.<br />
The Mutex causes other tasks to be suspended, when held by a ScopedLock or a SharedLock.<br />
Using a TaskLock pevents the current task from being interrupted,<br />
and the Signal can be used to synchronize tasks. 
</p>
