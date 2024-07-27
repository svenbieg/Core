<h1>Core</h1>

<p>
This kernel provides basic functionality for multi-tasking C++ applications.<br />
The scheduler is working without prioritization, while the
<a href="https://github.com/svenbieg/Heap">memory-manager</a> supports constant low time allocation.<br />
</p>
<br />

<img src="https://github.com/user-attachments/assets/68c63ccf-082a-4f04-9fe0-5bba4f655793" /><br />
<br />

<p>
I have implemented all synchronization-primitives that are important.<br />
There is a <b>CriticalSection</b> with a <b>SpinLock</b>, keeping other cores in a loop while scheduling.<br />
The <b>Mutex</b> causes other tasks to be suspended, when held by a <b>ScopedLock</b> or a <b>SharedLock</b>.<br />
Using a <b>TaskLock</b> pevents the current task from being interrupted.<br />
And the <b>Signal</b> can be used to synchronize tasks. 
</p>
