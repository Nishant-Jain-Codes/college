# Q1. CPU Scheduling and Criteria for Scheduling:

CPU scheduling is a crucial part of an operating system that determines the order in which processes or threads are executed on a computer's CPU (Central Processing Unit). It involves selecting a process/thread from the ready queue and allocating CPU time to it. The goal of CPU scheduling is to optimize CPU utilization, improve system responsiveness, and ensure fairness in executing processes/threads.

Various criteria are considered when selecting a process/thread for execution. These criteria help determine the order in which processes/threads are scheduled and can vary based on the specific scheduling algorithm employed. The most common criteria for CPU scheduling include:

1.  CPU Burst Time: CPU burst time refers to the amount of time a process/thread needs to execute its CPU-bound tasks. Processes/threads with shorter burst times are often given higher priority as they allow for faster turnaround and better overall system responsiveness.

2.  Priority: Priority-based scheduling assigns a priority level to each process/thread. Processes/threads with higher priorities are given preferential treatment and are executed first. Priority can be fixed or dynamic, with some algorithms allowing for priority adjustments based on factors such as aging or the amount of CPU time used.

3.  Preemptive vs. Non-preemptive: Scheduling algorithms can be categorized as preemptive or non-preemptive. In preemptive scheduling, a running process/thread can be interrupted and moved out of the CPU by a higher-priority process/thread. Non-preemptive scheduling, on the other hand, allows a process/thread to hold the CPU until it completes or voluntarily yields the CPU.

4.  Waiting Time: Waiting time refers to the time a process/thread spends waiting in the ready queue before it can acquire the CPU for execution. Minimizing waiting time is desirable as it reduces the overall response time and enhances system efficiency.

5.  Turnaround Time: Turnaround time is the total time taken from the submission of a process/thread until its completion. It includes the waiting time, execution time, and any other overhead. Minimizing turnaround time ensures faster completion of processes/threads and better system performance.

6.  Response Time: Response time is the time it takes from when a process/thread is submitted until it starts its first response. Lower response time is essential for interactive applications where quick user feedback is crucial.

7.  Fairness: Fairness aims to provide equal opportunities for all processes/threads to access CPU time. It ensures that no process/thread is continuously neglected or starved of CPU resources.

Different scheduling algorithms, such as First-Come-First-Served (FCFS), Shortest Job Next (SJN), Round Robin (RR), Priority Scheduling, and Multilevel Queue Scheduling, prioritize these criteria differently to meet specific system requirements. The choice of a scheduling algorithm depends on the nature of the workload, system characteristics, and desired performance metrics.

# Q2. Process and Steps Involved in Change of Process State:

A process can be defined as an instance of a program in execution. It represents the basic unit of work in an operating system. When a program is executed, it becomes a process that undergoes various states during its lifetime. The steps involved in the change of process state can be explained as follows:

1.  Creation:

    -   The process creation begins when a new program is started or when an existing process requests the creation of a new process (e.g., using the fork() system call in Unix-like systems).
    -   The operating system allocates the necessary resources to the new process, such as memory space, process control block (PCB), and other required data structures.
    -   The process is initialized with the necessary data, including program code, data, and stack.
2.  Ready:

    -   Once the process is created and initialized, it enters the ready state.
    -   In the ready state, the process is loaded into the main memory and is waiting to be assigned to the CPU for execution.
    -   The process is added to the ready queue, which is a data structure managed by the operating system that holds all the processes in the ready state.
3.  Running:

    -   When the operating system selects a process from the ready queue to execute, it transitions the process to the running state.
    -   The process is allocated CPU time and starts executing its instructions.
    -   During this state, the process may interact with system resources, perform calculations, or communicate with other processes.
4.  Blocked (Waiting):

    -   While executing, a process may encounter an event that requires it to pause execution temporarily, such as waiting for I/O completion or a specific condition to be satisfied.
    -   In such cases, the process transitions from the running state to the blocked (or waiting) state.
    -   The process is moved out of the CPU and its resources are temporarily suspended.
    -   The process is typically placed in a waiting queue, where it waits for the event it is dependent on to occur.
