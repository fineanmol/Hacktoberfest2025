import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode 207: Course Schedule
 * Determines if all courses can be finished given prerequisites.
 * Uses DFS with cycle detection.
 */
public class CourseSchedule {

    /**
     * Returns true if all courses can be finished.
     * @param numCourses total number of courses (0 to numCourses-1)
     * @param prerequisites list of prerequisite pairs [a, b] meaning b -> a
     */
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Build adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) graph.add(new ArrayList<>());
        for (int[] pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph.get(prereq).add(course);
        }

        // Track visited status: 0 = unvisited, 1 = visiting, 2 = visited
        int[] visited = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycleDFS(i, graph, visited)) return false;
            }
        }
        return true;
    }

    // DFS to detect cycle
    private boolean hasCycleDFS(int node, List<List<Integer>> graph, int[] visited) {
        visited[node] = 1; // visiting
        for (int neighbor : graph.get(node)) {
            if (visited[neighbor] == 1) return true; // cycle detected
            if (visited[neighbor] == 0 && hasCycleDFS(neighbor, graph, visited)) return true;
        }
        visited[node] = 2; // visited
        return false;
    }

    // Example usage
    public static void main(String[] args) {
        CourseSchedule cs = new CourseSchedule();

        int numCourses1 = 2;
        int[][] prereq1 = {{1,0}}; // 0 -> 1
        System.out.println("Can finish courses? " + cs.canFinish(numCourses1, prereq1)); // true

        int numCourses2 = 2;
        int[][] prereq2 = {{1,0}, {0,1}}; // cycle
        System.out.println("Can finish courses? " + cs.canFinish(numCourses2, prereq2)); // false
    }
}
