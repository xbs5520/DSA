# DSA + Embedded Modules: 4-Week Daily Checklist

Guideline: Each workday solve ~3 problems (2–3 hrs total), then spend 30–60 min on the embedded module micro-goal. Check items as you complete them and jot notes if useful.

- Pace: 4 weeks × 5 days/week = 20 days
- Order: Keep per-day set; if you already solved a problem, swap with the provided alternate.

---

## Week 1 — Sliding Window, Two Pointers, Binary Search, Bit Ops
Module focus: Ring Buffer + Seq Wrap

### Day 1
- [ ] LC11 Container With Most Water — https://leetcode.com/problems/container-with-most-water/
- [ ] LC15 3Sum — https://leetcode.com/problems/3sum/
- [ ] LC16 3Sum Closest — https://leetcode.com/problems/3sum-closest/
- [ ] Module micro-goal: Ring buffer API skeleton (rb_init/rb_size/rb_free/rb_push/rb_pop) — byte-wise version
- Notes:

### Day 2
- [ ] LC567 Permutation in String — https://leetcode.com/problems/permutation-in-string/
- [ ] LC438 Find All Anagrams in a String — https://leetcode.com/problems/find-all-anagrams-in-a-string/
- [ ] LC713 Subarray Product Less Than K — https://leetcode.com/problems/subarray-product-less-than-k/
- [ ] Module micro-goal: Add contiguous-block push/pop to reduce memcpy; expose rb_write_ptr/rb_read_ptr (optional)
- Notes:

### Day 3
- [ ] LC3 Longest Substring Without Repeating Characters — https://leetcode.com/problems/longest-substring-without-repeating-characters/
- [ ] LC424 Longest Repeating Character Replacement — https://leetcode.com/problems/longest-repeating-character-replacement/
- [ ] LC76 Minimum Window Substring — https://leetcode.com/problems/minimum-window-substring/
- [ ] Module micro-goal: Full/empty detection, wraparound correctness tests (unit tests for edge indices)
- Notes:

### Day 4
- [ ] LC33 Search in Rotated Sorted Array — https://leetcode.com/problems/search-in-rotated-sorted-array/
- [ ] LC153 Find Minimum in Rotated Sorted Array — https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
- [ ] LC34 Find First and Last Position — https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
- [ ] Module micro-goal: Seq wrap helpers seq_before/seq_after using signed diff
- Notes:

### Day 5
- [ ] LC338 Counting Bits — https://leetcode.com/problems/counting-bits/
- [ ] LC201 Bitwise AND of Numbers Range — https://leetcode.com/problems/bitwise-and-of-numbers-range/
- [ ] LC190 Reverse Bits — https://leetcode.com/problems/reverse-bits/
- [ ] Module micro-goal: Reassembly window (64-bit bitmap) mark/missing iterator; test across 2^32 wrap
- Notes:

Alternates (Week 1): LC18 4Sum, LC1004 Max Consecutive Ones III, LC239 Sliding Window Maximum, LC162 Find Peak Element, LC231 Power of Two

---

## Week 2 — Monotonic Stack, Heaps, Design
Module focus: Memory Pool (fixed block) + O(1) structures

### Day 6
- [ ] LC739 Daily Temperatures — https://leetcode.com/problems/daily-temperatures/
- [ ] LC496 Next Greater Element I — https://leetcode.com/problems/next-greater-element-i/
- [ ] LC84 Largest Rectangle in Histogram — https://leetcode.com/problems/largest-rectangle-in-histogram/
- [ ] Module micro-goal: mp_init with free-list layout; block alignment & metadata
- Notes:

### Day 7
- [ ] LC42 Trapping Rain Water — https://leetcode.com/problems/trapping-rain-water/
- [ ] LC735 Asteroid Collision — https://leetcode.com/problems/asteroid-collision/
- [ ] LC853 Car Fleet — https://leetcode.com/problems/car-fleet/
- [ ] Module micro-goal: mp_alloc/mp_free O(1); basic unit tests
- Notes:

### Day 8
- [ ] LC215 Kth Largest Element in an Array — https://leetcode.com/problems/kth-largest-element-in-an-array/
- [ ] LC347 Top K Frequent Elements — https://leetcode.com/problems/top-k-frequent-elements/
- [ ] LC23 Merge k Sorted Lists — https://leetcode.com/problems/merge-k-sorted-lists/
- [ ] Module micro-goal: Double-free/overflow guards（magic/poison）；diagnostic counters
- Notes:

### Day 9
- [ ] LC622 Design Circular Queue — https://leetcode.com/problems/design-circular-queue/
- [ ] LC641 Design Circular Deque — https://leetcode.com/problems/design-circular-deque/
- [ ] LC232 Implement Queue using Stacks — https://leetcode.com/problems/implement-queue-using-stacks/
- [ ] Module micro-goal: Integrate pool with ring buffer for "frame object" allocation
- Notes:

### Day 10
- [ ] LC146 LRU Cache — https://leetcode.com/problems/lru-cache/
- [ ] LC460 LFU Cache — https://leetcode.com/problems/lfu-cache/
- [ ] LC380 Insert Delete GetRandom O(1) — https://leetcode.com/problems/insert-delete-getrandom-o1/
- [ ] Module micro-goal: Stress test 1e6 alloc/free; latency histograms
- Notes:

