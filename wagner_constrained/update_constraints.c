void update_constraints( int add, int position ) { 
  int a , newnode;
  int treeconstnum ;
  treeconstnum = ref_tree [ nt ] ; 
  newnode = ancestor [ position ] ;
  if ( position < nt ) {
    grpsiz[ newnode ] = 0 ;
    if ( ref_tree [ position ] ) grpsiz[ newnode ] ++ ; 
    if ( ref_tree [ add ] ) grpsiz[ newnode ] ++ ;
   }
  else {
    grpsiz[ newnode ] = grpsiz[ position ] ;
    if ( ref_tree [ add ] ) grpsiz[ newnode ] ++ ;
   }
  if ( ref_tree [ add ] ) {
    a = ancestor [ newnode ] ; 
    while ( a != nt ) {
      ++ grpsiz[ a ] ;
      a = ancestor [ a ] ;
     } 
    ++ const_nodsiz[ a ] ;
   }
  a = ref_tree [ add ];
  if ( a ) // i.e. a is not a floater... 
    while ( a < treeconstnum) { 
      ++ const_nodsiz[ a ] ;
      constlast [ a ] = add;
      a = ref_tree [ a ] ;
    }
  return ;
}
