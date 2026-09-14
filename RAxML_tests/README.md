The files in this folder serve to test differences in constraint implementations in TNT and RAxML. 

The files dotest and runraxml are bash scripts. The file dodata.run is a TNT script, which creates
a dataset and constraints and saves them in a format that can be read with RAxML. You may have to 
edit runraxml to point to where the actual RAxML binary is in your machine. 

For each dataset, TNT generates a dataset with T and C characters, using a random tree as model (withb P(chg)=0.10).
For the model tree, TNT marks a group to be removed, R times (the same group can be marked twice!), then collapses
the groups marked and uses that as constraint for a search, comparing the times for TNT and RAxML. Last argument is 
the random seed (X). TNT will also take the tree produced by RAxML and subject it to SPR first, TBR second, 
recording the number of moves that improve the tree in every case.

Usage is: 

         ./dotest T C R X

Results are logged to a file "values.csv" (in append mode), with the following columns: 

    Number of times a group in model tree is marked for removal
    Average time for TNT to do 10 RAS+TBR (nomulpars)
    Time for RAxML to do a RAS+branch swapping (restricted SPR) 
    Ratio between the two times
    Number of SPR moves	made by TNT that improve the tree produced by RAxML (i.e. RAxML doesn't do full SPR)
    Number of TBR-moves	that improve the SPR tree produced by TNT (in previous column)
    Step difference between the tree produced by RAxML and the final TBR tree