Alternates (Week 2): LC503 Next Greater Element II, LC402 Remove K Digits, LC373 Find K Pairs with Smallest Sums, LC225 Implement Stack using Queues, LC155 Min Stack

---

## Week 3 — Trees/Graphs/DSU/Trie
Module focus: Frame Parser (streaming FSM)

### Day 11
- [ ] LC226 Invert Binary Tree — https://leetcode.com/problems/invert-binary-tree/
- [ ] LC543 Diameter of Binary Tree — https://leetcode.com/problems/diameter-of-binary-tree/
- [ ] LC199 Binary Tree Right Side View — https://leetcode.com/problems/binary-tree-right-side-view/
- [ ] Module micro-goal: FSM skeleton + WAIT_SOF/READ_LEN states
- Notes:

### Day 12
- [ ] LC98 Validate BST — https://leetcode.com/problems/validate-binary-search-tree/
- [ ] LC230 Kth Smallest in BST — https://leetcode.com/problems/kth-smallest-element-in-a-bst/
- [ ] LC235 LCA of a BST — https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
- [ ] Module micro-goal: READ_PAYLOAD buffering with max length guard
- Notes:

### Day 13
- [ ] LC236 LCA of a Binary Tree — https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
- [ ] LC437 Path Sum III — https://leetcode.com/problems/path-sum-iii/
- [ ] LC103 Zigzag Level Order — https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
- [ ] Module micro-goal: CRC16/CRC32 verification hook
- Notes:

### Day 14
- [ ] LC200 Number of Islands — https://leetcode.com/problems/number-of-islands/
- [ ] LC695 Max Area of Island — https://leetcode.com/problems/max-area-of-island/
- [ ] LC547 Number of Provinces — https://leetcode.com/problems/number-of-provinces/
- [ ] Module micro-goal: Error handling & resync after bad CRC/overflow
- Notes:

### Day 15
- [ ] LC208 Implement Trie — https://leetcode.com/problems/implement-trie-prefix-tree/
- [ ] LC211 Add and Search Word — https://leetcode.com/problems/add-and-search-word-data-structure-design/
- [ ] LC648 Replace Words — https://leetcode.com/problems/replace-words/
- [ ] Module micro-goal: Randomized chunking tests (粘包/半包/错帧)
- Notes:

Alternates (Week 3): LC105 Build Tree from Pre+In, LC173 BST Iterator, LC130 Surrounded Regions, LC129 Sum Root to Leaf Numbers, LC720 Longest Word in Dictionary

---

## Week 4 — DP, Answer-Binary-Search, Parsers/Math
Module focus: Backoff + Token Bucket

### Day 16
- [ ] LC53 Maximum Subarray — https://leetcode.com/problems/maximum-subarray/
- [ ] LC70 Climbing Stairs — https://leetcode.com/problems/climbing-stairs/
- [ ] LC198 House Robber — https://leetcode.com/problems/house-robber/
- [ ] Module micro-goal: Exponential backoff base/cap; Full Jitter
- Notes:

### Day 17
- [ ] LC62 Unique Paths — https://leetcode.com/problems/unique-paths/
- [ ] LC322 Coin Change — https://leetcode.com/problems/coin-change/
- [ ] LC91 Decode Ways — https://leetcode.com/problems/decode-ways/
- [ ] Module micro-goal: Equal/Decorrelated Jitter variants
- Notes:

### Day 18
- [ ] LC300 LIS — https://leetcode.com/problems/longest-increasing-subsequence/
- [ ] LC1143 LCS — https://leetcode.com/problems/longest-common-subsequence/
- [ ] LC72 Edit Distance — https://leetcode.com/problems/edit-distance/
- [ ] Module micro-goal: Token bucket core (rate, burst) + tb_allow(n)
- Notes:

### Day 19
- [ ] LC875 Koko Eating Bananas — https://leetcode.com/problems/koko-eating-bananas/
- [ ] LC1011 Capacity To Ship Packages — https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
- [ ] LC410 Split Array Largest Sum — https://leetcode.com/problems/split-array-largest-sum/
- [ ] Module micro-goal: Rate conformance tests (±10% window)
- Notes:

### Day 20
- [ ] LC8 String to Integer (atoi) — https://leetcode.com/problems/string-to-integer-atoi/
- [ ] LC50 Pow(x, n) — https://leetcode.com/problems/powx-n/
- [ ] LC150 Evaluate Reverse Polish Notation — https://leetcode.com/problems/evaluate-reverse-polish-notation/
- [ ] Module micro-goal: Backoff + Token Bucket integration sim; ensure no sync bursts
- Notes:

Alternates (Week 4): LC213 House Robber II, LC518 Coin Change II, LC139 Word Break, LC4 Median of Two Sorted Arrays（高难）, LC227 Basic Calculator II

---

Tips
- 如果当天某题已做过或卡太久，使用当周“Alternates”替换。
- 每周末复盘：提炼模板（滑窗、单调栈、并查集、DP 转移、答案二分判定函数、FSM），写一页小抄。
- 模块代码建议用 C/C++ 独立 .h/.c 组织，配 minimal test.c，便于后续移植到 IMX 工程。