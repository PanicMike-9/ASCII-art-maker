#include <stdio.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24

// prints empty space in the entire canvas
void clear_canvas(char canvas[HEIGHT][WIDTH])
{
	for(int r = 0; r < HEIGHT; ++r) {
		for(int c = 0; c < WIDTH; ++c) {
			canvas[r][c] = ' ';
		}	
	}
}

// takes input of, canvas obj, row, column, the char to print
void draw_point(char canvas[HEIGHT][WIDTH], int row, int column, char character) 
{
	// out of bounds check
	if(row < 0 || row > HEIGHT)
		return;
	if(column < 0 || column > WIDTH)
		return;
	
	canvas[row][column] = character;
}

// render the canvas
void render_canvas(const char canvas[HEIGHT][WIDTH]) 
{
	for(int r = 0; r < HEIGHT; ++r) {
		for(int c = 0; c < WIDTH; ++c) {
			printf("%c", canvas[r][c]);
		}
		putchar('\n');
	}
}

// draws a horizontal line, using the draw_point
void draw_horizontal_line(char canvas[HEIGHT][WIDTH], int row, int start_col, int length, char character) 
{
	for(int i = 0; i < length; ++i)
	{
		draw_point(canvas, row, start_col + i, character);
	}
}

// draws a vertical line, using the draw_point()
void draw_vertical_line(char canvas[HEIGHT][WIDTH], int start_row, int column, int length, char character)
{
	for(int i = 0; i < length; ++i) 
	{
		draw_point(canvas, start_row + i, column, character);
	}
}

// draws a rectangle of size width and height, and position top_row and left_col
void draw_rectangle(char canvas[HEIGHT][WIDTH], int top_row, int left_col, int width, int height, char character)
{
	// top 
	draw_horizontal_line(canvas, top_row, left_col, width, character);

	// bottom 
	draw_horizontal_line(canvas, top_row + height - 1, left_col, width, character);

	// left 
	draw_vertical_line(canvas, top_row, left_col, height, character);

	// right
	draw_vertical_line(canvas, top_row, left_col + width - 1, height, character);

}

// fills the rectangle with the given character
void fill_rectangle(char canvas[HEIGHT][WIDTH], int top_row, int left_col, int width, int height, char character) 
{
	for(int r = top_row + 1; r < top_row + height - 1; ++r)
	{
		for(int c = left_col + 1; c < left_col + width - 1; ++c)
		{
			draw_point(canvas, r, c, character);
		}
	} 
}

// fills rectangle with given fill_character or just prints border character
void draw_filled_rectangle(char canvas[HEIGHT][WIDTH], int top_row, int left_col, int width, int height, char fill_character, char border_character, bool filled)
{
	if(filled == true)
	{
		fill_rectangle(canvas, top_row, left_col, width, height, fill_character);
	}

		draw_rectangle(canvas, top_row, left_col, width, height, border_character);	
}

// creates a right angle triangle using draw_horizontal_line()
void draw_right_angle_triangle(char canvas[HEIGHT][WIDTH], int start_row, int column, int height, char character)
{
	for(int r = start_row; r <= start_row + height - 1; ++r)
	{
		draw_horizontal_line(canvas, r, column, r - start_row + 1, character);
	}
}	

// creates a center triangle
void draw_centered_triangle(char canvas[HEIGHT][WIDTH], int start_row, int center_col, int height, char character)
{
	for(int i = 0; i < height; ++i)
	{
		int start_col = center_col - i;
		draw_horizontal_line(canvas, start_row + i, start_col, height, character);
	}
}

// simple diagonal line, starts at top left, to bottom right
void draw_diagonal_down_right(char canvas[HEIGHT][WIDTH], int start_row, int start_col, int length, char character)
{
	for(int i = 0; i < length; ++i)
	{
		int row = start_row + i;
		int col = start_col + i;
		draw_point(canvas, row, col, character);
	}
}

// diagonal line, starts at top right, to bottom left
void draw_diagonal_down_left(char canvas[HEIGHT][WIDTH], int start_row, int start_col, int length, char character)
{
	for(int i = 0; i < length; ++i)
	{
		int row = start_row + i;
		int col = start_col - i;
		draw_point(canvas, row, col, character);
	}
}

int main(void)
{
	char m_canvas[HEIGHT][WIDTH]; // canvas obj 

	// calling functions
	clear_canvas(m_canvas);
    for(int r = 0; r < HEIGHT; ++r) 
    {
        draw_diagonal_down_left(m_canvas, r, 5, 8, '+');
    }
    for(int c = 0; c < WIDTH; ++c) 
    {
        fill_rectangle(m_canvas, 0, c, 5, 5, '*');
    }
    render_canvas(m_canvas);
}	

