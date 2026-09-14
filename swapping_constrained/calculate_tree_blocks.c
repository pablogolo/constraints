void calculate_tree_blocks ( char * blocks ) {
  int i , a , b , csz ;
  int lim = ref_tree [ nt ] ; 
  for ( i = nt - 1 ; ++ i < nodz ; ) blocks [ i ] = nodlist [ i ] = 0 ;
  nodlist[ nt ] = 1 ;
  fill_nodsizes( grpsiz ) ; // trivial
  for ( i = nt ; i ++ < lim ; ) {
    b = ref_tree [ a = constlast [ i ] ] ;
    a = ancestor [ a ] ;
    while ( !nodlist [ b ] ) {
      csz = const_nodsiz [ b ] ; 
      nodlist[ b ] = 1 ;
      b = ref_tree [ b ] ; 
      while ( grpsiz [ a ] != csz && a != nt ) a = ancestor [ a ] ;
      blocks [ a ] = 1 ;
     }
   }
  blocks [ nt ] = 1 ; 
  return ; 
}
