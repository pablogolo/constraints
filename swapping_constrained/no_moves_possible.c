int no_moves_possible( int clip , int dad ) {
  if ( isblocked [ dad ] && isblocked [ cousin ] ) {
    if ( clip < nt )
      return 1 ; 
    if ( isblocked [ lefdes [ clip ] ] && isblocked [ rigdes [ clip ] ] )
      return 1 ;
   }  
  return 0 ;     
}    
