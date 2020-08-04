# Loading bar

Just a simple loading bar string generator

## Example
```cpp
loading_bar *b = lb_create('#', 10); // # symbol for the bar, 10 chars wide
lb_update(b, 40); // Update to 40%
printf("%s\n", b->bar); // Outputs: [####      ]
lb_destroy(b); // clean up
```

## Api

The api is as straight forward as it gets it consist of only 4 functions.

```
lb_create()
lb_destroy()
lb_update()
lb_display_percentage()
```

And ``loading_bar->bar`` to get a handle to the actual bar string (char *).

## Compilation

You have can compile this as a shared lib or statically

```
make all     # will build both targets
make dynamic # and
make static  # will build each version independently
make tests   # Will build the dynamic version and run the tests
```

## Unicode symbol support

Not for now.
