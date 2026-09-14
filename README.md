# constraints
Pseudocode for constraints in branch-swapping and Wagner trees

Note that the function clip_tree() (not shown) works by clipping group clip, making ancestor [sister] and ancestor [cousin] equal to grandpa, with dad no longer a node of main subtree : 

"
left  right                    left  right        
 son   son                      son   son 
  \   /            becomes:       \   /   
   clip   sister     ====>        clip    
     \   /                        /    
      dad   cousin              dad      sister  cousin
        \    /                                \    /
        grandpa                               grandpa 
            \                                     \
             \                                     \
              \                                     \
             root                                  root
"
