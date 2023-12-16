#ifndef _SPINLOCK_H
#define _SPINLOCK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    bool locked;
    char *name;
} spinlock;

void initlock(spinlock *lock, char *name);
void aquire_lock(spinlock *lock);
void release_lock(spinlock *lock);

#endif // _SPINLOCK_H
