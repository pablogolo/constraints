int fill_root_list ( int clip , int * list ) {
  int * todo , * done , aux ;  
  todo = list ;
  if ( clip >= nt ) {
    * todo = lefdes [ clip ] ;
    aux = rigdes [ clip ] ;
    if ( aux >= nt ) 
      * ++ todo = aux ;
   }
  else * todo = clip ;     
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