5.  Ready (again):

    -   Once the event the process was waiting for happens, it transitions back to the ready state.
    -   The process is moved from the waiting queue to the ready queue.
    -   It is ready to be scheduled for execution by the operating system.
6.  Termination:

    -   A process enters the termination state when it finishes its execution or when it is explicitly terminated by the user or the operating system.
    -   The process releases all the resources it acquired during its lifetime, including memory, open files, and other system resources.
    -   The operating system removes the process from its data structures, deallocates the process's memory, and cleans up any remaining bookkeeping information.

Throughout these steps, the operating system maintains a data structure called the Process Control Block (PCB) for each process. The PCB contains essential information about the process, including its current state, program counter, CPU registers, memory allocation, I/O status, and other relevant details. The operating system uses this information to manage and control the execution of processes efficiently.

The change of process state is orchestrated by the operating system's process scheduler, which is responsible for selecting processes from the ready queue and allocating CPU time to them based on a chosen scheduling algorithm. The scheduler ensures fair utilization of system resources and efficient execution of processes.

# Q3. User-Level Thread vs Kernel-Level Thread:

User-Level Thread (ULT) and Kernel-Level Thread (KLT) are two different approaches to implementing threads in an operating system. Let's delve into each of them in detail:

User-Level Thread (ULT):

-   User-Level Threads are managed entirely by user-level libraries or runtime systems without direct involvement from the operating system kernel.
-   ULTs are lightweight and efficient as they do not require kernel intervention for thread management.
-   Thread operations such as creation, scheduling, and synchronization are handled by user-level libraries, which are typically part of a programming language or runtime environment.
-   ULTs provide greater flexibility and can be customized to suit specific application requirements.
-   Each ULT has its own thread control block (TCB) containing information about the thread's execution state and stack.
-   ULTs are typically more portable as they are not tied to a specific operating system's threading model.
-   However, ULTs have limitations in terms of parallelism and scalability since a blocking ULT can potentially block the entire process, including other ULTs.

Kernel-Level Thread (KLT):

-   Kernel-Level Threads are managed directly by the operating system kernel.
-   KLTs are implemented as part of the operating system's process management mechanism and rely on kernel services for thread management.
-   Thread operations are performed through system calls that involve kernel intervention.
-   KLTs provide better parallelism and scalability as the operating system can schedule and manage threads independently.
-   Each KLT has its own kernel-level thread control block (TCB) maintained by the kernel.
-   KLTs can utilize multiple processors or cores effectively, allowing true concurrent execution.
-   However, context switches between KLTs require kernel involvement, which introduces additional overhead.
-   KLTs are typically less portable as they are tied to the specific threading model and services provided by the operating system.

Comparison:

-   ULTs are lighter in terms of overhead as they do not rely on kernel services, while KLTs involve additional overhead due to kernel intervention.
-   ULTs offer more flexibility and customization options but may lack parallelism and scalability compared to KLTs.
-   ULTs can be implemented using different threading libraries specific to programming languages, whereas KLTs rely on the operating system's threading model.
-   ULTs may be more suitable for applications with lightweight threading requirements, while KLTs are preferred for performance-intensive and parallel applications.

It's worth noting that ULTs and KLTs are not mutually exclusive, and hybrid models combining both approaches exist. For example, some operating systems use KLTs for thread management at the kernel level while providing ULTs within each KLT for finer-grained control and customization.

The choice between ULTs and KLTs depends on factors such as application requirements, performance considerations, portability needs, and the threading model provided by the operating system.

# Q4. Thread vs Process:

Sure! Here's a comparison table highlighting the differences between threads and processes:

