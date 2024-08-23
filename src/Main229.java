import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main229 {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        HashMap<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (countMap.containsKey(nums[i])) {
                countMap.put(nums[i], countMap.get(nums[i]) + 1);
            } else {
                countMap.put(nums[i], 1);
            }
        }
        countMap.forEach((value, count) -> {
            if (count > nums.length / 3) {
                result.add(value);
            }
        });
        return result;
    }

    /**
     * 摩尔投票
     * @param nums
     * @return
     */
    public List<Integer> majorityElement1(int[] nums) {
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (vote1 > 0 && nums[i] == element1) {
                vote1++;
            } else if (vote2 > 0 && nums[i] == element2) {
                vote2++;
            } else if (vote1 == 0) {
                element1 = nums[i];
                vote1++;
            } else if (vote2 == 0) {
                element2 = nums[i];
                vote2++;
            } else {
                vote1--;
                vote2--;
            }
        }
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == element1) {
                count1++;
            }
            if (nums[i] == element2) {
                count2++;
            }
        }
        List<Integer> result = new ArrayList<>();
        if (vote1 > 0 && count1 > nums.length / 3) {
            result.add(element1);
        }
        if (vote2 > 0 && count2 > nums.length / 3) {
            result.add(element2);
        }
        return result;
    }
}
