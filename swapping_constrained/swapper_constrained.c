void swapper_constrained ( void ) {
►  calculate_tree_blocks ( isblocked ) ; 
   for ( i = 1 ; i < nodz ; ++ i ) {
     clip = i ; 
     sister = sisof[ i ] ; 
     dad = ancestor[ i ] ; 
     cousin = sisof[ dad ] ; 
     grandpa = ancestor[ dad ] ; 
►    if ( no_moves_possible ( clip , dad ) ) continue ;
     clip_tree ( i ) ;
     recalculate_MP_sets ( clip , grandpa ) ; 
►    n_inserts = mono_insert_list ( grandpa , insert_list ) ; 
►    n_roots = mono_root_list( clip , root_list ) ;
     for ( j = 0 ; j < n_roots ; ++ j ) 
       for ( k = 0 ; k < n_inserts ; ++ k ) 
         eval_move ( clip , root_list[ j ] , insert_list[ k ] ) ; 
     if ( some_move_was_successful ) {
       recalc_anc_n_desc ( clip , best_posit , best_root ) ; 
►      calculate_tree_blocks ( isblocked ) ; 
      }
     else unclip_tree ( clip , sister ) ; 
   } 
 }
