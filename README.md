# constraints
Pseudocode for constraints in branch-swapping and Wagner trees

Note that the function clip_tree() (not shown) works by clipping group clip, making ancestor [sister] and ancestor [cousin] equal to grandpa, with dad no longer a node of main subtree : 

left  right                    left  right \n
 son   son                      son   son \n
  \\   /            becomes:       \\ /\n   
   clip   sister     ====>        clip   \n 
     \\   /                        /    
      dad   cousin              dad      sister  cousin
        \\    /                                \\    /
        grandpa                               grandpa 
            \\                                     \\
             \\                                     \\
              \\                                     \\
             root                                  root

