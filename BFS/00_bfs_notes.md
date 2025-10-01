# BFS Notes

## Templates
### Tree Level Order (Size-based) 

### [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

```c++
queue<TreeNode*> q;
if(!root) return; q.push(root);
while(!q.empty()) {
    int sz=q.size();
    for(int i=0;i<sz;++i){
        auto cur=q.front();q.pop();
        /*process*/ 
        if(cur->left)q.push(cur->left); 
        if(cur->right)q.push(cur->right);
  	} 
 }
```
### Multi-source Grid BFS 

### [01 Matrix](https://leetcode.com/problems/01-matrix/)

```c++
queue<pair<int, int>> Que; 
vector<vector<int>> dist(m, vector<int>(n, -1));
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
for(all sources == 0) { dist[i][j] == 0; Que.push({i, j}); }
while(!Que.empty()) {
    for(Que.size())
    {
        auto p = Que.front(); Que.pop();
        for(auto &d:dirs)
            if(boundcheckok && dist[Xn][Yn] == -1)	// only if dist == -1 (unvisited)
            {
                //then fresh stat
                dist[Xn][Yn] = dist[p.first][p.first] + 1
                Que.push({Xn, Yn});
            }  
    }

}
```

## Edge / Trap Candidates (Outline)
1. Empty structure
2. Start is goal
3. Multiple sources
4. Blocked goal
5. Revisit due to late visited mark
6. Grid bounds off-by-one
7. Large queue memory usage
8. Non-uniform movement costs (BFS not valid)
9. State compression missing dimension
10. Early exit condition placement

---

## Problem Summaries 

### LC102 Binary Tree Level Order Traversal

[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150)

- Core: push every level nodes into queue and process
- Invariant: count every level's number for not visit new pushed node.
- Pitfall: forget to push level's vector , don't read `que.size()` dynamicly
- Complexity: O(N) time, O(W) space (W=max width)。

### LC994 Rotting Oranges

[Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/)

- Core: Push all initial rotten cells into a queue (multi-source BFS).  Each BFS layer = 1 minute
- Invariant: The first time we convert a fresh cell, the current layer index is its minimal rot time.
- Pitfall: Not record fresh number at begin. 
- Complexity: `O(m*n)` time, `O(m*n)` space。

### LC542 01 Matrix

[01 Matrix](https://leetcode.com/problems/01-matrix/description/)

- Core: Push all zeros (multi-source BFS). Each popped cell relaxes 4-neighbors; 
- Invariant: if dist != -1 it has been visited (already shortest)
- Pitfall: must put all zeros into queue, don't BFS 1
- Complexity: `O(mn)`time, `O(mn)` space。

## Edge / Trap List (Concrete 10)
1. Empty input (root=null / grid null) → return original
2. Start already satisfies goal
3. Multiple sources  -- not push all source into queue
4. Goal unreachable  -- set a value to count  --> fresh_remaining > 0。
5. Visited marking timing  -- every time find not visited nodes or count how many need to pop this level
6. Boundary off-by-one (nx<0 / nx>=m / ny>=n) 
7. Queue memory blowup  -- if visited then mark it.
8. Non-uniform cost -- Dijkstra/0-1 BFS。
9. Missing state dimension (含方向/钥匙/层数状态未编码) → 误判访问导致剪枝错误。
10. Early exit misplacement (在入队时退出或层未完整处理就返回) 导致层数错误。

## BFS vs DFS Shortest Path (English 5 sentences)
1. Breadth-First Search (BFS) explores the graph layer by layer, guaranteeing that the first time you dequeue a node you have found the shortest path length in an unweighted graph.
2. Depth-First Search (DFS) dives along a single branch and may reach the target early, but that path is not guaranteed minimal unless you exhaustively search and track the best.
3. BFS uses a queue that enforces non‑decreasing distance order (a “wavefront”); DFS uses a call stack and does not preserve global distance structure.
4. When edges carry non‑uniform positive weights (>1) or costs, plain BFS’s distance guarantee breaks and you must switch to 0‑1 BFS (for weights {0,1}) or Dijkstra (general non‑negative).
5. Practically, choose BFS for unweighted shortest path / minimal steps problems, and reserve DFS for full enumeration, structure analysis, or when path optimality is not required.

## Status Log
2025-10-01: +3 BFS (LC102, LC994, LC542) 标记= DRAFT（尚未完成 30 秒无卡顿口述，不计入 Coverage Done）。
Next Upgrade Criteria: 任一题完成 (1) 30s 口述 (2) 写出不变量+失败模式≥2 (3) 能迁移类比 → 将 BFS/DFS Done +1。
