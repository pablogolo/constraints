int float_insert_list ( int clip , int dad , int sister , int * list ) {
  int * todo , * done , isfirst , i , gs , n , gointo , lasthard ;
  if ( !grpsiz[ clip ] ) 
    return fill_insert_list ( root , list ) ; 
  done = list - 1 ;
  todo = list ;
  lasthard = -1 ;
  if ( sisof [ 0 ] == 0 ) // special case: clipped all but outgroup
    * todo ++ = 0 ;  
  else {
    if ( isblocked [ dad ] ) {
      i = sister ;
      gs = grpsiz[ dad ] ;
      n = ancestor [ sister ] ; 
      while ( grpsiz [ n ] == gs && n != nt ) { 
        i = n ; 
        n = ancestor [ n ] ; }
      gointo = 0 ;
     }
    else {
      gointo = 1 ; 
      i = ancestor [ sister ] ;
      while ( i != nt && !isblocked [ i ] ) i = ancestor [ i ] ;
      if ( i != nt ) {
        gs = grpsiz[ i ] ;
        n = ancestor [ i ] ; 
        while ( grpsiz [ n ] == gs && n != nt ) { 
          if ( isblocked [ i ] && lasthard < 0 ) lasthard = i ; 
          i = n ; 
          n = ancestor [ n ] ;
         }
        }
      }
    if ( i != nt ) * todo ++ = i ; 
    else {
      * todo ++ = sisof [ 0 ] ;
      gointo = 0 ;
     }
   } 
  while ( ++ done < todo ) {
    i = * done ;
    if ( i > nt && ( !isblocked [ i ] || ( done == list && gointo ) || i == lasthard ) ) {
      * todo ++ = lefdes [ i ] ;
      * todo ++ = rigdes [ i ] ;
     }
   }
  return todo - list ; 
}
