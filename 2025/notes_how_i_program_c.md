# from YouTube: Eskil Steenberg https://www.youtube.com/watch?v=443UNeGrFoM&pp=ygUNaG93IGkgd3JpdGUgYw%3D%3D


- uses C89 because C99 is "too new and too broken"
- doesn't use
  - goto
  - register
  - do
  - continue
  - auto
  - volatile
- 0 unwrapt dependencies
  - this might mean that he doesn't use dependencies at all
  - "i wrap everything so I have 100% control over my code"

- his code is durable, "i want my code to last forever"

- "really important to read your code and understand it"
  - there can't be any misunderstanding between how the compiler views your code and how you do. -> no ambiguity
    - therefore C++ is a terrible language
      - tries to be clever, which is the root of all evil
      - tries to hide things; but things should be explicit
      - overloading is bad

# Good Tooling + Simple Language = 👍

- e.g. he generates documentation websites of his C projects using his own tool, which parses C
- it's harder to make cool tools in more complex, heavier languages

# Naming

- long names are good; it means you're being descriptive
- being descriptive is good!
- snake case > camel, but camel might be more differentiated from vars (if you use snake for vars)
- func() > func ()

# Functions

- less flipping around
- write code that does something (no handlers, managers, controllers)
  - ~ verbs
- WIDE and LONG == good
  - you can track the state if it's all in one function
- _really_ long functions are great, you can follow it step by step

## Function Names

- module first, file second, object third, verb last
  - `vast_db_session_get`

# API Design

- create the API you want, then fill in the implementation
- one "entrypoint" (?) "external" file e.g. `main.h` which contains everything from the library modules
  - not `main.c` and `main.h`
  - put internal things into something called `*_internal.h`

## Object Orientation (!)

- no such thing as object-oriented on the machine level
  - data + code is impossible at the machine level
    - stops malicious attacks
    - all memory is write-protected
  - "objects are fundamentally wrong"

In C,

```c
    // can't and _shouldn't_ do

    object thing();
    thing.do_something();

    // this is the way

    thing = object_create();
    object_do_something(thing);

```

For internal functions being exposed externally, force their usage via void pointer, by exposing them as such.

```c
// external module
typedef void RShader

extern RShader *shader_shader_create(...)
extern int     shader_shader_make_opaque(...) 

// internal 
type def struct{
    ...
}RShader;


```

# Macros Are Mostly Bad and Dangerous

Even the first example below has problems: The debugger won't be able to help you.

## Except

### Duplicative code for different types

```c
func(float *array_a, float *array_b, uint count) {
    uint i;
    for (i = 0; i < count; i++) {
        array_a[i] *= array_b[i];
    }
}

// but you want a bunch of different versions of this with different types
// e.g. double *array_a, etc.
```

### __FILE__ and __LINE__

These interpolate as the filename and the line number.

This allows _easy finding of memory leaks_!:

```c
extern void *f_debug_mem_malloc(uint size, char *file, uint line);
extern void f_debug_mem_print(uint min_allocs);
// goes through the registry and makes sure the allocations are intact; if not, it gives an easy to read list of stomped memory
extern boolean f_debug_memory(); 
// if you have an allocation that happens a lot of times, you can comment on each allocation so the registry entry has more detail.
extern boolean f_debug_mem_comment(void *buf, char *comment);

#ifdef F_MEMORY_DEBUG
# define malloc(n) f_debug_mem_malloc(n, __FILE__, __LINE__)
# define realloc(n, m) f_debug_mem_malloc(n, m, __FILE__, __LINE__)
# define free(n) f_debug_mem_free(n, __FILE__, __LINE__)
```

Creates a registry of what _file_ and _line_no_ allocated or deallocated memory! (and other things, see comments)

He turns it on ~ once a week for debugging. It slows the execution, so not for use all the time.

### Debugging Data Packing/Unpacking

In binary files/network protocol stuff.

- add a `char *name` to your `pack` and `unpack` functions 
- has a flag enabling a macro to actually use `name`, so it's only on when trying to debug packing/unpacking or callers thereof

```c
#define testify_pack_uint8(n, m, l) testify_pack_uint8_internal(n, m, l, __FILE__, __LINE__)
#define testify_unpack_uint8 ...
```
# Only Use Unsigned Integers

