package com.acronymor.array;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class Lc1C2sumTest {
    @Test
    public void solve() {
        Lc1C2sum demo = new Lc1C2sum();

        int[] nums1 = {1, 2, 3, 4, 5};
        int target1 = 6;
        int[] res1 = {1, 3};
        int[] res = demo.solve(nums1, target1);
        Assertions.assertArrayEquals(res1, res);
    }
}