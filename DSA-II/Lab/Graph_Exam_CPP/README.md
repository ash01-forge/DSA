# Graph Algorithms Exam C++ Pack

**Start with `FILE_LIST.md` for all 40 standalone variations. `NEW_VARIATIONS_GUIDE.md` lists 13 added patterns; `MORE_VARIATIONS_GUIDE.md` lists 10 further patterns. `ALL_VARIATIONS_FULL_CODE.md` contains the full source of all 40 programs in one place.**

Each numbered `.cpp` file is a **standalone program**. Compile and run one at a
time, for example:

```bash
g++ -std=c++17 Dijkstra/02_ambulance_path.cpp -o ambulance
./ambulance
```

Type the numbers in each file's opening comment in order. The program prints
prompts between inputs. Its descriptive output labels are for learning.
**If an online judge requires exact output, remove the prompt and label `cout`
statements and print only the specified value(s).**

## Folder map

| Folder | Teacher code | Variations |
|---|---|---|
| Dijkstra | `00_teacher_original.cpp` | Pizza vertex wait; Tourist, Ambulance, Package paths; Wildfire and Farm nearest candidates |
| Bellman_Ford | `00_teacher_original_incomplete.cpp` | Banking, EV, Game with completed main and INF guard |
| DSU | DSU functions in Kruskal teacher file | Corporate MERGE and QUERY |
| Kruskal | `00_teacher_original.cpp` | Min-tree max edge, Max-tree min edge, truck limit, existing and required cables, budget/towers, metro indexed reuse, rail indexed mandate |
| Prims | `00_teacher_original.cpp` | Original Prim's MST reference |
| Teacher_Originals | `codes.zip` | Exact uploaded archive for byte-for-byte reference |

## What the input means

- **Vertex**: intersection, stop, town, hub, company, or island.
- **Edge**: road, route, link, transfer, cable, or merger.
- **Edge weight**: road time, construction cost, bandwidth/capacity, or net transfer cost.
- **Vertex weight**: only the Pizza example's waiting time at each intersection.
- In Metro and Rail, the last integer is a **0-based edge-list index**, not a vertex.
- In Wildfire and Farm, `A K` means starting vertex `A` and `K` candidate
  destination vertices, whose IDs come next.
- `n m` normally means vertex and edge counts. Corporate DSU uses `m` as
  the number of chronological operations instead.

## Choose the code

| Question clue | File |
|---|---|
| Nonnegative shortest path with vertex waiting time | `Dijkstra/01_pizza_node_wait.cpp` |
| One shortest path plus vertex sequence | `Dijkstra/01_tourist_path.cpp`, `02_ambulance_path.cpp`, `03_package_path.cpp` |
| Best of K candidate destinations plus path | `Dijkstra/04_wildfire_nearest_shelter.cpp`, `05_farm_nearest_cold_storage.cpp` |
| Negative edges / negative cycle from source | `Bellman_Ford/01_banking_transaction_cost.cpp` (same algorithm for EV and Game) |
| MERGE/QUERY connected groups | `DSU/01_corporate_merge_query.cpp` |
| Cheapest spanning tree, report largest selected edge | `Kruskal/01_min_tree_largest_edge.cpp` |
| Highest-weight spanning tree, report weakest selected edge | `Kruskal/02_max_tree_weakest_edge.cpp` |
| Maximum truck weight to every city | `Kruskal/03_max_truck_weight.cpp` |
| Existing connections and mandatory paid cable | `Kruskal/04_fiber_existing_required.cpp` |
| Budget, then count towers/components | `Kruskal/05_budget_tower_count.cpp` |
| Prebuilt route by 0-based index; sum chosen bandwidths | `Kruskal/06_metro_prebuilt_max_bandwidth.cpp` |
| Mandatory route by 0-based index; weakest selected capacity | `Kruskal/07_rail_mandatory_weakest.cpp` |

## Differences from teacher files and assumptions

The four original `.cpp` files are kept **unchanged**. The uploaded Bellman-Ford
file ends inside `main()` and contains a syntax error, so its `00_` file is a
reference, not a compilable program. The three completed Bellman-Ford variants
add an `INF` check so an unreachable vertex cannot relax an edge. They detect
negative cycles **reachable from the chosen source**.

Examples assume vertices are numbered from `1` and fewer than `1000`; the
0-based identifiers in Metro/Rail refer only to **edge positions**. Dijkstra
requires nonnegative edge weights and the Pizza example assumes nonnegative
waiting times. The sample roads are undirected; Bellman-Ford examples have
directed edges. Budgeted cable costs are nonnegative. If a real question uses
a different input layout or asks for exact words, adjust `main()` accordingly.

Metro and Rail assume forced routes form part of a **spanning tree**; the
program reports an error if they form a cycle. The question sheet's samples
meet that assumption. If a future question permits keeping cyclic prebuilt
routes, its objective needs separate clarification because simply adding
all positive-bandwidth edges would differ from a spanning-tree problem.

For the single-vertex MST edge-reporting cases, there is no selected edge and
therefore no largest/weakest selected edge; the learning code prints an
explanatory message. Reachability and disconnected results likewise depend
on the exact exam output specification.
