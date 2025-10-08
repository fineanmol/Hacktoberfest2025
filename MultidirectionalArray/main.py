def count_xmas(grid):
    """
    Count all occurrences of 'XMAS' in the grid.
    The word can appear in 8 directions: horizontal, vertical, and diagonal (all ways).
    """
    rows = len(grid)
    cols = len(grid[0])
    target = "XMAS"
    count = 0
    
    # 8 directions: right, left, down, up, down-right, down-left, up-right, up-left
    directions = [
        (0, 1),   # right
        (0, -1),  # left
        (1, 0),   # down
        (-1, 0),  # up
        (1, 1),   # down-right
        (1, -1),  # down-left
        (-1, 1),  # up-right
        (-1, -1)  # up-left
    ]
    
    def check_direction(row, col, dx, dy):
        """Check if XMAS exists starting from (row, col) in direction (dx, dy)"""
        for i in range(len(target)):
            new_row = row + i * dx
            new_col = col + i * dy
            
            # Check bounds
            if new_row < 0 or new_row >= rows or new_col < 0 or new_col >= cols:
                return False
            
            # Check if character matches
            if grid[new_row][new_col] != target[i]:
                return False
        
        return True
    
    # Check every position in the grid
    for row in range(rows):
        for col in range(cols):
            # Try all 8 directions from this position
            for dx, dy in directions:
                if check_direction(row, col, dx, dy):
                    count += 1
    
    return count


def main():
    # Read the input file
    with open('input-file', 'r') as f:
        grid = [line.strip() for line in f.readlines()]
    
    # Count all occurrences of XMAS
    result = count_xmas(grid)
    
    print(f"Total occurrences of XMAS: {result}")


if __name__ == "__main__":
    main()
