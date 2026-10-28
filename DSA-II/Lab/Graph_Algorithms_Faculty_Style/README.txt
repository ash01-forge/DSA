FOLDER STRUCTURE
================
Kruskal_DSU  : Faculty Kruskal, all DSU/MST practice, CT questions, variations
Prims        : Faculty Prim's and Maximum Prim's variation
Dijkstra     : Faculty Dijkstra, practice, CT questions, variations
Bellman_Ford : Faculty Bellman-Ford, practice, variation

HOW TO RUN
==========
Open any individual .cpp file and run it. Every .cpp has its own main().
The matching *_common.h file must remain in the same folder.

PROMPTS
=======
Each common header contains:
const bool SHOW_PROMPTS=true;

Keep true while practising. Change it to false when clean online-judge output is needed.

INPUT CHANGES TO WATCH
======================
1. N M versus N M K in the first line.
2. Special edges given as endpoint pairs versus 0-based edge indices.
3. Undirected input pushes both directions; directed input pushes only start to end.
4. One destination uses A B; multiple destinations use A K followed by K nodes.
5. Minimum spanning tree scans sorted edges from 0 to M-1.
6. Maximum spanning tree scans sorted edges from M-1 to 0.

