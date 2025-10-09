import java.util.*;

public class ArrayContainerWithMostWater {

    // Function to calculate the maximum area
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the area for the current left and right
            int width = right - left;
            int currentHeight = Math.min(height[left], height[right]);
            int currentArea = currentHeight * width;

            // Update the maximum area found so far
            maxArea = Math.max(maxArea, currentArea);

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right]) {
                left++;  // Move the left pointer to the right
            } else {
                right--; // Move the right pointer to the left
            }
        }

        return maxArea;
    }

    // Main function to test the solution
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        // Create a scanner for user input
        Scanner scanner = new Scanner(System.in);

        // Input the number of heights
        System.out.print("Enter the number of heights: ");
        int n = scanner.nextInt();

        // Input the height array
        int[] height = new int[n];
        System.out.println("Enter the heights of the lines:");
        for (int i = 0; i < n; i++) {
            height[i] = scanner.nextInt();
        }

        // Create an instance of the class and calculate the maximum area
        
        ArrayContainerWithMostWater solution = new ArrayContainerWithMostWater();
        int maxArea = solution.maxArea(height);

        // Output the result
        System.out.println("The maximum amount of water that can be contained is: " + maxArea);
    }
}
