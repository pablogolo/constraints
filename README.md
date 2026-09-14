# constraints
Pseudocode for constraints in branch-swapping and Wagner trees

Note that the function clip_tree() (not shown) works by clipping group clip, making ancestor [sister] and ancestor [cousin] equal 
to grandpa, with dad no longer a node of main subtree : 

<img width="867" height="349" alt="image" src="https://github.com/user-attachments/assets/2d9b13fe-7882-48aa-99f0-6781c3bf7e7c" />

The folders RAxML_tests and TNT_scripts contain TNT and bash scripts used in testing the correctness and efficiency of these algorithms, as
implemented in TNT.