|  | Thread | Process |
| --- | --- | --- |
| Definition | A thread is a lightweight unit of execution within a process. It shares the same memory space and resources as other threads within the same process. | A process is an instance of a program in execution. It has its own memory space, resources, and execution context. |
| Resource Ownership | Threads share the same resources (such as memory, file handles, and open sockets) within a process. | Processes have their own separate resources, which are not shared with other processes. |
| Creation | Threads are created within a process. | Processes are created by the operating system. |
| Communication | Threads within the same process can easily communicate with each other through shared memory. | Processes need inter-process communication mechanisms (e.g., pipes, sockets, message queues) to communicate with each other. |
| Context Switching | Context switching between threads within the same process is faster as they share the same memory space. | Context switching between processes is slower as it involves saving and restoring the entire process's memory space and resources. |
| Concurrency | Threads can run concurrently and share the same resources, enabling parallelism within a process. | Processes run independently of each other and do not share resources, limiting parallelism unless inter-process communication is used. |
| Scalability | Threads can be more scalable due to their lightweight nature, allowing for efficient utilization of system resources. | Processes are less scalable due to their overhead and isolation, requiring more system resources for each instance. |
| Fault Isolation | If one thread crashes or encounters an error, it can affect other threads within the same process, potentially leading to the termination of the entire process. | If one process crashes or encounters an error, it does not affect other processes, providing better fault isolation. |
| Synchronization | Threads within the same process can easily synchronize using thread synchronization primitives (e.g., locks, semaphores) to coordinate access to shared resources. | Processes need inter-process synchronization mechanisms (e.g., message passing, shared memory with proper synchronization) to coordinate access to shared resources. |
| Overhead | Threads have lower overhead in terms of memory and context switching compared to processes. | Processes have higher overhead in terms of memory and context switching due to their independent nature. |
| Portability | Threads are more portable as they rely on the threading model provided by the programming language or runtime environment. | Processes are less portable as they depend on the operating system's process management mechanisms. |

It's important to note that threads and processes serve different purposes and have different characteristics. Threads are suitable for concurrent programming within a single process, while processes provide isolation and are often used for independent program execution or inter-process communication. The choice between threads and processes depends on the specific requirements and design considerations of the application or system.

# Q5. Round Robin Scheduling Algorithm:

Sure! Round Robin is a popular CPU scheduling algorithm that is designed to provide fairness and prevent starvation in a multi-programmed or time-sharing environment. It works by allocating a fixed time slice, called a time quantum or time slice, to each process in the system, allowing them to run for a certain amount of time before being preempted and moved to the back of the ready queue. The algorithm is based on the concept of circular queues.

Here's an overview of the Round Robin scheduling algorithm:

1.  Time Quantum: The algorithm operates by assigning a fixed time quantum to each process. This time quantum represents the maximum amount of time a process can run before being preempted.

2.  Ready Queue: All processes in the system are stored in a ready queue, which represents the pool of processes that are waiting to be executed.

3.  Execution: The scheduler selects the first process from the ready queue and assigns it the time quantum for execution. The process runs for the specified time quantum or until it voluntarily releases the CPU.

4.  Preemption: If a process completes its time quantum, it is preempted and moved to the back of the ready queue to allow the next process in line to execute. Preemption ensures fairness and prevents a single process from monopolizing the CPU.

5.  Context Switching: When a process is preempted or finishes execution, a context switch occurs. The context switch involves saving the current process's state (registers, program counter, etc.) and loading the state of the next process to be executed.

6.  Queue Rotation: After each time quantum, the ready queue is rotated, and the next process in line becomes the front process. This rotation ensures that all processes get an equal chance of execution.

7.  Process Termination: Processes continue to execute in a round-robin fashion until they complete their execution or are terminated by the operating system.

The Round Robin scheduling algorithm is fair as it allocates an equal amount of CPU time to each process, preventing any single process from monopolizing the CPU. It also provides responsiveness and allows for a reasonable turnaround time for interactive processes.

Now, let's solve a numerical example to illustrate how the Round Robin scheduling algorithm works:

Consider three processes P1, P2, and P3 with their respective burst times and arrival times:

