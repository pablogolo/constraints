void wagner_constrained ( void ) {
  initialize_tree( addlist[ 0 ] , addlist[ 1 ] , addlist[ 2 ] ) ;
  init_treeconsts () ; 
  toadd = 3 ;
  while ( toadd < nt ) {
    add = addlist [ toadd ] ;
    n_inserts = wagner_insert_list( root , insert_list ) ;
    if ( insert_list[ 0 ] < nt )
      best_insert = insert_list[ 0 ] ;
    else 
      for ( i = 0 ; i < n_inserts ; ++ i )
        eval_moves( add , insert_list[ i ] ) ;      
    insert_taxon( add , best_insert ) ;
    update_constraints ( add , best_insert ) ;
   }
}
