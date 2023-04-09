/**
     *
     * @param grid the escape room
     * @param m number of rows of grid
     * @param n number of columns of grid
     * @param source_x current x coordinate
     * @param source_y current y coordinate
     * @param target_x exit x coordinate
     * @param target_y exit y coordinate
     * @param canBreakWall boolean if wall can be broken or not
     * @param moves current move count
     * @param visited boolean visited array
     * @param direction Direction object indicating the wall break direction
     * @return minimum number of moves
     */
    static int solve(char[][] grid, int m, int n, int source_x, int source_y, int target_x, int target_y, boolean canBreakWall, int moves, boolean[][] visited, Direction direction) {
        if(source_x == target_x && source_y == target_y) {
            return moves;
        }
        visited[source_x][source_y] = true;
        int ans = Integer.MAX_VALUE;
        int[] direction_x = {-1, 1, 0, 0};
        int[] direction_y = {0, 0, -1, 1};

        outer:for(int i=0;i<4;i++) {
            int row = source_x + direction_x[i];
            int cols = source_y + direction_y[i];

            if(row < 1 || row >= m - 1 || cols < 1 || cols >= n - 1 || visited[row][cols]) {
                continue outer;
            }
            else if(grid[row][cols] == '*') {
                int temp = solve(grid, m, n, row, cols, target_x, target_y, canBreakWall, moves + 1, visited, direction);
                if(temp != -1)
                    ans = Math.min(ans, temp);
            }else {
                if(canBreakWall) {
                    grid[row][cols] = '$';
                    int temp = switch (i) {
                        case 0 -> solve(grid, m, n, row, cols, target_x, target_y, false, moves + 1, visited, new Direction(false, false, true, false));
                        case 1 -> solve(grid, m, n, row, cols, target_x, target_y, false, moves + 1, visited, new Direction(false, false, false, true));
                        case 2 -> solve(grid, m, n, row, cols, target_x, target_y, false, moves + 1, visited, new Direction(true, false, false, false));
                        default -> solve(grid, m, n, row, cols, target_x, target_y, false, moves + 1, visited, new Direction(false, true, false, false));
                    };
                    if(temp != -1)
                        ans = Math.min(ans, temp);
                    grid[row][cols] = 'x';
                }else {
                    if(direction.down && row - 1 >= 1 && row - 1 < m - 1 && cols < n - 1 && grid[row - 1][cols] == '$') {
                        grid[row][cols] = '$';
                        int temp = solve(grid, m, n, row, cols, target_x, target_y, false, moves, visited, direction);
                        if(temp != -1)
                            ans = Math.min(ans, temp);
                        grid[row][cols] = 'x';
                    }
                    else if(direction.up && row + 1 < m - 1 && cols < n - 1 && grid[row + 1][cols] == '$') {
                        grid[row][cols] = '$';
                        int temp = solve(grid, m, n, row, cols, target_x, target_y, false, moves, visited, direction);
                        if(temp != -1)
                            ans = Math.min(ans, temp);
                        grid[row][cols] = 'x';
                    }
                    else if(direction.right && row < m - 1 && cols - 1 >= 1 && cols - 1 < n - 1 && grid[row][cols - 1] == '$') {
                        grid[row][cols] = '$';
                        int temp = solve(grid, m, n, row, cols, target_x, target_y, false, moves, visited, direction);
                        if(temp != -1)
                            ans = Math.min(ans, temp);
                        grid[row][cols] = 'x';
                    }
                    else if(direction.left && row < m - 1 && cols + 1 < n - 1 && grid[row][cols + 1] == '$') {
                        grid[row][cols] = '$';
                        int temp = solve(grid, m, n, row, cols, target_x, target_y, false, moves, visited, direction);
                        if(temp != -1)
                            ans = Math.min(ans, temp);
                        grid[row][cols] = 'x';
                    }
                }
            }
        }
        visited[source_x][source_y] = false;
        return ans == Integer.MAX_VALUE? -1: ans;
    }
    static class Direction {
        boolean up;
        boolean down;
        boolean left;
        boolean right;

        Direction(boolean up, boolean down, boolean left, boolean right) {
            this.up = up;
            this.down = down;
            this.left = left;
            this.right = right;
        }
    }
