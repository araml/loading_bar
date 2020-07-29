# Loading bar

Just a simple console loading bar implementation

## Example 
```cpp
loading_bar *b = loading_bar_create('#', 10); 
loading_bar_update(b, 40); // Update to 40%
printf("%s\n", b->bar); // Outputs: [####      ]
loading_bar_destroy(b); // clean up
```
