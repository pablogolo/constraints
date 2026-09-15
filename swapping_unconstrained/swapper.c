 void swapper ( void ) {
   for ( i = 1 ; i < nodz ; ++ i ) {
     clip = i ; 
     sister = sisof[ i ] ; 
     dad = ancestor[ i ] ; 
     cousin = sisof[ dad ] ; 
     grandpa = ancestor[ dad ] ; 
     clip_tree ( i ) ;
     recalculate_MP_sets ( clip , grandpa ) ; 
     n_inserts = fill_insert_list ( root , insert_list ) ; 
     n_roots = fill_root_list ( clip , root_list ) ; 
     for ( j = 0 ; j < n_roots ; ++ j ) 
       for ( k = 0 ; k < n_inserts ; ++ k ) 
         eval_move ( clip , root_list[ j ] , insert_list[ k ] ) ;
     if ( some_move_was_successful ) 
       recalc_anc_n_desc ( clip , best_posit , best_root ) ; 
     else unclip_tree ( clip , sister ) ; 
   } 
 }
