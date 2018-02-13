#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

SEXP find_windowC(SEXP Rpositions, SEXP Rstart, SEXP Rend, SEXP RMERKEN)
{

SEXP val        = R_NilValue;
PROTECT(val     = Rf_allocVector(INTSXP,2));
INTEGER(val)[0] = 0;
INTEGER(val)[1] = 0;

 Rstart       = coerceVector(Rstart, REALSXP);
 Rend         = coerceVector(Rend, REALSXP);
 Rpositions   = coerceVector(Rpositions, REALSXP);
 RMERKEN      = coerceVector(RMERKEN, INTSXP);

long int size;
double *start  = REAL(Rstart);
double *end    = REAL(Rend);
double *pos    = REAL(Rpositions);
int *merken    = INTEGER(RMERKEN);

size           = length(Rpositions);

long int begin = merken[0] - 1;

if(start[0]>pos[size-1]){
    UNPROTECT(1);
 return R_NilValue;
}
if(end[0]<pos[0]){
   UNPROTECT(1);
 return R_NilValue;
}

int notfound = 1;
for(long int i=begin; i < size; i++) {

  if(notfound){
   if(start[0]<=pos[i]){

       if(start[0]<pos[i] && end[0]<pos[i]){
          UNPROTECT(1);
          return R_NilValue;
       }
       INTEGER(val)[0]=i+1; // left side found
       notfound = 0;
   }
 }//not found 

  if(end[0]<=pos[i]){ // search for right side
   
    if(end[0]==pos[i]){
      INTEGER(val)[1]=i+1;
      goto mark;
    }

     INTEGER(val)[1]=i;
     goto mark;             
 }

}

mark:
UNPROTECT(1);
return val;


}

