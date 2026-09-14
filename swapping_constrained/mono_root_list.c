int mono_root_list( int clip , int * list ) {
  int * todo , * done , aux ; 
  todo = list ;
  if ( clip >= nt ) {
    * todo = lefdes [ clip ] ;
    aux = rigdes [ clip ] ; 
    if ( aux >= nt && !isblocked [ aux ] ) {
       * ++ todo = lefdes [ aux ] ; 
       * ++ todo = rigdes [ aux ] ;
      }
    }
  else * todo = clip ;         
  done = todo ++ ;
  while ( done < todo ) {
    at = * done ++ ; 
    if ( at >= nt && !isblocked [ at ] ) { 
      * todo ++ = lefdes [ at ] ; 
      * todo ++ = rigdes [ at ] ;
     }
   }
  return todo - list ; 
}
