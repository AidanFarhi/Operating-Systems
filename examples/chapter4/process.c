#include <stdint.h>

/* This is a basic structure of a UNIX xv6 process */

/* 
These are the registers xv6 will save and restore
to stop and subsequently restart a process
*/
struct context 
{
    int eip;
    int esp;
    int ebx;
    int ecx;
    int edx;
    int esi;
    int edi;
    int ebp;
};

/* The different states a process can be in */
enum proc_state
{
    UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE
};

/*
The information xv6 tracks about each process
including its register context and state
*/
struct proc
{
    char *mem;                  // Start of process memory
    uint32_t sz;                // Size of process memory
    char *kstack;               // Bottom of kernal stack
    enum proc_state state;      // Process state
    int pid;                    // Process ID
    struct proc *parent;        // Parent process
    void *chan;                 // If !zero, sleeping on chan
    int killed;                 // If !zero, has been killed
    struct file *ofile;         // Open files
    struct inode *cwd;          // Current directory
    struct context context;     // Switch here to run process
    struct trapframe *tf;       // Trap frame for the current interrupt
};