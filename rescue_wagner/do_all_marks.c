void do_all_marks( char * taxisafloat , char * grpwasok , char * nodeisfix , char * nodtobreak ) {
  mark_taxisafloat( taxisafloat ) ; 
  mark_neg_consts_obeyed( grpwasok ) ; 
  mark_nodes_that_must_be_mono( nodeisfix ) ;
  mark_nodes_that_are_mono_but_shouldnt_be( nodtobreak ) ; 
}
