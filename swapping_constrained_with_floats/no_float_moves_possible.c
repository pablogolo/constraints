int no_float_moves_possible( int clip , int dad , int sister ) {
   if ( grpsiz[ clip ] && isblocked [ dad ] && isblocked [ sister ] ) 
     if ( grpsiz[ dad ] != grpsiz[ grandpa ] )
       if ( clip < nt || ( clip > nt && isblocked [ lefdes [ clip ] ] && isblocked [ rigdes [ clip ] ] ) 
        return 1 ; 
  return 0 ; 
}