| Process | Burst Time | Arrival Time |
| --- | --- | --- |
| P1 | 6 ms | 0 ms |
| P2 | 4 ms | 1 ms |
| P3 | 8 ms | 2 ms |

Assume the time quantum is 3 ms.

The Gantt chart for the Round Robin scheduling algorithm will look as follows:

| Time | P1 | P2 | P3 | P1 | P3 | P3 | P3 | P1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 - 3 | P1(Run) |  |  |  |  |  |  |  |
| 3 - 6 | P1(Wait) | P2(Run) |  |  |  |  |  |  |
| 6 - 9 | P1(Run) | P2(Wait) | P3(Run) |  |  |  |  |  |
| 9 - 12 | P1(Run) | P3(Run) | P3(Wait) |  |  |  |  |  |
| 12 - 15 | P1(Wait) | P3(Run) | P3(Run) |  |  |  |  |  |
| 15 - 18 | P1(Run) | P3(Wait) | P3(Run) |  |  |  |  |  |
| 18 - 21 | P1(Wait) | P3(Wait) | P3(Run) |  |  |  |  |  |
| 21 - 24 |  | P3(Wait) | P3(Run) |  |  |  |  |  |
| 24 - 27 |  |  | P3(Run) |  |  |  |  |  |
| 27 - 30 |  |  | P3(Wait) |  |  |  |  |  |
| 30 - 33 |  |  | P3(Run) |  |  |  |  |  |
| 33 - 36 |  |  |  | P1(Run) |  |  |  |  |

In the above example, the time quantum is set to 3 ms. The processes are executed in a round-robin fashion, and each process gets a maximum of 3 ms of CPU time before being preempted. The execution continues until all processes are completed.

It's important to note that the Round Robin algorithm may not be suitable for all scenarios. The choice of time quantum is crucial, as a smaller time quantum may lead to increased overhead due to frequent context switching, while a larger time quantum may result in reduced responsiveness. The algorithm's performance can be influenced by the number of processes, their burst times, and the scheduling overhead.

# Q6. Deadlock, Necessary Conditions, and Prevention:

Deadlock refers to a situation in a computer system where two or more processes are unable to proceed because each is waiting for a resource held by another process in the set. Deadlocks can occur in various systems, such as operating systems, databases, and distributed systems, where multiple processes or threads compete for resources.

Necessary Conditions for Deadlock: For a deadlock to occur, four necessary conditions, known as the Coffman Conditions, must be present simultaneously:

1.  Mutual Exclusion: At least one resource must be held in a non-sharable mode, meaning that only one process can use the resource at any given time.

2.  Hold and Wait: Processes currently holding resources may request additional resources and are allowed to wait for them to become available. However, they must continue to hold the resources they already possess during this waiting period.

3.  No Preemption: Resources cannot be forcibly taken away from a process; only the process itself can release the resources voluntarily.

4.  Circular Wait: A circular chain of two or more processes exists, where each process in the chain is waiting for a resource held by the next process in the chain.

Preventing Deadlock: To prevent deadlocks from occurring, one or more of the necessary conditions must be eliminated. Here are some common deadlock prevention techniques:

1.  Deadlock Avoidance: This technique involves using resource allocation and scheduling algorithms to ensure that the system avoids entering an unsafe state, where deadlock is possible. The resource allocation algorithm analyzes resource requests and releases to determine if granting a request will potentially lead to a deadlock. Examples of algorithms used for deadlock avoidance include the Banker's algorithm.

2.  Resource Allocation Graph: A resource allocation graph is a graphical representation of resources and processes, where vertices represent processes and resources, and edges represent resource requests and allocations. The graph is used to detect potential deadlocks and to identify the processes involved in the deadlock.

3.  Resource Ordering: Implementing a strict order in which resources can be requested can prevent circular wait conditions. By assigning a unique numerical value or ordering to each resource, processes are required to request resources in increasing order. This way, the circular wait condition is eliminated.

