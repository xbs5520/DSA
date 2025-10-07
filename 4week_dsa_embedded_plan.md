# 4-Week DSA + Embedded Prep Plan (Alberta Embedded SWE)

Pace: 5 days/week, 3–4 problems per day (~90–120 min) + 20–30 min hand-written DS practice. Weekends optional review.
Acceptance per problem: 30s oral, implement from scratch, 2 pitfalls, 1 edge test, time/space.

---
## Week 1 — Arrays/Strings, Sliding Window, Binary Search, Bit Ops, Linked Lists
Day 1 (Two Pointers)
- LC11 Container With Most Water
- LC15 3Sum; LC16 3Sum Closest
- Alt: LC18 4Sum
Hand-write: ring buffer API draft (rb_init/rb_push/rb_pop); list wraparound tests

Day 2 (Sliding Window)
- LC567 Permutation in String; LC438 Find All Anagrams
- LC3 Longest Substring Without Repeating Characters
- Alt: LC713 Subarray Product < K
Hand-write: stack (array + linked) push/pop/top; under/overflow cases

Day 3 (Binary Search)
- LC33 Search in Rotated Sorted Array; LC153 Find Minimum in Rotated
- LC34 First/Last Position; Alt: LC74 or LC240
Hand-write: lower_bound/upper_bound template + proofs of invariants

Day 4 (Bit Operations)
- LC191/190/201 (Count/Reverse/AND Range)
- LC231 Power of Two; LC342 Power of Four; Alt: LC476/371
Hand-write: 64-bit reassembly bitmap (mark/missing iterator)

Day 5 (Linked Lists)
- LC206 Reverse List; LC141/142 Cycle / Cycle II; LC21 Merge Two Sorted Lists
- Alt: LC19 Remove Nth; LC86 Partition List
Hand-write: singly list reverse (iterative), delete node in O(1)

---
## Week 2 — Monotonic Stack, Heaps, Design (LRU/LFU/Rings), 0-1 BFS
Day 6 (Monotonic Stack)
- LC739 Daily Temperatures; LC496 Next Greater Element I
- LC84 Largest Rectangle in Histogram; Alt: LC42
Hand-write: array-based deque (front/back indices), wrap logic

Day 7 (Histogram/Stack Variants)
- LC85 Maximal Rectangle; LC735 Asteroid Collision; LC853 Car Fleet
Hand-write: prove monotonic invariant for LC84/85

Day 8 (Heaps / Top-K)
- LC215 Kth Largest; LC347 Top K Frequent; LC23 Merge k Lists; Alt: LC295
Hand-write: binary heap push/pop (0- or 1-based index); sift up/down

Day 9 (Design / Ring Structures)
- LC146 LRU Cache; LC622/641 Circular Queue/Deque; Alt: LC460 LFU
Hand-write: fixed-block memory pool (free-list, alignment, poison)

Day 10 (0-1 BFS + Buckets)
- Implement 0-1 BFS (deque) + 1 sample; Bucket BFS (0..K) mini-demo
- Add path reconstruction (parent) to classic BFS
Hand-write: deque skeleton; complexity reasoning (O(V+E))

---
## Week 3 — Trees/Graphs/DSU/Trie
Day 11 (Tree Basics)
- LC226 Invert; LC543 Diameter; LC199 Right Side View
Hand-write: iterative preorder with stack; postorder two-stack

Day 12 (BST)
- LC98 Validate BST; LC230 Kth Smallest; LC235/236 LCA in BST/BT
Hand-write: Morris inorder (可选); BST insert/delete概念

Day 13 (Paths/Counts)
- LC103 Zigzag Level Order; LC437 Path Sum III; LC129 Sum Root to Leaf
Hand-write: parent array记录路径，重建输出

Day 14 (Graphs/UF)
- LC200 Number of Islands; LC695 Max Area; LC547 Provinces (DFS/UF)
Hand-write: DSU find/union (rank/size) + 连通分量计数

Day 15 (Topo / Word Ladder / Trie)
- LC207/210 Course Schedule I/II (Kahn)
- LC127/433 Word Ladder/Mutation（双向 BFS 版本）
- LC208 Trie; Alt: LC211
Hand-write: trie with static node pool（MAX_NODES）

---
## Week 4 — DP & Answer-Binary-Search, Parsers/Math
Day 16 (Linear DP)
- LC53 Maximum Subarray; LC70 Climbing Stairs; LC198 House Robber
Hand-write: 子问题/转移表述；迭代状态压缩

Day 17 (Grid/Coins)
- LC62 Unique Paths; LC322 Coin Change; LC91 Decode Ways (可选)
Hand-write: 1D 滚动数组技巧

Day 18 (Sequence DP)
- LC300 LIS (nlogn); LC1143 LCS; LC72 Edit Distance (可选)
Hand-write: patience piles 解释 + 重建路径（可选）

Day 19 (Answer-Binary-Search)
- LC875 Koko; LC1011 Ship Capacity; LC410 Split Array (可选)
Hand-write: 判定函数 monotonic 证明；边界处理

Day 20 (Parsers/Math/Stack)
- LC8 atoi; LC150 RPN; LC50 Pow(x,n)
Hand-write: FSM 解析器（WAIT_SOF/READ_LEN/READ_PAYLOAD/CRC）

---
## Stretch Goals (Weekend / Spare)
- Bitmask BFS：LC864 Keys and Locks；LC847 Visit All Nodes
- Advanced Heap：LC502 IPO；LC373 K Smallest Pairs
- Design：LFU（O(1) 两层哈希+双链表）；LRU path reconstruction
- Tricky Graph：LC130 Surrounded Regions（DFS/UF）; LC207 cycle cases

## Tracking & Acceptance
- 每天在 logs/ 中记录：完成题目、模板成熟度（1-5）、常错点、1个口述小抄。
- 任何题若>20分钟卡壳：切换同类替代题或降级做模板复写练习。
