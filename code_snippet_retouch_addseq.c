
      Tint * nodp , * nulis , * endp , * visit_list ;
      char * saved_state , * isflt ; 

      mksis( ref_anclist ) ; 
      for ( n = 0 ; n < nt ; ++ n ) saved_state[ n ] = S0 ;
      endp = visit_list ;
      for ( p = ref_anclist [ nt ] ; -- p > nt ; ) {
        for ( nodp = visit_list  ; nodp < endp  ; ++ nodp ) saved_state[ * nodp ] = S0 ; 
        * ( nodp = visit_list  ) = p ;
        endp = nodp + 1 ; 
        while ( nodp < endp  ) {
           i = * nodp ++ ;
           if ( i < nt ) saved_state [ i ] = S1 ;
           else 
           for ( c = lefdes[ i ] ; c >= 0 ; c = sisof [ c ] )
              * endp  ++ = c ; }
        for ( n = 0 ; n < numcneg ; ++ n ) {
           isok = nnotp = inp = 0 ;
           for ( i = 0 ; i < nt ; ++ i ) {
              c = addlist [ i ] ; 
              sn = negmatrix[ c ][ n ] ;
              sp = saved_state [ c ] ; 
              if ( sn == S1 ) {
                    if ( sp != S1 || inp > 1 ) { isok = 1 ; break ; }
                    else { if ( ++ nnotp == 1 ) zertfm = i ; 
                            else break ; }}
              if ( sp == S1 ) ++ inp ; }
           if ( isok ) continue ;
           zertto = 0 ; 
           while ( ++ i < nt ) {
              c = addlist [ i ] ; 
              sn = negmatrix[ c ][ n ] ;
              sp = saved_state[ c ] ; 
              if ( sn == S1 && sp != S1 ) { zertto = i ; break ; }
              if ( sn == S0 && sp == S1 ) { zertto = i ; break ; }}
           if ( !zertto ) continue ; 
           first = addlist [ zertto ] ; 
           for ( j = zertto ; j > zertfm ; -- j ) addlist [ j ] = addlist [ j - 1 ] ;
           addlist [ zertfm ] = first ; }}

    if ( have_floaters && cncneg ) {
      for ( i = 0 ; i < nt ; ++ i ) 
         isflt[ i ] = 0 ; 
      for ( isok = i = 0 ; i < nt ; ++ i ) {
         atp = 0 ;
         if ( !ref_anclist[ i ] ) atp = 1 ; 
         for ( n = 0 ; n < numcneg && !atp ; ++ n ) {
            sn = negmatrix[ i ][ n ] ;
            if ( sn == S01 ) atp = 1 ; }
         if ( atp ) isflt [ i ] = 1 ;
         else ++ isok ; }
      if ( isok != nt ) {
          nodp = nulis ;
          endp = nulis + isok ;
          for ( i = 0 ; i < nt ; ++ i )
            if ( isflt [ addlist [ i ] ] ) * endp ++ = addlist [ i ] ;
            else * nodp ++ = addlist [ i ] ; 
          for ( i = 0 ; i < nt ; ++ i )
              addlist [ i ] = nulis [ i ] ; }}              