4.  Deadlock Detection and Recovery: Rather than preventing deadlocks, this technique focuses on detecting them when they occur and taking appropriate actions to recover from them. Deadlock detection involves periodically examining the resource allocation graph or using other algorithms to identify if a deadlock has occurred. Once detected, recovery can be achieved through processes such as process termination, resource preemption, or rollback.

It's important to note that preventing deadlock can come with drawbacks. Some prevention techniques may increase system overhead, reduce resource utilization, or introduce delays in resource allocation. Therefore, the choice of prevention technique depends on the specific requirements and characteristics of the system.

Overall, preventing deadlocks is crucial for maintaining the stability and reliability of computer systems. By understanding the necessary conditions for deadlock and employing appropriate prevention techniques, system designers and developers can minimize the occurrence of deadlocks and ensure the smooth operation of the system.

# Q7. Banker's Algorithm for Deadlock Avoidance:

The Banker's algorithm is a deadlock avoidance algorithm used to manage resource allocation and prevent deadlocks in a system. It was developed by Edsger Dijkstra. The algorithm ensures that resources are allocated to processes in a safe manner, meaning that the system can avoid entering a deadlock state.

The Banker's algorithm works by considering the maximum possible resource needs of processes and available resources. It uses a series of checks and calculations to determine if a resource request from a process can be granted without risking a deadlock. The algorithm maintains the concept of a "safe sequence" of resource allocations, which indicates that the system can satisfy the resource needs of all processes in a specific order, preventing deadlock.

Here is a step-by-step explanation of the Banker's algorithm:

1.  Data Structures:

    -   Available: An array of size m, where m represents the number of resource types. It specifies the number of available resources for each type.
    -   Max: A 2D array of size n x m, where n represents the number of processes and m represents the number of resource types. It indicates the maximum resource need of each process.
    -   Allocation: A 2D array of size n x m. It represents the number of resources allocated to each process.
    -   Need: A 2D array of size n x m. It indicates the remaining resource need for each process.
2.  Initialization:

    -   Set the Available array to represent the current available resources.
    -   Calculate the Need array by subtracting the Allocation array from the Max array for each process.
3.  Safety Check:

    -   Create a Work array and set it equal to the Available array.
    -   Create a Finish array of size n and initialize all elements to false.
    -   Start iterating through the processes.
    -   Check if the Need of a process is less than or equal to the Work for all resource types.
        -   If true, allocate the resources to the process and mark it as finished (set Finish[i] = true).
        -   Add the allocated resources to the Work array.
        -   Repeat the process until all processes are finished or there are no more processes that can be allocated resources.
    -   If all processes are finished, then the system is in a safe state. Otherwise, it is in an unsafe state and can potentially result in a deadlock.
4.  Resource Request:

    -   When a process requests resources, the request is checked against the Need array to ensure it doesn't exceed the maximum need.
    -   If the request is valid, it is compared with the Available resources.
        -   If the requested resources can be allocated without resulting in an unsafe state (i.e., the system remains in a safe state after the allocation), the resources are granted.
        -   Otherwise, the process must wait until sufficient resources become available.

The pseudocode for the Banker's algorithm is as follows:

```
# Initialization
    for i in range(n):
        Finish[i] = false

# Safety Check
    while True:
        found = false
        for i in range(n):
            if Finish[i] == false:
                if Need[i] <= Work:
                    Work = Work + Allocation[i]
                    Finish[i] = true
                    found = true

        if found == false:
            break

# Resource Request
    if Request <= Need[process] and Request <= Available:
        Available = Available - Request
        Allocation[process] = Allocation[process] + Request
        Need[process] = Need[process] - Request
    else:
        wait()
```

The Banker's algorithm ensures that resources are allocated in a way that prevents deadlock. It analyzes the current resource needs, available resources, and requests to make informed decisions about resource allocation, allowing the system to maintain a safe state. By carefully managing resource allocation, the algorithm helps ensure the stability and efficiency of the system.

