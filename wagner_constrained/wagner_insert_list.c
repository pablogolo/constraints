int wagner_insert_list( int add , int * list ) {
  int * todo , * done , a , ldes , rdes ; 
  a = * ( todo = list ) = giveme_starting_node( add ) ;
  if ( a < nt ) return 1 ; 
  done = todo ++ ; 
  while ( done < todo ) {
    ldes = lefdes [ * done ] ;
    rdes = rigdes [ * done ] ;
    ++ done ;
    if ( !ref_tree [ add ] ) { 
      if ( ldes > nt ) * todo ++ = ldes ;
      if ( rdes > nt ) * todo ++ = rdes ;
     }
    else {
      if ( ldes > nt ) 
        if ( !isblocked [ ldes ] || ldes == hardfixpoint ) * todo ++ = ldes ; 
      if ( rdes > nt ) 
        if ( !isblocked [ rdes ] || rdes == hardfixpoint ) * todo ++ = rdes ;
     }
   }
  return todo - list ; 
}