- 'nuff said, use them by default

# Memory

Understanding and having control over memory is a good thing, even if you don't program C.

## If Something Exists, It Exists _Somewhere_

A thing can be described by "what" as well as "_where_". _where_ is a pointer, which is a number. It's like a street address.

### Pointers

Why do pointers have types?

Because you can't _use_ the pointer if you don't know what/how long the thing is it's pointing to.

```c

void *p; // untyped, this is fine as seen before (internal objects)
short *short_pointer;
int *int_pointer;

a = *short_pointer; // reads 2 bytes as a short
b = *int_pointer; // reads 4 bytes as an int

short_pointer++; // adds 2 bytes = sizeof(short)
int_pointer++; // adds 4 bytes = sizeof(int)

if (short_pointer != int_pointer)
    printf("Not the same!");

```

Pointers point to one thing, but they sort of also point to the _next_ thing. They's also _kind of arrays_, they're pointers to the starting point of a street/array of addresses (midpoint really, you can go forwards or backwards).

## `malloc`

```c
double *a;

a = malloc(sizeof(float)); // looks like a function, but malloc is an operator in C. this is typically how malloc gets used, but below is better.

// better to write it this way, because it's more of a _cast_

a = malloc((sizeof *a) * 10); // this respects what it _is_ and it also is dynamic, since if `a`'s type changes this will remain correct.

sizeof (float)a; // this casts `a` as a float
```

## Arrays

- taking a pointer, stepping forward, then reading what's there

```c
a = x[3];

// equivalent to

uint *p;
p = x;
x = p + (sizeof *x) * 3;
a = *x;
```

## Counters

```c

// these are equivalent, but the bottom one is faster 
// because the first one requires multiplication
// (or not, because compilers are sophisticated)

uint i;
for (i = 0; i < 10; i++)
    // p + (sizeof *p) * i
    p[i] = 0;


void *end;
for (end = &p[10]; p != end; p++)
    *p = 0;
```

# Structs

Don't fool yourself that the computer knows the names in a struct! It's just a bunch of offsets.

```c
typedef struct{
    uint type;
    char name[32];
    float size;
}MyStructType;

// "scary code" to get the offset of size
offset = (uint)(&((MyStructType *)NULL)->size);
```

## Object-Oriented Inheritance

```c
typedef enum{
    MST_INT,
    MST_FLOAT,
    MST_COUNT
}MyStructType;

typedef struct{
    char name[32];
    MyStructType type;
}MyHeader;

typedef struct{
    MyHeader head;
    int value;
}MyStructInt;

typedef struct{
    MyHeader head;
    float value;
}MyStructFloat;

void my_set_value(MyHeader *h, double value) {
    if (h->type == MST_INT)
        ((MyStructInt *)h)->value = (int)value;
    else
        ((MyStructFloat *)h)->value = (float)value;
}

// a pointer to MyStructFloat _is_ a pointer to MyHeader, which is _also_ a pointer to MyHeader->name
```

## Alignment

Computers like to store things on even byte addresses.

```c
typedef struct{
    uint8 a; // 1 byte
    uint32 b; // 4 byte
}MyStructType;

sizeof(MyStructType) == 8 // we expected 5
// the compiler (computer?) stores `a` with three bytes of padding
// this is true even if you reverse the order

typedef struct{
    uint8 a; // 1 byte
    uint8 a; // 1 byte
    uint8 a; // 1 byte
    uint8 a; // 1 byte
    uint32 b; // 4 bytes
}MyStructType;

// uses exactly the same amount of memory as the one above

typedef struct{
    uint8 a; // 1 byte
    uint32 b; // 4 bytes
    uint8 x; // 1 byte
}MyStructType;

// sizeof (MyStructType) == 12

```

The takeaway is that you should try to order your struct attributes to land on even/factors of 4 of memory.


### Manual Packing

```c
uint8 *memory;
MyStructType *s;

memory = malloc(5 * 10);

for (i = 0; i < 10; i++) {
    s = (MyStructType *)&memory[i * 5];
    s->b = i;
    s->a = i;
}
// this may be slow or even cause a crash
```

## Memory Blocks

