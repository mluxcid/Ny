# Ly style guide

### Restrictions
* A line should not exceed 80 characters
* files should be all lowercase

### Alignment/Indentation
* it is indentented using 4 spaces

### Functions
* functions are written in lowercase
* functions should be prefixed with the namespace 
* arguments should be on the same line unless they exceed the 80 character limit
* curly brackets are put on a new line
* function types are on the same line as their names

examples:

```c
function_type myfunction()
{
    ...
}

// this would exceed the 80 character limit
function_type namespace_dosomething(
    my_long_type1 arg1,
    my_long_type2 arg2,
    my_long_type3 arg3)
{
    ...
}
```

### Types
* types must be typedef'd
* types are written in lowercase and are prefixed with namespaces
* kernel types are prefixed with `k`
* enum values are uppercase

examples:

```c
typedef struct {
    ...
} namespace_mytype;

typedef struct {
    ...
} ktype;
```


### variables
* variables are written lowercase

### Macros
* macros are written in uppercase
