This folder contains TNT scripts, used for checking the correctness and efficiency of the different types of constraints, as implemented in TNT.

GRANDTEST

The script grandtest.run takes as parameters the number of datasets to generate (G), the number of taxa (T, always with half 
as many characters as taxa)), the number of positive (=tree) constraints (C), the number of negative constraints (N), and the 
number of floating taxa (F), as arguments (in that order). All these arguments are mandatory.

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

ERRORCHKS

The script errorchks.run checks whether using the same constraints as tree-constraints, or group-membership variables, produce 
identical results. The script generates a dataset for the specified number of taxa (T, first arg), uses as constraint a random 
tree (with a probability of collapsing a branch of 0.33, and no more than 4-tomies) with F (second arg) taxa removed (=floating 
for the constraints), and does a random addition sequence Wagner tree followed by TBR (with mulpars on, saving up to 1,000 
trees (removing zero-lengthb ranches using "rule 1" of TNT) using the same constraints as tree-constraints and group-membership 
variables, comparing the results. If there is any difference in the number of trees considered as distinct, or their lengths, 
the program reports an error. This process is repeated R times (third arg). Every dataset has C characters (fourth arg). That is 

        errorchks T F R C ; <enter>

Keep in mind that with two few characters, there may be too many MPTs, filling the memory with 1,000 trees; with too many, there 
may be no zero-length branches, so that no branch is collapsed, regardless of constraints; either of these two cases make the test 
less meaningful).

If no argument is given, T=15, F=6, R=1,000, C=20.

TNTVSITSELF

This script checks the differences in time for a random sequence plus TBR, using the same constraints as tree-constraints and as 
group-membership variables, for datasets with 10,000 taxa and 10 characters (generated on a random model tree, with P(chg)=0.10).
The constraints are based on the model tree, with different numbers of nodes marked for removal (starting with 500, successively 
adding 500 until groups are marked 9,500 times; the script does not check whether the same group is marked twice, so it is possible 
that fewer groups are removed --more likely with larger number of groups removed). 

At the end, it writes to "tnt-vs-itself.csv" the comma-separated values for the times used for each run. Columns are: number of 
times a group is marked for removal, time for constraints as tree-constraints, time for constraints as group membership variables.

TAXALFA

This script either creates a dataset with taxa alphabetically named (as many characters as first arg, as many taxta as the second), or 
renames the taxa in an existing dataset alphabetically (if using two asterisks as args). Some of the other scripts use this, so 
you need to download it to your computer for using the other scripts.


