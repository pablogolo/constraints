#define S0   1 
#define S1   2 
#define MISS 3 

void change_addseq ( int * ladd ) {
  int n , p , i , t , in_pos , neg_not_pos ;
  int negstate , postate ; 
  for ( n = 0 ; n < n_neg_consts ; ++ n ) 
    for ( p = 0 ; p < n_pos_consts ; ++ p ) {
      isok = neg_not_pos = in_pos = 0 ; 
      for ( i = 0 ; i < nt ; ++ i ) {
        t = ladd [ i ] ; 
        negstate = neg_constraints[ t ][ n ] ; 
        postate = pos_constraints[ t ][ p ] ;
        if ( negstate == S1 ) 
          if ( postate != S1 || in_pos > 1 ) {
            isok = 1 ;
            break ; }
          else {
            if ( ++ neg_not_pos == 1 )
              zertfm = i ; 
            else break ; }
        if ( negstate == MISS || postate == MISS )
          flotandnegs = 1 ; 
        if ( postate == S1 )
          ++ in_pos ;
       }
      if ( isok ) continue ;
      zertto = 0 ; 
      while ( ++ i < nt ) {
        t = ladd [ i ] ; 
        negstate = neg_constraints[ t ][ n ] ;
        postate = pos_constraints[ t ][ p ] ;
        if ( negstate == MISS || postate == MISS )
          flotandnegs = 1 ;
        if ( negstate == S1 && postate != S1 ) {
          zertto = i ;
          break ;
         } 
        if ( negstate == S0 && postate == S1) {
          zertto = i ;
          break ;
         }
       }
      if ( !zertto ) continue ; 
      first = ladd [ zertto ] ; 
      for ( j = zertto ; j > zertfm ; -- j )
         ladd [ j ] = ladd [ j - 1 ] ;
      ladd [ zertfm ] = first ;
     }
  return ; 
}
