
/**
 * @brief Create a Grid
 * 
 * @param h Height
 * @param w Width
 * @return the grid 
 */
void * CreateGrid(int h, int w);

/**
 * @brief Display the grid
 * 
 * @param h Height
 * @param w width
 * @param grid the grid
 */
void DisplayGrid(int **grid, int h, int w);

/**
 * @brief Delete the grid
 * 
 * @param grid the grid to delete
 */
void DeleteGrid(int **grid);