Memory is one big array, BUT it's divided into blocks of 4k.

Each block has read/write/execute flags.

Each address isn't the *actual* address, they're virtualized.

"This piece of memory is for this program; this piece is for that other program. If an application tries to write into memory allocated for another application, I will _crash_ it."

Since memory addresses are virtualized, you can rearrange them. 

### `realloc`

`realloc` takes a piece of memory and reallocates the _size_ of it; the contents remain the same.

It's sometimes seen as bad because it may require copying of memory contents. However, since memory addresses are virtualized...

#### `gflags.exe`

If you allocate one byte of memory, the processor will assign you an entire block (4k bytes). Then if you ask for ten bytes more, it'll allocate from the original block. You allocate some more things, and the memory block looks like this:

----------------------------
1222222222222233333344444444

Then you allocate a fifth thing, and you are allocated a second block of 4k:

---------------------------
55555555555555555555555

Let's say `a1` is the first var, which only has one byte, then `b1` is the second one, and they're stored contiguously.

Then you try to do

```c
a1[1] = 0;
```

The computer isn't going to stop you because you're overwriting memory in _your_ application.

```c
{
    uint a[10], i;
    for (i = 0; i < 11; i++)
        a[i] = 0;
}
```

This will become an infinite loop because `i` when initialized is probably going to be directly after `a` in memory. So when `a[11] = 0` happens, `i` is overwritten as `0`.

For this reason "I'm always scared when I put an array on the stack."  Just be aware this can happen, it's okay to actually do it.

You can tell Gflags: "Every time I do a new allocation, give me a new block." It puts every item in its own block _separated by a 'kill block'_ which you may not touch.

When you do that, your computer won't work very well BECAUSE THERE ARE MEMORY LEAKS EVERYWHERE.

But turn it on every few weeks, run your application, and see if it crashes.

### Memory is Slow

Accessing data:

- register: 0 cycles
- level 1 cache: 2-3 cycles
- level 2 cache: 10-15
- main memory: 50 cycles

It's gotten _worse_ over the last 30 years and will continue to do so.

```c
// this might be faster
a = a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a;
b = b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b;
c = c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c;
d = d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d;

// than this

b = *a; // memory access
```

#### Linked List

They're the worst thing you can do for memory coherence. You're jumping around in memory, so lots of cache misses.

```c
typedef struct{
    void *data;
    void *next;
}LinkedList;
// uses twice as much memory as the other options here because it needs
// -> next

// not memory coherent
for (l = list; l != NULL; l = l->next)
    do_something(l);

// memory coherent (adjacency)
for (i = 0; i < array_length; i++)
    do_something(&array[i]);

// realloc rarely when adding
if (array_length == array_allocated) {
    array_allocated += 16; // allocate 16 more values
    // then reallocate (every 16 times)
    array = realloc(array, (sizeof *array) * array_allocated);
}
// operting on this piece of memory is very fast, everything is adjacent
array[array_length] = value;
array_length++;

// remove
array[i] = array[--array_length]; // fast

// if you need to preserve the order, backwards remove is still faster than an LL

for (i = array_length; i != 0;) {
    i--;
    if (array[i] == the_one_we_want_to_remove)
        break;
    last = save;
    save = array[i];
    array[i] = last;
}

// usually you don't need to preserve the order though

```

# Don't Store Data Twice

```c
typedef struct{
    float width;
    float length;
    float area;
}MyPlane;

// a bug waiting to happen because one of the attributes could be updated without one of the others being updated
// ideally, just don't store `area` since math is "free" as we've seen

// but if you must,

typedef void MyPlane;

void    my_plain_width_set(MyPlane *plane, float width);
float   my_plain_width_get(MyPlane *plane);
void    my_plain_length_set(MyPlane *plane, float length);
float   my_plain_length_get(MyPlane *plane);
float   my_plain_area_get(MyPlane *plane);

// this is safe because the only public interface is this set of functions
```

# Smart Allocations

## Array with Length

