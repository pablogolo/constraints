int giveme_starting_node( int add ) {
  int a , ndis , siz , treeconstnum ; 
  a = ref_tree [ add ] ;
  while ( !const_nodsiz[ a ] && a != nt )
    a = ref_tree [ a ] ; 
  siz = const_nodsiz [ a ] ; 
  if ( const_nodsiz[ a ] == 1 ) {
     b = a = constlast [ a ] ; 
     while ( grpsiz[ a ] == 1 && ancestor [ a ] != nt )
       a = ancestor [ b = a ] ;
     return b ;
    }
  ndis = a ; 
  a = ancestor [ constlast [ a ] ] ; 
  while ( grpsiz[ a ] < siz && a != nt )
    a = ancestor [ a ] ;
  hardfixpoint = a ; 
  if ( ancestor [ b = a ] != nt ) {
    while ( grpsiz[ ancestor [ a ] ] <= siz && a != nt ) {
      b = a ;
      a = ancestor [ a ] ;
     }
    a = b ;
   }
  for ( b = nt ; b ++ < ancestor [ nt ] ; ) isblocked [ b ] = 0 ;
  treeconstnum = ref_tree [ nt ] ; 
  for ( b = nt ; b < treeconstnum ; ++ b )  
    if ( ref_tree [ b ] == ndis ) { 
      c = ancestor [ constlast [ b ] ] ; 
      while ( c != nt && grpsiz[ c ] != const_nodsiz[ b ] ) c = ancestor [ c ] ;  
      isblocked [ c ] = 1 ;
     } 
  if ( a == nt ) a = lefdes [ a ] ;
  if( !a ) a = rigdes [ nt ] ;
  return a ;
}
