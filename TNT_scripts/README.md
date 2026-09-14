This folder contains TNT scripts.

GRANDTEST

The script grandtest.run takes as parameters the number of datasets to generate (G), the number of taxa (T, always with half 
as many characters as taxa)), the number of positive (=tree) constraints (C), the number of negative constraints (N), and the 
number of floating taxa (F), as arguments (in that order). 

Optionally, use "-v" as sixth (and last) argument, to generate diagrams of the constraints for every dataset (this can be a LOT
of output!).

For each dataset, the script creates two copies of a random tree, and makes 5 random moves to one of them (to create some 
differences). First, it prunes F taxa from the first tree,  collapses all its groups except C, and uses that as tree-constraints. 
Second, it prunes F taxa (a different set of F taxa), it finds all the groups in the second tree that are not present in the 
modified first tree, retains N of those (or fewer, if N too large), and uses those as negative constraints. It then effects 
1,000 random addition sequences plus TBR (nomulpars), and records the number of Wagner trees that needed to be fixed. This 
entire process is repeated G times. If an addition sequence produces a Wagner tree that cannot be fixed into satisfying 
constraints, the process halts and the script stops.

For each dataset that needs fixing a Wagner tree, the program reports the corresponding random seed (R). With this, you can 
reproduce the dataset for which that number of Wagner trees (out of the 1,000) needed to be fixed, with 

        grandtest 1 T C N F ; <enter>

Of course, the dataset and constraints will be identical only if T, C, N, and F are the same. 








