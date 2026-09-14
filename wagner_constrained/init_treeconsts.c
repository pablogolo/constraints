void init_treeconsts ( void )
{
  int a ;
  int treeconstnum = ref_tree [ nt ] ; 
  for( a = 0 ; a < treeconstnum ; ++ a ) 
    const_nodsiz[ a ] = constlast [ a ] = isblocked [ a ] = 0 ; 
  const_nodsiz[ nt ] = 1 ;
  a = ref_tree [ lefdes [ nt + 1 ]] ;
  while ( a && a < treeconstnum ) {
    ++ const_nodsiz[ a ] ;
    constlast [ a ] = lefdes [ nt + 1 ];
    a = ref_tree [ a ] ;
   } 
  a = ref_tree [ rigdes [ nt + 1 ]] ; 
  while ( a && a < treeconstnum ) {
    ++ const_nodsiz[ a ] ;
    constlast [ a ] = rigdes [ nt + 1 ];
    a = ref_tree [ a ] ;
   }
  a = ref_tree [ lefdes [ nt ] ] ; 
  while ( a && const_nodsiz[ a ] < 2 && a != nt ) a = ref_tree [ a ] ;
  grpsiz[ nt + 1 ] = grpsiz[ nt ] = 0 ;
  if ( ref_tree [ lef [ nt + 1 ] ] ) {
    grpsiz[ nt + 1 ] ++ ;
    grpsiz[ nt ] ++ ;
    if ( a && ref_tree [ lefdes [ nt + 1 ]] )
      constlast [ a ] = lefdes [ nt + 1 ] ;
   }
  if ( ref_tree [ rig [ nt + 1 ] ] ) {
    grpsiz[ nt + 1 ] ++ ;
    grpsiz[ nt ] ++ ;
    if ( a && ref_tree [ rigdes [ nt + 1 ]] )
      constlast [ a ] = rigdes [ nt + 1 ] ;
   }
  if ( !constlast [ nt ] ) constlast [ nt ] = sis [ 0 ] ; 
  if ( ref_tree [ 0 ] ) 
    grpsiz[ nt ] ++ ;
  return ;
}