# Q8. Deadlock vs Starvation:

Deadlock and starvation are two related but distinct concepts in the context of operating systems and concurrent programming.

1.  Deadlock:

    -   Deadlock refers to a situation where two or more processes are unable to proceed because each is waiting for a resource that is held by another process in the set.
    -   It is a state in which a process cannot complete its execution because the required resources are being held by other processes, and those processes are also waiting for additional resources held by other processes in the set.
    -   Deadlock occurs when four necessary conditions are met simultaneously:
        1.  Mutual Exclusion: At least one resource must be held in a non-shareable mode, meaning that it cannot be simultaneously used by multiple processes.
        2.  Hold and Wait: A process holds one or more resources while waiting to acquire additional resources.
        3.  No Preemption: Resources cannot be forcibly taken away from a process. They can only be released voluntarily.
        4.  Circular Wait: There exists a circular chain of two or more processes, where each process is waiting for a resource held by the next process in the chain.
2.  Starvation:

    -   Starvation refers to a situation where a process is indefinitely denied the resources it needs to make progress or complete its execution.
    -   It occurs when a process is continuously bypassed or delayed in favor of other processes, leading to the process being unable to proceed or complete its tasks.
    -   Starvation can occur even in the absence of deadlock if resource allocation policies or scheduling algorithms prioritize certain processes over others.
    -   Starvation can happen due to factors such as improper resource allocation, unfair scheduling, priority inversion, or resource exhaustion.

Differences between Deadlock and Starvation:

1.  Cause: Deadlock is caused by the four necessary conditions being satisfied, leading to a circular dependency of resource requests. Starvation, on the other hand, occurs when a process is continuously denied necessary resources.

2.  Resource Availability: In deadlock, resources are unavailable and held by other processes, creating a cyclic wait situation. In starvation, resources may be available, but a process is unable to access them due to scheduling or resource allocation policies.

3.  System State: Deadlock results in a system-wide deadlock state where multiple processes are unable to proceed. In starvation, individual processes may be affected, while others continue to execute.

4.  Resolution: Deadlock requires intervention or specific mechanisms to break the circular dependency and release resources. Starvation can be resolved by improving resource allocation policies, scheduling algorithms, or using fairness mechanisms.

In summary, deadlock refers to a specific state where multiple processes are stuck due to a circular dependency of resource requests, while starvation is a situation where a process is continuously denied necessary resources, hindering its progress or completion. Both deadlock and starvation can impact the proper functioning of concurrent systems and require careful system design and resource management techniques to prevent or resolve them.

--



Q1. CPU Scheduling and Criteria for Scheduling:

-   CPU scheduling determines the order in which processes/threads are executed on the CPU.
-   The goal of CPU scheduling is to optimize CPU utilization, improve system responsiveness, and ensure fairness.
-   Criteria for CPU scheduling include CPU burst time, priority, preemptive vs. non-preemptive scheduling, waiting time, turnaround time, response time, and fairness.
-   CPU burst time represents the time a process/thread needs for CPU-bound tasks.
-   Priority assigns a priority level to processes/threads, with higher priority receiving preferential treatment.
-   Preemptive scheduling allows for the interruption of running processes/threads by higher-priority ones, while non-preemptive scheduling lets processes/threads hold the CPU until completion or voluntary yield.
-   Waiting time is the time spent in the ready queue, while turnaround time is the total time from submission to completion.
-   Response time is the time from submission to the first response of a process/thread.
-   Fairness ensures equal opportunities for all processes/threads to access CPU time.
-   Different scheduling algorithms prioritize these criteria differently, such as FCFS, SJN, RR, Priority Scheduling, and Multilevel Queue Scheduling.

Q2. Process and Steps Involved in Change of Process State:

-   Creation: A new process is started or requested, and the operating system allocates necessary resources and initializes the process.

-   Ready: The process is loaded into main memory and added to the ready queue, waiting to be assigned CPU time.