```c
// typical way of storing an array with length

typedef struct{
    uint length;
    uint8 *data;
}MyArrayOfBytes;

MyArrayOfBytes *array;
array = malloc(sizeof *array);
array->length = length;
array->data = malloc((sizeof *array->data) * array->length);

// the flaw is that the struct and its instance may not be contiguous
// therefore slow

// 🚀 better:

typedef struct{
    uint length;
    uint8 data[1]; // in c99: data[];
    // if you add any additional members don't put them here! put them before `data[1]`
}MyArrayOfBytes;

MyArrayOfBytes *array;
array = malloc((sizeof *array) + sizeof(uint8) * (length - 1)); // because there's already one in `data`; in c99 no need for ' - 1'
array->length = length;

for (i = 0; i < length; i++)
    array->data[i] = 0;

// only one allocation! it's faster

```

## Instantiate Two Structs

Only one allocation!

```c
typedef struct{
    uint64 a;
    float b;
}MyStructA;

typedef struct{
    float x;
    uint64 y;
    double z;
}MyStructB;

MyStructA *a;
MyStructB *b;

a = malloc(sizeof(MyStructA) + sizeof(MyStructA));
b = (MyStructB *)&a[1];

// this could be dangerous because the alignments might not be right, depending on the machine
// however, it can boost performance
```

## Stride

```c
// requires rgb_pixels to be adjacent to each other
void rgb_color_correct(uint8 *rgb_pixels, uint pixel_count); 
// more flexible
void rgb_color_correct(uint8 *rgb_pixels, uint pixel_count, uint stride); 
// how to call
rgb_color_correct(rgba, pixel_count, sizeof(uint8) * 4);

typedef struct{
    float size;
    uint8 color[3];
    char name[16];
}Thing;

Thing t[10];

rgb_color_correct(t[0].color, 10, sizeof *t);
```

# Don't Be Afraid to Write Code: Build a Mountain

"Don't implement anything, everything is hard." == conventional wisdom

aliases: "Don't write your drivers, don't write an operating system."

Better: "This is something I don't know how to do; therefore I should be doing it." You learn by implementing things.

When you wrote the code, you can fix it/change it, you have an _expert_ == YOU. Super valuable in the long run.

## Concrete Advice

- build huge technology, small applications
  E.g. if you build a music player, 
    - build an interface library (tech)
    - build a sound library (tech)
    - then build the music player (app)

## Example: Apple

They built the mountain:

- QuickTime -> iTunes
            -> webobject -> iTunes Store

- OS X -> OpenGL 
       -> iOS
             -> App Store

- Safari -> iPhone

# Fix Your Code NOW

- don't fix it later; it snowballs and will be harder later
- have zero technical debt
- if you deliver things quickly at work because you hacked something together, it will create an expectation
  - give them very little at the beginning
  - only show your manager what's finished, debugged, ready
  - then they'll have a realistic idea of what you can build
  - (don't spend forever, but write it right from the beginning)
- really important, will always pay off

# How To Do UIs, Applications, etc.

Widgets can either 1) draw 2) have an event or 3) update itself, which all happens inside `input`.

So you can have a button which can be called many times for different reasons.

```c
void my_widget(BInputState *input) {
    if (input->mode == BAM_DRAW) { // draw widget }
    else if (input->mode == BAM_EVENT) { // deal with events }
    else if (input->mode == BAM_MAIN) { // advance time }
}

// most UI libs work like this, it's annoying and object-oriented
// lots of ids to keep track of etc
void button_func(void *user) { printf("button press"); }
void init_ui() {
    element = element_create;
    id = element_button_add(element, x, y, "hello", button_func, NULL);
    element_surface_add(element, x, y, size);
}
main_loop() { 
    element_move(element, id, sin(time), cos(time));
    element_run(element);
};


// nice to have
// problem: this looks nice, but it can't be done 
// I don't know if I'm going to draw a surface after the button press
// can't switch the order either
main_loop() {
    if (draw_button(sin(time), cos(time), "hello"))
        printf("button press");
    draw_surface(x, y, size);
}

// Better:
main_loop() {
    if(draw_button_add(id1, sin(time), cos(time), "hello"))
        printf("button press);
    draw_surface(id2, x, y, size);

    // the `id`s are pointers and can be to ANYTHING.
    // turns out you usually have a pointer:

    slider(&value, &value, x, y, size);

    // if you need an id:

    malloc()

    // the id could even be a string, because everything has an address, and therefore pointers can be `id`s

}
```
