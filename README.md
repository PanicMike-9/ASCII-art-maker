o# ASCII Canvas

- Each pixel is a character
- Arranged in rows and columns
- We can
 * clear it
 * Modify positions
 * print it

## Representing a Canvas

- Two dimensions

``` C
canvas
  |-- row 0: [][][][]
  |-- row 1: [][][][]
  |-- row 2: [][][][]
```
- Each cell stores one character.
- `' '` as empty
- fixed width
- fixed height

# Old function version

###  fill_rectangle v1.0

``` C
// fills the rectangle with the given character
void fill_rectangle(char canvas[HEIGHT][WIDTH], int top_row, int left_col, int width, int height, char character)
{
        for(int i = 0; i < height; ++i)
        {
                draw_horizontal_line(canvas, top_row + i, left_col, width, character);
        }
}
```
###  draw_centered_triangle v1.0

```C
// creates a center triangle
void draw_centered_triangle(char canvas[HEIGHT][WIDTH], int start_row, int center_col, int height, char character)
{
	for(int i = 0; i < height; ++i)
	{
		int start_col = center_col - i;
		draw_horizontal_line(canvas, start_row + i, start_col, height, character);
	}
}
```


