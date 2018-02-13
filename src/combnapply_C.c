#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

SEXP combnapply_C(SEXP Rvector, SEXP RRmode){

SEXP ret = R_NilValue;

long int size;
double  value1;
double  value2;
char    *mode;

SEXP Rsize;
SEXP Rmode;
SEXP Rvalue;

size          = length(Rvector);
//size  = INTEGER(Rsize)[0]; // size of vector 

Rmode         = STRING_ELT(RRmode,0);
mode          = (char*)CHAR(Rmode);

Rvalue        = coerceVector(Rvector, REALSXP);
double *Rval  = REAL(Rvalue);

PROTECT(ret = allocVector(REALSXP, (size * (size-1))/2 ));

// Init ret
for(long int x = 0; x <  (size*(size-1))/2; x++){ 
   REAL(ret)[x]=0; 
}
// ------------

// multiply
if(*mode=='*'){

double acc = 0 ;
long int  count = 0 ;

 for (long int i = 0; i < size; i++){

    value1  = Rval[i];

   for (long int j = i + 1; j < size; j++){

     value2           = Rval[j];
     REAL(ret)[count] = value1 * value2;
     count ++;  
 
   }
 }

} // End of mode *

// add
if(*mode=='+'){

double acc = 0 ;
long int  count = 0 ;

 for (long int i = 0; i < size; i++){

    value1  = Rval[i];

   for (long int j = i + 1; j < size; j++){

     value2           = Rval[j];
     REAL(ret)[count] = value1 + value2;
     count ++;  
 
   }
 }

} // End of mode +


// minus
if(*mode=='-'){

double acc = 0 ;
long int  count = 0 ;

 for (long int i = 0; i < size; i++){

    value1  = Rval[i];

   for (long int j = i + 1; j < size; j++){

     value2           = Rval[j];
     REAL(ret)[count] = value1 - value2;
     count ++;  
 
   }
 }

} // End of mode -


// devide
if(*mode=='/'){

double acc = 0 ;
long int  count = 0 ;

 for (long int i = 0; i < size; i++){

    value1  = Rval[i];

   for (long int j = i + 1; j < size; j++){

     value2           = Rval[j];
     REAL(ret)[count] = value1 / value2;
     count ++;  
 
   }
 }

} // End of mode /

// bool
if(*mode=='='){

double acc = 0 ;
long int  count = 0 ;

 for (long int i = 0; i < size; i++){

    value1  = Rval[i];

   for (long int j = i + 1; j < size; j++){

     value2           = Rval[j];
     REAL(ret)[count] = value1 == value2;
     count ++;  
 
   }
 }

} // End of mode ==


UNPROTECT(1);

return ret;

}