-   Running: The operating system selects a process from the ready queue, allocates CPU time, and the process begins executing its instructions.

-   Blocked (Waiting): The process encounters an event that requires it to pause temporarily, such as waiting for I/O completion, and transitions to the blocked state. It is moved out of the CPU and placed in a waiting queue.

-   Ready (again): Once the event the process was waiting for occurs, it transitions back to the ready state and is moved from the waiting queue to the ready queue.

-   Termination: The process finishes execution or is explicitly terminated, releasing resources and being removed from the operating system's data structures.

-   The Process Control Block (PCB) holds information about the process's state, program counter, CPU registers, memory allocation, and I/O status.

-   The process scheduler, managed by the operating system, orchestrates the change of process state by selecting processes from the ready queue and allocating CPU time based on a scheduling algorithm.

Q3. User-Level Thread vs Kernel-Level Thread:

-   Creation: A new process is started or requested, and the operating system allocates necessary resources and initializes the process.

-   Ready: The process is loaded into main memory and added to the ready queue, waiting to be assigned CPU time.

-   Running: The operating system selects a process from the ready queue, allocates CPU time, and the process begins executing its instructions.

-   Blocked (Waiting): The process encounters an event that requires it to pause temporarily, such as waiting for I/O completion, and transitions to the blocked state. It is moved out of the CPU and placed in a waiting queue.

-   Ready (again): Once the event the process was waiting for occurs, it transitions back to the ready state and is moved from the waiting queue to the ready queue.

-   Termination: The process finUser-Level Thread (ULT):

-   Managed by user-level libraries or runtime systems without kernel involvement.
-   Lightweight and efficient, with thread operations handled by user-level libraries.
-   Greater flexibility and customization, with each ULT having its own TCB.
-   More portable but limited in parallelism and scalability.

Kernel-Level Thread (KLT):

-   Managed directly by the operating system kernel.
-   Relies on kernel services for thread management through system calls.
-   Better parallelism and scalability, with each KLT having its own kernel-level TCB.
-   Less portable but allows for true concurrent execution.

Comparison:

-   ULTs have lower overhead, while KLTs involve additional overhead due to kernel intervention.
-   ULTs offer more flexibility and customization, while KLTs provide better parallelism and scalability.
-   ULTs can be implemented using specific threading libraries, while KLTs rely on the operating system's threading model.
-   ULTs are suitable for lightweight threading, while KLTs are preferred for performance-intensive and parallel applications.

Note: Hybrid models combining ULTs and KLTs exist, where KLTs manage thread management at the kernel level while providing ULTs within each KLT for finer control and customization. The choice depends on application requirements, performance, portability, and the operating system's threading model.ishes execution or is explicitly terminated, releasing resources and being removed from the operating system's data structures.

-   The Process Control Block (PCB) holds information about the process's state, program counter, CPU registers, memory allocation, and I/O status.

-   The process scheduler, managed by the operating system, orchestrates the change of process state by selecting processes from the ready queue and allocating CPU time based on a scheduling algorithm.

Q4. Thread vs Process:

Thread:

Lightweight unit of execution within a process, sharing resources.
Created within a process.
Communication through shared memory.
Faster context switching.
Enables concurrency and parallelism within a process.
More scalable and efficient resource utilization.
One thread's error can affect other threads within the same process.
Synchronization through thread synchronization primitives.
Lower overhead and more portable.
Process:

Instance of a program in execution, with separate resources.
Created by the operating system.
Communication through inter-process communication mechanisms.
Slower context switching.
Runs independently of other processes.
Less scalable and higher resource overhead.
Better fault isolation between processes.
Synchronization through inter-process synchronization mechanisms.
Higher overhead and less portable.

Q5. Round Robin Scheduling Algorithm:



Q6. Deadlock, Necessary Conditions, and Prevention:



Q7. Banker's Algorithm for Deadlock Avoidance:



Q8. Deadlock vs Starvation:
Short summary: