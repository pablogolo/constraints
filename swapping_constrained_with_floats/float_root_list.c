int float_root_list( int clip , int * list ) {
  int * todo , * done , i , afreeroot ; 
  if ( !grpsiz[ clip ] ) 
    return fill_root_list ( clip , list ) ; 
  done = list - 1 ;
  todo = list ;
  if ( clip < nt ) * todo ++ = clip ;
  else {
    * todo ++ = rigdes [ clip ] ;
    i = lefdes [ clip ] ; 
    if ( i > nt && ( !isblocked [ i ] || grpsiz[ i ] == grpsiz[ clip ] ) ) {
      * todo ++ = lefdes [ i ] ;
      * todo ++ = rigdes [ i ] ;
     }
   }
  while ( ++ done < todo ) {
    i = * done ;
    if ( i > nt ) {
      afreeroot = 1 ;
      if ( isblocked [ i ] ) {
        afreeroot = 0 ;  
        if ( grpsiz[ clip ] == grpsiz[ i ] ) afreeroot = 1 ;
       }
      if ( afreeroot || grpsiz[ i ] == grpsiz[ lefdes [ i ] ] )  
        * todo ++ = lefdes [ i ] ;
      if ( afreeroot || grpsiz[ i ] == grpsiz[ rigdes [ i ] ] )  
        * todo ++ = rigdes [ i ] ;
      }
    }
  return todo - list ; 
}
