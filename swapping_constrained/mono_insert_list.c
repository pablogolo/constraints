int mono_insert_list ( int from , int * list ) {
  int * todo , * done , isfirst ;  
  while ( !isblocked [ from ] )
    from = ancestor [ from ] ; // more groups constrained, stops earlier!
  *  ( todo = list ) = from ;
  done = todo ++ ;
  isfirst = 1 ; 
  while ( done < todo ) {
    at = * done ++ ; 
    if ( at >= nt && ( !isblocked [ at ] || isfirst ) ) { 
      * todo ++ = lefdes [ at ] ; 
      * todo ++ = rigdes [ at ] ;
     }
    isfirst = 0 ;
   }
  return todo - list ; 
}
