int unmono_groups( void ) {
  int i , ii , j , k , n , sisis , isok = 0 , besval , have_breaks , isaflot ;
  int * desl ;
  int nodetochk , bottom , first_break , somechgs = 0 ; 
  all_mono_wagner ( ancestor ) ; // build a tree with all positive groups together...
  if ( obeys_constraints ( ancestor ) ) return 1 ; // did it, just by chance...
  do_all_marks ( taxisafloat , grpwasok , nodeisfix , nodtobreak ) ; 
  for ( i = 0 ; i < nodz ; ++ i ) nodisout[ i ] = 0 ;
  for ( ii = 0 ; ii < nodz && !isok ; ++ ii ) {
    i = ladd[ ii ] ; 
    if ( !i || i == nt || ancestor [ i ] == nt ) {
       if ( somechgs && ii == nodz – 1 ) {
           ii = -1 ; 
           somechgs = 0 ; }
       continue ; }
    j = ancestor [ i ] ;
    have_breaks = 0 ;
    isaflot = taxisaflot[ i ] ; 
    while ( ( !nodeisfix[ j ] || isaflot ) && ancestor [ j ] != nt ) {
      if ( nodtobreak[ j ] ) {
        if ( !have_breaks ) first_break = j ; 
        have_breaks = 1 ; }
      j = ancestor [ j ] ; }
    if ( !have_breaks ) { // no nodes to be made non-mono going down…
       if ( somechgs && ii == nodz – 1 ) {
           ii = -1 ; 
           somechgs = 0 ; }
      continue ; }
    nodetochk = i ; 
    bottom = j ; 
    sisis = sisof [ nodetochk ] ;
    unzert_and_upgrade_constraints( nodetochk ) ;
    while ( !nodeisfix[ bottom ] && ancestor [ bottom ] != nt ) bottom = ancestor [ bottom ] ;
    n_inserts = mono_insert_list ( bottom , insert_list ) ; // N.B. not going inside of first_break
    for ( m = 0 , desl = insert_list , besval = 0 ; m < n_inserts ; ++ desl , ++ m ) 
      if ( ( k = numimpros( nodetochk , * desl , grpwasok ) ) > besval ) {
        besval = k ; 
        n = * desl ; }
    // Try moving "nodetochk" to possible locations out of group 
    if ( besval ) {
      if ( isavalidpos( nodetochk , n ) ) isok = 1 ; 
      zert( nodetochk , n ) ;
      if ( isok ) break ; // we're done!
      do_all_marks ( taxisafloat , grpwasok , nodeisfix , nodtobreak ) ; 
      if ( ii == nodz – 1 ) {
           ii = -1 ; 
           somechgs = 0 ; }
      else somechgs = 1 ; 
      continue ; }
    else 
      zert_and_upgrade_constraints( nodetochk , sisis ) ;
    // Try placing as sister of "nodetochk" things that are now out
    for ( j = nodetochk ; j != bottom ; ) nodisout[ j = ancestor [ j ] ] = 1 ;
    for ( m = 0 , desl = insert_list , besval = 0 ; m < n_inserts ; ++ desl , ++ m ) {
      j = * desl ;
      if ( nodisout[ j ] ) { // invalid move, reset nodisout and skip...
        nodisout[ j ] = 0 ; continue ; } 
      sisis = sisof [ j ] ;
      unzert_and_upgrade_constraints( j ) ;
      if ( ( k = numimpros( j , nodetochk , grpwasok ) ) > besval ) {
        besval = k ; 
        n = j ; }
      zert_and_upgrade_constraints( j , sisis ) ; }
   if ( besval ) {
     sisis = sisof [ n ] ;
     unzert_and_upgrade_constraints( n ) ;
     if ( isavalidpos( n , nodetochk ) ) isok = 1 ; 
     zert( n , nodetochk ) ;
     if ( isok ) break ; // we're done!
     do_all_marks ( taxisafloat , grpwasok , nodeisfix , nodtobreak ) ; 
     if ( somechgs && ii == nodz – 1 ) {
         ii = -1 ; 
         somechgs = 0 ; }
     else somechgs = 1 ; 
     continue ; }
   // last resort: do TBR-like moves between "nodtchk" and "bottom"
   for ( j = first_break ; j != bottom ; ) {
     j = ancestor [ j ] ;     
     sisis = sisof[ j ] ;
     unzert_and_upgrade_constraints( j ) ; 
     if ( numimpros( nodetochk , sisis , grpwasok ) ) {
       if ( isavalidpos( nodetochk , sisis ) ) isok = 1 ; 
       tbreroot( nodetochk , j ) ;
       zert( j , sisis ) ;
       if ( isok ) break ; // we're done!
       do_all_marks ( taxisafloat , grpwasok , nodeisfix , nodtobreak ) ; 
       if ( somechgs && ii == nodz – 1 ) {
           ii = -1 ; 
           somechgs = 0 ; }
       else somechgs = 1 ; 
       break ; }
     else 
       zert_and_upgrade_constraints( j , sisis ) ; }
   if ( somechgs && ii == nodz – 1 && !isok ) {
       somechgs = 0 ; 
       ii = -1 ; }}
  if ( !isok ) 
    return 0 ; 
  return 1 ;
}
