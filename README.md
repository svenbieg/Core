<h1>Core</h1>

<p>
This kernel provides basic functionality for multi-tasking C++ applications.<br />
The <a href="https://github.com/svenbieg/Core/wiki/Scheduler">scheduler</a> is working with dynamic prioritization,
while the <a href="https://github.com/svenbieg/Heap">memory-manager</a><br />
supports constant low time allocation.<br />
</p>
<br />

<img src="https://github.com/user-attachments/assets/a62770eb-6f1a-4035-a30c-d2c6846475e8" /><br />
<br />

<h2>Synchronization Primitives</h2>

<table>
  <tr>
    <td><a href="https://github.com/svenbieg/Core/wiki/Scheduler#critical-section">CriticalSection</a></td>
    <td>Used with a SpinLock, keeping other cores in a loop while scheduling</td>
  </tr><tr><td></td></tr><tr>
    <td><a href="https://github.com/svenbieg/Core/wiki/Scheduler#mutex">Mutex</a></td>
    <td>Suspending other tasks when held by a ScopedLock, a SharedLock or a TaskLock</td>
  </tr><tr><td></td></tr><tr>
    <td><a href="https://github.com/svenbieg/Core/wiki/Scheduler#signal">Signal</a></td>
    <td>Used to synchronize tasks</td>
  </tr>
</table><br />

<p>
You can find a Blink-example for Raspberry Pi 5 <a href="https://github.com/svenbieg/Blink">here</a>.
</p>
