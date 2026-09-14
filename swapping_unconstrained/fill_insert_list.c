int fill_insert_list ( int from , int * list ) {
  int * todo , * done ;  
  * ( todo = list ) = from ;
  done = todo ++ ;
  while ( done < todo ) {
    at = * done ++ ; 
    if ( at >= nt ) { 
      * todo ++ = lefdes [ at ] ; 
      * todo ++ = rigdes [ at ] ;
    }
  }
  return todo - list ; 
}   
