# Loading bar

Just a simple loading bar string generator

## Example
```cpp
loading_bar *b = loading_bar_create('#', 10); // # symbol for the bar, 10 chars wide
loading_bar_update(b, 40); // Update to 40%
printf("%s\n", b->bar); // Outputs: [####      ]
loading_bar_destroy(b); // clean up
```

## Api

The api is as straight forward as it gets it consist of only 4 functions.

```
lb_create()
lb_destroy()
lb_update()
lb_display_percentage()
```

And ``loading_bar->bar`` to get the actual bar string.

## Unicode symbol support

Not for now.
