#include "asm/spinlock.h"

// TODO: implement SMP for locking
void initlock(spinlock *lock, char *name)
{
    lock->name = name;
    lock->locked = false;
}

void acquire_lock(spinlock *lock)
{
    while (__sync_lock_test_and_set(&lock->locked, true) != 0)
        ;

    __sync_synchronize();
}

void release_lock(spinlock *lock)
{
    __sync_synchronize();

    __sync_lock_release(&lock->locked);
}
