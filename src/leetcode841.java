import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Leetcode841
 *
 * @author: Wenhao Tong
 * @date: 2023/7/16
 */
public class Leetcode841 {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int[] visited = new int[rooms.size()];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        while (!queue.isEmpty()) {
            Integer key = queue.poll();
            if (visited[key] == 1) {
                continue;
            }
            visited[key] = 1;
            rooms.get(key).forEach(queue::offer);
        }
        int count = 0;
        for (int i : visited) {
            if (i == 1) {
                count++;
            }
        }
        return count == rooms.size();
    }

    int[] visited;

    public boolean canVisitAllRooms_v2(List<List<Integer>> rooms) {
        visited = new int[rooms.size()];
        dfs(rooms, 0);
        int count = 0;
        for (int i : visited) {
            count += i;
        }
        return count == rooms.size();
    }

    private void dfs(List<List<Integer>> rooms, Integer key) {
        if (visited[key] == 1) {
            return;
        }
        visited[key] = 1;
        rooms.get(key).forEach(item -> {
            dfs(rooms, item);
        });
    }
}